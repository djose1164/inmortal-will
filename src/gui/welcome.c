#include "gui/welcome.h"

#define MAX_INPUT_CHARS 20

bool done = false;

static __attribute__((always_inline)) void set_end(void) 
{
    done = true;
}

bool welcome_start(Player *const player)
{
    TextInput text_input;
    Rectangle rec = {GetScreenWidth()/3.5, 125, 500, 100};
    char *line = MemAlloc(sizeof *line * 1024);
    textInput_init(&text_input, &rec, 20, 46, line, set_end);

    Button button;
    button_init(&button, NULL, "resources/start_button_2.png", set_end);

    while (!WindowShouldClose())
    {
        if (done && strlen(text_input.msg))
        {
            Player_set_name(player, text_input.msg);
            return true;
        }
        done = false;
        
        BeginDrawing();
            ClearBackground(BLACK);
            welcome_message("Welcome to Immortal Will!");

            textInput_draw(&text_input);
            button_draw(&button);
        EndDrawing();
    }
    return false;
}

static void welcome_message(const char *msg)
{
    DrawText(msg, GetScreenWidth()/4, 0, 50, RED);
}