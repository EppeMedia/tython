//
// Created by manzi on 27/02/24.
//

#include <stddef.h>
#include <assert.h>
#include "object/classobject.h"
#include "object/dictobject.h"

object* class_create(string_object* name, object* base) {

    class_object* class_obj = AS_CLASS(class_type.alloc(&class_type));

    class_obj->name = name;
    class_obj->members = AS_DICT(dict_create(0));

    return AS_OBJECT(class_obj);
}

static object* class_to_string(object* obj) {

    assert(IS_CLASS(obj));

    class_object* class_obj = AS_CLASS(obj);

    return AS_OBJECT(class_obj->name);
}

type_object class_type = {

        .obj_base = {
                .identity   = &class_type.obj_base,
                .type       = &type_type,
        },

        .alloc              = &default_alloc,
        .seqalloc           = NULL,

        .base               = NULL,
        .instance_size      = sizeof(class_object),
        .item_size          = 0,

        .rich_compare       = NULL,
        .str                = &class_to_string,
        .hash               = NULL,

        .number_functions   = NULL,
        .mapping_functions  = NULL,
        .sequence_functions = NULL,
};
