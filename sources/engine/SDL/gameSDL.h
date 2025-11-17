#ifndef GAME_SDL_H
#define GAME_SDL_H
#include <SDL3/SDL_main.h>
#include <stdbool.h>
#include "../../gameGlobal.h"


bool gameSDL_init(GameState *g);
bool gameSDL_initMedia(GameState *g);
void gameSDL_free(GameState *g);

#endif  
