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
    type* type;             // types are immutable
} object;

/**
 * This is similar to CPython's PyVarObject. This struct describes the first X+Y bytes of collection objects (it is an extension of object).
 */
typedef struct collection_object_t {
    object obj;
    size_t size;
} collection_object;

#endif //TYTHON_OBJECT_H
