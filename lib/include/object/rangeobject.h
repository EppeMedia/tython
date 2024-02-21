//
// Created by manzi on 30/01/24.
//

#ifndef TYTHON_RANGEOBJECT_H
#define TYTHON_RANGEOBJECT_H

#include "object.h"
#include "type.h"

extern type_object range_type;

typedef struct range_object_t {
    ObjectHead

    long long start;
    long long end;
    long long step;

} range_object;

extern type_object range_iterator_type;

/**
 * This is the iterator object for ranges.
 */
typedef struct range_iterator_object_t {
    ObjectHead

    object* start;
    object* step;
    object* length;

} range_iterator_object;

#define IS_RANGE(instance) ((instance)->type == &range_type)
#define AS_RANGE(instance) ((range_object*)(instance))

#define IS_RANGE_ITERATOR(instance) ((instance)->type == &range_iterator_type)
#define AS_RANGE_ITERATOR(instance) ((range_iterator_object*)(instance))

/**
 * Creates an range object instance with its parameters set to the specified start, end and step size.
 * @param start The starting point of the range.
 * @param end The ending point of the range.
 * @param step The step size of the range.
 * @return Returns a new range object instance with its parameters set to the specified start, end and step size.
 */
object* range_create(object* start, object* end, object* step);

#endif //TYTHON_RANGEOBJECT_H
