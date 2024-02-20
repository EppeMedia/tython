//
// Created by manzi on 26/01/24.
//

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "object/stringobject.h"
#include "object/floatobject.h"
#include "object/integerobject.h"

char* to_cstr(string_object* string_obj) {

    if (string_obj->str[string_obj->length - 1] == '\0') {
        char* cstr = malloc(string_obj->length * sizeof(char));
        strcpy(cstr, string_obj->str);
        return cstr;
    }

    char* cstr = malloc((string_obj->length + 1) * sizeof(char));
    memcpy(cstr, string_obj->str, string_obj->length);
    cstr[string_obj->length] = '\0';
    return cstr;
}

object* string_create(const char* cstr, size_t length) {

    char* content = malloc(sizeof(char) * length);

    for (int i = 0; i < length; ++i) {

        char c = cstr[i];

        if (c == '\0') {
            break;
        }

        content[i] = cstr[i];
    }

    object* obj = string_type.alloc(&string_type);

    AS_STRING(obj)->str = content;
    AS_STRING(obj)->length = length;

    obj->identity = obj;
    obj->type = &string_type;

    return obj;
}

object* string_length(object* str) {

    size_t length = AS_STRING(str)->length;

    return float_create(length);
}

/**
 * Adapted from djb2 by Dan Bernstein
 */
static object* string_hash(object* obj) {

    assert(IS_STRING(obj));

    string_object* string_obj = AS_STRING(obj);

    unsigned long hash = 5381;

    for (int i = 0; i < string_obj->length; ++i) {
        hash = ((hash << 5) + hash) + string_obj->str[i]; /* hash * 33 + c */
    }

    return TO_INT(hash);
}

static object* identity(object* str) {
    return str;
}

static sequence_functions string_sequence_functions = {
    .length = &string_length,
};

type_object string_type = {

        .obj_base = {
                .identity   = &string_type.obj_base,
                .type       = &type_type,
        },

        .alloc              = &default_alloc,
        .seqalloc           = NULL,

        .base               = NULL,
        .instance_size      = sizeof(string_object),
        .item_size          = sizeof(char),             // a sequence of characters

        .rich_compare       = NULL,                     // todo: implement
        .str                = &identity,
        .hash               = &string_hash,

        .number_functions   = NULL,
        .mapping_functions  = NULL,
        .sequence_functions = &string_sequence_functions,
};
