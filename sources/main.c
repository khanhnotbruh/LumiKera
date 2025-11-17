#include "engine/SDL/gameSDL.h"
#include <stdlib.h>
#include <gameGlobal.h>


WINDOW_HEIGHT=600;
WINDOW_WIDTH=800;
WINDOW_TITLE="skibidi";



int main(void) {
    Game *game = calloc(1, sizeof(struct Game));
    if (!game) return EXIT_FAILURE;

    if (!sdl_init(game)) return EXIT_FAILURE;
    if (!sdl_load_media(game)) return EXIT_FAILURE;

    game_run(game);
    sdl_cleanup(&game);

    return EXIT_SUCCESS;
}

