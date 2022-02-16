#include "characters/base.h"
#include "core/memory_p.h"
#include <stdio.h>

const static float multiplier = 4.0f;

Base *base_init(const char *name, Type type, const Frame *frame)
{
    puts("Creating base...");
    Base *self = memory_allocate(sizeof *self);
    self->frame = frame;
    if (type == PLAYER)
        self->laser = laser_create_lasers(MAX_NUMS_OF_LASER, PLAYER);
    else
        self->laser = laser_create_lasers(MAX_NUMS_OF_LASER, MONSTER);
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

static void base_del_lasers(Laser laser, bool restart)
{
    TraceLog(LOG_INFO, "At %s(): deleting...", __func__);
    if (laser || laser_is_attacking(laser))
        laser_destroy_all(laser, restart);
    TraceLog(LOG_INFO, "At %s(): deleting... Done!", __func__);
}

void base_restart(Base *self, Vector2 pos)
{
    self->frame->pos = pos;
    base_del_lasers(self->laser, true);
}

static void base_del(Base **self)
{
    puts("Deleting base...");
    assert(self);
    assert(*self);
    base_del_lasers((*self)->laser, false);
    (*self)->frame->del(&(*self)->frame);
    memory_release(&(*self)->laser);
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
    Vector2 pos = {self->frame->pos.x + self->frame->rectangle.width, self->frame->pos.y};
    if (!laser_next_laser(self->laser, &pos))
        return;
    self->attacking = true;
    puts("Launching laser... Done!");
}

static void base_update_lasers(const Base *self)
{
    laser_update_lasers(self->laser);
}

static void base_draw_lasers(const Base *self)
{
    laser_draw_lasers(self->laser);
}

static bool base_is_killed(Base *self)
{
    return self->killed;
}
