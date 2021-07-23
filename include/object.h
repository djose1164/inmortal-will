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

#ifndef OBJECT_H
#define OBJECT_H

#include "include/str.h"

/**
 * @brief Parent class. Its members, like name, make refernce to the object
 * not to its instances. object.name is the name of the object, for example:
 * object.name = "Person" and player.name = "djose1164". The first one is the
 * object and its name means that this instance is of player while the second
 * one is the player's nickname.
 * 
 * @details Type is for make difference if the object is Person so its type is
 * human. If type is weapon so its name could be a sword o katana?. Repr like
 * at Python must print out information about the object like name and type 
 * and further useful members.
 * 
 */
struct Object
{
    char *name; /* Object's name.         */
    char *type; /* Object's type.         */
    char *repr; /* Info about the object. */

    void (*set_repr)(Object *self, const char *msg);
    void (*get_repr)(Object *self);
    void (*set_type)(Object *self, const char *msg);
    char *(*get_type)(Object *self);
    void (*set_name)(Object *self, const char *msg);
    char *(*get_name)(Object *self);
};

typedef struct Object Object;

/*****************************************************************************/
/* Private functions:                                                        */
/*****************************************************************************/

static inline void set_name(Object *self, const char *name)
{
    self->name = name;
}

static inline char *get_name(Object *self)
{
    return self->name;
}

static inline set_type(Object *self, const char *type)
{
    self->type = type;
}

static inline get_type(Object *self)
{
    return self->type;
}

static inline void set_repr(Object *self, const char *msg)
{
    self->repr = msg;
}

static inline char *get_repr(Object *self)
{
    return self->repr;
}

extern void object_binding_setters(Object *self);


#endif // OBJECT_H
