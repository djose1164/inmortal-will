#include "graphics/frame.h"
#include "core/memory_p.h"
#include <assert.h>
#include <stdio.h>

static size_t allocated_frames, deallocated_frames;

void frame_memstats(void)
{
    if (allocated_frames == deallocated_frames)
        puts("Everything on frames is Ok.");
    else
        printf("Problem on frame...\nAllocated: %zu \t Deallocate: %zu", allocated_frames, deallocated_frames);
}

Frame *frame_init(const IW_Texture *texture, const Vector2 *pos,
                  Color *color)
{
    puts("Creating frame...");
    assert(texture);
    Frame *self = memory_allocate(sizeof *self);
    self->_texture = texture;
    self->pos = *pos;
    self->color = *color;

    self->rectangle.width = (float)texture->get_width(texture);
    self->rectangle.height = (float)texture->get_height(texture);
    self->rectangle.x = 0.0f;
    self->rectangle.y = 0.0f;

    self->bind_texture = frame_bind_texture;
    self->del_texture = frame_del_texture;
    self->del = frame_del;
    self->get_texture = frame_get_texture;
    self->get_texture_width = frame_get_texture_width;
    self->get_texture_height = frame_get_texture_height;
    self->draw = frame_draw;
    self->check_margins = frame_check_margins;
    puts("Creating frame... Done!");
    allocated_frames++;
    return self;
}

static void frame_del(Frame **self, bool del_texture)
{
    puts("Deleting frame...");
    if (del_texture)
        (*self)->_texture->del((*self)->_texture);
    memory_release(*self);
    deallocated_frames++;
    puts("Deleting frame... Done!");
}

static void frame_bind_texture(Frame *const self, const IW_Texture *texture)
{
    if (self->_texture)
        frame_del_texture(self);
    self->_texture = texture;
}

static void frame_del_texture(Frame *const self)
{
    self->_texture->del(self->_texture);
}

static void frame_draw(const Frame *self)
{
    frame_check_margins(self);
    DrawTextureRec(*self->get_texture(self), self->rectangle, self->pos, self->color);
}

static Texture2D *frame_get_texture(const Frame *self)
{
    return &self->_texture->_texture2D;
}

static unsigned frame_get_texture_width(const Frame *self)
{
    return self->_texture->get_width(self->_texture);
}
static unsigned frame_get_texture_height(const Frame *self)
{
    return self->_texture->get_height(self->_texture);
}

static void frame_check_margins(const Frame *self)
{
    // TODO: update after screen implementation.
    float *frame_x = &self->pos.x;
    float *frame_y = &self->pos.y;
    const unsigned width = self->get_texture_width(self) / 4;
    unsigned screen_width = GetScreenWidth();
    unsigned screen_height = GetScreenHeight();

    // Check x-axis.
    /*if (*frame_x + width > screen_width)
        *frame_x = (float)screen_width - width;
    else*/ if (*frame_x < 1.0f)
        *frame_x = 1.0f;

    // Check y-axis.
    if (*frame_y + self->get_texture_height(self) > screen_height)
        *frame_y = (float)screen_height - self->get_texture_height(self);
    else if (*frame_y < 1)
        *frame_y = 1.0f;
}