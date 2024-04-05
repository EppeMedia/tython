//
// Created by manzi on 30/01/24.
//

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "object/integerobject.h"
#include "object/stringobject.h"
#include "object/floatobject.h"
#include "object/boolobject.h"

object* int_create(long long v) {

    object* a = int_type.alloc(&int_type);

    AS_INT(a)->value = v;

    return a;
}

static object* int_to_string(object* object) {

    // determine length
    const int str_len = snprintf(NULL, 0, "%lld", AS_INT(object)->value);

    // allocate string buffer
    char* str = malloc(sizeof(char) * str_len);

    // fill string
    sprintf(str, "%lld", AS_INT(object)->value);

    return string_create(str, str_len);
}

static object* int_to_bool(object* number) {
    return TO_BOOL(AS_INT(number)->value != 0);
}

static object* int_rich_compare(object* lhs, object* rhs, int op) {

    assert(IS_INT(lhs));
    long long lhs_value = AS_INT(lhs)->value;

    assert(IS_FLOAT(rhs) || IS_INT(rhs));
    long long rhs_value;

    if (IS_FLOAT(rhs)) {
        rhs_value = (long long)AS_FLOAT(rhs)->value;
    } else if (IS_INT(rhs)) {
        rhs_value = AS_INT(rhs)->value;
    }

    NUMBER_RICH_COMPARE(lhs_value, rhs_value, op)
}

static object* identity(object* obj) {
    return obj;
}

static object* int_to_float(object* int_obj) {

    assert(IS_INT(int_obj));

    long long v = AS_INT(int_obj)->value;

    return TO_FLOAT((double)v);
}

static int_object* convert_to_int(object* obj) {

    if (IS_INT(obj)) {
        return AS_INT(obj);
    }

    number_functions* nfs = obj->type->number_functions;

    // todo: type error
    assert(nfs && nfs->to_int);

    return AS_INT(nfs->to_int(obj));
}

static object* int_add(object* lhs, object* rhs) {

    assert(IS_INT(lhs));

    int_object* lhs_obj = AS_INT(lhs);

    // left-hand side is leading in type, so we will try to convert the rhs value into an integer
    int_object* rhs_obj = convert_to_int(rhs);

    return TO_INT(lhs_obj->value + rhs_obj->value);
}

static object* int_sub(object* lhs, object* rhs) {

    assert(IS_INT(lhs) && IS_INT(rhs));

    int_object* lhs_obj = AS_INT(lhs);

    // left-hand side is leading in type, so we will try to convert the rhs value into an integer
    int_object* rhs_obj = convert_to_int(rhs);

    return TO_INT(lhs_obj->value - rhs_obj->value);
}

static object* int_mul(object* lhs, object* rhs) {

    assert(IS_INT(lhs) && IS_INT(rhs));

    int_object* lhs_obj = AS_INT(lhs);

    // left-hand side is leading in type, so we will try to convert the rhs value into an integer
    int_object* rhs_obj = convert_to_int(rhs);

    return TO_INT(lhs_obj->value * rhs_obj->value);
}

static object* int_div(object* lhs, object* rhs) {

    assert(IS_INT(lhs) && IS_INT(rhs));

    int_object* lhs_obj = AS_INT(lhs);

    // left-hand side is leading in type, so we will try to convert the rhs value into an integer
    int_object* rhs_obj = convert_to_int(rhs);

    return TO_INT(lhs_obj->value / rhs_obj->value);
}

static object* int_exp(object* lhs, object* rhs) {

    assert(IS_INT(lhs) && IS_INT(rhs));

    int_object* lhs_obj = AS_INT(lhs);

    // left-hand side is leading in type, so we will try to convert the rhs value into an integer
    int_object* rhs_obj = convert_to_int(rhs);

    return TO_INT(powl((long double)lhs_obj->value, (long double)rhs_obj->value));
}

static number_functions int_number_functions = {
        .to_bool            = &int_to_bool,
        .to_int             = &identity,
        .to_float           = &int_to_float,

        .add                = &int_add,
        .sub                = &int_sub,
        .mult               = &int_mul,
        .div                = &int_div,
        .exp                = &int_exp,
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

        .rich_compare       = &int_rich_compare,
        .str                = &int_to_string,
        .hash               = &identity,

        .number_functions   = &int_number_functions,
        .mapping_functions  = NULL,
        .sequence_functions = NULL,                     // not a sequence type
};
