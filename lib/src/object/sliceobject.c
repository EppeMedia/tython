//
// Created by manzi on 26/02/24.
//

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "object/sliceobject.h"
#include "object/integerobject.h"
#include "object/stringobject.h"
#include "object/boolobject.h"
#include "object/noneobject.h"

object* slice_create(object* start, object* end, object* step) {

    assert(IS_INT(start) || IS_NONE(start));
    assert(IS_INT(end) || IS_NONE(end));
    assert(IS_INT(step) || IS_NONE(step));

    int_object* start_obj;

    if (IS_INT(start)) {
        start_obj = AS_INT(start);
    } else {
        start_obj = AS_INT(TO_INT(0));
    }

    int_object* end_obj = AS_INT(end);
    int_object* step_obj = AS_INT(step);

    assert(step_obj->value != 0);

    slice_object* slice_obj = AS_SLICE(slice_type.alloc(&slice_type));

    slice_obj->start = start_obj->value;
    slice_obj->end = end_obj->value;
    slice_obj->step = step_obj->value;

    return AS_OBJECT(slice_obj);
}

static object* slice_to_string(object* object) {

    assert(IS_SLICE(object));

    slice_object* slice_obj = AS_SLICE(object);

    // determine length
    const int fields_len = snprintf(NULL, 0, "%lld", slice_obj->start)
                           + snprintf(NULL, 0, "%lld", slice_obj->end)
                           + snprintf(NULL, 0, "%lld", slice_obj->step);

    // allocate string buffer ("slice" + braces + commas + spaces)
    const int str_len = fields_len + (5 + 2 + 2 + 2);
    char* str = malloc(str_len * sizeof(char));

    // fill string
    sprintf(str, "slice(%lld, %lld, %lld)", slice_obj->start, slice_obj->end, slice_obj->step);

    return string_create(str, str_len);
}

static object* slice_to_bool(object* object) {

    assert(IS_SLICE(object));

    slice_object* slice_obj = AS_SLICE(object);

    return TO_BOOL(slice_obj->start < slice_obj->end);
}

static inline bool slice_eq(slice_object* lhs, slice_object* rhs) {
    return lhs->start == rhs->start
        && lhs->end == rhs->end
        && lhs->step == rhs->step;
}

static object* slice_rich_compare(object* lhs, object* rhs, int op) {

    assert(IS_SLICE(lhs));
    slice_object* lhs_obj = AS_SLICE(lhs);

    assert(IS_SLICE(rhs));
    slice_object* rhs_obj = AS_SLICE(rhs);

    switch (op) {
        case TYTHON_CMP_OP_EQ:

            if (slice_eq(lhs_obj, rhs_obj)) {
                return TYTHON_TRUE;
            }
            return TYTHON_FALSE;

        case TYTHON_CMP_OP_NEQ:

            if (!slice_eq(lhs_obj, rhs_obj)) {
                return TYTHON_TRUE;
            }
            return TYTHON_FALSE;

        default:
            assert("Unsupported rich comparison operator" && NULL);
    }
}

static long long slice_length_c(slice_object* slice_obj) {
    return (slice_obj->end - slice_obj->start) / slice_obj->step;
}

static object* slice_length(object* obj) {

    assert(IS_SLICE(obj));

    slice_object* slice_obj = AS_SLICE(obj);

    return TO_INT(slice_length_c(slice_obj));
}

static number_functions slice_number_functions = {
        .to_bool            = &slice_to_bool,
} ;

static mapping_functions slice_mapping_functions = {
        .length             = &slice_length,
};

type_object slice_type = {
        .obj_base = {
                .identity   = &slice_type.obj_base,
                .type       = &type_type,
        },

        .alloc              = &default_alloc,
        .seqalloc           = NULL,

        .base               = NULL,
        .instance_size      = sizeof(slice_object),
        .item_size          = 0,                        // not a sequence type

        .rich_compare       = &slice_rich_compare,
        .str                = &slice_to_string,
        .hash               = NULL,

        .number_functions   = &slice_number_functions,
        .mapping_functions  = &slice_mapping_functions,
        .sequence_functions = NULL,                     // not a sequence type

        .create_iterator    = NULL,
};
