#include "graphics/texture.h"

IW_Texture *texture_init(const char *rpath)
{
    puts("Creating texture...");
    if (!utils_file_exists(rpath))
        memory_die("texture_init(): file does not exist.");
    IW_Texture *self = memory_allocate(self, sizeof *self);
    self->obj_super = NULL;
    self->rpath = rpath;
    self->_texture2D = LoadTexture(rpath);
    self->get_height = texture_get_height;
    self->get_width = texture_get_width;
    puts("Creating texture... Done!");

    return self;
}

static unsigned texture_get_width(const IW_Texture *self)
{
    return self->_texture2D.width;
}

static unsigned texture_get_height(const IW_Texture *self)
{
    return self->_texture2D.height;
}
