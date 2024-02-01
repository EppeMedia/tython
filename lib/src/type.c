//
// Created by manzi on 20/01/24.
//

#include "type.h"
#include <stdlib.h>

/**
 * The type "type" cannot be instantiated, hence all its instance details are unimportant (set to null).
 */
type_object type_type = {
        .obj_base           = {
            .identity       = &type_type.obj_base,
            .type           = &type_type
        },

        .alloc              = NULL,
        .seqalloc           = NULL,

        .base               = NULL,
        .instance_size      = 0,
        .item_size          = 0,

        .rich_compare       = NULL,

        .number_functions   = NULL,
        .mapping_functions  = NULL,
        .sequence_functions = NULL,
};

object* default_alloc(type_object* typeobj) {
    return (object*) default_seqalloc(typeobj, 0);
}

object* default_seqalloc(type_object* typeobj, size_t n) {

    size_t size = typeobj->instance_size + (n * typeobj->item_size);

    object* obj = calloc(1, size);

    obj->identity = obj;
    obj->type = typeobj;

    return obj;
}
