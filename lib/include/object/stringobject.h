//
// Created by manzi on 26/01/24.
//

#ifndef TYTHON_STRINGOBJECT_H
#define TYTHON_STRINGOBJECT_H

#include "type.h"

extern type_object string_type;

typedef struct string_object_t {

    ObjectHead

    char* str;
    size_t length;

} string_object;

#define IS_STRING(instance) (AS_OBJECT(instance)->type == &string_type)
#define AS_STRING(instance) ((string_object*)(instance))

/**
 * Creates a string object for the specified c-style string and length. At most {length} characters of {str} are copied.
 * If {str} is null-terminated, and that null character's index is {i}, then if {i} is smaller than {length}, the rest of the string object's content (the interval ({i}, {length})) is undefined.
 * @param cstr The c-style string to create a string object for (by copy).
 * @param length The length of the string object to create.
 * @return Returns a new string object with the specified contents.
 */
object* string_create(const char* cstr, size_t length);

/**
 * Determines the lenght of the specified string instance.
 * @param str The string instance of which to determine its length.
 * @return Returns a number object instance whose value is the length of the specified string.
 */
object* string_length(object* str);

#define TO_STRING(cstr, len) (string_create(cstr, len))

#endif //TYTHON_STRINGOBJECT_H
