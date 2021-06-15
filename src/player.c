/**
 * @file player.c
 * @author your name (you@domain.com)
 * @brief Defefinition of player.h. All methods that modify or work with player
 * must be here.
 * @version 0.1
 * @date 2021-06-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdlib.h>

#include "../include/player.h"
#include "../include/memory.h"

extern inline struct Player *Player_init(struct Player *self)
{
    self = memory_allocate(self, sizeof(struct Player));
    return self;
}

void Player_del(struct Player *const self)
{
    if (self)
        free(self);
}