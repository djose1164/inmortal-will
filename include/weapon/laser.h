/*
*----------------------------------------------------------------------------*
|                     laser.h     ---     Public Interface                   |
*----------------------------------------------------------------------------*
|   Declaration for laser-like stuff. Here's provided only: functions,       |
|   variables, opaque pointers declariations                                 |
|   For any definition see laser.c.                                          |
*----------------------------------------------------------------------------*
*/
#ifndef WEAPON_H
#define WEAPON_H

#include "graphics/frame.h" /* For: */
#include "core/type.h"      /* For: Type enum.*/
typedef struct Laser *Laser; /* Laser object. */

#define MAX_NUMS_OF_LASER 32 /* Max number of lasers to handle. */
#define LASER_SPEED 120.f    /* Each laser's speed. */
#define T Laser

typedef Type Owner; /* To know who lauchend the laser. */

/**
 * @brief Create an array of lasers.
 *
 * @param quantity Number of lasers to create.
 * @return Laser Pointer to array of lasers.
 */
T laser_create_lasers(unsigned quantity, Owner direction);

/**
 * @brief Get the nest avaible laser.
 * 
 * @param laser The attacker's laser.
 * @param pos Where to put the laser.
 * @return T is the avaible laser. NULL for none.
 */
T laser_next_laser(T laser, Vector2 *pos);

void laser_update_lasers(Laser laser);

/**
 * @brief Draw all the launched lasers.
 * 
 * @param laser The attacker's laser.
 */
void laser_draw_lasers(T laser);

/**
 * @brief Set frame to a laser.
 * 
 * @param laser The laser to put the frame.
 * @param frame The frame to be set.
 */
void laser_set_frame(T laser, Frame *frame);

/**
 * @brief Change the status wether was launched or not.
 * 
 * @param laser The laser to change status.
 * @param launched True if was launched. False if you want to delete it.
 */
void laser_set_lauched(T laser, bool launched);

/**
 * @brief Put the laser at.
 * 
 * @param laser The laser to put at.
 * @param pos Position (Vector2).
 */
void laser_set_pos(T laser, Vector2 *pos);

/**
 * @brief Bind texture to laser.
 * 
 * @param laser The laser to set texture.
 * @param texture The texture to be set.
 */
void laser_set_texture(T laser, IW_Texture texture);

/**
 * @brief Destroy all lasers.
 * 
 * @param laser Whom to delete.
 * @param restart Should delete texture and sound.
 */
void laser_destroy_all(T laser, bool restart);

/**
 * @brief Get laser's texture.
 * 
 * @param laser Laser to get the texture.
 * @return const IW_Texture* NULL if doesn't have texture.
 */
const IW_Texture *laser_get_texture(T laser);

/**
 * @brief Get current position.
 * 
 * @param Laser Laser to get the position.
 * @return Vector2 is the current position.
 */
Vector2 laser_get_pos(T Laser);

/**
 * @brief To know is the provided laser have some lasers launched.
 * 
 * @param laser The laser to see.
 * @return true Have some lasers launched.
 * @return false There's no any lasers launched (all are deleted).
 */
bool laser_is_attacking(T laser);

bool laser_crash_was_success(Laser laser, const Rectangle *target, Type attacker);

/****************************************************************************/
/*                            Private Functions.                            */
/****************************************************************************/

static void laser_destroy(Laser laser);

#undef T
#endif /* WEAPON_H */