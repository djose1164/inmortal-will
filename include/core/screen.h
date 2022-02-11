#ifndef SCREEN_H
#define SCREEN_H

#include "core/screen_p.h"
#include "core/string.h"
#include "characters/player.h"
#include "graphics/frame.h"
#include "utils/utils.h"
#include <raylib.h>

typedef void (*fptrCallBack)(void *arg);
typedef struct Screen Screen;
typedef enum
{
    TESTING,
    GAMEOVER,
    _SCREEN_MANAGER_MAX
} ScreenIndex;
typedef Screen *ScreenManager;

/* Global variables. */
extern Screen **screens;
extern ScreenManager screen_manager; /* For switching screen. */

struct ScreenHandler
{
    fptrCallBack *draw;
    fptrCallBack *update;
    fptrCallBack *del;
};

/**
 * @brief Screen is a container for whatever you want to keep or do in
 * this stage. Usings screen as a container make the thinds easier to render
 * just pass the screen to the screen manager and that's it.
 *
 */
struct Screen
{
    String *title;       /* Screen's title. */
    Frame **background;   /* Screen's background. */
    Camera2D camera;     /* Screen's camera. */
    const void *frames; /* Array of frames to render. */
    unsigned frame_len;  /* Frame total to render. */
    void *_target;       /* Target for camera. */
    struct ScreenHandler *manager;
    bool end;

    void (*render)(const Screen *self);
    void (*update)(const Screen *self);
    void (*set_target)(Screen *const self, const Frame *target);
    void (*cleanup)(Screen *self);
    void (*del)(Screen *self);
};

/**
 * @brief Create a new screen.
 *
 * @param title Screen title.
 * @param background If NULL, lightgay will be draw.
 * @param frames Array.
 * @return Screen* Pointer to new screen.
 */
Screen *screen_init(String *title, void *target, Frame *background, const void *frames, size_t nframes,
                    const struct ScreenHandler *manager);

static void screen_init_camera2D(Screen *const self);

static void screen_render(const Screen *self);

static void screen_update(const Screen *self);

static void screen_cleanup(Screen *self);

static void screen_del(Screen **self);

static void screen_set_target(Screen *const self, const Frame *target);
#endif // SCREEN_H
