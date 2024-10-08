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
#include "object/listobject.h"

static object* dict_rich_compare(object* lhs,  object* rhs, int op) {
    return TYTHON_FALSE; // todo: implement a default handler that prints a type error for all ORDINAL comparisons on dicts. (In)equaltity should be implemented.
}

static object* dict_to_string(object* obj) {

    assert(IS_DICT(obj));

    dict_object* dict_obj = AS_DICT(obj);

    // collect the string objects and the cumulative size of the strings
    size_t entries_string_length = 0;

    for (int i = 0; i < dict_obj->size; ++i) {
        dict_entry entry = dict_obj->entries[i];

        object* key_string = entry.key->type->str(entry.key);
        GRAB_OBJECT(key_string);
        entries_string_length += AS_STRING(key_string)->length;
        RELEASE_OBJECT(key_string);

        object* value_string = entry.value->type->str(entry.value);
        GRAB_OBJECT(value_string);
        entries_string_length += AS_STRING(value_string)->length;
        RELEASE_OBJECT(value_string);
    }

    // allocate memory for the final string, which includes two curly braces for the dict, a colon and a space between each key and value, and a comma and space between each entry
    size_t separator_count = (dict_obj->size * 4) - 2; // the last entry is not followed by a comma and a space
    size_t str_len = (entries_string_length * sizeof(char)) + 2 + (separator_count * sizeof(char));
    char string[str_len];
    string[0] = '{';
    string[str_len - 1] = '}';

    char* offset = string + 1;
    for (int i = 0; i < dict_obj->size; ++i) {
        dict_entry entry = dict_obj->entries[i];

        // copy the string representation of each entry
        string_object* key_string = GET_STRING(entry.key);
        GRAB_OBJECT(key_string);
        memcpy(offset, key_string->str, key_string->length);
        offset += key_string->length;
        RELEASE_OBJECT(key_string);

        *offset++ = ':';
        *offset++ = ' ';

        string_object* value_string = GET_STRING(entry.value);
        GRAB_OBJECT(value_string);
        memcpy(offset, value_string->str, value_string->length);
        offset += value_string->length;
        RELEASE_OBJECT(value_string);

        if (i != dict_obj->size - 1) {
            *offset++ = ',';
            *offset++ = ' ';
        }
    }

    return TO_STRING(string, str_len);
}

static object** dict_subscript(object* obj, object* key) {

    assert(IS_DICT(obj));

    dict_object* dict_obj = AS_DICT(obj);

    // todo: implement as a hashmap

    // linear search
    for (int i = 0; i < dict_obj->size; ++i) {

        const dict_entry dict_entry = dict_obj->entries[i];

        int_object* key_hash = HASH_OBJECT(key);
        int_object* entry_key_hash = HASH_OBJECT(dict_entry.key);

        GRAB_OBJECT(key_hash);
        GRAB_OBJECT(entry_key_hash);

        if (key_hash->value == entry_key_hash->value) {
            // found it, return a pointer to the value
            RELEASE_OBJECT(key_hash);
            RELEASE_OBJECT(entry_key_hash);
            return &dict_obj->entries[i].value;
        }
    }

    assert(NULL && "Key error; key not found!");

    return NULL;
}

static object* dict_length(object* obj) {

    assert(IS_DICT(obj));

    return TO_INT(AS_DICT(obj)->size);
}

object* dict_create(size_t size) {

    dict_object* dict_obj = malloc(sizeof(dict_object));

    // initialize object header
    AS_OBJECT(dict_obj)->identity = AS_OBJECT(dict_obj);
    AS_OBJECT(dict_obj)->type = &dict_type;
    AS_OBJECT(dict_obj)->refs = 0;

    dict_obj->size = size;

    // allocate space for entries
    dict_obj->entries = malloc(size * sizeof(dict_entry));

    return AS_OBJECT(dict_obj);
}

static object* dict_to_bool(object* obj) {

    assert(IS_DICT(obj));

    if (AS_DICT(obj)->size > 0) {
        return TYTHON_TRUE;
    }

    return TYTHON_FALSE;
}

static object* dict_values(object* self) {

    assert(IS_DICT(self));

    dict_object* dict_obj = AS_DICT(self);

    // the list to return
    list_object* list_obj = AS_LIST(list_create(dict_obj->size));

    for (int i = 0; i < dict_obj->size; ++i) {

        object* v = dict_obj->entries[i].value;

        GRAB_OBJECT(v); // the new list grabs a reference to the value in the dictionary
        list_obj->elements[i] = v;
    }

    return AS_OBJECT(list_obj);
}

static void dict_release(object* obj) {

    assert(IS_DICT(obj));

    dict_object* dict_obj = AS_DICT(obj);

    // only release elements if we are about to be freed!
    if (obj->refs == 1) {

        // release all the elements this dict references
        for (size_t i = 0; i < dict_obj->size; ++i) {

            dict_entry entry = dict_obj->entries[i];

            RELEASE_OBJECT(entry.key);
            RELEASE_OBJECT(entry.value);
        }

        free(dict_obj->entries);
    }

    // delegate the dict object to default release
    default_release(obj);
}

static number_functions dict_number_functions = {
        .to_bool = &dict_to_bool
};

static mapping_functions dict_mapping_functions = {
        .length     = &dict_length,
        .subscript  = &dict_subscript,
};

static builtin_method dict_methods[] = {
        { "values", &dict_values },
        { NULL, NULL }              // sentinel
};

type_object dict_type = {

        .obj_base = {
            .identity       = &dict_type.obj_base,
            .type           = &type_type,
            .refs           = 0,
        },

        .alloc              = &default_alloc,
        .seqalloc           = NULL,                 // todo: dict_create should be the seqalloc

        .base               = NULL,
        .instance_size      = sizeof(dict_object),
        .item_size          = sizeof(dict_entry),

        .rich_compare       = &dict_rich_compare,
        .str                = &dict_to_string,

        .number_functions   = &dict_number_functions,
        .mapping_functions  = &dict_mapping_functions,
        .sequence_functions = NULL,

        .create_iterator    = NULL,

        .methods            = dict_methods,

        .grab               = &default_grab,
        .release            = &dict_release,
};
