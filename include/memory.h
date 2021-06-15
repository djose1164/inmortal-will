#ifndef MEMORY_H
#define MEMORY_H

#include <stdio.h>
#include <stdbool.h>

#define memory_check_allocation(ptr) (             \
    {                                              \
        if (!ptr)                                  \
        {                                          \
            memory_die("Couldn't assign memory."); \
        }                                          \
    })

#define memory_die(msg) (             \
    {                                 \
        fprintf(stderr, "%s\n", msg); \
        exit(-1);                     \
    })

extern size_t memory_get_allocated_counter(void);
extern size_t memory_get_realased_counter(void);

/*****************************************************************************/
/* Public functions:                                                         */
/*****************************************************************************/

/**
 * @brief All method of allocation must call this function to set memory
 * somewhere.
 * 
 * @param ptr The pointer to assign a memory.
 * @param size The size to set. 
 */
void *memory_allocate(void *ptr, unsigned size);

/**
 * @brief Check if the memory pointed to is free or not. If yes, cannot be 
 * freed.
 * 
 * @param ptr Pointer to some memory.
 * @return true Points to some allocated memory. Can be realased.
 * @return false Points to nothing. Cannot be realased.
 */
bool memory_is_free(void *ptr);

void memory_release(void *ptr);

void memory_check_counter(void);

//inline void s(void *ptr);
//inline void
#endif //MEMORY_H
