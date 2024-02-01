//
// Created by manzi on 30/01/24.
//

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "object/integerobject.h"
#include "object/stringobject.h"
#include "object/floatobject.h"

object* int_create(long v) {

    object* a = int_type.alloc(&int_type);

    AS_INT(a)->value = v;

    return a;
}

static object* int_to_string(object* object) {

    // determine length
    const int str_len = snprintf(NULL, 0, "%ld", AS_INT(object)->value);

    // allocate string buffer
    char* str = malloc(sizeof(char) * str_len);

    // fill string
    sprintf(str, "%ld", AS_INT(object)->value);

    return string_create(str, str_len);
}

static object* int_cmp_eq(object* lhs, object* rhs) {
    return TO_INT(AS_INT(lhs)->value == AS_INT(rhs)->value);
}

static object* int_to_bool(object* number) {
    return TO_INT(AS_INT(number)->value != 0);
}

static object* int_rich_compare(object* lhs, object* rhs, int op) {

    // todo: check types are the same, or apply the necessary conversions
    assert(IS_INT(lhs) && IS_INT(rhs));

    switch (op) {

        case TYTHON_CMP_OP_EQ:
            return lhs->type->number_functions->cmp_eq(lhs, rhs);

        default:
            return TO_INT(TYTHON_CMP_RES_ERR);
    }
}

static object* identity(object* obj) {
    return obj;
}

static object* int_to_float(object* int_obj) {

    assert(IS_INT(int_obj));

    long v = AS_INT(int_obj)->value;

    return TO_FLOAT((double)v);
}

static number_functions int_number_functions = {
        .to_bool            = &int_to_bool,
        .to_int             = &identity,
        .to_float           = &int_to_float,
        .cmp_eq             = &int_cmp_eq
} ;

type_object int_type = {
        .obj_base = {
                .identity   = &int_type.obj_base,
                .type       = &type_type,
        },

        .alloc              = &default_alloc,
        .seqalloc           = NULL,

        .base               = NULL,
        .instance_size      = sizeof(int_object),
        .item_size          = 0,                        // not a sequence type

        .rich_compare       = int_rich_compare,
        .str                = &int_to_string,

        .number_functions   = &int_number_functions,
        .mapping_functions  = NULL,
        .sequence_functions = NULL,                     // not a sequence type
};

