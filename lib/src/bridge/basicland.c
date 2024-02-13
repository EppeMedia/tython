//
// Created by manzi on 30/01/24.
//

#include <assert.h>
#include "object/boolobject.h"
#include "bridge/basicland.h"

bool object_is_truthy(object* obj) {

    const number_functions* nf = obj->type->number_functions;

    if (nf && nf->to_bool) {

        object* bool_obj = (*nf->to_bool)(obj);

        assert(IS_BOOL(bool_obj));

        return AS_BOOL(bool_obj)->value;
    }

    // todo: throw unsupported error

    return false;
}
