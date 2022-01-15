#include "core/screen.h"

Screen *screen_init(String *title, Frame *background, const Frame *frames)
{
    Screen *self = memory_allocate(self, sizeof *self);
    self->object_super = object_init("Screen", SCREEN);
    self->title = string_init(title);
    self->background = background;
    screen_init_camera2D(self);

    return self;
}

static void screen_init_camera2D(Screen *const self)
{
    float x_offset = self->target->get_texture_width(self->target) / 2.f;
    float y_offset = self->target->get_texture_height(self->target) / 2.f;
    self->camera.target = self->target->position;
    self->camera.offset = (Vector2){x_offset, y_offset};
    self->camera.rotation = 0.f;
    self->camera.zoom = 1.f;
}

static void screen_render(const Screen *self)
{
    BeginMode2D(self->camera);
    ClearBackground(LIGHTGRAY);
    DrawText("Holala", 50, 50, 36, RED);
    self->target->draw(self->target);
    EndMode2D();
}

static void screen_update(const Screen *self)
{
    size_t num = self->update_struct->num;

    for (size_t i = 0; i < num; i++)
        self->update_struct->update_arr[i](self->update_struct->objcs[i]);
}