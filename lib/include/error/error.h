//
// Created by manzi on 13/06/24.
//

#ifndef TYTHON_ERROR_H
#define TYTHON_ERROR_H

#include <stdint.h>

extern __thread int tython_errno;

#define set_tython_errno(err) (tython_errno = (err))
#define tython_errno (tython_errno)

#define TYTHON_ERROR_TYPE_ERROR         0xA1
#define TYTHON_ERROR_TYPE_MISMATCH      0xA2

/**
 * Sets the thread error code to TYTHON_ERROR_TYPE_ERROR and exits the process.
 */
void type_error();

/**
 * Sets the thread error code to TYTHON_ERROR_TYPE_MISMATCH and exits the process.<br>
 * <br>
 * This function does check if the encountered type does not match the expected type, but the process will be exited regardless.
 *
 * @param encountered_type The type encountered.
 * @param expected_type The expected type.
 */
void type_mismatch(int32_t encountered_type, int32_t expected_type);

#endif //TYTHON_ERROR_H
