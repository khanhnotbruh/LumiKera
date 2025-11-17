#ifndef GAME_SDL_H
#define GAME_SDL_H
#include <SDL3/SDL.h> //for window renderer
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_opengl.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "../../gameGlobal.h"

#include <dirent.h> // for opendir(), readdir(), closedir()
#include <stdbool.h>
#include <stdio.h>  // for printf()
#include <stdlib.h>

bool gameSDL_init(GameState *g);
bool gameSDL_initMedia(GameState *g);
void gameSDL_free(GameState *g);

#endif  
