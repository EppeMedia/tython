//
// Created by manzi on 30/01/24.
//

#ifndef TYTHON_INTEGEROBJECT_H
#define TYTHON_INTEGEROBJECT_H

#include "object.h"
#include "type.h"

extern type_object int_type;

typedef struct int_object_t {
    ObjectHead

    long long value;

} int_object;

#define IS_INT(instance) (instance->type == &int_type)
#define AS_INT(instance) ((int_object*)instance)

/**
 * Creates an integer object instance with the value set to {v}.
 * @param v The value to set the integer object instance to.
 * @return Returns a new integer object instance with its value set to {v}.
 */
object* int_create(long long v);

#define TO_INT(value)    (int_create(value))

#endif //TYTHON_INTEGEROBJECT_H
