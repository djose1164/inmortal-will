#include "graphics/texture.h"

IW_Texture *texture_init(const char *rpath)
{
    puts("Creating texture...");
    if (!utils_file_exists(rpath))
        memory_die("texture_init(): file does not exist.");
        
    Object *obj = object_init("Texture", TEXTURE);
    IW_Texture *self = memory_allocate(sizeof *self);
    self->obj_super = obj;
    self->rpath = rpath;

    self->_texture2D = LoadTexture(rpath);
    self->get_height = texture_get_height;
    self->get_width = texture_get_width;
    self->del = texture_del;
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

static void texture_del(IW_Texture *self)
{
    puts("Deleting texture...");
    self->obj_super->del(self->obj_super);
    UnloadTexture(self->_texture2D);
    memory_release(self);
    puts("Deleting texture... Done!");
}