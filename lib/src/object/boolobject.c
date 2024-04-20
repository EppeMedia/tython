//
// Created by manzi on 01/02/24.
//

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "object/boolobject.h"
#include "object/stringobject.h"
#include "object/floatobject.h"
#include "object/integerobject.h"

object* bool_create(bool v) {
    return v ? TYTHON_TRUE : TYTHON_FALSE;
}

static object* bool_to_string(object* object) {

    assert(IS_BOOL(object));

    const bool value = AS_BOOL(object)->value;

    // determine length
    const size_t str_len = value ? 5 : 6;

    // allocate string buffer
    char* str = malloc(sizeof(char) * str_len);

    // fill string
    sprintf(str, "%s", value ? "true" : "false");

    return TO_STRING(str, str_len);
}

static object* bool_rich_compare(object* lhs, object* rhs, int op) {

    assert(IS_BOOL(lhs));
    const bool lhs_value = AS_BOOL(lhs)->value;

    assert(IS_BOOL(rhs));
    const bool rhs_value = AS_BOOL(rhs)->value;

    NUMBER_RICH_COMPARE(lhs_value, rhs_value, op)
}

static object* identity(object* obj) {
    return obj;
}

static object* bool_to_int(object* obj) {

    assert(IS_BOOL(obj));

    bool v = AS_BOOL(obj)->value;

    return TO_INT((int)v);
}

static object* bool_to_float(object* obj) {

    assert(IS_BOOL(obj));

    bool v = AS_BOOL(obj)->value;

    return TO_FLOAT((double)v);
}

static number_functions int_number_functions = {
        .to_bool            = &identity,
        .to_int             = &bool_to_int,
        .to_float           = &bool_to_float,
} ;

type_object bool_type = {
        .obj_base = {
                .identity   = &int_type.obj_base,
                .type       = &type_type,
                .refs       = 0,
        },

        .alloc              = &default_alloc,
        .seqalloc           = NULL,

        .base               = NULL,
        .instance_size      = sizeof(int_object),
        .item_size          = 0,                        // not a sequence type

        .rich_compare       = &bool_rich_compare,
        .str                = &bool_to_string,
        .hash               = &bool_to_int,

        .number_functions   = &int_number_functions,
        .mapping_functions  = NULL,
        .sequence_functions = NULL,                     // not a sequence type

        .grab               = &default_grab,
        .release            = &default_release,
};

bool_object bool_true = {
        .obj_base = {
                .identity   = &bool_true.obj_base,
                .type       = &bool_type,
        },

        .value              = true,
};

bool_object bool_false = {
        .obj_base = {
                .identity   = &bool_false.obj_base,
                .type       = &bool_type,
        },

        .value              = false,
};
