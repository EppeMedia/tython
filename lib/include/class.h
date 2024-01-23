//
// Created by manzi on 17/01/24.
//

#ifndef TYTHON_CLASS_H
#define TYTHON_CLASS_H

#include "builtin/dictionary.h"
#include <inttypes.h>

typedef struct class_t {
    char* name;
    struct class_t* base;
    dictionary attributes;
} class_;

#endif //TYTHON_CLASS_H
