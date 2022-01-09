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
#ifndef player_H
#define player_H

#include "characters/player_vars.h"
#include "core/physics.h"

/**
 * @brief To eliminate an existing player.
 * 
 * @param self The player to remove.
 */
void player_del(Player *self);

void player_set_name(Player *const self, const char *name);

static inline char *player_get_name(Player *const self)
{
    return self->being.attrs.name;
}

void player_draw(const Player *self);

void player_goto(Player *self);

/****************************************************************************/
/*                                   Private Functions.                     */
/****************************************************************************/

Player *player_init(Player *self, const char *name);
#endif // player_H
