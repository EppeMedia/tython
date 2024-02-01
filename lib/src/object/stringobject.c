//
// Created by manzi on 26/01/24.
//

#include <stdlib.h>
#include <stdio.h>
#include "object/stringobject.h"
#include "object/floatobject.h"

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

static object* identity(object* str) {
    return str;
}

sequence_functions string_sequence_functions = {
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

        .number_functions   = NULL,
        .mapping_functions  = NULL,
        .sequence_functions = &string_sequence_functions,
};
