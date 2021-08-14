#include "core/memory.h"

static size_t memory_allocated_counter;
static size_t memory_release_counter;

void *memory_allocate(void *ptr, unsigned size)
{
    memory_is_free(ptr, "ptr no free");

    ptr = malloc(size);
    memory_check_allocation(ptr);

    ++memory_allocated_counter;
    return ptr;
}

void *memory_allocate_type(void *ptr, unsigned size, Type type)
{
    memory_is_free(ptr, "ptr no free");
    switch (type)
    {
    case PLAYER:
        /**
         * @brief Debo crear un node tipo player y agregarlo a la linked list.
         * El nuevo nudo sera agregado al final de la linked list.
         * 
         */
        
        break;
    
    default:
        break;
    }

}

void memory_release(void *ptr)
{
    memory_is_free(ptr, "Memory already freed!\n");

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
    SET_YELLOW;
    printf(
        "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
        "|Function: %-20s\t\tFrom: %-20s|"
        "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
        ,__FUNCTION__,__FILE__);

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
               "%s\n", errmsg);
    }

    RESET_COLOR;
}

void memoryGarbage_watch(LinkedList *l)
{
    List *current = l->head;
    for (; current; current = current->next)
    {
        
    }
}