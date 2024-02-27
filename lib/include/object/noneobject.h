//
// Created by manzi on 21/02/24.
//

#ifndef TYTHON_NONEOBJECT_H
#define TYTHON_NONEOBJECT_H

#include "type.h"

extern type_object none_type;

typedef struct none_object_t {
    ObjectHead
} none_object;

extern none_object none_instance;

#define IS_NONE(obj)        (AS_OBJECT(obj)->type == &none_type)
#define AS_NONE(instance)   ((none_object*)(instance))

#define TYTHON_NONE (&none_instance)

#endif //TYTHON_NONEOBJECT_H
