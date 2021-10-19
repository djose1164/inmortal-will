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

#define EXPAND_AS_ENUMERATION(a, b) a,
#define EXPAND_AS_MEANING(a, b) b,
#define ERROR_TABLE(X)                                      \
    X(FAILED_MEMORY_ALLOCATION, "Failed memory allocation") \
    X(NULL_POINTER, "Null pointer")                         \
    X(ALLOCATIONS_GREATER, "Allocations greater")           \
    X(DEALLOCATIONS_GREATER, "Deallocations greater")

enum ErrCode
{
    ERROR_TABLE(EXPAND_AS_ENUMERATION)
        ERRCODE_LAST
};

char *err_string_list[ERRCODE_LAST] = {
    ERROR_TABLE(EXPAND_AS_MEANING)

};

extern enum ErrCode current_error;

#endif //ERROR_VARS_H
