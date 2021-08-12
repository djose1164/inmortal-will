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
#include <stddef.h>
#include <stdio.h>

typedef struct TextInput TextInput;
struct TextInput
{
    Rectangle rec;
    char *msg;
    short max_char;
    size_t char_counter;
    size_t font_size;
};

// Private variables
static size_t frameCounter;

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
void textInput_init(TextInput *text_input, const Rectangle *rec, size_t max_char,
                    size_t font_size);

/**
 * @brief Draw the a text input box.
 * 
 * @param text_input A pointer to the text input to be drew.
 */
void textInput_draw(TextInput *text_input);

/*****************************************************************************/
/*                                  Private functions:                       */
/*****************************************************************************/

/**
 * @brief Dectect when the user click onto the text input.
 * 
 * @param text_input A constant pointer.
 */
static bool textInput_set_cursor(const TextInput *text_input);

/**
 * @brief Shows the blinking undersocore in the text input. The cursor must be 
 * set first.
 * 
 */
static void textInput_blinking_underscore(const TextInput *text_input);

/**
 * @brief Display each char get from the user.
 * 
 * @param text_input 
 */
static void textInput_getchar(TextInput *const text_input);

#endif //TEXT_INPUT_H
