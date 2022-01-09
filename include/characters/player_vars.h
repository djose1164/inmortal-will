#ifndef player_VARS
#define player_VARS

#include "living.h"
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
struct Player
{
    Living being;
    char *profession;
    Vector2 pos;
    Texture2D skin;
};
typedef struct Player Player;

/* Player's linked list. */
extern LinkedList player_list;

#endif //player_VARS
