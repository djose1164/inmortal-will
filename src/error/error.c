//----------------------------------------------------------------------------
// Implementation for handling errors.
//----------------------------------------------------------------------------

#include "error/error.h"

char *err_code_string(enum ErrCode code)
{
    switch (code)
    {
#define X(errcode, errmean) \
    case errcode:           \
        return errmean;
        ERROR_TABLE(X)
#undef X
    }

    return NULL;
}

/*      Private.        */

static void err_die(char *errmsg)
{
    fprintf(stderr, "%s\n", errmsg);
    exit(-1);
}

int main(void)
{
    enum ErrCode errcode = FAILED_MEMORY_ALLOCATION;
    printf("Error: %s\n", err_code_string(errcode));
    return 0;
}
