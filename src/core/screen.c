#include "core/screen.h"
#include "core/memory_p.h"

Screen **screens = NULL;
static ScreenManager *_screen_manager_private;
ScreenManager screen_manager = &_screen_manager_private;

static inline void screen_update_camera2D(Screen *const self)
{
    Vector2 pos;
    if (self->_target)
    {
        Frame *_target = ((Player *)self->_target)->base_super->frame;
        pos = (Vector2){_target->pos.x, 0};
    }
    else
        pos = (Vector2){GetScreenWidth() / 2, 0};
    self->camera.target = pos;
}

Screen *screen_init(String *title, void *target, Frame *background, const void *frames, size_t nframes,
                    const struct ScreenHandler *manager)
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
    printf("Creating [Screen]%s... Created!\n", self->title->str);

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
    BeginMode2D(self->camera);
    // Background must be drawn first.
    if (self->background)
        (*self->background)->draw((*self->background));
    unsigned t = (GetScreenWidth() - self->title->len);
    unsigned font_size = 64;
    float spacing = 4.5f;
    Vector2 text_pos = MeasureTextEx(GetFontDefault(), self->title->str, font_size, spacing);
    text_pos.x = (GetScreenWidth() - text_pos.x) / 2;
    text_pos.y = (GetScreenHeight() - text_pos.y) / 2;

    if (*screen_manager == screens[GAMEOVER])
    {
        text_pos.y = (GetScreenHeight() - text_pos.y) / 4;
        unsigned font_size = 30;
        static bool restart_game = false;
        if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT))
            restart_game = false;
        else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT))
            restart_game = true;
        Rectangle rec = {
            .x = restart_game ? text_pos.x + 100 + 25 : text_pos.x + 50,
            .y = text_pos.y * 2 + 30 + font_size,
            .width = restart_game ? 55 : 37,
            .height = font_size,
        };
        DrawRectangleRec(rec, LIGHTGRAY);
        DrawText("Want to tray again?", text_pos.x, text_pos.y * 2 + 20, font_size, RED);
        DrawText("No\t\tYes", text_pos.x + 50, text_pos.y * 2 + 30 + font_size, font_size, RED);
        if (IsKeyPressed(KEY_ENTER))
            if (!restart_game)
                exit(0);
    }
    DrawTextEx(GetFontDefault(), self->title->str, text_pos, font_size, spacing, RED);
    // DrawText(self->title->str, (GetScreenWidth()/2)-self->title->len, 50, font_size, RED);
    if (self->frame_len)
    {
        void **frames = (void **)self->frames;
        for (size_t i = 0; i < self->frame_len; i++)
            if (frames[i])
                if (self->manager->draw)
                    self->manager->draw[i](frames[i]);
    }

    EndMode2D();
}

static void screen_update(const Screen *self)
{
    if (self->frames)
    {
        void **targets = (void **)self->frames;
        size_t num = self->frame_len;
        for (size_t i = 0; i < num; i++)
            if (self->manager->update)
                self->manager->update[i](targets[i]);
        // self->manager->update[1](targets[1])
    }
    screen_update_camera2D(self);
}

static void screen_cleanup(Screen *self)
{
    void **targets = (void **)self->frames;
    puts("Screen cleaning up...");
    for (size_t i = 0; i < self->frame_len; i++)
        if (self->manager->del)
            self->manager->del[i](&targets[i]);
    puts("Screen cleaning up... Done");
}

static void screen_del(Screen **self)
{
    printf("Deleting [Screen]%s...\n", (*self)->title->str);
    if ((*self)->manager)
        (*self)->cleanup((*self));
    if (*(*self)->background)
    {
        printf("## *-*-*-*Actually deleting: %s*-*-*-*-\n"
               "self->background at %p\n",
               (*self)->title->str, (*self)->background);
        (*(*self)->background)->del((*self)->background);
    }
    (*self)->title->del(&(*self)->title);

    memory_release(self);
    puts("Deleting screen... Done!");
}