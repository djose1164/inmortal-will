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

enum Error
{
    FAILED_MEMORY_ALLOCATION = 1,
    NULL_POINTER,
    ALLOCATIONS_GREATER,
    DEALLOCATIONS_GREATER,
};

extern enum Error current_error;

#endif //ERROR_VARS_H
