#include "main.h"

#define APP_NAME "InmortalWill"

int main(int argc, char const *argv[])
{
    // Windows size.
    const unsigned screenWidth = 1280;
    const unsigned screenHeight = 700;

    // The first thing. Init the window.
    InitWindow(screenWidth, screenHeight, APP_NAME);

    Player pj = {
        .pos.x = 0,
        .pos.y = GetScreenHeight() / 2,
        .skin = LoadTexture("resources/player.png"),
        .being.weight = .5,
        .being.str = .5
    };

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        Player_goto(&pj);

        BeginDrawing();
            ClearBackground(BLACK);

            // Draw the app's title.
            DrawText(APP_NAME, (int)screenWidth / 2.5, 0, 64, RED);

            // Stats.
            DrawText(TextFormat("position: (%.3f, %.3f)", pj.pos.x, pj.pos.y), 0, 
                     0, 32, RED);
            DrawText(TextFormat("time: %.3fs", 5.5), 0, 32, 32, RED);
            DrawText(TextFormat("vel: %.3fm/s", physics_get_velocity(&pj.being, 2.5)), 0,
                    64, 32, RED);

            Player_draw(&pj);
            //game_start();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
