#ifndef GAME_H
#define GAME_H

#include "characters/player.h"
#include "memory.h"
#include "gui/text_input.h"
#include <string.h>
#include <raylib.h>

void game_start();

static void set_profession(Player *const self);
void game_setup_player(Player *const self, const char *name);

#endif //GAME_H
