//
// Created by manzi on 20/01/24.
//

#include <stddef.h>
#include "object/dictionaryobject.h"

static object* dict_length(object* dict) {
    return NULL; // todo: implement
}

static object* dict_subscript(object* dict, object* name) {
    return NULL; // todo: implement
}

static mapping_functions dict_mapping_functions = {
        .length     = &dict_length,
        .subscript  = &dict_subscript,
};

type_object dictionary_type = {
    .obj_base           = {
            .identity   = &dictionary_type.obj_base,
            .type       = &type_type,
    },

    .base               = NULL,                     // parent type
    .instance_size      = sizeof(dictionary_object),
    .item_size          = 0,                        // not a sequence type

    .alloc              = &default_alloc,
    .seqalloc           = NULL,

    .rich_compare       = NULL,
    .str                = NULL,                     // todo: implement

    .number_functions   = NULL,
    .mapping_functions  = &dict_mapping_functions,
    .sequence_functions = NULL,                     // todo: implement
};
