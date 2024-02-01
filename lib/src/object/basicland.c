//
// Created by manzi on 30/01/24.
//

#include <assert.h>
#include "object/basicland.h"
#include "type.h"
#include "object/integerobject.h"

bool object_is_truthy(object* obj) {

    const number_functions* nf = obj->type->number_functions;

    if (nf && nf->to_bool) {

        object* bool_obj = (*nf->to_bool)(obj);

        assert(IS_INT(bool_obj));

        return AS_INT(bool_obj)->value;
    }

    // todo: there are other ways an object can be truthy (i.e. a non-empty sequence object is truthy, a non-empty string is truthy...)

    return false;
}
