#include "gui/button.h"

static const unsigned NUM_FRAME = 3U;

void button_draw(const Button *button)
{
    DrawTextureRec(button->texture, button->source, button->pos, button->color);
    button_update(button);
}

void button_init(Button *button, const char *str_sound, const char *texture, void (*on_click)(void))
{
    // If the sound's path was passed, load it.
    if (str_sound)
    {
        InitAudioDevice();
        button->sound = LoadSound(str_sound);
        button->play_sound = true;
    }
    else
        button->play_sound = false;
    button->on_click = on_click;
    
    // Load the texture's source.
    button->texture = LoadTexture(texture);
    unsigned frame_height = button->texture.height/NUM_FRAME;
    // Frame for drawing.
    button->source.x = 0;
    button->source.y = frame_height;
    button->source.width = (float)button->texture.width; 
    button->source.height = frame_height;

    button->pos.x = GetScreenWidth()/2;
    button->pos.y = GetScreenHeight()/2.5;
    button->color = WHITE;

    printf("File: %s Function: %s\n", __FILE__, __FUNCTION__);
}

/*****************************************************************************/
/*                                  Private functions:                       */
/*****************************************************************************/

static Button *button_new(Button *ptr)
{
    ptr = memory_allocate(ptr, sizeof(Button));
    return ptr;
}

static void button_update(Button *button)
{
    // Choose what button draw.
    enum ButtonStatus btn_status = NORMAL;
    bool clicked = false;
    Rectangle btn_bound = {
        button->pos.x,
        button->pos.y,
        button->source.width,
        button->source.height
    };
    
    if (CheckCollisionPointRec(GetMousePosition(), btn_bound))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            btn_status = PRESSED;
        else
            btn_status = MOUSE_HOVER;
        
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            clicked = true;
    }
    else
        btn_status = NORMAL;
    
    button->source.y = btn_status * button->source.height;
    if (clicked)
    {
        if (button->on_click)
            button->on_click();
        if (button->play_sound)
            PlaySound(button->sound);
    }
}