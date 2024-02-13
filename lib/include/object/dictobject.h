//
// Created by manzi on 07/02/24.
//

#ifndef TYTHON_DICTOBJECT_H
#define TYTHON_DICTOBJECT_H

#include "object.h"
#include "type.h"

extern type_object dict_type;

/**
 * Entries are owned by a dictionary. They should not outlive the dictionary they are a member of.
 */
typedef struct dict_entry_t {
    object* key;
    object* value;
} dict_entry;

typedef struct dict_object_t {

    ObjectHead;

    size_t size;
    dict_entry* entries;

} dict_object;

#define IS_DICT(obj) (AS_OBJECT(obj)->type == &dict_type)
#define AS_DICT(obj) ((dict_object*)(obj))

/**
 * Creates a new dictionary object, provisioning for {size} entries.
 * @param size The initial entry capacity of the dictionary.
 * @return Returns a newly instantiated dictionary object, with a capacity of {size} entries.
 */
object* dict_create(size_t size);

#endif //TYTHON_DICTOBJECT_H
