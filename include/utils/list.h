#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

struct List
{
    void *item;
    struct List *next;
    bool deleted;
};
typedef struct List List;

struct LinkedList
{
    List *head;
};
typedef struct LinkedList LinkedList;

#endif //LIST_H
