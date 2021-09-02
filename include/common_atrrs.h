/*
*----------------------------------------------------------------------------*
|               commonattrs.h     ---     Public Interface                   |
*----------------------------------------------------------------------------*
|   Public interface for common attributes. Here's only functions, structs,  |
|   and/or variables declariations                                           |
|   For any definition see commonattrs.h.                                    |
*----------------------------------------------------------------------------*
*/

#ifndef COMMONATTRS_H
#define COMMONATTRS_H

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

/**
 * @brief This struct contains any common attribute shared for any living being.
 * 
 */
struct CommonAttrs
{
    char *name;     /* Name (the nicksame has to be saved here). */
    unsigned lvl;   /* Current level. */
    int defense;    /* Current defense. */
    int attack;     /* Current attack. */
    char *repr;     /* A brief description. */
    bool delete;    /* TODO: Remember this. */
};
typedef struct CommonAttrs CommonAttrs;

/*          --------     Setters.    --------                */

/**
 * @brief Set the name object.
 * 
 * @param self Pointer to object.
 * @param name The name to be setted.
 */
static inline void commonAttrs_set_name(CommonAttrs *const self, const char *name)
{
    self->name = (char *)name;
}

/**
 * @brief Set the lvl object
 * 
 * IMPORTANT: For upgrade lvl use `commonAttrs_upgrade_lvl()`.
 * 
 * @param self Pointer to object.
 * @param lvl The level to be setted.
 */
static inline void commonAttrs_set_lvl(CommonAttrs *self, const unsigned lvl)
{
    self->lvl = lvl;
}

/**
 * @brief Set the defense object. 
 * 
 * @param self Pointer to object.
 * @param defense The defense to set.
 */
static inline void commonAttrs_set_defense(CommonAttrs *self, const unsigned defense)
{
    self->defense = defense;
}

/**
 * @brief Set the attack object
 * 
 * @param self Pointer to object.
 * @param attack The attack to set.
 */
static inline void commonAttrs_set_attack(CommonAttrs *self, const unsigned attack)
{
    self->attack = attack;
}

static inline void commonAttrs_set_repr(CommonAttrs *self, const char *msg)
{
    self->repr = (char *)msg;
}

/*          --------     Upgrades.  ---------                */

/**
 * @brief Upgrade the attack object
 * 
 * @param self Pointer to object.
 * @param attack The attack to add.
 */
static inline void commonAttrs_upgrade_attack(CommonAttrs *self, const unsigned attack)
{
    self->attack += attack;
}

/**
 * @brief Upgrade defense object. 
 * 
 * @param self Pointer to object.
 * @param defense The defense to add.
 */
static inline void commonAttrs_upgrade_defense(CommonAttrs *self, const unsigned defense)
{
    self->defense += defense;
}

/**
 * @brief Upgrade level (adding the passed lvl to the current lvl).
 * 
 * @param self Pointer to object.
 * @param lvl The levels to be added.
 */
static inline void commonAttrs_upgrade_lvl(CommonAttrs *self, const unsigned lvl)
{
    self->lvl += lvl;
}

/*          --------     Getters.    --------                */

/**
 * @brief Get the name object
 * 
 * @param self Pointer to object.
 * @return char* The name setted.
 */
static inline char *commonAttrs_get_name(CommonAttrs *self)
{
    return self->name;
}

/**
 * @brief Get the lvl object
 * 
 * @param self Pointer to object.
 * @return char* The level setted.
 */
static inline unsigned commonAttrs_get_lvl(CommonAttrs *self)
{
    return self->lvl;
}

/**
 * @brief Get the defense object
 * 
 * @param self Pointer to object.
 * @return unsigned The defense setted.
 */
static inline unsigned commonAttrs_get_defense(CommonAttrs *self)
{
    return self->defense;
}

/**
 * @brief Get the attack object
 * 
 * @param self 
 * @return unsigned The attack setted. 
 */
static inline unsigned commonAttrs_get_attack(CommonAttrs *self)
{
    return self->attack;
}

/**
 * @brief Get the short description of this object.
 * 
 * @param self Pointer to object.
 * @return const char* The short description.
 */
static inline const char *commonAttrs_get_repr(CommonAttrs *self)
{
    return (const char *)self->repr;
}

#endif //COMMONATTRS_H
