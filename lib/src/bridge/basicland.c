//
// Created by manzi on 30/01/24.
//

#include <assert.h>
#include <string.h>
#include "object/boolobject.h"
#include "bridge/basicland.h"
#include "object/integerobject.h"
#include "object/floatobject.h"
#include "api/api.h"
#include "error/error.h"

bool object_is_truthy(object* obj) {

    if (!obj) {
        return false;
    }

    const number_functions* nf = obj->type->number_functions;

    assert(nf && nf->to_bool && "Type error: boolean conversion not implemented on this type!");

    object* bool_obj = (*nf->to_bool)(obj);

    assert(IS_BOOL(bool_obj));

    return AS_BOOL(bool_obj)->value;
}

/**
 * Creates a function object for the named method of the specified builtin object.
 * @param object The object for whose method the function object should be created.
 * @param name The name of the method to create a function object for.
 * @return Returns a new function object for the specified method.
 */
function_object_function* resolve_builtin_method(object* object, const char* name) {

    // first try the built-in methods on the object

    for (int i = 0 ;; ++i) {

        builtin_method* methods = object->type->methods;

        if (!methods || !methods[i].name) {
            break;
        }

        if (strcmp(methods[i].name, name) == 0) {
            return methods[i].f;
        }
    }

    assert("Type error: method not found" && NULL);

    return NULL;
}

primitive_t object_to_primitive(object* object, int32_t type) {

    switch (type) {

        case SPEC_INT:
            if (IS_INT(object)) {
                return (primitive_t){ .integer = AS_INT(object)->value };
            } else if (IS_FLOAT(object)) {
                return (primitive_t){ .integer = AS_FLOAT(object)->value };
            } else {
                type_error();
            }

        case SPEC_FLOAT:

            if (IS_INT(object)) {
                return (primitive_t){ .floating_point = AS_INT(object)->value };
            } else if (IS_FLOAT(object)) {
                return (primitive_t){ .floating_point = AS_FLOAT(object)->value };
            } else {
                type_error();
            }

        default:
            type_error();
    }

    return (primitive_t){ .integer = 0 };
}
