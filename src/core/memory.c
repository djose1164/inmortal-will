#include "core/memory.h"

static LinkedList allocated_ptrs = { .head = NULL };

static size_t memory_allocated_counter;
static size_t memory_release_counter;

void *memory_allocate(void *ptr, unsigned size)
{
    //memory_is_free(ptr, "ptr no free");
    ptr = malloc(size);
    memory_check_allocation(ptr);
    linkedList_push(&allocated_ptrs, ptr);
    ++memory_allocated_counter;
    return ptr;
}

void *memory_allocate_type(void *ptr, Type type)
{
    //memory_is_free(ptr, "ptr no free");
    switch (type)
    {
    case PLAYER:
        /**
         * @brief Debo crear un node tipo player y agregarlo a la linked list.
         * El nuevo nudo sera agregado al final de la linked list.
         * 
         */
        ptr = memory_allocate_p(ptr, sizeof(Player));
        linkedList_push(&player_list, ptr);
        break;
    
    case LIST:
        ptr = memory_allocate_p(ptr, sizeof(List));

    default:
        break;
    }
}

static void *memory_allocate_p(void *ptr, unsigned size)
{
    //memory_is_free(ptr, "ptr no free");
    ptr = malloc(size);
    memory_check_allocation(ptr);

    ++memory_allocated_counter;
    return ptr;
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

void memoryGarbage_watch(LinkedList *l, Type type)
{
    switch (type)
    {
    case PLAYER:
        memoryGarbage_watch_player(l);
        break;

    default:
        break;
    }
}

static void memoryGarbage_watch_player(LinkedList *player_list)
{
    List *current = player_list->head;
    while (current)
    {
        if (current->delete)
        {
            List *temp = current->next;
            player_del(current->item);
            linkedList_delete(player_list, current);
            current = temp;
        }
        else
            current = current->next;
    }
}

void memoryGarbage_atexit(void)
{
    linkedList_detroy(&allocated_ptrs);
}