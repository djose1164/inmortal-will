#ifndef TEXTURE_H
#define TEXTURE_H

#include <stddef.h>
#include <raylib.h>

typedef struct IW_Texture IW_Texture;
struct IW_Texture
{
    Texture2D _texture2D;
    const char *rpath;

    void (*del)(IW_Texture *texture);
    char *(*get_name)(IW_Texture *self);
    void (*set_name)(IW_Texture *self);
    unsigned (*get_width)(const IW_Texture *self);
    unsigned (*get_height)(const IW_Texture *self);
};

void texture_memstats(void);

IW_Texture *texture_init(const char *rpath);

static unsigned texture_get_width(const IW_Texture *self);

static unsigned texture_get_height(const IW_Texture *self);

static void texture_del(IW_Texture **self);

#endif //TEXTURE_H
