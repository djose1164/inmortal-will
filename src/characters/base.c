#include "characters/base.h"

const static float multiplier = 4.0f;

Living *base_init(const char *name, Type type, const Frame *frame)
{
    puts("Creating living...");
    Living *self = memory_allocate(sizeof *self);
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

static void base_bindfuncs(Living *const self)
{
    self->draw = base_draw;
    self->del = base_del;
}

static void base_set_frame(Living *const self, const Frame *frame)
{
    self->frame = frame;
}


static void base_draw(const Living *self)
{
    self->frame->draw(self->frame);
}

static void base_del(Living *self)
{
    puts("Deleting living...");
    self->object_super->del(self->object_super);
    self->frame->del(self->frame, true);
    memory_release(self);
    puts("Deleting living... Done!");
}
