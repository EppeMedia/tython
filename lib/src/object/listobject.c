//
// Created by manzi on 07/02/24.
//

#include <stddef.h>
#include <assert.h>
#include <malloc.h>
#include <memory.h>
#include <stdlib.h>
#include "object/listobject.h"
#include "object/boolobject.h"
#include "object/stringobject.h"
#include "object/integerobject.h"

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
    assert(IS_INT(idx));

    list_object* list_obj = AS_LIST(obj);
    int_object* idx_obj = AS_INT(idx);

    long long index = idx_obj->value;

    if (index < 0) {

        // negative indexes wrap around

        assert(llabs(index) <= list_obj->size);
        index += list_obj->size;
    }

    // assert that the index is within list bounds
    assert(index < list_obj->size);

    return list_obj->elements[index];
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

static number_functions dict_number_functions = {
        .to_bool = &list_to_bool
};

static mapping_functions dict_mapping_functions = {
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

        .number_functions   = &dict_number_functions,
        .mapping_functions  = &dict_mapping_functions,
        .sequence_functions = NULL,
};
