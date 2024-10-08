//
// Created by manzi on 30/01/24.
//

/**
 * Basic land is where we deal with the relationship between C basic data types and Tython objects.
 */

#ifndef TYTHON_BASICLAND_H
#define TYTHON_BASICLAND_H

#include "object.h"
#include <stdbool.h>

typedef union primitive {

    long long integer;
    double floating_point;

} primitive_t;
/**
 * Converts the object to a basic boolean value.
 * @param obj The object to evaluate.
 * @return Returns {true} iff the specified object is "truthy".
 */
bool object_is_truthy(object* obj);

/**
 * Resolves the function pointer for a given method name.
 * @param object The object the method should exist on.
 * @param name The name of the method to resolve.
 * @return Returns a function pointer to the named method on the specified object, or NULL if no such method exists.
 */
function_object_function* resolve_builtin_method(object* object, const char* name);

/**
 * Returns the primitive representation for the specified object.
 * Throws a type assertion error if the type of the specified object has no representation of the expected primitive type.
 *
 * @param object The object to obtain a primitive representation for.
 * @param type The expected primitive type.
 * @return Returns the primitive representation of the specified object.
 */
primitive_t object_to_primitive(object* object, int32_t type);

#endif //TYTHON_BASICLAND_H
