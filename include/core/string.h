#ifndef string_H
#define string_H

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <raylib.h>
#include <assert.h>

typedef struct String String;
struct String
{
    
    const char *str;
    unsigned len;

    const char *(*to_upper)(const String *self);
    const char *(*to_lower)(const String *self);
    bool (*is_equal)(const String *self, const String *str);
    bool (*is_empty)(const String *self);
    bool (*starts_with_space)(const String *self);
    void (*del)(String *self);
};

String *string_init(const char *str);

void print(const String *str, ...);

/****************************************************************************/
/*                                   Private Functions.                     */
/****************************************************************************/

static void string_bindfuncs(String *const self);

static bool string_is_empty(const char *_s);

static bool string_is_equal(const String *self, const String *str);

static String *string_to_upper(const String *self);

static String *string_to_lower(const String *self);

static void string_del(String *self);

static bool string_starts_with_space(const char *_s);

const char *string_fmt(const char *_s, ...);

#endif //string_H
