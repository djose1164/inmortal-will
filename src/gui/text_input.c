#include "gui/text_input.h"

void textInput_draw(const TextInput *text_input)
{
    DrawRectangleRec(text_input->rectangle, LIGHTGRAY);
}

void textInput_init(TextInput *text_input, int x, int y, 
                    unsigned width, unsigned height)
{
    text_input->rectangle.height = height;
    text_input->rectangle.width = width;
    text_input->rectangle.x = x;
    text_input->rectangle.y = y;
}