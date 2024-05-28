//
// Created by manzi on 24/02/24.
//

#ifndef TYTHON_TUPLEOBJECT_H
#define TYTHON_TUPLEOBJECT_H

#include "type.h"

extern type_object tuple_type;

typedef struct tuple_object_t {
    ObjectHead;     // 8 + 8

    size_t size;    // 8
    object** elements;

} tuple_object;

extern type_object tuple_iterator_type;

typedef struct tuple_iterator_object_t {
    ObjectHead;

    object* idx;
    tuple_object* tuple_obj;

} tuple_iterator_object;

#define IS_TUPLE(obj) (AS_OBJECT(obj)->type == &tuple_type)
#define AS_TUPLE(obj) ((tuple_object*)(obj))

#define IS_TUPLE_ITERATOR(obj) (AS_OBJECT(obj)->type == &tuple_iterator_type)
#define AS_TUPLE_ITERATOR(obj) ((tuple_iterator_object*)(obj))

/**
 * Creates a new __tuple__ object, provisioning for {size} elements.
 * @param size The number of elements of the __tuple__.
 * @return Returns a newly instantiated __tuple__ object, with a capacity of {size} elements.
 */
object* tuple_create(size_t size);

#endif //TYTHON_TUPLEOBJECT_H
