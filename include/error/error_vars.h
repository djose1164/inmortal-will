/*
*----------------------------------------------------------------------------*
|               error_vars.h     ---     Public Interface                    |
*----------------------------------------------------------------------------*
|   Public interface for error variables. Here's only functions declariations|
|   For functions declaritions see error.h.                                  |
*----------------------------------------------------------------------------*
*/

#ifndef ERROR_VARS_H
#define ERROR_VARS_H

enum ErrCode
{
    FAILED_MEMORY_ALLOCATION,
    NULL_POINTER,
    ALLOCATIONS_GREATER,
    DEALLOCATIONS_GREATER,
    ERRCODE_LAST
};

char *err_string_list[ERRCODE_LAST] = {
    "Failed memory allocation",
    "Null pointer",
    "Allocations greater",
    "Deallocations greater",
};

extern enum ErrCode current_error;

#endif //ERROR_VARS_H
