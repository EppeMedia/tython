//
// Created by manzi on 20/01/24.
//

#include <stddef.h>
#include "builtin/dictionary.h"

static object* dict_length(object* dict) {
    return NULL; // todo: implement
}

static mapping_functions dict_mapping_functions = {
        .length = &dict_length,
};

type dictionary_type = {
    .obj_base           = {
            .identity   = &dictionary_type.obj_base,
            .type       = &type_type,
    },
    .base               = NULL,                     // parent type
    .instance_size      = sizeof(dictionary),
    .item_size          = 0,                        // not a collection type
    .number_functions   = NULL,
    .mapping_functions  = &dict_mapping_functions,
};
