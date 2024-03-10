//
// Created by manzi on 27/02/24.
//

#include <stddef.h>
#include "object/functionobject.h"
#include "object/dictobject.h"

object* function_create(string_object* name, function_arg_object* arguments, size_t argument_count, function_object_function* function_ptr) {

    object* obj = function_type.alloc(&string_type);

    AS_FUNCTION(obj)->name = name;
    AS_FUNCTION(obj)->arguments = arguments;
    AS_FUNCTION(obj)->argument_count = argument_count;
    AS_FUNCTION(obj)->function_ptr = function_ptr;

    obj->identity = obj;
    obj->type = &function_type;

    return obj;
}

type_object function_type = {

        .obj_base = {
                .identity   = &function_type.obj_base,
                .type       = &type_type,
        },

        .alloc              = &default_alloc,
        .seqalloc           = NULL,

        .base               = NULL,
        .instance_size      = sizeof(function_object),
        .item_size          = 0,

        .rich_compare       = NULL,
        .str                = NULL,
        .hash               = NULL,

        .number_functions   = NULL,
        .mapping_functions  = NULL,
        .sequence_functions = NULL,

        .iterator_next      = NULL,
};

type_object function_arg_type = {

        .obj_base = {
                .identity   = &function_arg_type.obj_base,
                .type       = &type_type,
        },

        .alloc              = &default_alloc,
        .seqalloc           = NULL,

        .base               = NULL,
        .instance_size      = sizeof(function_arg_object),
        .item_size          = 0,

        .rich_compare       = NULL,
        .str                = NULL,
        .hash               = NULL,

        .number_functions   = NULL,
        .mapping_functions  = NULL,
        .sequence_functions = NULL,

        .iterator_next      = NULL,
};

