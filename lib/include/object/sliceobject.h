//
// Created by manzi on 26/02/24.
//

#ifndef TYTHON_SLICEOBJECT_H
#define TYTHON_SLICEOBJECT_H

#include "object.h"
#include "type.h"

extern type_object slice_type;

typedef struct slice_object_t {
    ObjectHead

    long long start;
    long long end;
    long long step;

} slice_object;

#define IS_SLICE(instance) ((instance)->type == &slice_type)
#define AS_SLICE(instance) ((slice_object*)(instance))

/**
 * Creates an slice object instance with its parameters set to the specified start, end and step size.
 * @param start The starting point of the slice.
 * @param end The ending point of the slice.
 * @param step The step size of the slice.
 * @return Returns a new slice object instance with its parameters set to the specified start, end and step size.
 */
object* slice_create(object* start, object* end, object* step);

#endif //TYTHON_SLICEOBJECT_H
