#ifndef BASE_H
#define BASE_H

/**
 * @file base.h
 * @author your name (you@domain.com)
 * @brief A base between player and monster for now. Here're some feactures
 * sared between them.
 * @version 0.1
 * @date 2021-06-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// TODO: Think on a better name.

struct Base
{
    /**El nombre del jugador. */
    char *name;
    /**La edad del jugador. No debe ser negativa. */
    unsigned age;
    /**El ataque del jugador. */
    unsigned attack;
    /**Defensa del jugador. */
    unsigned defense;
    /**La vida del jugador. */
    int hp;
    /**El mana del jugador. */
    int mp;
};

/*****************************************************************************/
/* Private functions:                                                        */
/*****************************************************************************/

//inline void base_check_string(const char *_s);
struct Base *base_init(struct Base *base);
void base_set_hp(struct Base *base, unsigned hp);

#endif // BASE_H
