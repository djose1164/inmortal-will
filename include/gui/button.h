#ifndef BUTTON_H
#define BUTTON_H

#include "core/memory_p.h"
#include "utils/terminal_colors.h"
#include "utils/utils.h"
#include <raylib.h>

enum ButtonStatus
{
    NORMAL,
    MOUSE_HOVER,
    PRESSED
};

typedef struct Button Button;
struct Button
{
    Sound sound;            /* The sound to play. */
    Texture2D texture;      /* The image to set. */
    Rectangle source;       /* The container for the texture. */
    Vector2 pos;            /* The pos fo the container. */
    Color color;            /* The button's color. */
    bool play_sound;        /* Wheather should play sound or not. */

    void (*set_audio)(Button *self, const char *url);
    void (*set_texture)(Button *self, const char *url);
    void (*on_click)(void); /* Function to call on click. */
    void (*set_pos)(Button *self, Vector2 *pos);
};

void button_draw(const Button *button);

/**
 * @brief Initialize a button. Do this before drawing it!
 * 
 * @param sound For no sound, pass NULL. Otherwise path to sound.
 * @param texture Path to texture.
 * @param rec Pointer to the rectangle area.
 * @return Pointer to button.
 */
Button *button_init(const char *str_sound, const char *texture, void (*on_click)(void));

/**
 * @brief Set the audio for a button. The sound will be played when the button
 * is clicked.
 * 
 * @param button Pointer to a button. 
 * @param sound_url Path to sound.
 */
void button_set_audio(Button *button, const char *sound_url);

/**
 * @brief Set the texture of skin for the button.
 * 
 * @param button Pointer to button.
 * @param path Path to texture/skin.
 */
void button_set_texture(Button *button, const char *path);

void button_set_pos(Button *button, Vector2 *pos);

/*****************************************************************************/
/*                                  Private functions:                       */
/*****************************************************************************/

/**
 * @brief Update the button.
 * 
 * @param ptr Pointer to the button.
 */
static void button_update(Button *ptr);

static void button_bindfuncs(Button *self, void (*on_click)(void));
#endif //BUTTON_H
