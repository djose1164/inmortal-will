#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include "utils/vars.h"
#include "common_atrrs.h"
#include "str.h"
#include "../include/memory.h"
#include "gui/button.h"
#define APP_NAME "Immortal Will"

const unsigned screenWidth = 1280;
const unsigned screenHeight = 700;

int main(int argc, char const *argv[])
{
    // Window size.
    
    
    InitWindow(screenWidth, screenHeight, APP_NAME);
    const char *msg = "aloha";
   /* char temp[MAX_INPUT+1] = "\0";
    const unsigned input_fontSize = 32;
    TextInput text_input;
    Rectangle rec = {
        100, 
        100, 
        ((int)input_fontSize/2)*MAX_INPUT + (int)100/4, 
        input_fontSize+10
    };
    textInput_init(&text_input, &rec, MAX_INPUT, input_fontSize);
    text_input.msg = temp; */

    Button button;
     printf("File: %s Function: %s Line: %d\n", __FILE__, __FUNCTION__, __LINE__);
    button_init(&button, "resources/buttonfx.wav", "resources/button.png");
     printf("File: %s Function: %s Line: %d\n", __FILE__, __FUNCTION__, __LINE__);
    
    
    ClearBackground(BLACK);
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
    BeginDrawing();
        ClearBackground(BLACK);
        // Draw the app's title.
        DrawText(APP_NAME, (int)screenWidth/2.5, 1, 64, RED);
        //textInput_draw(&text_input);
        button_draw(&button);
        //game_start();
    EndDrawing();    
    }
    //memory_release((void *)msg);
    //atexit(memory_check_counter);
    return 0;
}
