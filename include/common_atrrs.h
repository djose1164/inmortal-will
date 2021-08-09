/*
*----------------------------------------------------------------------------*
|               commonatrrs.h     ---     Public Interface                   |
*----------------------------------------------------------------------------*
|   Public interface for common attributes. Here's only functions, structs,  |
|   and/or variables declariations                                           |
|   For any definition see commonatrrs.h.                                    |
*----------------------------------------------------------------------------*
*/

#ifndef COMMONATRRS_H
#define COMMONATRRS_H

typedef struct CommonAtrrs CommonAtrrs;
struct CommonAtrrs
{
    char *name;
    unsigned level;
    int defense;
    int attack;
};

/*      --------     Setters.    --------                */

/**
 * @brief Set the name object.
 * 
 * @param self Pointer to object.
 * @param name The name to be setted.
 */
static inline void set_name(CommonAtrrs *self, const char *name)
{
    self->name = (char *)name;
}

/**
 * @brief Set the level object
 * 
 * @param self 
 * @param level 
 */
static inline void set_level(CommonAtrrs *self, const unsigned level)
{
    self->level += level;
}

/**
 * @brief Set the defense object
 * 
 * @param self 
 * @param defense 
 */
static inline void set_defense(CommonAtrrs *self, const unsigned defense)
{
    self->defense += defense;
}

/**
 * @brief Set the attack object
 * 
 * @param self 
 * @param attack 
 */
static inline void set_attack(CommonAtrrs *self, const unsigned attack)
{
    self->attack += attack;
}

/*      --------     Getters.    --------                */

/**
 * @brief Get the name object
 * 
 * @param self 
 * @return char* 
 */
static inline char *get_name(CommonAtrrs *self)
{
    return self->name;
}

/**
 * @brief Get the level object
 * 
 * @param self 
 * @return char* 
 */
static inline unsigned get_level(CommonAtrrs *self)
{
    return self->level;
}

/**
 * @brief Get the defense object
 * 
 * @param self 
 * @return char* 
 */
static inline unsigned get_defense(CommonAtrrs *self)
{
    return self->defense;
}

/**
 * @brief Get the attack object
 * 
 * @param self 
 * @return char* 
 */
static inline unsigned get_attack(CommonAtrrs *self)
{
    return self->attack;
}
#endif //COMMONATRRS_H
