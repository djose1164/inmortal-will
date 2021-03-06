/**
 * @file memory.h
 * @author your name (you@domain.com)
 * @brief Declarations of all functions related to memory management.
 * @version 0.1
 * @date 2021-06-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef MEMORY_P_H
#define MEMORY_P_H

#include "core/garbage.h"
#include "utils/list.h"
#include "utils/utils.h"
#include "utils/terminal_colors.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

/**
 * @brief Kill the program and shows the reasion.
 * 
 */
#define memory_die(msg) (             \
    {                                 \
        fprintf(stderr, "%s\n", msg); \
        exit(-1);                     \
    })

/*****************************************************************************/
/* Public functions:                                                         */
/*****************************************************************************/

/**
 * @brief Get the counter's value.
 * 
 * @return size_t Times of memory allocated.
 */
extern size_t memory_get_allocated_counter(void);

/**
 * @brief Get the counter's value.
 * 
 * @return size_t Times of memory released.
 */
extern size_t memory_get_released_counter(void);

/**
 * @brief All method of allocation must call this function to set memory
 * somewhere.
 * 
 * @param ptr The pointer to assign a memory.
 * @param size The size to set. 
 */
void *memory_allocate(unsigned size);


/**
 * @brief Free memory. If the memory is already freed the program's gonna die.
 * 
 * @param ptr Pointer to somewhere memory.
 */
void memory_release(void **ptr);

/**
 * @brief Must be executed atexit. Will check if the management of memory was
 * good.
 * 
 */
void memory_check_counter(void);

#endif //MEMORY_P_H
