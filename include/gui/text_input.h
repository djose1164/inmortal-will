/*
*----------------------------------------------------------------------------*
|               text_input.h     ---     Public Interface                    |
*----------------------------------------------------------------------------*
|   Public interface for text input & its management. Here's only functions, |
|   variables or struct declariations.                                       |
|   For any definition see text_input.h.                                     |
*----------------------------------------------------------------------------*
*/

#ifndef TEXT_INPUT_H
#define TEXT_INPUT_H

#include <raylib.h>

typedef struct TextInput TextInput;
struct TextInput
{
    Rectangle rectangle;
    char *msg;
};

/**
 * @brief Setup a text input. Do this before drawing it!
 * 
 * @param text_input The pointer to the struct.
 * @param width The rectangle's width.
 * @param height The rectangle's height.
 * @param x The rectangle position on x axis.
 * @param y The rectangle position on y axis.
 * @param msg Save the getted input. 
 */
void textInput_init(TextInput *text_input, int x, int y, 
                    unsigned width, unsigned height);

/**
 * @brief Draw the a text input box.
 * 
 * @param text_input A pointer to the text input to be drew.
 */
void textInput_draw(const TextInput *text_input);

#endif //TEXT_INPUT_H
