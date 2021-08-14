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
#ifndef MEMORY_H
#define MEMORY_H

#include <stdio.h>
#include <stdbool.h>
#include "utils/linked_list.h"
#include "utils/utils.h"
#include "utils/terminal_colors.h"
#include "common_atrrs.h"

/**
 * @brief Verify that the allocation was successful. If wasn't, the program
 * will die.
 * 
 */
#define memory_check_allocation(ptr) (             \
    {                                              \
        if (!ptr)                                  \
        {                                          \
            memory_die("Couldn't assign memory."); \
        }                                          \
    })

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
void *memory_allocate(void *ptr, unsigned size);

/**
 * @brief Create an specific type of object.
 * 
 * @param ptr The pointer to assign memory.
 * @param size The size to be setted.
 * @param type The type of object to create.
 * @return void* Return the memory allocated.
 */
void *memory_allocate_type(void *ptr, unsigned size, Type type);

/**
 * @brief Check if the memory pointed to is free or not. If yes, cannot be 
 * freed.
 * 
 * @param ptr Pointer to some memory.
 * @return true Points to some allocated memory. Can be released.
 * @return false Points to nothing. Cannot be released.
 */
static inline void memory_is_free(void *ptr, const char *errmsg)
{
    if (!ptr)
        memory_die(errmsg);
}

/**
 * @brief Free memory. If the memory is already freed the program's gonna die.
 * 
 * @param ptr Pointer to somewhere memory.
 */
void memory_release(void *ptr);

/**
 * @brief Must be executed atexit. Will check if the management of memory was
 * good.
 * 
 */
void memory_check_counter(void);

/**
 * @brief Look up for any node that needs to be deallocated.
 * 
 */
void memoryGarbage_watch(LinkedList *l);
#endif //MEMORY_H
