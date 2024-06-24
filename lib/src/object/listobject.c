//
// Created by manzi on 07/02/24.
//

#include <stddef.h>
#include <assert.h>
#include <memory.h>
#include <stdlib.h>
#include "object/listobject.h"
#include "object/boolobject.h"
#include "object/stringobject.h"
#include "object/integerobject.h"
#include "object/sliceobject.h"
#include "object/noneobject.h"

static object* list_rich_compare(object* lhs,  object* rhs, int op) {
    return TYTHON_FALSE; // todo: implement
}

static object* list_to_string(object* obj) {

    assert(IS_LIST(obj));

    list_object* list_obj = AS_LIST(obj);

    // collect string representations of all entries:
    object** element_strings = malloc(list_obj->size * sizeof(object*));
    size_t element_strings_total_length = 0;

    for (int i = 0; i < list_obj->size; ++i) {
        string_object* str = GET_STRING(list_obj->elements[i]);

        element_strings[i] = AS_OBJECT(str);
        element_strings_total_length += str->length;
    }

    // allocate memory for the final string, which includes two square brackets for the list and a comma and space between each element
    size_t separator_count = list_obj->size > 0 ? ((list_obj->size - 1) * 2) : 0; // the last entry is not followed by a comma and a space
    size_t str_len = (element_strings_total_length * sizeof(char)) + 2 + (separator_count * sizeof(char));
    char* string = malloc(str_len);
    string[0] = '[';
    string[str_len - 1] = ']';

    char* offset = string + 1;
    for (int i = 0; i < list_obj->size; ++i) {

        // copy the string representation of each entry
        string_object* element_str = AS_STRING(element_strings[i]);
        memcpy(offset, element_str->str, element_str->length);
        offset += element_str->length;

        if (i != list_obj->size - 1) {
            *offset++ = ',';
            *offset++ = ' ';
        }
    }

    return TO_STRING(string, str_len);
}

static object** list_subscript(object* obj, object* idx) {

    assert(IS_LIST(obj));
    assert(IS_INT(idx));

    list_object* list_obj = AS_LIST(obj);

    if (IS_INT(idx)) {

        int_object* idx_obj = AS_INT(idx);

        long long index = idx_obj->value;

        if (index < 0) {

            // negative indexes wrap around

            assert(llabs(index) <= list_obj->size);
            index += list_obj->size;
        }

        // assert that the index is within list bounds
        assert(index < list_obj->size);

        // return the element at the specified index
        return &list_obj->elements[index];
    }

    assert("Only integers are allowed as indexes for list subscripts!" && NULL);
}

static object* list_take_slice(object* obj, object* slice) {

    assert(IS_LIST(obj));
    assert(IS_SLICE(slice));

    list_object* list_obj = AS_LIST(obj);
    slice_object* slice_obj = AS_SLICE(slice);

    // determine the size of the new list to create
    object* length_obj = slice_type.mapping_functions->length(AS_OBJECT(slice_obj));

    long long start = slice_obj->start;
    long long len;

    if (IS_INT(length_obj)) {

        len = AS_INT(length_obj)->value;

    } else if (IS_NONE(length_obj)) {
        // the length cannot be determined without knowledge of the list (probably a negative index)

        if (start < 0) {
            // negative indexes wrap around
            assert(llabs(start) <= list_obj->size);
            start += list_obj->size;
        }

        assert(IS_INT(slice_obj->end) || IS_NONE(slice_obj->end));

        long long end = 0;

        if (IS_INT(slice_obj->end)) {
            end = AS_INT(slice_obj->end)->value;
        } else if (IS_NONE(slice_obj->end)) {
            end = list_obj->size;
        }

        if (end < 0) {
            // negative indexes wrap around
            assert(llabs(end) <= list_obj->size);
            end += list_obj->size;
        }

        len = end - start;
    }

    list_object* new_list = AS_LIST(list_create(len));

    for (int i = 0; i < len; ++i) {

        const size_t k = slice_obj->start + (slice_obj->step * i);

        object* v = *list_subscript(obj, TO_INT(k));

        GRAB_OBJECT(v); // the new list has a reference to the element

        new_list->elements[i] = v;
    }

    return AS_OBJECT(new_list);
}

static object* list_length(object* obj) {

    assert(IS_LIST(obj));

    return TO_INT(AS_LIST(obj)->size);
}

object* list_create(size_t size) {

    list_object* list_obj = malloc(sizeof(list_object));

    // initialize object header
    AS_OBJECT(list_obj)->identity = AS_OBJECT(list_obj);
    AS_OBJECT(list_obj)->type = &list_type;
    AS_OBJECT(list_obj)->refs = 0;

    list_obj->size = size;
    list_obj->capacity = size;

    // allocate space for entries
    list_obj->elements = malloc(list_obj->capacity * sizeof(object*));

    return AS_OBJECT(list_obj);
}

static object* list_to_bool(object* obj) {

    assert(IS_LIST(obj));

    if (AS_LIST(obj)->size > 0) {
        return TYTHON_TRUE;
    }

    return TYTHON_FALSE;
}

/**
 * This is a special case: we are defining a c-function as if it is a member of the list "class".
 * The fact that there is no tython code declaring such a list class is what makes this so strange.
 * Regardless, we want to provide the user with a consistent interface, so we will go to a great length to achieve this.
 * Todo: find a place for this comment
 * @param self The list object to append to
 * @return Returns None
 */
static object* list_append(object* self, object* item) {

    assert(IS_LIST(self));

    list_object* list_obj = AS_LIST(self);

    // check if we have enoiugh allocated space for this new item
    if (list_obj->size < list_obj->capacity) {

        // we have enough space; simply place the new item and increment the size counter
        GRAB_OBJECT(item);
        list_obj->elements[list_obj->size++] = item;

    } else {

        // we need to extend the capacity of the list

        // find a new capacity (doubling is a popular approach)
        const size_t new_capacity = (list_obj->capacity == 0) ? 2 : (list_obj->capacity * 2);
        object** new_elements = realloc(list_obj->elements, new_capacity * sizeof(object*));

        if (!new_elements) {
            new_elements = malloc(new_capacity * sizeof(object*));
            memcpy(new_elements, list_obj->elements, list_obj->capacity * sizeof(object*));
            free(list_obj->elements);
        }

        assert(new_elements && "Heap allocation failure!");

        list_obj->elements = new_elements;
        list_obj->capacity = new_capacity;

        return list_append(self, item);
    }

    return AS_OBJECT(TYTHON_NONE);
}

static object* list_create_iterator(object* obj) {

    assert(IS_LIST(obj));

    list_object* list_obj = AS_LIST(obj);

    list_iterator_object* it = AS_LIST_ITERATOR(list_iterator_type.alloc(&list_iterator_type));

    it->idx = TO_INT(0);
    it->list_obj = list_obj;

    GRAB_OBJECT(it->idx);
    GRAB_OBJECT(AS_OBJECT(it->list_obj));

    return AS_OBJECT(it);
}

static void list_release(object* obj) {

//    printf("--- releasing list...\r\n");

    assert(IS_LIST(obj));

    list_object* list_obj = AS_LIST(obj);

    // only release elements if we are about to be freed!
    if (obj->refs != 1) {
        return default_release(obj);
    }

    // release all the elements this list references
    for (size_t i = 0; i < list_obj->size; ++i) {

//        printf("- releasing element %lu..\r\n", i);

        object* e = list_obj->elements[i];

        e->type->release(e);
    }

//    printf("--- released all list elements.\r\n");

    // delegate the list object to default release
    default_release(obj);
}

static number_functions list_number_functions = {
        .to_bool = &list_to_bool
};

static mapping_functions list_mapping_functions = {
        .length     = &list_length,
        .subscript  = &list_subscript,
};

static sequence_functions list_sequence_functions = {
        .length     = &list_length,
        .take_slice = &list_take_slice,
};

static builtin_method list_methods[] = {
        { "append", &list_append },
        { NULL, NULL }              // sentinel
};

type_object list_type = {

        .obj_base = {
            .identity       = &list_type.obj_base,
            .type           = &type_type,
            .refs           = 0,
        },

        .alloc              = &default_alloc,
        .seqalloc           = NULL,                 // todo: should be list_create

        .base               = NULL,
        .instance_size      = sizeof(list_object),
        .item_size          = sizeof(object*),

        .rich_compare       = &list_rich_compare,
        .str                = &list_to_string,

        .number_functions   = &list_number_functions,
        .mapping_functions  = &list_mapping_functions,
        .sequence_functions = &list_sequence_functions,

        .create_iterator    = &list_create_iterator,

        .methods            = list_methods,

        .grab               = &default_grab,
        .release            = &list_release,
};

static object* list_iterator_next(object* obj) {

    assert(IS_LIST_ITERATOR(obj));

    list_iterator_object* it = AS_LIST_ITERATOR(obj);

    if (AS_INT(it->idx)->value >= it->list_obj->size) {
        // this iterator has run off the end
        return AS_OBJECT(TYTHON_NONE);
    }

    object* e = *list_subscript(AS_OBJECT(it->list_obj), it->idx);

    // increment index
    AS_INT(it->idx)->value++;

    return e;
}

static object* list_iterator_to_bool(object* obj) {

    assert(IS_LIST_ITERATOR(obj));

    list_iterator_object* it = AS_LIST_ITERATOR(obj);

    if (AS_INT(it->idx)->value >= it->list_obj->size) {
        return TYTHON_FALSE;
    }

    return TYTHON_TRUE;
}

static number_functions list_iterator_number_functions = {
        .to_bool            = &list_iterator_to_bool,
};

type_object list_iterator_type = {
        .obj_base = {
                .identity   = &list_iterator_type.obj_base,
                .type       = &type_type,
                .refs       = 0,
        },

        .alloc              = &default_alloc,
        .seqalloc           = NULL,

        .base               = NULL,
        .instance_size      = sizeof(list_iterator_object),
        .item_size          = 0,                        // not a sequence type

        .rich_compare       = NULL,
        .str                = NULL,
        .hash               = NULL,

        .number_functions   = &list_iterator_number_functions,
        .mapping_functions  = NULL,
        .sequence_functions = NULL,                     // not a sequence type

        .iterator_next      = &list_iterator_next,

        .grab               = &default_grab,
        .release            = &default_release,
};
