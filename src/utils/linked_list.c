#include "utils/linked_list.h"

void linkedList_add(LinkedList *l, List *list)
{
    List *current = l->head;
    for (; current; current = current->next);
    current = list;
}

void list_init(List *new, void *item)
{
    new = memory_allocate(new, sizeof(new));
    new->item = item;
    new->next = NULL;
}


/*****************************************************************************/
/*                                  Private functions:                       */
/*****************************************************************************/

static void list_delete(LinkedList *l, List *target, Type type)
{
    List **current = &l->head;
    while ((*current) != target)
        *current = (*current)->next;
    *current = target->next;
}

static List *list_new(List *new)
{
    List *mem = memory_allocate(mem, sizeof(List));
    return mem;
}

static void linkedList_add_player(LinkedList *l, List *list)
{

}

static void linkedList_add_monster(LinkedList *l, List *list)
{
    
}