//
// Created by manzi on 20/01/24.
//

#include "object/stringobject.h"
#include <stdio.h>
#include <memory.h>

void print(object* object) {

    // call the type's "str" function
    string_object* string_obj = AS_STRING(object->type->str(object));

    // get the content from the string object and terminate it with a null-character if necessary
    int null = 0;

    for (int i = 0; i < string_obj->length; ++i) {
        if (string_obj->str[i] == '\0') {
            null = 1;
        }
    }

    unsigned long buf_size = null == 0 ? string_obj->length + 1 : string_obj->length;
    char buf[buf_size];

    memcpy(buf, string_obj->str, string_obj->length);

    // ensure null-termination
    buf[buf_size - 1] = '\0';

    printf("%s\r\n", buf);
}

// todo: instantiate a globally unique None object here
