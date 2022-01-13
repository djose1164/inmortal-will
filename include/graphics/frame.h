#ifndef FRAME_H
#define FRAME_H

#include "core/object.h"
#include "graphics/texture.h"

enum FrameReturn
{
    MARGIN_OK,
    GREATER_THAN_X_AXIS,
    LESSER_THAN_X_AXIS,
    GREATER_THAN_Y_AXIS,
    LESSER_THAN_Y_AXIS
};
typedef enum FrameReturn FrameReturn;

typedef struct Frame Frame;
struct Frame
{
    Object *object_super;
    Rectangle rectangle;
    IW_Texture *_texture;
    Vector2 position;
    Color color;

    void (*draw)(const Frame *self);
    Texture2D *(*get_texture)(const Frame *self);
    unsigned (*get_texture_width)(const Frame *self);
    unsigned (*get_texture_height)(const Frame *self);
    void (*bind_texture)(Frame *const self, const IW_Texture *texture);
    void (*del_texture)(Frame *const self);
    void (*del)(Frame *self);
    FrameReturn (*check_margins)(const Frame *self);
};

Frame *frame_init(const IW_Texture *texture, const Vector2 *position,
                    Color *color);

static void frame_del(Frame *self);

static Texture2D *frame_get_texture(const Frame *self);

static unsigned frame_get_texture_width(const Frame *self);

static unsigned frame_get_texture_height(const Frame *self);
/**
 * @brief If there's a texture already setted will be deleted and the new one
 * bound.
 * 
 * @param self Pointer to frame. 
 * @param texture Pointer to IW_Texture
 */
static void frame_bind_texture(Frame *const self, const IW_Texture *texture);

static void frame_del_texture(Frame *const self);

static void frame_draw(const Frame *self);

static void frame_check_margins(const Frame *self);
#endif //FRAME_H
