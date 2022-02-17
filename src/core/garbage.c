#include "core/garbage.h"
#include "utils/linked_list.h"

static LinkedList l = {0};
Stack allocated_ptrs = &l;

void garbage_add(void *ptr)
{
    stack_push(allocated_ptrs, ptr);
}

void garbage_cleanup(void)
{
    stack_destroy(allocated_ptrs);
}

static void stack_push(Stack stack, void* arg)
{
    linkedList_push(stack, arg);
}

static void stack_destroy(Stack stack)
{
    linkedList_detroy(stack);
}