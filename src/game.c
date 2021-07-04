#include "../include/game.h"
#include "../include/memory.h"
#include "../include/base.h"
#include <string.h>

static const char *const professions[] = {"Warrior", "Wizard"};

void game_start()
{
    struct Player *player = 0x00;
    player = Player_init(player);
    player->base = base_init(player->base);

    printf("\t\t\t*-*-*-*-*-*-*-\n"
           "\t\t\tImmortal Will!\n"
           "\t\t\t*-*-*-*-*-*-*-\n"
           "\t\t\t          v0.1\n"
           "\n\n"
           "\t\aTo start playing enter some information below!\n\n");

    game_set_player_name(player);
    set_profession(player);
    printf("You have chose: %s as your nickname.\n", player->base->name);
    printf("You have chose: %s as your profession.\n", player->profession);

    memory_release(player->base->name);
    memory_release(player->base);
    memory_release(player);
    printf("Allocated: %zu\t Deallocated: %zu\n", memory_get_allocated_counter(), memory_get_released_counter());
}

static void game_set_player_name(struct Player *self)
{
    char line[50];
    char *name = 0L;

    printf("Enter a name(not greater than 50 letters): ");
    fgets(line, sizeof(line), stdin);
    line[strlen(line) - 1] = '\0';

    name = memory_allocate(name, sizeof(line));
    strncpy(name, line, sizeof(name));
    self->base->name = name;
}

static void set_profession(struct Player *const self)
{
    char line[sizeof(unsigned short)];
    const char *profession;
    unsigned short chose;

    printf("Select your profession!\n"
           "1) Warrior.\n"
           "2) Wizard.\n"
           "\aOption: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%hu", &chose);

    profession_option_is_valid(chose);

    
    self->profession = (char *)professions[chose - 1];
}

static bool profession_option_is_valid(unsigned option)
{
    switch (option)
    {
    case 1:
        //TODO: Some stuff for this.
        break;
    case 2:
        //TODO: Some stuff here too.
        break;

    default:
        printf("Invalid option!");
        break;
    }

    return 0;
}