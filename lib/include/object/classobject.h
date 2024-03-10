//
// Created by manzi on 27/02/24.
//

#ifndef TYTHON_CLASSOBJECT_H
#define TYTHON_CLASSOBJECT_H

#include "type.h"
#include "stringobject.h"

extern type_object class_type;

typedef struct class_object_t {

    ObjectHead

    string_object* name;
    struct dict_object_t* members;

} class_object;

#define IS_CLASS(instance) (AS_OBJECT(instance)->type == &class_type)
#define AS_CLASS(instance) ((class_object*)(instance))

/**
 * Creates a class object with the specified name and polymorphic base.
 * @param name The name of the new class object.
 * @param base The polymorphic base of this class.
 * @return Returns a new instance of a class object with the specified name and base.
 */
object* class_create(string_object* name, object* base);

#endif //TYTHON_CLASSOBJECT_H
