//
// Created by manzi on 20/01/24.
//

#include "object/stringobject.h"
#include <stdio.h>
#include <memory.h>
#include <stdbool.h>
#include <assert.h>

void print(object* object) {

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
}

object* len(object* object) {

    mapping_functions* mf = object->type->mapping_functions;

    assert(mf && "Type error: attempted to call \"len\", but argument is not a mapping type!");
    assert(mf->length && "Type error: the mapping type does not implement the length function.");

    return mf->length(object);
}

// todo: instantiate a globally unique None object here
