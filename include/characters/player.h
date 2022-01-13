/**
 * @file player.h
 * @author Jose S. Daniel (djose1164@gmail.com)
 * @brief Preliminar object-base. This will follow the OOP style.
 * @version 0.1
 * @date 2021-04-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef PLAYER_H
#define PLAYER_H

#include "characters/player_vars.h"
#include "characters/living.h"
// #include "core/physics.h"
#include "utils/utils.h"

Player *player_init(const Living *living);

/**
 * @brief To eliminate an existing player.
 * 
 * @param self The player to remove.
 */
void player_del(Player *self);

void player_set_name(Player *const self, const char *name);

static inline char *player_get_name(Player *const self)
{
    return self->living_super->name;
}

void player_goto(Player *self);


/****************************************************************************/
/*                                   Private Functions.                     */
/****************************************************************************/

/**
 * @brief Set the given `texture` for the player `self`.
 * 
 * @param self Pointer to player.
 * @param texture Texture to set.
 */
static void player_set_texture(Player *const self, IW_Texture *texture);

static void player_bindfuncs(Player *const self);

static void player_update(Player *const self);

static void player_draw(const Player *self);

static void player_handle_input(Player *const self);

#endif // PLAYER_H
