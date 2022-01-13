#ifndef PLAYER_VARS_H
#define PLAYER_VARS_H

#include "characters/living_vars.h"
#include "utils/list.h"
#include <stddef.h>
#include <raylib.h>

/**
 * @brief Struct with the basic information of a player.
 * 
 * @details 's following the style of a RPG.
 * 
 * @var being The type of
 */
typedef struct Player Player;
struct Player
{
    Living *living_super;
    char *profession;

    Player *(*init)(const char *name, const char *texture);
    void (*set_texture)(Player *const self, const char *texture);
    void (*set_name)(Player *const self, const char *name);
    void (*update)(const Player *self);
    void (*draw)(const Player *self);
    void (*del)(Player *self);
};

/* Player's linked list. */
extern LinkedList player_list;


#endif //PLAYER_VARS_H
