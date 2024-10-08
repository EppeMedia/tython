//
// Created by manzi on 20/01/24.
//

#ifndef TYTHON_OBJECT_H
#define TYTHON_OBJECT_H

#include "typedefs.h"

/**
 * This is similar to CPython's PyObject. It is a proxy for polymorphism.
 * This struct represents the root type, and describes the first X bytes of all objects.
 */
typedef struct object_t {
    struct object_t* identity;     // identities are immutable
    type_object* type;             // types are immutable
    int32_t refs;
} object;

/**
 * This is similar to CPython's PyVarObject. This struct describes the first X+Y bytes of collection objects (it is an extension of object).
 */
typedef struct sequence_object_t {
    object obj_base;
    size_t size;
} sequence_object;

#define ObjectHead object obj_base;
#define SequenceObjectHead sequence_object obj_base;

#define ObjectHeadInitType(type)        \
    .obj_base = {                       \
        .identity   = &(type).obj_base,   \
        .type       = &type_type        \
    }                                   \

#define AS_OBJECT(instance)     ((object*)(instance))
#define AS_SEQOBJECT(instance)  ((sequence_object*)(instance))

#endif //TYTHON_OBJECT_H
