#include <stdlib.h>
#include "../include/memory.h"

static size_t memory_allocated_counter;
static size_t memory_release_counter;

void *memory_allocate(void *ptr, unsigned size)
{
    if (memory_is_free(ptr))
        memory_die("ptr no free\n");

    ptr = malloc(size);
    memory_check_allocation(ptr);

    ++memory_allocated_counter;
    return ptr;
}


void memory_release(void *ptr)
{
    if (!memory_is_free(ptr))
        memory_die("Memory already freed!\n");

    free(ptr);
    ptr = NULL;

    ++memory_release_counter;
}

size_t memory_get_allocated_counter(void)
{
    return memory_allocated_counter;
}

size_t memory_get_released_counter(void)
{
    return memory_release_counter;
}

void memory_check_counter(void)
{
    if (memory_allocated_counter == memory_release_counter)
    {
        printf("No problem!\n");
    }
    else
    {
        char errmsg[50];
        snprintf(errmsg, sizeof(errmsg), "Allocated: %zu.\tReleased: %zu\n",
                 memory_allocated_counter, memory_release_counter);
    }
}