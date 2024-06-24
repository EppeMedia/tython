//
// Created by manzi on 01/02/24.
//

#ifndef TYTHON_BOOLOBJECT_H
#define TYTHON_BOOLOBJECT_H

#include "object.h"
#include "type.h"
#include <stdbool.h>

extern type_object bool_type;

typedef struct bool_object_t {
    ObjectHead

    bool value;

} bool_object;

#define IS_BOOL(instance) ((instance)->type == &bool_type)
#define AS_BOOL(instance) ((bool_object*)(instance))

/**
 * Creates a boolean object instance with the value set to {v}.
 * @param v The value to set the boolean object instance to.
 * @return Returns a new boolean object instance with its value set to {v}.
 */
object* bool_create(bool v);

extern bool_object bool_true, bool_false;

#define TYTHON_TRUE ((struct object_t*)&bool_true)
#define TYTHON_FALSE ((struct object_t*)&bool_false)

#define TO_BOOL(value)    ((value) ? TYTHON_TRUE : TYTHON_FALSE)

#endif //TYTHON_BOOLOBJECT_H
