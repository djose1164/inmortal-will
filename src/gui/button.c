#include "gui/button.h"
#include "core/memory_p.h"

static const unsigned NUM_FRAME = 3U;

void button_draw(const Button *button)
{
    DrawTextureRec(button->texture, button->source, button->pos, button->color);
    button_update(button);
}

Button  *button_init_texture(const char *str_sound, const char *texture, void (*on_click)(void))
{
    Button *self = memory_allocate(sizeof *self);
    button_bindfuncs(self, on_click);
    puts("Setting audio to button...");
    self->set_audio(self, str_sound);
    puts("Setting audio to button... Done!");

    puts("Setting texture to button...");
    self->set_texture(self, texture);
    puts("Setting texture to button... Done");

    puts("Setting posittion to button...");
    Vector2 current_pos = {(float)(GetScreenWidth() / 2), 
                           (float)(GetScreenHeight() / 2)};
    self->set_pos(self, &current_pos);
    puts("Setting posittion to button... Done!");
    self->color = WHITE;

    printf("File: %s Function: %s\n", __FILE__, __func__);
    return self
}

Button *button_init(const char *text, Rectangle *rec, Color color,void (*on_click)(void *arg))
{
    Button *self = memory_allocate(sizeof *self);
    self->pos = (Vector2){rec->x, rec->y};
    self->frame.rectangle = *rec;
    self->color = color;
    return self;
}

void button_set_audio(Button *button, const char *sound_url)
{
    button->play_sound = false;
    if (!sound_url)
        return;
    if (!utils_file_exists(sound_url))
        return; // TODO: this must be handle as a error.

    InitAudioDevice();
    button->sound = LoadSound(sound_url);
    button->play_sound = true;
}

void button_set_texture(Button *button, const char *path)
{
    if (!utils_file_exists(path))
        return; //TODO: must be handle as a error.

    // Load the texture's source.
    button->texture = LoadTexture(path);
    unsigned frame_height = button->texture.height / NUM_FRAME;
    // Frame for drawing.
    button->source.x = 0;
    button->source.y = frame_height;
    button->source.width = (float)button->texture.width;
    button->source.height = frame_height;
    puts("Texture loaded!");
}

void button_set_pos(Button *button, Vector2 *pos)
{
    printf("x=%.3f\ty=%.3f\n"
           "Expecting: x=%d\ty=%d\n", pos->x, pos->y, GetScreenWidth()/2, GetScreenHeight()/2);
    button->pos.x = pos->x;
    button->pos.y = pos->y;
}

/*****************************************************************************/
/*                                  Private functions:                       */
/*****************************************************************************/

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
        // Change cursor.
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            btn_status = PRESSED;
        else
            btn_status = MOUSE_HOVER;

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            clicked = true;
    }
    else
    {
        btn_status = NORMAL;
    }
    button->source.y = btn_status * button->source.height;
    if (clicked)
    {
        SetMouseCursor(MOUSE_CURSOR_ARROW);
        if (button->on_click)
            button->on_click();
        if (button->play_sound)
            PlaySound(button->sound);
    }
}

static void button_bindfuncs(Button *self, void (*on_click)(void))
{
    puts("Binding funcs to button...");
    self->set_audio = button_set_audio;
    self->set_texture = button_set_texture;
    self->set_pos = button_set_pos;
    self->on_click = on_click;
    puts("Binding funcs to button... Done!");
}