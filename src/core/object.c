#include "core/object.h"

static void object_del(Object *self)
{
    memory_release(self);
}

static void object_set_repr(Object *const self, const char *msg)
{
    self->repr = msg;
}

static char *object_get_repr(const Object *self)
{
    return self->repr;
}

static void object_set_type(Object *const self, const Type type)
{
    self->type = type;
}

/*
static char *object_get_type(const Object *self)
{
    return self->type;
}
*/
static void object_bindfuncs(Object *const self)
{
    self->set_repr = object_set_repr;
    self->get_repr = object_get_repr;
    self->set_type = object_set_type;
    // self->get_type = object_get_type;
    self->del = object_del;
}
