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
    Screen *self = memory_allocate(sizeof *self);
    Frame *_target = NULL;
    if (target)
        _target = ((Player *)target)->base_super->frame;

    self->_target = target;
    screen_init_camera2D(self);
    self->title = title;
    self->frames = frames;
    self->frame_len = nframes;

    self->background = background;
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
    Vector2 pos;
    float x_offset;
    if (self->_target)
    {
        Player *temp = (Player *)self->_target;
        Frame *_target = temp->base_super->frame;
        x_offset = _target->get_texture_width(_target) / 2.f;
        pos = _target->pos;
    }
    else
    {
        pos = (Vector2){GetScreenWidth() / 2, GetScreenHeight() / 2};
        x_offset = GetScreenWidth() / 2.f;
    }
    self->camera.target = pos;
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
    if (self->frames)
    {
        void **targets = (void **)self->frames;
        size_t num = self->frame_len;
        for (size_t i = 0; i < num; i++)
            self->manager->update[i](targets[i]);
        // self->manager->update[1](targets[1])
        screen_update_camera2D(self);
    }
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
    // if (self->title && strcmp(self->title, APP) != 0)
    {
        self->title->del(self->title);
        puts("*-*-*-Screen string deleted*-*-*-");
    }
    memory_release(self);
    puts("Deleting screen... Done!");
}