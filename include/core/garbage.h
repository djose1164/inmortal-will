#ifndef GARBAGE_H
#define GARBAGE_H

#include "utils/list.h"

typedef LinkedList *Stack;

#define T Stack
extern T allocated_ptrs;

void garbage_add(void *ptr);

void garbage_cleanup(void);

static void stack_push(T stack, void* arg);

static void stack_destroy(T stack);

#endif /* GARBAGE_H */