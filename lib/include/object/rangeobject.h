//
// Created by manzi on 30/01/24.
//

#ifndef TYTHON_RANGEOBJECT_H
#define TYTHON_RANGEOBJECT_H

#include "object.h"
#include "type.h"
#include "integerobject.h"

extern type_object range_type;

typedef struct range_object_t {
    ObjectHead

    long long start;
    long long end;
    long long step;

    /**
     * The following field is a bit hacky. It solves the issue of creating memory leaks for the indirection required for the current subscript API.
     * What makes this work is that setting to a range object through subscript access is not allowed. It raises a type error in CPython. Here now it leads to undefined behaviour.
     * The better solution would be to pull apart subscript read and write access (i.e. subscript (read) and set (write))
     */
    object** subscript_cache;

} range_object;

extern type_object range_iterator_type;

/**
 * This is the iterator object for ranges.
 */
typedef struct range_iterator_object_t {
    ObjectHead

    long long start;
    long long step;
    long long length;

    int_object* cursor_cache;

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

/**
 * Creates an range object instance with its parameters set to the specified start, end and step size.
 * @param start The starting point of the range.
 * @param end The ending point of the range.
 * @param step The step size of the range.
 * @return Returns a new range object instance with its parameters set to the specified start, end and step size.
 */
object* range_create_primitive(long long int start, long long int end, long long int step);

#endif //TYTHON_RANGEOBJECT_H
