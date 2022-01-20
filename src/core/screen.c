#include "core/screen.h"

static inline void screen_update_camera2D(Screen *const self)
{
    self->camera.target = (Vector2){self->_target->position.x, 0};
}

Screen *screen_init(String *title, Frame *target, Frame *background, const Frame *frames,
                    const struct Update *_update, const struct Cleanup *_cleanup)
{
    puts("Creating screen...");
    Screen *self = memory_allocate(sizeof *self);
    self->object_super = object_init("Screen", SCREEN);
    self->title = string_init(title);

    screen_set_target(self, target);
    screen_init_camera2D(self);

    self->background = background;
    assert(_update && _cleanup);
    self->update_struct = _update;
    self->cleanup_struct = _cleanup;

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
    float x_offset = self->_target->get_texture_width(self->_target) / 2.f;
    //float y_offset = self->_target->get_texture_height(self->_target) / 2.f;
    self->camera.target = self->_target->position;
    self->camera.offset = (Vector2){x_offset, 0};
    self->camera.rotation = 0.f;
    self->camera.zoom = 1.f;
    puts("Init camera... Done!");
}

static void screen_render(const Screen *self)
{
    BeginMode2D(self->camera);
    ClearBackground(LIGHTGRAY);
    DrawText("Holala", 50, 50, 36, RED);
    self->_target->draw(self->_target);
    EndMode2D();
}

static void screen_update(const Screen *self)
{
    size_t num = self->update_struct->num;
    for (size_t i = 0; i < num; i++)
        self->update_struct->update_arr[i](self->update_struct->objcs[i]);
    screen_update_camera2D(self);
}

static void screen_set_target(Screen *const self, const Frame *_target)
{
    self->_target = _target;
}

static void screen_cleanup(Screen *self)
{
    puts("Screen cleaning up...");
    for (size_t i = 0; i < self->cleanup_struct->num; i++)
        self->cleanup_struct->del_arr[i](self->cleanup_struct->objcs[i]);
    puts("Screen cleaning up... Done");
}

static void screen_del(Screen *self)
{
    puts("Deleting screen...");
    if (self->cleanup_struct)
        self->cleanup(self);

    if (self->background)
        self->background->del(self->background);

    self->object_super->del(self->object_super);
    self->title->del(self->title);

    memory_release(self);
    puts("Deleting screen... Done!");
}