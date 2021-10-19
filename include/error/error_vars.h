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

#define ERROR_TABLE                                         \
    X(FAILED_MEMORY_ALLOCATION, "Failed memory allocation") \
    X(NULL_POINTER, "Null pointer")                         \
    X(ALLOCATIONS_GREATER, "Allocations greater")           \
    X(DEALLOCATIONS_GREATER, "Deallocations greater")

enum ErrCode
{
#define X(errname, b) errname,
    ERROR_TABLE
#undef X
        ERRCODE_LAST
};

char *err_string_list[ERRCODE_LAST] = {
#define X(a, errmean) errmean,
    ERROR_TABLE
#undef X
};

extern enum ErrCode current_error;

#endif //ERROR_VARS_H
