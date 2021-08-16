#ifndef PLAYER_VARS
#define PLAYER_VARS

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

#endif //PLAYER_VARS
