/**
 * @file linked_list.c
 * @author Jose S. Daniel (djose1164@gmail.com)
 * @brief Definition of the methods of linked list.
 * @version 0.1
 * @date 2021-08-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "utils/linked_list.h"


// TODO: Check implemention of indirect for push.

void linkedList_push(LinkedList *l, void *object)
{
    // TODO: Review this.
    List *current;
    if (list_head_is_NULL(l))
    {
        list_set_head(l, object);
        return;
    }

    // For each node, check if empty. If so, put the new list there, otherwise
    // continue searching.
    current = l->head;
    while (current->next)
        current = current->next;
    current->next = list_init(current->next, object);
}


void linkedList_delete(LinkedList *l, List *target)
{
    List **before = list_find_indirect(l, target);
    List *temp = *before;
    *before = target->next;
    printf("## aout\n");
    list_delete(temp);
}

List *linkedList_find_by_value(LinkedList *l, void *value)
{
    List *current = l->head;
    bool found = false;
    // While current isn't null and value diffrent, keep searching.
    while (current)
    {
        if (current->item == value)
            found = true;
        if (found)
            return current;
        current = current->next;
    }

    return NULL;
}

/*****************************************************************************/
/*                                  Private functions:                       */
/*****************************************************************************/

static void list_delete(List *target)
{
    memory_release(target);
}

static List **list_find_indirect(const LinkedList *l, const List *target)
{
    List **current = &l->head;
    if ((*current) == target)
        return current;

    while ((*current) && (*current)->next != target)
        current = &(*current)->next;
    return current;
}

static bool list_head_is_NULL(const LinkedList *l)
{
    if (l->head)
        return false;

    return true;
}

static void list_set_head(LinkedList *l, void *object)
{
    List *mem = list_init(mem, object);
    mem->item = object;
    mem->delete = false;

    l->head = mem;
}

static List *list_init(List *new, void *item)
{
    new = memory_allocate(new, sizeof(List));
    new->item = item;
    new->delete = false;
    new->next = NULL;

    return new;
}