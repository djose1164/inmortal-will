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

#include "include/object.h"
#include "../include/memory.h"

/**
 * @brief Struct with the basic information of a player.
 * It's following the style of a RPG.
 * 
 */
struct Player
{
    struct Object object;
    char *profession;
};

typedef struct Player Player;

/**
 * @brief To create a new player. Further parameters will be passed to the 
 * constructor.
 * 
 * @param self The object to create.
 * @return Player* The new memory allocated.
 */
extern Player *Player_init(Player *self);

/**
 * @brief To eliminate an existing player.
 * 
 * @param self The player to remove.
 */
static inline void Player_del(Player *const self)
{
    memory_release(self);
};

void Player_set_name(Player *const self, const char *name);

static inline char *Player_get_name(Player *const self)
{
    return self->object.name;
}

#endif // PLAYER_H