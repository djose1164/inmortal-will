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

#include "player.h"
#include "str.h"
#include "memory.h"


void Player_init(Player *self, const char *name)
{
    self = Player_new(self);
    CommonAtrrs *temp = &self->being.attrs;
    self->being.attrs.name = (char *)name;
    commonAtrrs_set_repr(temp, Str_fmt("Name: %s\n", commonAtrrs_get_name(temp)));
}

void Player_set_name(Player *const self, const char *name)
{
    if (!Str_is_valid(name))
        memory_die("Introduce a valid name!");
    //self->object.name = (char *)name;
}

/*****************************************************************************/
/*                                  Private functions:                       */
/*****************************************************************************/

static Player *Player_new(Player *self)
{
    self = memory_allocate_type(self, sizeof(Player), PLAYER);
    return self;
}