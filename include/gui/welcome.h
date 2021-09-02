/*
*----------------------------------------------------------------------------*
|               welcome.h     ---     Public Interface                       |
*----------------------------------------------------------------------------*
|   Public interface for welcome screen. Here's only functions declariations.|
|   For variables declaritions see error_vars.h.                             |
*----------------------------------------------------------------------------*
*/

#ifndef WELCOME_H
#define WELCOME_H

#include "characters/player_vars.h"
#include "gui/button.h"
#include "gui/text_input.h"
#include <raylib.h>

//----------------------------------------------------------------------------
//                          Public methods.
//----------------------------------------------------------------------------

/**
 * @brief Start the job of this module.
 * 
 * @details After starting a welcome message will be show followed by text
 * inputs to enter info like your name and your desire profession.
 */
bool welcome_start(Player *const player);

//----------------------------------------------------------------------------
//                          Private methods.
//----------------------------------------------------------------------------

/**
 * @brief Display the welcome message.
 * 
 * @param msg Message to be displayed on screen.
 */
static void welcome_message(const char *msg);

#endif //WELCOME_H
