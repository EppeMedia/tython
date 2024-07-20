//
// Created by manzi on 30/01/24.
//

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "object/rangeobject.h"
#include "object/integerobject.h"
#include "object/stringobject.h"
#include "object/boolobject.h"
#include "object/noneobject.h"

object* range_create_primitive(long long int start, long long int end, long long int step) {

    range_object* range_obj = AS_RANGE(range_type.alloc(&range_type));

    range_obj->start = start;
    range_obj->end = end;
    range_obj->step = step;

    range_obj->subscript_cache = malloc(sizeof(object*));

    return AS_OBJECT(range_obj);
}

object* range_create(object* start, object* end, object* step) {

    assert(IS_INT(start));
    assert(IS_INT(end));
    assert(IS_INT(step));

    int_object* start_obj = AS_INT(start);
    int_object* end_obj = AS_INT(end);
    int_object* step_obj = AS_INT(step);

    assert(step_obj->value != 0 && "Step size cannot be zero!");

    return range_create_primitive(start_obj->value, end_obj->value, step_obj->value);
}

static object* range_to_string(object* object) {

    assert(IS_RANGE(object));

    range_object* range_obj = AS_RANGE(object);

    // determine length
    const int fields_len = snprintf(NULL, 0, "%lld", range_obj->start)
                           + snprintf(NULL, 0, "%lld", range_obj->end)
                           + snprintf(NULL, 0, "%lld", range_obj->step);

    // allocate string buffer ("range" + braces + commas + spaces)
    const int str_len = fields_len + (5 + 2 + 2 + 2);
    char str[str_len];

    // fill string
    sprintf(str, "range(%lld, %lld, %lld)", range_obj->start, range_obj->end, range_obj->step);

    return string_create(str, str_len);
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
    return (long long)ceill((long double)(range_obj->end - range_obj->start) / range_obj->step);
}

static object* range_length(object* obj) {

    assert(IS_RANGE(obj));

    range_object* range_obj = AS_RANGE(obj);

    return TO_INT(range_length_c(range_obj));
}

static object** range_subscript(object* obj, object* idx) {

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

    object* v = TO_INT((index * range_obj->step) + range_obj->start);

    *range_obj->subscript_cache = v;

    return range_obj->subscript_cache;
}

static object* range_create_iterator(object* obj) {

    assert(IS_RANGE(obj));

    range_object* range_obj = AS_RANGE(obj);

    range_iterator_object* it = AS_RANGE_ITERATOR(ALLOC(range_iterator_type));

    it->start = range_obj->start;
    it->step = range_obj->step;
    it->length = range_length_c(range_obj);
    it->cursor_cache = AS_INT(int_create(it->start));
    GRAB_OBJECT(it->cursor_cache);

    return AS_OBJECT(it);
}

static void range_release(object* obj) {

    assert(IS_RANGE(obj));

    if (obj->refs == 1) {
        free(AS_RANGE(obj)->subscript_cache);
    }

    default_release(obj);
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
                .refs       = 0,
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

        .grab               = &default_grab,
        .release            = &range_release,
};

static object* range_iterator_next(object* obj) {

    assert(IS_RANGE_ITERATOR(obj));

    range_iterator_object* it = AS_RANGE_ITERATOR(obj);

    if (it->length <= 0) {
        // this iterator has run off the end
        return AS_OBJECT(TYTHON_NONE);
    }

    // decrement length
    it->length--;

    const long long cur = it->start;

    if (it->cursor_cache->obj_base.refs == 1) {

        // the cursor is only referenced by this iterator; we can safely reuse the memory:
        it->cursor_cache->value = cur;

    } else {

        // the cursor is referenced by another object. We cannot update its content.
        // Release our reference to the cursor and overwrite it (the other referencing objects will take care of its cleanup when they release their reference).

        RELEASE_OBJECT(it->cursor_cache);

        // create the new cursor
        it->cursor_cache = AS_INT(int_create(cur));

        GRAB_OBJECT(it->cursor_cache);
    }

    it->start += it->step;

    return AS_OBJECT(it->cursor_cache);
}

static object* range_iterator_to_bool(object* obj) {

    assert(IS_RANGE_ITERATOR(obj));

    range_iterator_object* it_obj = AS_RANGE_ITERATOR(obj);

    if (it_obj->length <= 0) {
        return TYTHON_FALSE;
    }

    return TYTHON_TRUE;
}

static number_functions range_iterator_number_functions = {
        .to_bool            = &range_iterator_to_bool,
};

static void range_iterator_release(object* obj) {

    assert(IS_RANGE_ITERATOR(obj));

    // if we are cleaning up, release cursor first
    if (obj->refs == 1) {
        RELEASE_OBJECT(AS_RANGE_ITERATOR(obj)->cursor_cache);
    }

    default_release(obj);
}

type_object range_iterator_type = {
        .obj_base = {
                .identity   = &range_iterator_type.obj_base,
                .type       = &type_type,
                .refs       = 0,
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

        .grab               = &default_grab,
        .release            = &range_iterator_release,
};
