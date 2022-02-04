#ifndef WEAPON_H
#define WEAPON_H

#include "graphics/frame.h"
typedef struct Laser *Laser;

#define MAX_NUMS_OF_LASER 32
#define LASER_SPEED 5.f
#define T Laser

/**
 * @brief Create an array of lasers.
 * 
 * @param quantity Number of lasers to create.
 * @return Laser Pointer to array of lasers.
 */
T weapon_create_lasers(unsigned quantity);

T weapon_next_laser(T laser, Vector2 *pos);

void weapon_update_lasers(T laser);

void weapon_draw_lasers(T laser);

void weapon_set_frame(T laser, Frame *frame);

void weapon_set_lauched(T laser, bool launched);

void weapon_set_pos(T laser, Vector2 *pos);

void weapon_set_texture(T laser, IW_Texture texture);

void weapon_destroy_all(T laser);

const IW_Texture *weapon_get_texture(T laser);

Vector2 weapon_get_pos(T Laser);

/****************************************************************************/
/*                            Private Functions.                            */
/****************************************************************************/

static void weapon_laser_destroy(Laser laser, bool del_texture);

#undef T
#endif /* WEAPON_H */