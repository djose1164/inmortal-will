#ifndef STR_H
#define STR_H

#include <stdbool.h>
#include <string.h>

static inline bool Str_is_empty(const char *_s)
{
    return _s == "" ? true : false;
}

static inline bool Str_start_space(const char *_s)
{
    return _s[0] == ' ' ? true : false;
}

static inline bool Str_valid_length(const char *_s)
{
    return strlen(_s) < 25 ? true : false;
}

static inline bool Str_is_valid(const char *_s)
{
    return !Str_is_empty(_s) && !Str_start_space(_s) && Str_valid_length(_s)
               ? true
               : false;
}

const char *Str_fmt(const char *_s, ...);

#endif //STR_H
