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

#define NUMS_OF_FRAME 2

Player *player_init(const Base *living)
{
    puts("Creating player...");
    Player *self = memory_allocate(sizeof *self);
    const unsigned frame_height = living->frame->get_texture_height(living->frame);
    living->frame->rectangle.height = frame_height / NUMS_OF_FRAME;
    self->base_super = living;
    self->laser = weapon_create_lasers(MAX_NUMS_OF_LASER);
    self->attacking = false;
    player_bindfuncs(self);
    puts("Creating player... Done!");
    return self;
}

void player_del(Player *self)
{
    puts("Deleting player...");
    self->base_super->del(self->base_super);
    memory_release(self);
    puts("Deleting player... Done");
}

void player_set_name(Player *const self, const char *name)
{
    //if (!Str_is_valid(name))
    //    memory_die("Introduce a valid name!");
    self->base_super->name = (char *)name;
}

static void player_draw(const Player *self)
{
    puts("Player drawing...");
    assert(self);
    self->base_super->draw(self->base_super);
    assert(self->laser);
    weapon_draw_lasers(self->laser);
    puts("Player drawing... Done!");
}

static void player_update(Player *const self)
{
    player_handle_input(self);
    if (self->base_super->attacking)
        weapon_update_lasers(self->base_super->laser);
}

/*****************************************************************************/
/*                                  Private functions:                       */
/*****************************************************************************/

void player_set_texture(Player *self, IW_Texture *texture)
{
    self->base_super->frame->bind_texture(self->base_super->frame, texture);
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
    Frame *frame = self->base_super->frame;
    unsigned height = (float)frame->get_texture_height(frame);
    bool condition = IsKeyDown(KEY_A) || IsKeyDown(KEY_D) || IsKeyDown(KEY_W) || IsKeyDown(KEY_S);
    counter++;
    if (condition)
    {
        // if (counter >= GetFPS() / multiplier)
        // {
        //     counter = 0;
        //     current_frame++;
        //     if (current_frame > 2)
        //         current_frame = 1;

        //     frame->rectangle.y = (float)current_frame * (height / 2);
        // }
        frame->rectangle.y = (float)height / 2;
    }
    else
        frame->rectangle.y = 0;

    if (IsKeyDown(KEY_A))
        frame->position.x -= multiplier;
    if (IsKeyDown(KEY_D))
        frame->position.x += multiplier;
    if (IsKeyDown(KEY_W))
        frame->position.y -= multiplier;
    if (IsKeyDown(KEY_S))
        frame->position.y += multiplier;
    if (IsKeyReleased(KEY_J))
        player_attack(self);
    /* Jump stuff. */
}