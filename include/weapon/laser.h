#ifndef WEAPON_H
#define WEAPON_H

#include "graphics/frame.h"
#include "core/type.h"
typedef struct Laser *Laser;

#define MAX_NUMS_OF_LASER 32
#define LASER_SPEED 120.f
#define T Laser

typedef Type Owner;

/**
 * @brief Create an array of lasers.
 *
 * @param quantity Number of lasers to create.
 * @return Laser Pointer to array of lasers.
 */
T laser_create_lasers(unsigned quantity, Owner direction);

T laser_next_laser(T laser, Vector2 *pos);

void laser_update_lasers(T laser);

void laser_draw_lasers(T laser);

void laser_set_frame(T laser, Frame *frame);

void laser_set_lauched(T laser, bool launched);

void laser_set_pos(T laser, Vector2 *pos);

void laser_set_texture(T laser, IW_Texture texture);

void laser_destroy_all(T laser);

const IW_Texture *laser_get_texture(T laser);

Vector2 laser_get_pos(T Laser);

bool laser_is_laser_attacking(T laser);

/****************************************************************************/
/*                            Private Functions.                            */
/****************************************************************************/

static void laser_laser_destroy(Laser laser);

#undef T
#endif /* WEAPON_H */