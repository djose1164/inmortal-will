#include "../include/base.h"
#include "../include/player.h"

void set_hp(struct Player *self, unsigned hp)
{
    if (hp > 0)
    {
        self->base->hp = hp;
    }
    else
    {
        fprintf(stderr, "Can't assignt negative value to HP.");
        exit(-1);
    }
}