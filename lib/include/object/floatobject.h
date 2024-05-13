//
// Created by manzi on 23/01/24.
//

#ifndef TYTHON_FLOATOBJECT_H
#define TYTHON_FLOATOBJECT_H

#include "object.h"
#include "type.h"

#define FLOATOBJECT_REPRESENTATION_FORMAT       "%.*Lf"
#define FLOATOBJECT_REPRESENTATION_PRECISION    17

extern type_object float_type;

typedef struct float_object_t {
    ObjectHead

    double value;

} float_object;

#define IS_FLOAT(instance) (instance->type == &float_type)
#define AS_FLOAT(instance) ((float_object*)instance)

/**
 * Creates a float object instance with the value set to {v}.
 * @param v The value to set the float object instance to.
 * @return Returns a new float object instance with its value set to {v}.
 */
object* float_create(double v);

#define TO_FLOAT(value)    (float_create(value))

#endif //TYTHON_FLOATOBJECT_H
