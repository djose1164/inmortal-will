#include "player.h"
#include "utils/vars.h"
#include <stdio.h>
#include <stdlib.h>

#define APP_NAME "Immortal Will"

const unsigned screenWidth = 1080;
const unsigned screenHeight = 700;

int main(int argc, char const *argv[])
{
    InitWindow(screenWidth, screenHeight, APP_NAME);

    Texture2D texture = LoadTexture("resources/player.png");
    Player pj = {
        .vector2D.x = screenWidth / 4,
        .vector2D.y = screenHeight / 5,
        .skin = texture
    };
    
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
    BeginDrawing();
        ClearBackground(BLACK);

        // Draw the app's title.
        DrawText(APP_NAME, (int)screenWidth/2.5, 1, 64, RED);
        
        Player_draw(&pj);
        Player_goto(&pj);
        //game_start();
    EndDrawing();    
    }

    return 0;
}
