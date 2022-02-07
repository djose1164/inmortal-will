#include "characters/base.h"
#include "item/weapon.h"
#include "core/memory_p.h"
#include <stdio.h>

const static float multiplier = 4.0f;

Base *base_init(const char *name, Type type, const Frame *frame)
{
    puts("Creating base...");
    Base *self = memory_allocate(sizeof *self);
    self->frame = frame;
    if (type == PLAYER)
        self->laser = weapon_create_lasers(MAX_NUMS_OF_LASER, WEAPON_LASER_FORWARD);
    else
        self->laser = weapon_create_lasers(MAX_NUMS_OF_LASER, WEAPON_LASER_FORWARD);
    self->attacking = false;

    base_bindfuncs(self);
    puts("Creating base... Done!");

    return self;
}

/****************************************************************************/
/*                                   Private Functions.                     */
/****************************************************************************/

static void base_bindfuncs(Base *const self)
{
    self->draw = base_draw;
    self->del = base_del;
    self->attack = base_attack;
    self->update_lasers = base_update_lasers;
    self->draw_lasers = base_draw_lasers;
}

static void base_set_frame(Base *const self, const Frame *frame)
{
    self->frame = frame;
}

static void base_draw(const Base *self)
{
    self->frame->draw(self->frame);
}

static void base_del_lasers(Laser *laser)
{
    TraceLog(LOG_INFO, "At %s(): deleting...", __FUNCTION__);
    if (laser || weapon_is_laser_attacking(laser))
        weapon_destroy_all(laser);
    TraceLog(LOG_INFO, "At %s(): deleting... Done!", __FUNCTION__);
}

static void base_del(Base **self)
{
    puts("Deleting base...");
    assert(self);
    assert(*self);
    base_del_lasers(*self);
    (*self)->frame->del(&(*self)->frame);
    memory_release(self);
    puts("Deleting base... Done!");
}

static void base_attack(Base *const self)
{
    /*
        Aqui se lanza los lasers.
        El Laser tiene velocidad. Debe ser lanzado dede su punta.
    */
    puts("Launching laser...");
    Vector2 pos = {self->frame->pos.x + self->frame->rectangle.width, self->frame->pos.y + 24.5f};
    if (!weapon_next_laser(self->laser, &pos))
        return;
    self->attacking = true;
    puts("Launching laser... Done!");
}

static void base_update_lasers(const Base *self)
{
    weapon_update_lasers(self->laser);
}

static void base_draw_lasers(const Base *self)
{
    weapon_draw_lasers(self->laser);
}
