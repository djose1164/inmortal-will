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
struct Player;

/**
 * @brief The virtual method for the player.
 * 
 */
struct vtable_Player
{
    // I love Python. Create a new player.
    struct Player (*__init__)(struct Player *const player);
    // Delete a player.
    void (*__delete__)(struct Player *const player);

    void (*attack)(struct Player *const player);
    void (*talk)();
    void (*eat)();
    void (*equip)(struct Player *const player);
};

/**
 * @brief Struct with the basic information of a player.
 * It's following the style of a RPG.
 * 
 */
struct Player
{
    /**The name of the player.*/
    char *name;
    /**The age of the player. Mustn't be negative.*/
    unsigned age;
    /**The tipical profession of the player. Like a manga character. */
    char *profession;
    /**The total attack of the player.*/
    unsigned attack;
    /**The total life of the player. */
    int life;
};

void *__init__(struct vtable_Player);

#endif // PLAYER_H