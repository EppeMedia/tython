//
// Created by manzi on 17/01/24.
//

#ifndef TYTHON_VARIABLE_H
#define TYTHON_VARIABLE_H

#include "value.h"

typedef struct variable_ {
    char* name;
    value_t* content;
} variable_t;

#endif //TYTHON_VARIABLE_H
