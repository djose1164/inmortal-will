#include <stdio.h>
#include <assert.h>
#include <raylib.h>
#include "gui/welcome.h"

#define APP_NAME "Immortal Will"

int main(int argc, char const *argv[])
{
    const int screenWidth = 800;
    const int screenHeight = 700;

    InitWindow(screenWidth, screenHeight, APP_NAME);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        welcome_start();
        EndDrawing();
    } //game_start();
    return 0;
}
