#include "gui/text_input.h"

static size_t frameCounter = 0;

void textInput_draw(TextInput *text_input)
{
    // Draw the rectangle and later the cursur.
    DrawRectangleRec(text_input->rec, LIGHTGRAY);

    if (textInput_set_cursor(text_input))
        textInput_getchar(text_input);

    DrawText(text_input->msg, text_input->rec.x + 5,
             text_input->rec.y, text_input->font_size, RED);

    // Blinking event.
    if (!((frameCounter / 20) % 2))
        textInput_blinking_underscore(text_input);
}

void textInput_init(TextInput *text_input, const Rectangle *rec, size_t max_char, size_t font_size)
{
    text_input->rec.height = rec->height;
    text_input->rec.width = rec->width;
    text_input->rec.x = rec->x;
    text_input->rec.y = rec->y;

    text_input->max_char = max_char;
    text_input->char_counter = 0;
    text_input->font_size = font_size;
    text_input->msg = NULL;
}

/*****************************************************************************/
/*                                  Private functions:                       */
/*****************************************************************************/

static bool textInput_set_cursor(const TextInput *text_input)
{
    bool set_cursor = CheckCollisionPointRec(GetMousePosition(),
                                             text_input->rec);
    // If the mouse is on the text input, set the cursor.
    if (set_cursor)
    {
        ++frameCounter;
        SetMouseCursor(MOUSE_CURSOR_IBEAM);
        return true;
    }
    else
    {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        frameCounter = 0;
    }
    return false;
}

static void textInput_blinking_underscore(const TextInput *text_input)
{
    unsigned x = text_input->rec.x + 5 + MeasureText(text_input->msg, text_input->font_size);
    unsigned y = text_input->rec.y + 12;
    DrawText("_", x, y, text_input->font_size, RED);
}

static void textInput_getchar(TextInput *const text_input)
{   
    int key = GetCharPressed();

    // Check if there are more chars pressed.
    while (key > 0)
    {
        if (((key >= 32) && (key <= 125)) && text_input->char_counter < text_input->max_char)
        {
            text_input->msg[text_input->char_counter] = (char)key;
            text_input->msg[text_input->char_counter + 1] = '\0';
            ++text_input->char_counter;
        }

        key = GetCharPressed(); /* Get next char in the queue. */
    }

    if (IsKeyPressed(KEY_BACKSPACE))
    {
        if (text_input->char_counter == 0)
            return;
        --text_input->char_counter;
        text_input->msg[text_input->char_counter] = '\0';
    }
    //printf("## char: %c\n", (char)key);
}