#include "gui/text_input.h"

static size_t frameCounter = 0;

static inline void _set_cursor(const TextInput *text_input)
{
    if (textInput_set_cursor(text_input) 
        && textInput_check_bound(text_input))
        textInput_getchar(text_input);
}

static inline void _blinking_event(TextInput *text_input)
{
    if (!((frameCounter / 20) % 2))
        textInput_blinking_underscore(text_input);
}

void textInput_draw(TextInput *text_input)
{
    DrawRectangleRec(text_input->rec, LIGHTGRAY);

    // Set the cursor inside the rectangle.
    _set_cursor(text_input);

    DrawText(text_input->msg, text_input->rec.x + 5,
             text_input->rec.y, text_input->font_size, RED);

    _blinking_event(text_input);
}

void textInput_init(TextInput *text_input, const Rectangle *rec, size_t max_char, 
                    size_t font_size, char *buffer, void (*on_enter)(void))
{
    text_input->rec.height = rec->height;
    text_input->rec.width = rec->width;
    text_input->rec.x = rec->x;
    text_input->rec.y = rec->y;

    text_input->max_char = max_char;
    text_input->char_counter = 0;
    text_input->font_size = font_size;
    text_input->msg = buffer;
    text_input->on_enter = on_enter;

    memset(&text_input->underscore, 0, sizeof text_input->underscore);
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

static void textInput_blinking_underscore(TextInput *text_input)
{
    text_input->underscore.x = text_input->rec.x + 5 + 
                               MeasureText(text_input->msg, 
                               text_input->font_size);
    text_input->underscore.y = text_input->rec.y + text_input->font_size/2;

    DrawText("_", text_input->underscore.x, text_input->underscore.y, 
            text_input->font_size, RED);
}

static inline void textInput_update_msg(TextInput *const text_input, const char key)
{
    text_input->msg[text_input->char_counter] = (char)key;
    text_input->msg[text_input->char_counter + 1] = '\0';
    ++text_input->char_counter;
}

static void textInput_getchar(TextInput *const text_input)
{   
    int key = GetCharPressed();
    
    // Check if there are more chars pressed.
    while (key > 0)
    {
        if (((key >= 32) && (key <= 125)) && (text_input->char_counter 
                                              <= text_input->max_char))
            textInput_update_msg(text_input, key);    

        key = GetCharPressed(); /* Get next char in the queue. */
    }

    if (IsKeyPressed(KEY_BACKSPACE))
    {
        if (text_input->char_counter == 0)
            return;
        --text_input->char_counter;
        text_input->msg[text_input->char_counter] = '\0';
    }
   
    if (IsKeyReleased(KEY_ENTER))
    {
        if (text_input->on_enter)
            text_input->on_enter();
    }

}
