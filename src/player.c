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
#include "../include/str.h"
#include "../include/memory.h"



void Player_set_name(struct Player *const self, const char *name)
{
    if (!Str_is_valid(name))
        memory_die("Introduce a valid name!");
    self->object.name = (char *)name;
}