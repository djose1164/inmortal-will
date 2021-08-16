#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include "utils/vars.h"
#include "common_atrrs.h"
#include "str.h"
#include "../include/memory.h"
#include "gui/button.h"

#define APP_NAME "InmortalWill"

int main(int argc, char const *argv[])
{
    // Windows size.
    const unsigned screenWidth = 1280;
    const unsigned screenHeight = 700;

    InitWindow(screenWidth, screenHeight, APP_NAME);
    
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
    BeginDrawing();
        ClearBackground(BLACK);
        // Draw the app's title.
        DrawText(APP_NAME, (int)screenWidth/2.5, 1, 64, RED);

        // TODO: Stuff.
        
    EndDrawing();    
    }

    return 0;
}
