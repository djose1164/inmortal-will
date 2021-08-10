#ifndef UTILS_H
#define UTILS_H
#include <stdlib.h>
#include <stdio.h>

static inline void utils_clear_terminal(void)
{
    fflush(stdout);
    system("clear||cls");
}

#endif //UTILS_H
