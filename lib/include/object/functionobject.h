//
// Created by manzi on 27/02/24.
//

#ifndef TYTHON_FUNCTIONOBJECT_H
#define TYTHON_FUNCTIONOBJECT_H

#include "type.h"
#include "stringobject.h"

extern type_object function_type;
extern type_object function_arg_type;

typedef struct function_arg_object_t {

    ObjectHead

    type_object* type;
    string_object* name;
    object* value;

} function_arg_object;

typedef struct function_object_t {

    ObjectHead

    string_object* name;
    function_arg_object* arguments;
    size_t argument_count;

    function_object_function* function_ptr;

} function_object;

#define IS_FUNCTION(instance) (AS_OBJECT(instance)->type == &function_type)
#define AS_FUNCTION(instance) ((function_object*)(instance))

object* function_create(string_object* name, function_arg_object* arguments, size_t argument_count, function_object_function* function_ptr);

#endif //TYTHON_FUNCTIONOBJECT_H
