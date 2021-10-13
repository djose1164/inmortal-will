/*
*----------------------------------------------------------------------------*
|               error.h     ---     Public Interface                         |
*----------------------------------------------------------------------------*
|   Public interface for error handling. Here's only functions declariations.|
|   For variables declaritions see error_vars.h.                             |
*----------------------------------------------------------------------------*
*/

#ifndef ERROR_H
#define ERROR_H

#include "error_vars.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//----------------------------------------------------------------------------
//                          Public methods.
//----------------------------------------------------------------------------

/**
 * @brief Get the meaning of the code.
 * 
 * @param code Error code.
 * @return char* The code's meaning.
 */
char * err_code_string(enum ErrCode code);

/*      Private.        */

/**
 * @brief Check if the given code is valid.
 * 
 * @param code The error code.
 * @return true The code is valid.
 * @return false The code is invalid.
 */
static bool err_code_is_valid(unsigned code);

/**
 * @brief Show a message and die.
 * 
 * @param errmsg Message describing the reason.
 */
static void err_die(char *errmsg);

#endif //ERROR_H