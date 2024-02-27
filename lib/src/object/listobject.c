//
// Created by manzi on 07/02/24.
//

#include <stddef.h>
#include <assert.h>
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
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
    size_t separator_count = ((list_obj->size - 1) * 2); // the last entry is not followed by a comma and a space
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

static object* list_subscript(object* obj, object* idx) {

    assert(IS_LIST(obj));
    assert(IS_INT(idx) || IS_SLICE(idx));

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
        return list_obj->elements[index];

    } else if (IS_SLICE(idx)) {

        slice_object* slice_obj = AS_SLICE(idx);

        // determine the size of the new list to create
        object* length_obj = slice_type.mapping_functions->length(AS_OBJECT(slice_obj));

        long long start = slice_obj->start;
        long long len;

        if (IS_INT(length_obj)) {

            len = AS_INT(length_obj)->value;

            printf("length is int\r\n");

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

            printf("length is none: len = end - start\r\n");
            printf("start\t: %lld\r\n", start);
            printf("end\t: %lld\r\n", end);
        }

        printf("len: %lld\r\n", len);

        list_object* new_list = AS_LIST(list_create(len));

        for (int i = 0; i < len; ++i) {

            const size_t k = slice_obj->start + (slice_obj->step * i);

            new_list->elements[i] = list_subscript(obj, TO_INT(k));
        }

        return AS_OBJECT(new_list);
    }

    assert("Only integers or slices are allowed as indexes for list subscripts!" && NULL);
}

static object* list_length(object* obj) {

    assert(IS_LIST(obj));

    return TO_INT(AS_LIST(obj)->size);
}

object* list_create(size_t size) {

    list_object* list_obj = malloc(sizeof(list_object));

    // initialize object header
    AS_OBJECT(list_obj)->type = &list_type;
    AS_OBJECT(list_obj)->identity = AS_OBJECT(list_obj);

    list_obj->size = size;

    // allocate space for entries
    list_obj->elements = malloc(size * sizeof(object*));

    return AS_OBJECT(list_obj);
}

static object* list_to_bool(object* obj) {

    assert(IS_LIST(obj));

    if (AS_LIST(obj)->size > 0) {
        return TYTHON_TRUE;
    }

    return TYTHON_FALSE;
}

static object* list_create_iterator(object* obj) {

    assert(IS_LIST(obj));

    list_object* list_obj = AS_LIST(obj);

    list_iterator_object* it = AS_LIST_ITERATOR(list_iterator_type.alloc(&list_iterator_type));

    it->idx = TO_INT(0);
    it->list_obj = list_obj;

    return AS_OBJECT(it);
}

static number_functions list_number_functions = {
        .to_bool = &list_to_bool
};

static mapping_functions list_mapping_functions = {
        .length     = &list_length,
        .subscript  = &list_subscript,
};

type_object list_type = {

        .obj_base = {
            .identity       = &list_type.obj_base,
            .type           = &type_type,
        },

        .alloc              = &default_alloc,
        .seqalloc           = NULL,         // todo: should be list_create

        .base               = NULL,
        .instance_size      = sizeof(list_object),
        .item_size          = sizeof(object*),

        .rich_compare       = &list_rich_compare,
        .str                = &list_to_string,

        .number_functions   = &list_number_functions,
        .mapping_functions  = &list_mapping_functions,
        .sequence_functions = NULL,

        .create_iterator    = &list_create_iterator,
};

static object* list_iterator_next(object* obj) {

    assert(IS_LIST_ITERATOR(obj));

    list_iterator_object* it = AS_LIST_ITERATOR(obj);

    if (AS_INT(it->idx)->value >= it->list_obj->size) {
        // this iterator has run off the end
        return NULL; // todo: None?
    }

    object* e = list_subscript(AS_OBJECT(it->list_obj), it->idx);

    // increment index
    it->idx = TO_INT(AS_INT(it->idx)->value + 1);

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
};
