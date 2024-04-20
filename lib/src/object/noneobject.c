//
// Created by manzi on 21/02/24.
//

#include <stddef.h>
#include <assert.h>
#include <stdio.h>
#include "object/noneobject.h"
#include "object/boolobject.h"
#include "object/stringobject.h"

/**
 * The globally unique None object instance
 */
none_object none_instance = {
        .obj_base = {
                .identity       = &none_instance.obj_base,
                .type           = &none_type,
                .refs       = 0,
        },
};

static void grab_none_noop(object* instance) {

    assert(IS_NONE(instance));

    (void)0;
}

static void release_none_noop(object* instance) {

    assert(IS_NONE(instance));

    (void)0;
}

static object* none_rich_compare(object* lhs, object* rhs, int op) {

    assert(IS_NONE(lhs));

    switch (op) {

        case TYTHON_CMP_OP_EQ:
            return TO_BOOL(lhs == rhs);
        case TYTHON_CMP_OP_NEQ:
            return TO_BOOL(lhs != rhs);

        default:
            assert("Type error: rich comparison type not supported on None value!" && NULL);
    }
}

static object* none_to_string(object* obj) {

    assert(IS_NONE(obj));

    return TO_STRING("None", 4);
}

static object* none_to_bool(object* obj) {

    assert(IS_NONE(obj));

    return TYTHON_FALSE;
}

static number_functions none_number_functions = {
        .to_bool            = &none_to_bool,
};

type_object none_type = {

        .obj_base = {
                .identity       = &none_type.obj_base,
                .type           = &type_type,
                .refs           = 0,
        },

        .alloc              = NULL,     // The None object is globally unique
        .seqalloc           = NULL,

        .base               = NULL,
        .instance_size      = sizeof(none_object),
        .item_size          = 0,

        .rich_compare       = &none_rich_compare,
        .str                = &none_to_string,

        .number_functions   = &none_number_functions,
        .mapping_functions  = NULL,
        .sequence_functions = NULL,

        .create_iterator    = NULL,

        .grab               = &grab_none_noop,       // The None object is globally unique; grab has no effect
        .release            = &release_none_noop,    // The None object is globally unique; release has no effect
};
