//
// Created by manzi on 07/02/24.
//

#include <stddef.h>
#include <assert.h>
#include <malloc.h>
#include <memory.h>
#include "object/dictobject.h"
#include "object/boolobject.h"
#include "object/stringobject.h"
#include "object/integerobject.h"

static object* dict_rich_compare(object* lhs,  object* rhs, int op) {
    return TYTHON_FALSE; // todo: implement
}

static char* to_cstr(string_object* string_obj) {

    if (string_obj->str[string_obj->length - 1] == '\0') {
        char* cstr = malloc(string_obj->length * sizeof(char));
        strcpy(cstr, string_obj->str);
        return cstr;
    }

    char* cstr = malloc((string_obj->length + 1) * sizeof(char));
    memcpy(cstr, string_obj->str, string_obj->length);
    cstr[string_obj->length] = '\0';
    return cstr;
}

static object* dict_to_string(object* obj) {

    assert(IS_DICT(obj));

    dict_object* dict_obj = AS_DICT(obj);

    // collect the string objects and the cumulative size of the strings
    size_t entries_string_length = 0;

    for (int i = 0; i < dict_obj->size; ++i) {
        dict_entry entry = dict_obj->entries[i];

        object* key_string = entry.key->type->str(entry.key);
        entries_string_length += AS_STRING(key_string)->length;

        object* value_string = entry.value->type->str(entry.value);
        entries_string_length += AS_STRING(value_string)->length;
    }

    // allocate memory for the final string, which includes two curly braces for the dict, a colon between each key and value, and a comma after each entry, ending with a null pointer
    size_t separator_count = (dict_obj->size * 3) - 2; // the last entry is not followed by a comma and a space
    size_t str_len = (entries_string_length * sizeof(char)) + 2 + (separator_count * sizeof(char)) + 1;
    char* string = malloc(str_len);
    string[0] = '{';
    string[str_len - 2] = '}';
    string[str_len - 1] = '\0';

    char* offset = string + 1;
    for (int i = 0; i < dict_obj->size; ++i) {
        dict_entry entry = dict_obj->entries[i];

        // copy the string representation of each entry
        string_object* key_string = AS_STRING(entry.key->type->str(entry.key));
        memcpy(offset, key_string->str, key_string->length);
        offset += key_string->length;

        *offset = ':';
        ++offset;

        string_object* value_string = AS_STRING(entry.value->type->str(entry.value));
        memcpy(offset, value_string->str, value_string->length);
        offset += value_string->length;

        if (i != dict_obj->size - 1) {
            *offset++ = ',';
            *offset++ = ' ';
        }
    }

    return TO_STRING(string, str_len);
}

static object* dict_subscript(object* obj, object* key) {

    assert(IS_DICT(obj));

    dict_object* dict_obj = AS_DICT(obj);

    // todo: implement as a hashmap

    // linear search
    for (int i = 0; i < dict_obj->size; ++i) {
        dict_entry dict_entry = dict_obj->entries[i];
        if (HASH_OBJECT(key)->value == HASH_OBJECT(dict_entry.key)->value) {
            // found it
            return dict_entry.value;
        }
    }

    printf("Key not found!\r\n");

    return AS_OBJECT(NULL); // todo: implement and return None
}

static object* dict_length(object* obj) {

    assert(IS_DICT(obj));

    return TO_INT(AS_DICT(obj)->size);
}

object* dict_create(size_t size) {

    // provision for the object header and entries
    dict_object* dict_obj = malloc(sizeof(dict_object));

    // initialize object header
    AS_OBJECT(dict_obj)->type = &dict_type;
    AS_OBJECT(dict_obj)->identity = AS_OBJECT(dict_obj);

    dict_obj->size = size;

    // allocate space for entries
    dict_obj->entries = malloc(size * sizeof(dict_entry));

    return AS_OBJECT(dict_obj);
}

static mapping_functions dict_mapping_functions = {
        .length     = &dict_length,
        .subscript  = &dict_subscript,
};

type_object dict_type = {

        .obj_base = {
            .identity       = &dict_type.obj_base,
            .type           = &type_type,
        },

        .alloc              = &default_alloc,
        .seqalloc           = NULL,                 // todo: dict_create should be the seqalloc

        .base               = NULL,
        .instance_size      = sizeof(dict_object),
        .item_size          = sizeof(dict_entry),   // todo: size of entry struct

        .rich_compare       = &dict_rich_compare,
        .str                = &dict_to_string,

        .number_functions   = NULL,
        .mapping_functions  = &dict_mapping_functions,
        .sequence_functions = NULL,
};
