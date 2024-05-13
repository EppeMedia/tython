//
// Created by manzi on 21/02/24.
//

#ifndef TYTHON_API_H
#define TYTHON_API_H

#include "object.h"

#define SPEC_INT    0
#define SPEC_FLOAT  1
#define SPEC_OBJECT 2

typedef struct specialization {

    uint32_t tag;

    union {
        long long integer;
        double floating_point;
        struct object_t* object;
    };

} specialization_t;

/**
 * Prints the specified speialization value to standard out.
 * @param value The specialization value to print.
 */
void print(specialization_t* value);

/**
 * Determines the length of the specified object instance. Throws an assertion error if the object is not of a sequence or mapping type.
 * @param object The object instance to determine the length of.
 * @return Returns a new integer object instance which is the length of the specified object instance.
 */
object* len(object* object);

/**
 * Creates a new slice object with the specified properties.
 * @param start The start of the new slice.
 * @param end The end of the new slice.
 * @param step The step size of the new slice.
 * @return Returns a fresh instance of a slice with the specified properties.
 */
object* slice(object* start, object* end, object* step);

/**
 * Creates a new list with the ordered contents of the specified iterable object. Order is determined by the object's iterator.
 * @param obj The iterable object to create a list over.
 * @return Returns a new list containing the ordered elements of the iterable object. Order is determined by the object's iterator.
 */
object* list(object* obj);

#endif //TYTHON_API_H
