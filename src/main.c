#include "main.h"

// TODO: This function definition must be hidden.
void draw_background(const Frame *self)
{
    static float scrolling = 0.f;
    scrolling -= 1.f;
    const float max = -self->_texture->_texture2D.width * 4.5f;
    if (scrolling <= max)
        scrolling = 0;
    DrawTextureEx(*self->get_texture(self), (Vector2){scrolling, self->pos.y},
                  0.f, 4.5f, WHITE);
    DrawTextureEx(*self->get_texture(self), (Vector2){self->get_texture_width(self) * 4.5f + scrolling, self->pos.y}, 0.f, 4.5f, WHITE);
}

int main(int argc, char const *argv[])
{
    // Windows size.
    const unsigned screenWidth = 1080;
    const unsigned screenHeight = 500;

    // The first thing. Init the window.
    InitWindow(screenWidth, screenHeight, APP_NAME);
    InitAudioDevice();
    // SetTraceLogLevel(LOG_DEBUG);
    SetTargetFPS(60);

    Music music = LoadMusicStream("resources/eon.mp3");
    PlayMusicStream(music);
    SetMusicVolume(music, .0f);

    Player *player = player_init(texture_init("resources/spaceship-draft.png"));

    IW_Texture *enemy_skin = texture_init("resources/enemy.png");
    alien_create(enemy_skin);

    Frame *background = frame_init(texture_init("./resources/space_with_stars.png"), &(Vector2){0, 0}, &WHITE);
    background->draw = draw_background;
    while (!WindowShouldClose())
    {

        UpdateMusicStream(music);
        player->update(player);
        alien_update();

        BeginDrawing();
        ClearBackground(BLACK);
        background->draw(background);
        player->draw(player);
        alien_draw();
        EndDrawing();
    }

game_cleanup:

    UnloadMusicStream(music);
    CloseWindow();
    texture_memstats();
    frame_memstats();
    memory_check_counter();

    return 0;
}
