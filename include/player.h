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

#include "living.h"
#include "utils/linked_list.h"

/**
 * @brief Struct with the basic information of a player.
 * It's following the style of a RPG.
 * 
 */
struct Player
{
    Living being;
    char *profession;
};
typedef struct Player Player;

/* Player's linked list. */
extern LinkedList player_list;

/**
 * @brief To eliminate an existing player.
 * 
 * @param self The player to remove.
 */
void Player_del(Player *self);

void Player_set_name(Player *const self, const char *name);

static inline char *Player_get_name(Player *const self)
{
    return self->being.attrs.name;
}

/****************************************************************************/
/*                                   Private Functions.                     */
/****************************************************************************/

Player *Player_init(Player *self, const char *name);
#endif // PLAYER_H
