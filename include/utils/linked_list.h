#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../memory.h"

typedef struct LinkedList LinkedList;
typedef struct List List;

struct LinkedList
{
    List *head;
};

struct List
{
    void *item;
    List *next;
};

/**
 * @brief Add a new list to the end of linked list.
 * 
 * @param head The linked list' head.
 * @param l The list to add.
 */
void linkedList_add(LinkedList *l, List *list);

/**
 * @brief Delete the entire linked list inclunding all its nodes.
 * 
 * @param head The linked list to be deleted.
 */
void linkedList_detroy(LinkedList *head);

List *list_new(void *item);

// ---------------------------------------------------------------------------
//                                   Private methods
// ---------------------------------------------------------------------------

/**
 * @brief Delete the given list.
 * 
 * @param list The list to be deleted.
 */
static void list_delete(LinkedList *l, List *target);

/**
 * @brief Initialize a list.
 * 
 * @param target The list to be init.
 * @param item The list's value.
 */
static void list_init(List *target, void *item);
#endif //LINKED_LIST_H
