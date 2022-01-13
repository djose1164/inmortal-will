#include "game.h"

void game_start()
{
    Player player;
    memset(&player, 0, sizeof player);

    if (!welcome_start(&player))
        return;
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText(TextFormat("Welcome %s.", player.living_super->attrs.name), 0, 200, 
                     36, RED);
        EndDrawing();
    }
}

