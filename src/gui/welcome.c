#include "gui/welcome.h"
#include <raylib.h>

#define MAX_INPUT_CHARS 20

void welcome_start(void)
{
    welcome_message("Welcome to Immortal Will!");
}

static void welcome_message(const char *msg)
{
    DrawText(msg, 100, 100, 30, RED);
}