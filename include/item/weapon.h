#ifndef WEAPON_H
#define WEAPON_H

typedef struct Laser *Laser;

/**
 * @brief Create an array of lasers.
 * 
 * @param quantity Number of lasers to create.
 * @return Laser Pointer to array of lasers.
 */
Laser weapon_create_lasers(unsigned quantity);

Laser weapon_next_laser(Laser laser);

void weapon_update_lasers(Laser laser);

void weapon_draw_lasers(Laser laser);

#endif /* WEAPON_H */