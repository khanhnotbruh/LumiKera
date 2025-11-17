#include <SDL3/SDL.h> //for window renderer
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_opengl.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

#include <dirent.h> // for opendir(), readdir(), closedir()
#include <stdbool.h>
#include <stdio.h>  // for printf()
#include <stdlib.h> // for malloc(), free()

#include "gameGlobal.h"
#include "engine/Engine.h"
#include "game/Game.h"

int main(void) {
    GameState *game = calloc(1, sizeof(GameState));
    if (!game) return EXIT_FAILURE;

    if (!gameSDL_init(game)) return EXIT_FAILURE;
    if (!gameSDL_initMedia(game)) return EXIT_FAILURE;

    gameGame_run(game);
    gameSDL_free(game);

    printf("fist try!");

    return EXIT_SUCCESS;
}

