//
// Created by manzi on 20/01/24.
//

#ifndef TYTHON_DICTIONARYOBJECT_H
#define TYTHON_DICTIONARYOBJECT_H

#include "object.h"
#include "type.h"
#include "inttypes.h"

extern type_object dictionary_type;

typedef struct dictionary_entry_t {
    ObjectHead

    object* key;
    object* value;

} dictionary_entry;

typedef struct dictionary_t {
    ObjectHead

    dictionary_entry* entries;
    int64_t entries_length;

} dictionary_object;

#endif //TYTHON_DICTIONARYOBJECT_H
