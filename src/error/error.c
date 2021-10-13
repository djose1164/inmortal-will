//----------------------------------------------------------------------------
// Implementation for handling errors.
//----------------------------------------------------------------------------

#include "error/error.h"

char *err_code_string(enum ErrCode code)
{
    if (!err_code_is_valid(code))
        err_die("The given code is not valid. Closing...");
    
    return err_string_list[code];
}

/*      Private.        */

static bool err_code_is_valid(unsigned code)
{
    if (code < ERRCODE_LAST)
        return true;
    return false;
}

static void err_die(char *errmsg)
{
    fprintf(stderr, "%s\n", errmsg);
    exit(-1);
}

int main(void)
{
    printf("Error: %s\n", err_code_string(1));
    return 0;
}
