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

/**
 * Converts the object to a basic boolean value.
 * @param obj The object to evaluate.
 * @return Returns {true} iff the specified object is "truthy".
 */
bool object_is_truthy(object* obj);

#endif //TYTHON_BASICLAND_H
