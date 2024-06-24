//
// Created by manzi on 21/02/24.
//

#include "api/api.h"
#include "object/stringobject.h"
#include "object/sliceobject.h"
#include "object/listobject.h"
#include "bridge/basicland.h"
#include "object/integerobject.h"
#include "object/rangeobject.h"
#include "object/tupleobject.h"
#include "object/floatobject.h"
#include "object/dictobject.h"
#include "error/error.h"
#include "object/noneobject.h"
#include <memory.h>
#include <stdio.h>
#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>

static object* box_internal(specialization_t spec) {

    switch (spec.tag) {

        case SPEC_INT:
            return int_create(spec.integer);

        case SPEC_FLOAT:
            return float_create(spec.floating_point);

        case SPEC_OBJECT:
            return spec.object;

        default:
            assert(NULL && "Encountered unknown specialization tag!");
    }
}

specialization_t box(specialization_t spec) {
    return (specialization_t) {
            .tag    = SPEC_OBJECT,
            .object = box_internal(spec),
    };
}

static long long int range_parameter_spec_to_int(specialization_t spec, long long int default_value) {

    switch (spec.tag) {

        case SPEC_INT:
            return spec.integer;

        case SPEC_FLOAT:
            type_mismatch(SPEC_FLOAT, SPEC_INT);

        case SPEC_OBJECT:

            // ducktype this thing

            {} // when are we getting C23?

            if (spec.object->type == &none_type) {
                return default_value; // if unspecified, return the default
            }

            number_functions* nf = spec.object->type->number_functions;

            assert(nf && nf->to_int && "Object does not support type conversion to float!");
            // in case assertions are disabled:
            if (!nf || !nf->to_int) {
                type_error();
            }

            const object* int_obj = nf->to_int(spec.object);

            return AS_INT(int_obj)->value;

        default:
            type_error();
    }

    return default_value;  // the type error will have exited the program before we get here
}

static double spec_to_float(specialization_t s) {

    switch(s.tag) {

        case SPEC_INT:
            return (double)s.integer;

        case SPEC_FLOAT:
            return s.floating_point;

        case SPEC_OBJECT:

            // ducktype this thing

            {} // when are we getting C23?

            number_functions* nf = s.object->type->number_functions;

            assert(nf && nf->to_float && "Object does not support type conversion to float!");
            // in case assertions are disabled:
            if (!nf || !nf->to_float) {
                type_error();
            }

            const object* float_obj = nf->to_float(s.object);

            return AS_FLOAT(float_obj)->value;

        default:
            type_error();
    }

    return .0; // the type error will have exited the program before we get here
}

void throw_type_error(specialization_t subject, int32_t expected_type) {
    type_mismatch(subject.tag, expected_type);
}

specialization_t spec_pow(specialization_t base, specialization_t exponent) {

    const double base_primitive = spec_to_float(base);
    const double exponent_primitive = spec_to_float(exponent);

    const double result = pow(base_primitive, exponent_primitive);

    return (specialization_t) {
        .tag = SPEC_FLOAT,
        .floating_point = result,
    };
}

static unsigned long string_obj_len(string_object* str) {

    for (int i = 0; i < str->length; ++i) {
        if (str->str[i] == '\0') {
            return i + 1;
        }
    }

    return str->length + 1;
}

static void sprint_string_object(char* buf, string_object* str, unsigned long length) {

    memcpy(buf, str->str, str->length);

    // ensure null-termination
    buf[length - 1] = '\0';
}

void ewout(specialization_t value) {

    fprintf(stderr, "\033[0;31m"); // Set STDERR to print in red

    object* object = box_internal(value);

    string_object* string_obj = AS_STRING(object->type->str(object));

    const unsigned long buf_size = string_obj_len(string_obj);
    char buf[buf_size];

    sprint_string_object(buf, string_obj, buf_size);

    // transform to uppercase, to increase urgency
    for (int i = 0; i < buf_size; ++i) {
        if (buf[i] >= 97 && buf[i] <= 122) {
            buf[i] -= 32;
        }
    }

    fprintf(stderr, "%s\r\n", buf); // print the error/warning

    fprintf(stderr, "\033[0m"); // Reset STDERR to its default color
}

static void print_object(object* object) {

    //    GRAB_OBJECT(object);

    // call the type's "str" function
    string_object* string_obj = AS_STRING(object->type->str(object));

    const unsigned long buf_size = string_obj_len(string_obj);
    char buf[buf_size];

    sprint_string_object(buf, string_obj, buf_size);

    printf("%s\r\n", buf);

//    object->type->release(object);
}

void print(specialization_t value) {

    switch (value.tag) {
        case SPEC_INT:
            printf("%lld\r\n", value.integer);
            break;
        case SPEC_FLOAT:
            printf("%f\r\n", value.floating_point);
            break;
        case SPEC_OBJECT:
            print_object(value.object);
            break;
        default:
            assert(NULL && "Encountered unexpected specialization type!");
    }
}

specialization_t range(specialization_t start, specialization_t end, specialization_t step) {

    long long int start_obj = range_parameter_spec_to_int(start, 0);
    long long int end_obj = range_parameter_spec_to_int(end, 0);
    long long int step_obj = range_parameter_spec_to_int(step, 1);

    object* range_obj = range_create_primitive(start_obj, end_obj, step_obj);

    return (specialization_t) {
        .tag    = SPEC_OBJECT,
        .object = range_obj,
    };
}

specialization_t __tuple__(size_t count, ...) {

    // todo: GC

    tuple_object* tuple_obj = AS_TUPLE(tuple_create(count));

    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {

        specialization_t e = va_arg(args, specialization_t);

        object* e_obj = box_internal(e);

        // store the element object in the tuple
        object** e_ref = tuple_obj->elements + i;
        (*e_ref) = e_obj;
    }

    va_end(args);

    return (specialization_t) {
        .tag = SPEC_OBJECT,
        .object = AS_OBJECT(tuple_obj),
    };
}

specialization_t __list__(size_t count, ...) {

    // todo: GC

    list_object * list_obj = AS_LIST(list_create(count));

    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {

        specialization_t e = va_arg(args, specialization_t);

        object* e_obj = box_internal(e);

        // store the element object in the list
        object** e_ref = list_obj->elements + i;
        (*e_ref) = e_obj;
    }

    va_end(args);

    return (specialization_t) {
        .tag = SPEC_OBJECT,
        .object = AS_OBJECT(list_obj),
    };
}

specialization_t __dict__(size_t count, ...) {

    // todo: GC

    dict_object * dict_obj = AS_DICT(dict_create(count));

    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {

        specialization_t key = va_arg(args, specialization_t);

        object* key_obj = box_internal(key);

        specialization_t value = va_arg(args, specialization_t);

        object* value_obj = box_internal(value);

        // store the element object in the list
        dict_entry* e_ref = dict_obj->entries + i;
        e_ref->key = key_obj;
        e_ref->value = value_obj;
    }

    va_end(args);

    return (specialization_t) {
        .tag = SPEC_OBJECT,
        .object = AS_OBJECT(dict_obj),
    };
}

void __set__(specialization_t object_spec, specialization_t key_spec, specialization_t value_spec) {

    assert(object_spec.tag == SPEC_OBJECT && "Type error: cannot set by index on non-object type!");

    object* obj = object_spec.object;
    object* key = box_internal(key_spec);
    object* value = box_internal(value_spec);

    assert(obj->type->mapping_functions && obj->type->mapping_functions->subscript && "Type error: target object does not support key access!");

    object** ref = obj->type->mapping_functions->subscript(obj, key);
    (*ref) = value;
}

specialization_t len(specialization_t spec) {

    assert(spec.tag == SPEC_OBJECT && "Type error: cannot obtain length of a primitive value!");

    object* object = spec.object;

    mapping_functions* mf = object->type->mapping_functions;

    assert(mf && "Type error: attempted to call \"len\", but argument is not a mapping type!");
    assert(mf->length && "Type error: the mapping type does not implement the length function.");

    return (specialization_t) {
        .tag = SPEC_OBJECT,
        .object = mf->length(object),
    };
}

specialization_t slice(specialization_t start_spec, specialization_t end_spec, specialization_t step_spec) {

    object* start = box_internal(start_spec);
    object* end = box_internal(end_spec);
    object* step = box_internal(step_spec);

    return (specialization_t) {
        .tag = SPEC_OBJECT,
        .object = slice_create(start, end, step),
    };
}

specialization_t list(specialization_t spec) {

    assert(spec.tag == SPEC_OBJECT && "Type error: cannot create list from non-iterable object!");

    object* obj = spec.object;

    assert(obj->type->create_iterator && "Type error: cannot create list from non-iterable object!");

    object* it = obj->type->create_iterator(obj);
    list_object* list_obj = AS_LIST(list_create(0));

    GRAB_OBJECT(it);

    function_object_function* list_append = resolve_builtin_method(AS_OBJECT(list_obj), "append");

    while (object_is_truthy(it)) {

        object* e = it->type->iterator_next(it);
        GRAB_OBJECT(e);

        (*list_append)(AS_OBJECT(list_obj), e);

        e->type->release(e);
    }

    it->type->release(it);

    return (specialization_t) {
        .tag = SPEC_OBJECT,
        .object = AS_OBJECT(list_obj),
    };
}

specialization_t str(specialization_t spec) {

    object* boxed = box_internal(spec);

    if (!boxed->type->str) {
        type_error();
    }

    return (specialization_t) {
        .tag    = SPEC_OBJECT,
        .object = boxed->type->str(boxed),
    };
}
