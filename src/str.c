#include "str.h"

const char *Str_fmt(const char *_s, ...)
{
    va_list args;
    va_start(args, _s);

    char *buf = NULL;
    int n = vsnprintf(NULL, 0, _s, args);
    
    va_end(args);
    
    if (n >= 0)
    {
        va_start(args, _s);
        buf = memory_allocate((void *)buf, n + 1);
        if (buf)
            vsnprintf(buf, n + 1, _s, args);
        va_end(args);
    }
    
    return buf;
}