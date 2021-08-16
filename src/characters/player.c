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

#include "player.h"

LinkedList player_list = {.head = NULL};

Player *Player_init(Player *self, const char *name)
{
    self = memory_allocate(self, sizeof(Player));

    CommonAtrrs *temp = &self->being.attrs;
    temp->name = (char *)name;
    commonAtrrs_set_repr(temp, Str_fmt("Name: %s.", commonAtrrs_get_name(temp)));

    return self;
}

void Player_del(Player *self)
{
    // If repr was setted, release it.
    if (self->being.attrs.repr)
        memory_release(self->being.attrs.repr);

    // Finally release the memory.
    memory_release(self);
}

void Player_set_name(Player *const self, const char *name)
{
    //if (!Str_is_valid(name))
    //    memory_die("Introduce a valid name!");
    //self->object.name = (char *)name;
}

void Player_draw(const Player *self)
{
    Rectangle rec = {
        .x = 0,
        .y = 0,
        .width = self->skin.width,
        .height = self->skin.height};

    DrawTextureRec(self->skin, rec, self->vector2D, WHITE);
}

void Player_goto(Player *self)
{
    const unsigned short multiplier = 4U;
    graphics_check_bound_limits(self);    

    if (IsKeyDown(KEY_A))
        self->vector2D.x -= multiplier;
    if (IsKeyDown(KEY_D))
        self->vector2D.x += multiplier;
    if (IsKeyDown(KEY_W))
        self->vector2D.y -= multiplier;
    if (IsKeyDown(KEY_S))
        self->vector2D.y += multiplier;

    printf("## %d --- %d\n", self->vector2D.x, GetScreenWidth());
}

/*****************************************************************************/
/*                                  Private functions:                       */
/*****************************************************************************/
