//
// Created by manzi on 30/01/24.
//

#include <assert.h>
#include <stdio.h>
#include "object/boolobject.h"
#include "bridge/basicland.h"

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
