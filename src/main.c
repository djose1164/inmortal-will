#include "main.h"

int main(int argc, char const *argv[])
{
    // Windows size.
    const unsigned screenWidth = 1280;
    const unsigned screenHeight = 700;

    // The first thing. Init the window.
    InitWindow(screenWidth, screenHeight, APP_NAME);
    SetTargetFPS(30);
    
    game_start();
    
    
    CloseWindow();
    return 0;
}
