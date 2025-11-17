#include "engine/sdl_core.h"
#include "game/game.h"
#include <stdlib.h>

int main(void) {
    struct Game *game = calloc(1, sizeof(struct Game));
    if (!game) return EXIT_FAILURE;

    if (!sdl_init(game)) return EXIT_FAILURE;
    if (!sdl_load_media(game)) return EXIT_FAILURE;

    game_run(game);
    sdl_cleanup(&game);

    return EXIT_SUCCESS;
}

