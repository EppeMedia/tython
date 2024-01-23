//
// Created by manzi on 20/01/24.
//

#ifndef TYTHON_DICTIONARY_H
#define TYTHON_DICTIONARY_H

#include "object.h"
#include "type.h"
#include "inttypes.h"

type dictionary_type;

typedef struct dictionary_entry_t {
    ObjectHead
    object* key;
    object* value;
} dictionary_entry;

typedef struct dictionary_t {
    ObjectHead
    dictionary_entry* entries;
    int64_t entries_length;
} dictionary;

#endif //TYTHON_DICTIONARY_H
