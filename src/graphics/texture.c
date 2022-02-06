#include "graphics/texture.h"
#include "utils/utils.h"
#include "core/error.h"
#include "core/memory_p.h"
#include <stdio.h>

static size_t allocated, deallocated;

void texture_memstats(void)
{
    printf("%s():%d\n", __FUNCTION__, __LINE__);
    if (allocated == deallocated)
        puts("Everything on textures is Ok.");
    else
        printf("%s:\n Allocated: %zu \t Deallocated: %zu\n", allocated, deallocated);
}

IW_Texture *texture_init(const char *rpath)
{
    puts("Creating texture...");
    if (!utils_file_exists(rpath))
        ERROR_DIE("file does not exist.");
        
    IW_Texture *self = memory_allocate(sizeof *self);
    self->rpath = rpath;
    self->_texture2D = LoadTexture(rpath);
    self->get_height = texture_get_height;
    self->get_width = texture_get_width;
    self->del = texture_del;
    puts("Creating texture... Done!");
    allocated++;
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

static void texture_del(IW_Texture **self)
{
    puts("Deleting texture...");
    assert(self);
    assert(*self);
    UnloadTexture((*self)->_texture2D);
    memory_release(self);
    deallocated++;
    puts("Deleting texture... Done!");
}