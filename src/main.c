#include <stdio.h>
#include <assert.h>
#include "../include/player.h"
#include "../include/base.h"
#include "../include/memory.h"

int main(int argc, char const *argv[])
{
    struct Player *player = player_init(player);
    player->base = base_init(player->base);

    base_set_hp(player->base, 100);
    //printf("hp: %u\n", player->base->hp);

    memory_release(player->base);
    memory_release(player);
    memory_check_counter();
    return 0;
}
