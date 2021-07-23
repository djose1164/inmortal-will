#include "include/object.h"
#include "../include/memory.h"

extern void object_binds(Object *self)
{
    // Binds setter methods.
    self->set_name = set_name;
    self->set_type = set_type;
    self->set_repr = set_repr;

    // Binds getter methods.
    self->get_name = get_name;
    self->get_type = get_type;
    self->get_repr = get_repr;
}