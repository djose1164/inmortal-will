#ifndef GAME_H
#define GAME_H

#include "../include/player.h"

void game_start();

static void set_profession(struct Player *const self);
static void game_set_player_name(struct Player *self);

#endif //GAME_H
