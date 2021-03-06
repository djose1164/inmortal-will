#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "utils/list.h"

/**
 * @brief Add a new list to the end of linked list.
 * 
 * @param l The linked list.
 * @param object The object to keep track of.
 */
void linkedList_push(LinkedList *l, void *object);

/**
 * @brief Delete the passed list.
 * 
 * @param l The linked list.
 * @param target List to delete.
 */
void linkedList_delete(LinkedList *l, List *target);

/**
 * @brief Delete the entire linked list inclunding all its nodes.
 * 
 * @param l The linked list to be deleted.
 */
void linkedList_detroy(LinkedList *l);

/**
 * @brief Return the list if was found, NULL otherwise.
 * 
 * @param l The linked list.
 * @param value The value to search -a pointer-.
 * @return List* Resturn the list if found, otherwise NULL.
 */
List *linkedList_find_by_value(LinkedList *l, void *value);

/****************************************************************************/
/*                                   Private Functions.                     */
/****************************************************************************/

static void list_delete_all(List *head);

/**
 * @brief Initialize a new list.
 * 
 * @param item The list's value.
 */
static List *list_init(List *new, void *item);

static List **list_find_indirect(const LinkedList *l, const List *target);

static bool list_head_is_NULL(const LinkedList *l);

static void list_set_head(LinkedList *l, void *object);
#endif //LINKED_LIST_H
