#include "characters/living.h"

const static float multiplier = 4.0f;

Living *living_init(const char *name, Type type, const Frame *frame)
{
    puts("Creating living...");
    Living *self = memory_allocate(self, sizeof *self);
    Object *obj = object_init(name, type);
    self->object_super = obj;
    self->frame = frame;
    living_bindfuncs(self);
    self->lvl = 1;
    self->magic = true;
    puts("Creating living... Done!");

    return self;
}

/****************************************************************************/
/*                                   Private Functions.                     */
/****************************************************************************/

static void living_bindfuncs(Living *const self)
{
    self->draw = living_draw;
    self->del = living_del;
}

static void living_set_frame(Living *const self, const Frame *frame)
{
    self->frame = frame;
}


static void living_draw(const Living *self)
{
    self->frame->draw(self->frame);
}

static void living_del(Living *self)
{
    puts("Deleting living...");
    self->object_super->del(self->object_super);
    self->frame->del(self->frame);
    memory_release(self);
    puts("Deleting living... Done!");
}
