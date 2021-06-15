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

/**
 * @brief Struct with the basic information of a player.
 * It's following the style of a RPG.
 * 
 */
struct Player
{
    struct Base *base;
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
void del(struct Player *const self);

#endif // PLAYER_H