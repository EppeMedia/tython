//
// Created by manzi on 24/02/24.
//

#include <stddef.h>
#include <assert.h>
#include <memory.h>
#include <stdlib.h>
#include "object/tupleobject.h"
#include "object/boolobject.h"
#include "object/stringobject.h"
#include "object/integerobject.h"


static object* tuple_rich_compare(object* lhs,  object* rhs, int op) {
    return TYTHON_FALSE; // todo: implement
}

static object* tuple_to_string(object* obj) {

    assert(IS_TUPLE(obj));

    tuple_object* tuple_obj = AS_TUPLE(obj);

    // collect string representations of all entries:
    object** element_strings = malloc(tuple_obj->size * sizeof(object*));
    size_t element_strings_total_length = 0;

    for (int i = 0; i < tuple_obj->size; ++i) {
        string_object* str = GET_STRING(tuple_obj->elements[i]);

        element_strings[i] = AS_OBJECT(str);
        element_strings_total_length += str->length;
    }

    // allocate memory for the final string, which includes two parentheses for the tuple and a comma and space between each element
    size_t separator_count = ((tuple_obj->size - 1) * 2); // the last entry is not followed by a comma and a space
    size_t str_len = (element_strings_total_length * sizeof(char)) + 2 + (separator_count * sizeof(char));
    char* string = malloc(str_len);
    string[0] = '(';
    string[str_len - 1] = ')';

    char* offset = string + 1;
    for (int i = 0; i < tuple_obj->size; ++i) {

        // copy the string representation of each entry
        string_object* element_str = AS_STRING(element_strings[i]);
        memcpy(offset, element_str->str, element_str->length);
        offset += element_str->length;

        if (i != tuple_obj->size - 1) {
            *offset++ = ',';
            *offset++ = ' ';
        }
    }

    return TO_STRING(string, str_len);
}

static object* tuple_subscript(object* obj, object* idx) {

    assert(IS_TUPLE(obj));
    assert(IS_INT(idx));

    tuple_object* tuple_obj = AS_TUPLE(obj);
    int_object* idx_obj = AS_INT(idx);

    long long index = idx_obj->value;

    if (index < 0) {

        // negative indexes wrap around

        assert(llabs(index) <= tuple_obj->size);
        index += tuple_obj->size;
    }

    // assert that the index is within tuple bounds
    assert(index < tuple_obj->size);

    return tuple_obj->elements[index];
}

static object* tuple_length(object* obj) {

    assert(IS_TUPLE(obj));

    return TO_INT(AS_TUPLE(obj)->size);
}

object* tuple_create(size_t size) {

    tuple_object* tuple_obj = malloc(sizeof(tuple_object));

    // initialize object header
    AS_OBJECT(tuple_obj)->type = &tuple_type;
    AS_OBJECT(tuple_obj)->identity = AS_OBJECT(tuple_obj);

    tuple_obj->size = size;

    // allocate space for entries
    tuple_obj->elements = malloc(size * sizeof(object*));

    return AS_OBJECT(tuple_obj);
}

static object* tuple_to_bool(object* obj) {

    assert(IS_TUPLE(obj));

    if (AS_TUPLE(obj)->size > 0) {
        return TYTHON_TRUE;
    }

    return TYTHON_FALSE;
}

static object* tuple_create_iterator(object* obj) {

    assert(IS_TUPLE(obj));

    tuple_object* tuple_obj = AS_TUPLE(obj);

    tuple_iterator_object* it = AS_TUPLE_ITERATOR(tuple_iterator_type.alloc(&tuple_iterator_type));

    it->idx = TO_INT(0);
    it->tuple_obj = tuple_obj;

    return AS_OBJECT(it);
}

static number_functions tuple_number_functions = {
        .to_bool = &tuple_to_bool
};

static mapping_functions tuple_mapping_functions = {
        .length     = &tuple_length,
        .subscript  = &tuple_subscript,
};

type_object tuple_type = {

        .obj_base = {
                .identity       = &tuple_type.obj_base,
                .type           = &type_type,
        },

        .alloc              = &default_alloc,
        .seqalloc           = NULL,         // todo: should be tuple_create

        .base               = NULL,
        .instance_size      = sizeof(tuple_object),
        .item_size          = sizeof(object*),

        .rich_compare       = &tuple_rich_compare,
        .str                = &tuple_to_string,

        .number_functions   = &tuple_number_functions,
        .mapping_functions  = &tuple_mapping_functions,
        .sequence_functions = NULL,

        .create_iterator    = &tuple_create_iterator,
};

static object* tuple_iterator_next(object* obj) {

    assert(IS_TUPLE_ITERATOR(obj));

    tuple_iterator_object* it = AS_TUPLE_ITERATOR(obj);

    if (AS_INT(it->idx)->value >= it->tuple_obj->size) {
        // this iterator has run off the end
        return NULL; // todo: None?
    }

    object* e = tuple_subscript(AS_OBJECT(it->tuple_obj), it->idx);

    // increment index
    it->idx = TO_INT(AS_INT(it->idx)->value + 1);

    return e;
}

static object* tuple_iterator_to_bool(object* obj) {

    assert(IS_TUPLE_ITERATOR(obj));

    tuple_iterator_object* it = AS_TUPLE_ITERATOR(obj);

    if (AS_INT(it->idx)->value >= it->tuple_obj->size) {
        return TYTHON_FALSE;
    }

    return TYTHON_TRUE;
}

static number_functions tuple_iterator_number_functions = {
        .to_bool            = &tuple_iterator_to_bool,
};

type_object tuple_iterator_type = {
        .obj_base = {
                .identity   = &tuple_iterator_type.obj_base,
                .type       = &type_type,
        },

        .alloc              = &default_alloc,
        .seqalloc           = NULL,

        .base               = NULL,
        .instance_size      = sizeof(tuple_iterator_object),
        .item_size          = 0,                        // not a sequence type

        .rich_compare       = NULL,
        .str                = NULL,
        .hash               = NULL,

        .number_functions   = &tuple_iterator_number_functions,
        .mapping_functions  = NULL,
        .sequence_functions = NULL,                     // not a sequence type

        .iterator_next      = &tuple_iterator_next,
};
