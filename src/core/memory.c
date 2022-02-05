#include "core/memory_p.h"
#include <stdlib.h>

static size_t memory_allocated_counter;
static size_t memory_release_counter;

void *memory_allocate(unsigned size)
{
    if (size < 1)
        memory_die("Invalid size at memory_allocate()");

    void *ptr = malloc(size);
    assert(ptr);
    memset(ptr, 0, sizeof *ptr);
    ++memory_allocated_counter;
    return ptr;
}

void memory_release(void **ptr)
{
    if (*ptr)
    {
        free(*ptr);
        *ptr = NULL;
        ++memory_release_counter;
    }
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
    SET_YELLOW;
    printf(
        "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
        "|Function: %-20s\t\tFrom: %-20s|"
        "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n",
        __FUNCTION__, __FILE__);

    if (memory_allocated_counter == memory_release_counter)
    {
        printf("There's no leak problem!\n");
    }
    else
    {
        char errmsg[50];
        snprintf(errmsg, sizeof(errmsg), "Allocated: %zu.\tReleased: %zu.\n",
                 memory_allocated_counter, memory_release_counter);

        SET_RED;
        printf("Leak of memory found, getting details...\n\n"
               "%s\n",
               errmsg);
    }

    RESET_COLOR;
}