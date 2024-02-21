//
// Created by manzi on 21/02/24.
//

#ifndef TYTHON_USERFUNCTIONS_H
#define TYTHON_USERFUNCTIONS_H

#include "object.h"

/**
 * Prints the specified object to standard out.
 * @param object The object to print.
 */
void print(object* object);

/**
 * Determines the length of the specified object instance. Throws an assertion error if the object is not of a sequence or mapping type.
 * @param object The object instance to determine the length of.
 * @return Returns a new integer object instance which is the length of the specified object instance.
 */
object* len(object* object);

#endif //TYTHON_USERFUNCTIONS_H
