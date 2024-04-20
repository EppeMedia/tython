//
// Created by manzi on 23/01/24.
//

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "object/floatobject.h"
#include "object/stringobject.h"
#include "object/integerobject.h"
#include "object/boolobject.h"

object* float_create(double v) {

    object* a = float_type.alloc(&float_type);

    AS_FLOAT(a)->value = v;

    return a;
}

static object* float_to_string(object* object) {

    assert(IS_FLOAT(object));

    // determine length
    const int str_len = snprintf(NULL, 0, FLOATOBJECT_REPRESENTATION_FORMAT, FLOATOBJECT_REPRESENTATION_PRECISION, AS_FLOAT(object)->value);

    // allocate string buffer
    char* str = malloc(sizeof(char) * str_len);

    // fill string
    sprintf(str, FLOATOBJECT_REPRESENTATION_FORMAT, FLOATOBJECT_REPRESENTATION_PRECISION, AS_FLOAT(object)->value);

    return string_create(str, str_len);
}

static object* float_to_bool(object* number) {

    assert(IS_FLOAT(number));

    return TO_BOOL(AS_FLOAT(number)->value != 0.0);
}

static object* float_rich_compare(object* lhs, object* rhs, int op) {

    assert(IS_FLOAT(lhs));
    double lhs_value = AS_FLOAT(lhs)->value;

    assert(IS_FLOAT(rhs) || IS_INT(rhs));
    double rhs_value;

    if (IS_FLOAT(rhs)) {
        rhs_value = AS_FLOAT(rhs)->value;
    } else if (IS_INT(rhs)) {
        rhs_value = (double)AS_INT(rhs)->value;
    }

    NUMBER_RICH_COMPARE(lhs_value, rhs_value, op)
}

static object* float_to_int(object* float_obj) {

    assert(IS_FLOAT(float_obj));

    double v = AS_FLOAT(float_obj)->value;

    return TO_INT((long long)v);
}

static object* identity(object* obj) {
    return obj;
}

static float_object* convert_to_float(object* obj) {

    if (IS_FLOAT(obj)) {
        return AS_FLOAT(obj);
    }

    number_functions* nfs = obj->type->number_functions;

    // todo: type error
    assert(nfs && nfs->to_float);

    return AS_FLOAT(nfs->to_float(obj));
}

static object* float_add(object* lhs, object* rhs) {

    assert(IS_FLOAT(lhs));

    float_object* lhs_obj = AS_FLOAT(lhs);
    float_object* rhs_obj = convert_to_float(rhs);

    return TO_FLOAT(lhs_obj->value + rhs_obj->value);
}

static object* float_sub(object* lhs, object* rhs) {

    assert(IS_FLOAT(lhs));

    float_object* lhs_obj = AS_FLOAT(lhs);
    float_object* rhs_obj = convert_to_float(rhs);

    return TO_FLOAT(lhs_obj->value - rhs_obj->value);
}

static object* float_mult(object* lhs, object* rhs) {

    assert(IS_FLOAT(lhs));

    float_object* lhs_obj = AS_FLOAT(lhs);
    float_object* rhs_obj = convert_to_float(rhs);

    return TO_FLOAT(lhs_obj->value * rhs_obj->value);
}

static object* float_div(object* lhs, object* rhs) {

    assert(IS_FLOAT(lhs));

    float_object* lhs_obj = AS_FLOAT(lhs);
    float_object* rhs_obj = convert_to_float(rhs);

    return TO_FLOAT(lhs_obj->value / rhs_obj->value);
}

static object* float_exp(object* lhs, object* rhs) {

    assert(IS_FLOAT(lhs));

    float_object* lhs_obj = AS_FLOAT(lhs);
    float_object* rhs_obj = convert_to_float(rhs);

    return TO_FLOAT(powl(lhs_obj->value, rhs_obj->value));
}

static number_functions float_number_functions = {
    .to_bool            = &float_to_bool,
    .to_int             = &float_to_int,
    .to_float           = &identity,

    .add                = &float_add,
    .sub                = &float_sub,
    .mult               = &float_mult,
    .div                = &float_div,
    .exp                = &float_exp,
} ;

type_object float_type = {
    .obj_base = {
            .identity   = &float_type.obj_base,
            .type       = &type_type,
            .refs       = 0,
    },

    .alloc              = &pool_alloc,
    .seqalloc           = NULL,

    .base               = NULL,
    .instance_size      = sizeof(float_object),
    .item_size          = 0,                        // not a sequence type

    .rich_compare       = float_rich_compare,
    .str                = &float_to_string,
    .hash               = &float_to_int,

    .number_functions   = &float_number_functions,
    .mapping_functions  = NULL,
    .sequence_functions = NULL,                     // not a sequence type

    .grab               = &default_grab,
    .release            = &default_release,
};
