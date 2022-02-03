#ifndef BASE_H
#define BASE_H

#include "item/weapon.h"
#include "core/type.h"
#include "core/object.h"
#include "graphics/frame.h"
#include "item/weapon.h"

typedef struct Base Base;
struct Base
{
    Object *object_super;
    char *name; /* Name (the nicksame has to be saved here). */
    Frame *frame;
    /* Current level. */
    unsigned lvl;
    bool magic;

    Laser laser;
    bool attacking;
    void (*attack)(const Base *self);
    void (*set_texture)(Base *const self, const char *texture);
    void (*set_name)(Base *const self, const char *name);
    void (*update)(const Base *self);
    void (*del)(Base *self);
    void (*draw)(const Base *self);
};

Base *base_init(const char *name, Type type, const Frame *frame);

/****************************************************************************/
/*                                   Private Functions.                     */
/****************************************************************************/

static void base_bindfuncs(Base *const self);

static void base_set_frame(Base *const self, const Frame *frame);

static void base_update(const Base *self);

static void base_draw(const Base *self);

static void base_del(Base *self);

#endif //BASE_H
