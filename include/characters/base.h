#ifndef BASE_H
#define BASE_H

#if !defined(__GNUC__)
#error "Must use GCC to compile!"
#endif /* !define(__GNUC__) */

#include "weapon/laser.h"
#include "core/type.h"
#include "graphics/frame.h"

typedef struct Base Base;
struct Base
{

    char *name; /* Name (the nicksame has to be saved here). */
    Frame *frame;
    Laser laser;
    bool attacking;
    bool destroyed;
    double speed;

    void (*attack)(const Base *self);
    void (*update)(const Base *self);
    void (*draw_lasers)(const Base *self);
    void (*set_texture)(Base *const self, const char *texture);
    void (*set_name)(Base *const self, const char *name);
    void (*del)(Base *self);
    void (*draw)(const Base *self);
    Rectangle (*get_rec)(const Base *self);
};

Base *base_init(const char *name, Type type, const Frame *frame, double speed);

/****************************************************************************/
/*                                   Private Functions.                     */
/****************************************************************************/

static void base_bindfuncs(Base *const self);

static void base_set_frame(Base *const self, const Frame *frame);

static void base_draw(const Base *self);

static void base_attack(Base *self);

static void base_update(Base *self);

static void base_draw_lasers(const Base *self);

static bool base_is_destroyed(Base *self);

static void base_del(Base **self);

static Rectangle base_get_rec(const Base *self);
#endif // BASE_H
