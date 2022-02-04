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
    if (list_head_is_NULL(l))
    {
        list_set_head(l, object);
        return;
    }

    // For each node, check if empty. If so, put the new list there, otherwise
    // continue searching.
    for_each_item(item, l)
    {
        if (!item->next)
        {
            item->next = list_init(item, object);
            break;
        }
    }
}

void linkedList_delete(LinkedList *l, List *target)
{
    List **before = list_find_indirect(l, target);
    *before = target->next;
    //printf("## temp: %p --- target->next: %p\n", temp, target->next);
    memory_release(target);
}

List *linkedList_find_by_value(LinkedList *l, void *value)
{
    for_each_item(item, l)
    {
        if (item->item == value)
            return item;
    }

    return NULL;
}

void linkedList_detroy(LinkedList *l)
{
    puts("Deleting list...");
    list_delete_all(l->head);
    puts("Deleting list... Done!");
}

/*****************************************************************************/
/*                                  Private functions:                       */
/*****************************************************************************/

static void list_delete_all(List *head)
{
    if (head && head->next)
        list_delete_all(head->next);

    memory_release(head->item);
    memory_release(head);
}

static List **list_find_indirect(const LinkedList *l, const List *target)
{
    List **current = &l->head;
    while ((*current) && (*current) != target)
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

    l->head = mem;
}

static List *list_init(List *new, void *item)
{
    new = malloc(sizeof *new);
    new->item = item;
    new->deleted = false;
    new->next = NULL;

    return new;
}