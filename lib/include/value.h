//
// Created by manzi on 17/01/24.
//

#ifndef TYTHON_VALUE_H
#define TYTHON_VALUE_H

typedef struct value_ {
    char type;
    void* content;
} value_t;

#endif //TYTHON_VALUE_H
