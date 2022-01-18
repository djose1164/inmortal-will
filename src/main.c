#include "main.h"

int main(int argc, char const *argv[])
{
    // Windows size.
    const unsigned screenWidth = 1080;
    const unsigned screenHeight = 600;

    // The first thing. Init the window.
    InitWindow(screenWidth, screenHeight, APP_NAME);
    SetTargetFPS(60);

    IW_Texture *texture = texture_init("resources/player.png");
    Frame *frame = frame_init(texture, &(Vector2){100, 100}, &WHITE);
    Player *player = player_init(living_init("djose1164", PLAYER, frame));
    struct Update update = {
        .num = 1,
        .objcs = &player,
        .update_arr = &player->update
    };
    struct Cleanup cleanup = {
        .num = 1,
        .objcs = &player,
        .del_arr = &player->del,
    };
    Screen *current = screen_init(string_init("Testing"), frame, NULL, NULL, &update, &cleanup);    

    
    while (!WindowShouldClose())
    {
        current->update(current);
        BeginDrawing();
            ClearBackground(LIGHTGRAY);
            DrawText("Holala", 50, 50, 36, RED);
            current->render(current);
        EndDrawing();
    }
    
    current->del(current);
    CloseWindow();
    memory_check_counter();
    return 0;
}
