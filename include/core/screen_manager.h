#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H

#include "core/screen.h"

/**
 * @brief ScreenManager is responsable to render its current screen. To render
 * any other screen the current to point to that screen.
 * 
 */
struct ScreenManager
{
    Screen *current;

    void (*render)(const Screen *screen);
};
typedef struct ScreenManager ScreenManager;

static void screenManager_render(const ScreenManager *manager);

#endif //SCREEN_MANAGER_H
