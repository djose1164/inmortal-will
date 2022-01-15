#ifndef SCREEN_H
#define SCREEN_H

#include "core/string.h"
#include "graphics/frame.h"
#include "utils/utils.h"
#include <raylib.h>

struct Update
{
    size_t num;
    void **objcs;
    void (**update_arr)(void *objcs);
};

typedef struct Screen Screen;
/**
 * @brief Screen is a container for whatever you want to keep or do in 
 * this stage. Usings screen as a container make the thinds easier to render
 * just pass the screen to the screen manager and that's it.
 * 
 */
struct Screen
{
    Object *object_super; /* Super. */
    String *title; /* Screen's title. */
    Frame *background; /* Screen's background. */
    Camera2D camera;    /* Screen's camera. */
    const Frame *frames; /* Array of frames to render. */
    unsigned frame_len; /* Frame total to render. */
    Frame *target; /* Target for camera. */
    struct Update *update_struct;

    void (*render)(const Screen *self);
    void (*update)(const Screen *self);
};

/**
 * @brief Create a new screen.
 * 
 * @param title Screen title.
 * @param background If NULL, lightgay will be draw.
 * @param frames Array.
 * @return Screen* Pointer to new screen.
 */
Screen *screen_init(String *title, Frame *background, const Frame *frames);

static void screen_init_camera2D(Screen *const self);

static void screen_render(const Screen *self);
#endif //SCREEN_H
