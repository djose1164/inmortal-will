#include "characters/base.h"

const static float multiplier = 4.0f;

Base *base_init(const char *name, Type type, const Frame *frame)
{
    puts("Creating living...");
    Base *self = memory_allocate(sizeof *self);
    Object *obj = object_init(name, type);
    self->object_super = obj;
    self->frame = frame;
    base_bindfuncs(self);
    self->lvl = 1;
    self->magic = true;
    puts("Creating living... Done!");

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
}

static void base_set_frame(Base *const self, const Frame *frame)
{
    self->frame = frame;
}


static void base_draw(const Base *self)
{
    self->frame->draw(self->frame);
}

static void base_del(Base *self)
{
    puts("Deleting living...");
    self->object_super->del(self->object_super);
    self->frame->del(self->frame, true);
    memory_release(self);
    puts("Deleting living... Done!");
}

static void base_attack(Base *const self)
{
    /*
        Aqui se lanza los lasers.
        El Laser tiene velocidad. Debe ser lanzado dede su punta.
    */
    puts("Launching laser...");
    Laser laser = weapon_next_laser(self->laser);
    if (!laser)
        return;
    weapon_set_frame(laser, frame_init(weapon_get_texture(laser), &self->frame->position, &WHITE));
    weapon_set_lauched(laser, true);
    weapon_set_pos(laser, &(Vector2){self->frame->rectangle.width + self->frame->position.x, self->frame->position.y + 24.5f});
    self->attacking = true;
    puts("Launching laser... Done!");
}