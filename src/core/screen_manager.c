#include "core/screen_manager.h"

static void screenManager_render(const ScreenManager *manager)
{
    BeginDrawing();
    manager->current->update(manager->current);
    manager->current->render(manager->current);
    EndDrawing();
}