#ifndef BUTTON_H
#define BUTTON_H

#include <raylib.h>
#include "memory.h"
#include "utils/terminal_colors.h"

enum ButtonStatus
{
    NORMAL,
    MOUSE_HOVER,
    PRESSED
};

struct Button
{
    Sound sound;        /* The sound to play. */
    Texture2D texture;  /* The image to set. */
    Rectangle source;   /* The container for the texture. */
    Vector2 pos;        /* The position fo the container. */
    Color color;        /* The button's color. */
};
typedef struct Button Button;

void button_draw(const Button *button);

/**
 * @brief Initialize a button. Do this before drawing it!
 * 
 * @param sound For no sound, pass NULL. Otherwise path to sound.
 * @param texture Path to texture.
 * @param rec Pointer to the rectangle area.
 */
void button_init(Button *button, const char *str_sound, const char *texture);

/*****************************************************************************/
/*                                  Private functions:                       */
/*****************************************************************************/

/**
 * @brief Allocate memory for a new button.
 * 
 * @param ptr The pointer asking for memory.
 */
static Button *button_new(Button *ptr);

/**
 * @brief Update the button.
 * 
 * @param ptr Pointer to the button.
 */
static void button_update(Button *ptr);
#endif //BUTTON_H
