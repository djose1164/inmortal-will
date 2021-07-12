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

#include "../include/base.h"
#include "../include/memory.h"

/**
 * @brief Struct with the basic information of a player.
 * It's following the style of a RPG.
 * 
 */
struct Player
{
    struct Base *base;
    char *profession;
};

/**
 * @brief To create a new player. Further parameters will be passed to the 
 * constructor.
 * 
 * @param self The object to create.
 * @return struct Player* The new memory allocated.
 */
struct Player *Player_init(struct Player *self);

/**
 * @brief To elimante an existing player.
 * 
 * @param self The player to remove.
 */
inline void Player_del(struct Player *const self)
{
    memory_release(self);
};

void Player_set_name(struct Player *const self, const char *_s);

static inline char *Player_get_name(struct Player *const self)
{
    return self->base->name;
}

#endif // PLAYER_H