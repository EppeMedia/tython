//
// Created by manzi on 20/02/24.
//

#ifndef TYTHON_LISTOBJECT_H
#define TYTHON_LISTOBJECT_H

#include "object.h"
#include "type.h"

extern type_object list_type;

typedef struct list_object_t {

    ObjectHead;

    size_t size;
    object** elements;

} list_object;

#define IS_LIST(obj) (AS_OBJECT(obj)->type == &list_type)
#define AS_LIST(obj) ((list_object*)(obj))

/**
 * Creates a new list object, provisioning for {size} elements.
 * @param size The initial capacity of the list.
 * @return Returns a newly instantiated list object, with a capacity of {size} elements.
 */
object* list_create(size_t size);

#endif //TYTHON_LISTOBJECT_H
