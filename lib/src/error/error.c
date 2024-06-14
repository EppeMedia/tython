//
// Created by manzi on 13/06/24.
//

#include <stdlib.h>
#include <stdio.h>
#include "error/error.h"

__thread int tython_errno;

void type_error() {

    set_tython_errno(TYTHON_ERROR_TYPE_ERROR);

    fprintf(stderr, "\033[0;31m"); // Set STDERR to print in red
    fprintf(stderr, "TypeError!\r\n");
    fprintf(stderr, "\033[0m"); // Reset STDERR to its default color

    exit(tython_errno);
}

void type_mismatch(int32_t encountered_type, int32_t expected_type) {

    set_tython_errno(TYTHON_ERROR_TYPE_MISMATCH);

    fprintf(stderr, "\033[0;31m"); // Set STDERR to print in red

    if (encountered_type == expected_type) {

        // strange to throw a type error for a matching type, but OK...
        fprintf(stderr, "TypeError: type mismatch for types of queal tag [%u]!\r\n", expected_type);

    } else {


        if (encountered_type >= 0 && encountered_type < 3 && expected_type >= 0 && expected_type < 3) {

            char* labels[] = { "Integer", "Float", "Object" };
            fprintf(stderr, "TypeError: type mismatch! Expected type [%s], but the encountered type is [%s].\r\n", labels[expected_type], labels[encountered_type]);

        } else {

            fprintf(stderr, "TypeError: mismatch in unknown types!\r\n");
        }
    }

    fprintf(stderr, "\033[0m"); // Reset STDERR to its default color

    exit(tython_errno);
}
