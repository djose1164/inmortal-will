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

#include <stdbool.h>

/**
 * @brief For passing to memory_allocate. If you don't care the type pass OBJECT.
 * Objects should be freed at exit.
 */
extern enum Type
{
    PLAYER,     /* Will be player type. */
    MONSTER,    /* Will be monster type. */
    ITEM,       /* Will be item type. */
    OBJECT,     /* The type doesn't care. */
    LIST        /* Node of linked list. */
};
typedef enum Type Type;

typedef struct CommonAtrrs CommonAtrrs;
struct CommonAtrrs
{
    char *name;
    unsigned lvl;
    int defense;
    int attack;
    char *repr;
    bool delete;
};

/*      --------     Setters.    --------                */

/**
 * @brief Set the name object.
 * 
 * @param self Pointer to object.
 * @param name The name to be setted.
 */
static inline void commonAtrrs_set_name(CommonAtrrs *self, const char *name)
{
    self->name = (char *)name;
}

/**
 * @brief Set the lvl object
 * 
 * @param self 
 * @param lvl 
 */
static inline void commonAtrrs_set_lvl(CommonAtrrs *self, const unsigned lvl)
{
    self->lvl = lvl;
}

/**
 * @brief 
 * 
 * @param self 
 * @param lvl 
 */
static inline void commonAtrrs_upgrade_lvl(CommonAtrrs *self, const unsigned lvl)
{
    self->lvl += lvl;
}
/**
 * @brief Set the defense object
 * 
 * @param self 
 * @param defense 
 */
static inline void commonAtrrs_set_defense(CommonAtrrs *self, const unsigned defense)
{
    self->defense += defense;
}

/**
 * @brief Set the attack object
 * 
 * @param self 
 * @param attack 
 */
static inline void commonAtrrs_set_attack(CommonAtrrs *self, const unsigned attack)
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
static inline char *commonAtrrs_get_name(CommonAtrrs *self)
{
    return self->name;
}

/**
 * @brief Get the lvl object
 * 
 * @param self 
 * @return char* 
 */
static inline unsigned commonAtrrs_get_lvl(CommonAtrrs *self)
{
    return self->lvl;
}

/**
 * @brief Get the defense object
 * 
 * @param self 
 * @return char* 
 */
static inline unsigned commonAtrrs_get_defense(CommonAtrrs *self)
{
    return self->defense;
}

/**
 * @brief Get the attack object
 * 
 * @param self 
 * @return char* 
 */
static inline unsigned commonAtrrs_get_attack(CommonAtrrs *self)
{
    return self->attack;
}

static inline void commonAtrrs_set_repr(CommonAtrrs *self, const char *msg)
{
    self->repr = (char *)msg;
}

static inline const char *commonAtrrs_get_repr(CommonAtrrs *self)
{
    return (const char *)self->repr;
}

#endif //COMMONATRRS_H
