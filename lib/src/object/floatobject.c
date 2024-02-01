//
// Created by manzi on 23/01/24.
//

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "object/floatobject.h"
#include "object/stringobject.h"
#include "object/integerobject.h"

object* float_create(double v) {

    object* a = float_type.alloc(&float_type);

    AS_FLOAT(a)->value = v;

    return a;
}

static object* float_to_string(object* object) {

    assert(IS_FLOAT(object));

    // determine length
    const int str_len = snprintf(NULL, 0, "%f", AS_FLOAT(object)->value);

    // allocate string buffer
    char* str = malloc(sizeof(char) * str_len);

    // fill string
    sprintf(str, "%f", AS_FLOAT(object)->value);

    return string_create(str, str_len);
}

static object* float_cmp_eq(object* lhs, object* rhs) {

    // todo: check types and convert if necessary
    assert(IS_FLOAT(lhs) && IS_FLOAT(rhs));

    return TO_FLOAT(AS_FLOAT(lhs)->value == AS_FLOAT(rhs)->value);
}

static object* float_to_bool(object* number) {

    assert(IS_FLOAT(number));

    return TO_INT(AS_FLOAT(number)->value != 0.0);
}

static object* float_rich_compare(object* lhs, object* rhs, int op) {

    // todo: check types are the same, or apply the necessary conversions
    assert(IS_FLOAT(lhs) && IS_FLOAT(rhs));

    switch (op) {

        case TYTHON_CMP_OP_EQ:
            return lhs->type->number_functions->cmp_eq(lhs, rhs);

        default:
            return TO_FLOAT(TYTHON_CMP_RES_ERR);
    }
}

static object* float_to_int(object* float_obj) {

    assert(IS_FLOAT(float_obj));

    double v = AS_FLOAT(float_obj)->value;

    return TO_INT((long)v);
}

static object* identity(object* obj) {
    return obj;
}

static number_functions float_number_functions = {
    .to_bool            = &float_to_bool,
    .to_int             = &float_to_int,
    .to_float           = &identity,
    .cmp_eq             = &float_cmp_eq
} ;

type_object float_type = {
    .obj_base = {
            .identity   = &float_type.obj_base,
            .type       = &type_type,
    },

    .alloc              = &default_alloc,
    .seqalloc           = NULL,

    .base               = NULL,
    .instance_size      = sizeof(float_object),
    .item_size          = 0,                        // not a sequence type

    .rich_compare       = float_rich_compare,
    .str                = &float_to_string,

    .number_functions   = &float_number_functions,
    .mapping_functions  = NULL,
    .sequence_functions = NULL,                     // not a sequence type
};
