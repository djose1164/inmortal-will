#ifndef UTILS_H
#define UTILS_H

#include "utils/list.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define in ,

/**
 * @brief Will run through the linked list until find a NULL pointer. 
 * 
 * @example for_each_item(i, l)
 *              printf("%d\n", i->value);
 * 
 * @param item Var that will be use for each iteration.
 * @param l The linked list.
 * 
 * TODO: Add more abstraction/polymorphism.
 */
#define for_each_item(item, l) \
    for (List * (item) = (l)->head; (item); (item) = (item)->next)

/**
 * @brief Go through all item of a given array.
 * 
 * @param item Var that will be use for each iteration.
 * @param array Array to go through.
 */
#define for_each(item, array)                           \
    for (int keep = 1, count = 0,                       \
             size = sizeof((array)) / sizeof(*(array)); \
         keep && count != size;                         \
         keep = !keep, ++count)                         \
        for (typeof(*(item)) = (array) + count; keep; keep = !keep)

static inline void utils_clear_terminal(void)
{
    fflush(stdout);
    system("clear||cls");
}

static inline void utils_append_cwd(char *restrict buf, const char *restrict rpath, size_t size)
{
    getcwd(buf, size);
    strncat(buf, rpath, size);
}

/**
 * @brief Check weather the file exists or not.
 * 
 * @param fname Relative path to file.
 * @return true The file exists.
 * @return false The file does not exist.
 */
static inline bool utils_file_exists(const char *fname)
{
    char buf[512];
    utils_append_cwd(buf, fname, sizeof buf);
    if (access(buf, F_OK))
        return true;
    return false;
}

#endif //UTILS_H
