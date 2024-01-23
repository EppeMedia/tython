//
// Created by manzi on 20/01/24.
//

#include "../include/type.h"
#include <stdlib.h>

/**
 * The type "type" cannot be instantiated, hence all its instance details are unimportant (set to null).
 */
type type_type = {
        .obj_base           = {
            .identity       = &type_type.obj_base,
            .type           = &type_type
        },

        .base               = NULL,
        .instance_size      = 0,
        .item_size          = 0,

        .number_functions   = 0,
        .mapping_functions  = 0,
};

object* alloc(type* typeobj) {
    return (object*) alloc_collection(typeobj, 0);
}

collection_object* alloc_collection(type* typeobj, size_t number) {

    collection_object* obj;

    size_t size = typeobj->instance_size + (number * sizeof(object*));

    obj = (collection_object*)malloc(size);

    AS_OBJECT(obj)->identity = AS_OBJECT(obj);
    AS_OBJECT(obj)->type = typeobj;

    return obj;
}
