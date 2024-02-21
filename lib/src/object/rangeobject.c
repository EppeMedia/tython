//
// Created by manzi on 30/01/24.
//

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "object/rangeobject.h"
#include "object/integerobject.h"
#include "object/stringobject.h"
#include "object/boolobject.h"

object* range_create(object* start, object* end, object* step) {

    assert(IS_INT(start));
    assert(IS_INT(end));
    assert(IS_INT(step));

    int_object* start_obj = AS_INT(start);
    int_object* end_obj = AS_INT(end);
    int_object* step_obj = AS_INT(step);

    assert(step_obj->value != 0);

    range_object* range_obj = AS_RANGE(range_type.alloc(&range_type));

    range_obj->start = start_obj->value;
    range_obj->end = end_obj->value;
    range_obj->step = step_obj->value;

    return AS_OBJECT(range_obj);
}

static object* range_to_string(object* object) {

    assert(IS_RANGE(object));

    range_object* range_obj = AS_RANGE(object);

    // determine length
    const int fields_len = snprintf(NULL, 0, "%lld", range_obj->start)
                           + snprintf(NULL, 0, "%lld", range_obj->end)
                           + snprintf(NULL, 0, "%lld", range_obj->step);

    // allocate string buffer ("range" + braces + commas + spaces)
    char* str = malloc((fields_len * sizeof(char)) + ((5 + 2 + 2 + 2) * sizeof(char)));

    // fill string
    sprintf(str, "range(%lld, %lld, %lld)", range_obj->start, range_obj->end, range_obj->step);

    return string_create(str, fields_len);
}

static object* range_to_bool(object* object) {

    assert(IS_RANGE(object));

    range_object* range_obj = AS_RANGE(object);

    return TO_BOOL(range_obj->start < range_obj->end);
}

static inline bool range_eq(range_object* lhs, range_object* rhs) {
    return lhs->start == rhs->start
        && lhs->end == rhs->end
        && lhs->step == rhs->step;
}

static object* range_rich_compare(object* lhs, object* rhs, int op) {

    assert(IS_RANGE(lhs));
    range_object* lhs_obj = AS_RANGE(lhs);

    assert(IS_RANGE(rhs));
    range_object* rhs_obj = AS_RANGE(rhs);

    switch (op) {
        case TYTHON_CMP_OP_EQ:

            if (range_eq(lhs_obj, rhs_obj)) {
                return TYTHON_TRUE;
            }
            return TYTHON_FALSE;

        case TYTHON_CMP_OP_NEQ:

            if (!range_eq(lhs_obj, rhs_obj)) {
                return TYTHON_TRUE;
            }
            return TYTHON_FALSE;

        default:
            assert("Unsupported rich comparison operator" && NULL);
    }
}

static long long range_length_c(range_object* range_obj) {
    return (range_obj->end - range_obj->start) / range_obj->step;
}

static object* range_length(object* obj) {

    assert(IS_RANGE(obj));

    range_object* range_obj = AS_RANGE(obj);

    return TO_INT(range_length_c(range_obj));
}

static object* range_subscript(object* obj, object* idx) {

    assert(IS_RANGE(obj));
    assert(IS_INT(idx));

    range_object* range_obj = AS_RANGE(obj);
    int_object* idx_obj = AS_INT(idx);

    const long long length = range_length_c(range_obj);
    long long index = idx_obj->value;

    if (index < 0) {

        // negative indexes wrap around
        assert(llabs(index) <= length);
        index += length;
    }

    // assert that the index is within list bounds
    assert(index < length);

    return TO_INT((index * range_obj->step) + range_obj->start);
}

static object* range_create_iterator(object* obj) {

    assert(IS_RANGE(obj));

    range_object* range_obj = AS_RANGE(obj);

    range_iterator_object* it = AS_RANGE_ITERATOR(range_iterator_type.alloc(&range_iterator_type));

    it->start = TO_INT(range_obj->start);
    it->step = TO_INT(range_obj->step);
    it->length = range_length(obj);

    return AS_OBJECT(it);
}

static number_functions range_number_functions = {
        .to_bool            = &range_to_bool,
} ;

static mapping_functions range_mapping_functions = {
        .length             = &range_length,
        .subscript          = &range_subscript,
};

type_object range_type = {
        .obj_base = {
                .identity   = &range_type.obj_base,
                .type       = &type_type,
        },

        .alloc              = &default_alloc,
        .seqalloc           = NULL,

        .base               = NULL,
        .instance_size      = sizeof(range_object),
        .item_size          = 0,                        // not a sequence type

        .rich_compare       = &range_rich_compare,
        .str                = &range_to_string,
        .hash               = NULL,

        .number_functions   = &range_number_functions,
        .mapping_functions  = &range_mapping_functions,
        .sequence_functions = NULL,                     // not a sequence type

        .create_iterator    = &range_create_iterator,
};

static object* range_iterator_next(object* obj) {

    assert(IS_RANGE_ITERATOR(obj));

    range_iterator_object* it = AS_RANGE_ITERATOR(obj);

    if (AS_INT(it->length)->value <= 0) {
        // this iterator has run off the end
        return NULL; // todo: None?
    }

    // decrement length
    it->length = TO_INT(AS_INT(it->length)->value - 1);

    object* cur = it->start;

    const long long new_cur = AS_INT(it->start)->value + AS_INT(it->step)->value;
    it->start = TO_INT(new_cur);

    return cur;
}

static object* range_iterator_to_bool(object* obj) {

    assert(IS_RANGE_ITERATOR(obj));

    range_iterator_object* it_obj = AS_RANGE_ITERATOR(obj);

    if (AS_INT(it_obj->length)->value <= 0) {
        return TYTHON_FALSE;
    }

    return TYTHON_TRUE;
}

static number_functions range_iterator_number_functions = {
        .to_bool            = &range_iterator_to_bool,
};

type_object range_iterator_type = {
        .obj_base = {
                .identity   = &range_iterator_type.obj_base,
                .type       = &type_type,
        },

        .alloc              = &default_alloc,
        .seqalloc           = NULL,

        .base               = NULL,
        .instance_size      = sizeof(range_iterator_object),
        .item_size          = 0,                        // not a sequence type

        .rich_compare       = NULL,
        .str                = NULL,
        .hash               = NULL,

        .number_functions   = &range_iterator_number_functions,
        .mapping_functions  = NULL,
        .sequence_functions = NULL,                     // not a sequence type

        .iterator_next      = &range_iterator_next,
};
