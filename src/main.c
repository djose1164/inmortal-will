#include "main.h"

int main(int argc, char const *argv[])
{
    // Windows size.
    const unsigned screenWidth = 1080;
    const unsigned screenHeight = 600;

    // The first thing. Init the window.
    InitWindow(screenWidth, screenHeight, APP_NAME);
    SetTargetFPS(60);
    
    game_start();
    
    
    CloseWindow();
    return 0;
}
