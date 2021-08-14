#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "memory.h"
#include "gui/text_input.h"
#include "vars.h"
#include <string.h>
#include <raylib.h>
void game_start();

static void set_profession(Player *const self);
static void game_set_player_name(Player *self);

#endif //GAME_H
