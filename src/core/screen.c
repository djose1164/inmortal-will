#include "core/screen.h"
#include "core/memory_p.h"

static inline void screen_update_camera2D(Screen *const self)
{
    Frame *_target = ((Player *)self->_target)->base_super->frame;   
    self->camera.target = (Vector2){_target->pos.x, 0};
}

Screen *screen_init(String *title, void *target, Frame *background, const void *frames, size_t nframes,
                    const struct ScreenManager *manager)
{
    puts("Creating screen...");
    Frame *_target = ((Player *)target)->base_super->frame;
    Screen *self = memory_allocate(sizeof *self);
    self->title = string_init(title);
    
    self->_target = target;
    self->frames = frames;
    self->frame_len = nframes;

    screen_init_camera2D(self);

    self->background = background;
    assert(manager);
    self->manager = manager;
    self->update = screen_update;
    self->render = screen_render;
    self->del = screen_del;
    self->cleanup = screen_cleanup;
    puts("Creating screen... Done!");

    return self;
}

static void screen_init_camera2D(Screen *const self)
{
    puts("Init camera...");
    assert(self->_target);
    assert(((Player *)self->_target)->base_super->frame);
    Player *temp = (Player *)self->_target;
    Frame *_target = temp->base_super->frame;
    assert(_target);
    float x_offset = _target->get_texture_width(_target) / 2.f;
    //float y_offset = self->_target->get_texture_height(self->_target) / 2.f;
    self->camera.target = _target->pos;
    self->camera.offset = (Vector2){x_offset, 0};
    self->camera.rotation = 0.f;
    self->camera.zoom = 1.f;
    puts("Init camera... Done!");
}

static void screen_render(const Screen *self)
{
    void **frames = (void **)self->frames;
    BeginMode2D(self->camera);
    if (self->background)
        self->background->draw(self->background);   
    DrawText("Holala", 50, 50, 36, RED);
    assert(frames);
    for (size_t i = 0; i < self->frame_len; i++)
        if (frames[i])
            self->manager->draw[i](frames[i]);
    EndMode2D();
}

static void screen_update(const Screen *self)
{
    void **targets = (void **)self->frames;
    size_t num = self->frame_len;
    for (size_t i = 0; i < num; i++)
        if (targets[i])
        self->manager->update[i](targets[i]);
    //self->manager->update[1](targets[1])
    screen_update_camera2D(self);
}

static void screen_cleanup(Screen *self)
{
    void **targets = (void **)self->frames;
    puts("Screen cleaning up...");
    for (size_t i = 0; i < self->frame_len; i++)
        self->manager->del[i](targets[i]);
    puts("Screen cleaning up... Done");
}

static void screen_del(Screen *self)
{
    puts("Deleting screen...");
    if (self->manager)
        self->cleanup(self);

    if (self->background)
        self->background->del(self->background, true);

    self->title->del(self->title);

    memory_release(self);
    puts("Deleting screen... Done!");
}