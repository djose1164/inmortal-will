#include "../include/base.h"
#include "../include/memory.h"

void base_set_hp(struct Base *base, unsigned hp)
{
    //struct Player *self = (struct Player *)ptr;
    if (hp > 0)
        base->hp = hp;
}

struct Base *base_init(struct Base *base)
{
    base = memory_allocate(base, sizeof(struct Base));
    return base;
}

/*inline void base_check_string(const char *_s)
{
    if (_s == "")
        ;
}*/