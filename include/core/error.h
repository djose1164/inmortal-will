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

enum Error
{
    FAILED_MEMORY_ALLOCATION = 1,
    NULL_POINTER,
    ALLOCATIONS_GREATER,
    DEALLOCATIONS_GREATER,
};

extern enum Error current_error;

#define ERROR_DIE(msg) \
    error_die(msg, __FUNCTION__, __LINE__)

void error_die(const char *msg, const char *func, unsigned line);

//----------------------------------------------------------------------------
//                          Public methods.
//----------------------------------------------------------------------------

#endif // ERROR_H