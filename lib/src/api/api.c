//
// Created by manzi on 21/02/24.
//

#include "api/api.h"
#include "object/stringobject.h"
#include "object/sliceobject.h"
#include "object/listobject.h"
#include "bridge/basicland.h"
#include <memory.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

void print(object* object) {

//    GRAB_OBJECT(object);

    // call the type's "str" function
    string_object* string_obj = AS_STRING(object->type->str(object));

    // get the content from the string object and terminate it with a null-character if necessary
    bool null = false;

    for (int i = 0; i < string_obj->length; ++i) {
        if (string_obj->str[i] == '\0') {
            null = true;
        }
    }

    unsigned long buf_size = null ? string_obj->length : string_obj->length + 1;
    char buf[buf_size];

    memcpy(buf, string_obj->str, string_obj->length);

    // ensure null-termination
    buf[buf_size - 1] = '\0';

    printf("%s\r\n", buf);

//    object->type->release(object);
}

object* len(object* object) {

    mapping_functions* mf = object->type->mapping_functions;

    assert(mf && "Type error: attempted to call \"len\", but argument is not a mapping type!");
    assert(mf->length && "Type error: the mapping type does not implement the length function.");

    return mf->length(object);
}

object* slice(object* start, object* end, object* step) {
    return slice_create(start, end, step);
}

object* list(object* obj) {

    assert(obj->type->create_iterator && "Type error: cannot create list from non-iterable object!");

    object* it = obj->type->create_iterator(obj);
    list_object* list_obj = AS_LIST(list_create(0));

    GRAB_OBJECT(it);

    function_object_function* list_append = resolve_builtin_method(AS_OBJECT(list_obj), "append");

    while (object_is_truthy(it)) {

        object* e = it->type->iterator_next(it);
        GRAB_OBJECT(e);

        (*list_append)(AS_OBJECT(list_obj), e);

        e->type->release(e);
    }

    it->type->release(it);

    return AS_OBJECT(list_obj);
}
