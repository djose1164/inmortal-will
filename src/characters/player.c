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

#include "characters/player.h"

LinkedList player_list = {.head = NULL};
static const unsigned multiplier = 4;

Player *player_init(const Living *living)
{
    puts("Creating player...");
    Player *self = memory_allocate(self, sizeof *self);
    self->living_super = living;
    player_bindfuncs(self);
    puts("Creating player... Done!");
    return self;
}

void player_del(Player *self)
{
    puts("Deleting player...");
    self->living_super->del(self->living_super);
    memory_release(self);
    puts("Deleting player... Done");
}

void player_set_name(Player *const self, const char *name)
{
    //if (!Str_is_valid(name))
    //    memory_die("Introduce a valid name!");
    self->living_super->name = (char *)name;
}

static void player_draw(const Player *self)
{
    self->living_super->draw(self->living_super);
}

static void player_update(Player *const self)
{
    player_handle_input(self);
}

/*****************************************************************************/
/*                                  Private functions:                       */
/*****************************************************************************/

void player_set_texture(Player *self, IW_Texture *texture)
{
    self->living_super->frame->bind_texture(self->living_super->frame, texture);
    puts("Skin loaded!");
}

static void player_bindfuncs(Player *const self)
{
    self->init = player_init;
    self->set_texture = player_set_texture;
    self->set_name = player_set_name;
    self->update = player_update;
    self->draw = player_draw;
    self->del = player_del;
}

static void player_handle_input(Player *const self)
{
    static int counter = 0, current_frame = 1;
    Frame *frame = self->living_super->frame;
    unsigned width = (float)frame->get_texture_width(frame);
    bool condition = IsKeyDown(KEY_A) || IsKeyDown(KEY_D) || IsKeyDown(KEY_W)
                     || IsKeyDown(KEY_S);
    counter++;
    if (condition)
    {
        if (counter >= GetFPS() / multiplier)
        {
            counter = 0;
            current_frame++;
            if (current_frame >= 3)
                current_frame = 1;

            frame->rectangle.x = (float)current_frame * (width / 3);
        }
    }
    else
        frame->rectangle.x = 0;

    if (IsKeyDown(KEY_A))
        frame->position.x -= multiplier;
    if (IsKeyDown(KEY_D))
        frame->position.x += multiplier;
    /* Jump stuff. */
}
