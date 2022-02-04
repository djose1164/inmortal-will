#include "core/error.h"
#include <stdio.h>
#include <stdlib.h>

void error_die(const char *msg, const char *func, unsigned line)
{
    fprintf(stderr, "%s():%d --- %s\n", func, line, msg);
    fflush(stderr);
    exit(0);    
}