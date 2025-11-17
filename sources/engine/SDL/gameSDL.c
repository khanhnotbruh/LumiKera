#include <SDL3/SDL.h> //for window renderer
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_opengl.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "../../gameGlobal.h"

#include <dirent.h> // for opendir(), readdir(), closedir()
#include <stdbool.h>
#include <stdio.h>  // for printf()
#include <stdlib.h> // for malloc(), free()
/*--------------------------------------------------------------------------------------------------------------------*/
bool gameSDL_init(GameState *g) {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    printf("SDL init failed! err: %s\n", SDL_GetError());
    return false;
  }
  if (!TTF_Init()) {
    printf("SDL-TTF init failed! err: %s\n", SDL_GetError());
    return false;
  }

  g->window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  if (!g->window) {
    printf("window init failed! err: %s\n", SDL_GetError());
    return false;
  }
  g->renderer = SDL_CreateRenderer(g->window, NULL);
  if (!g->renderer) {
    printf("renderer init failed! err: %s\n", SDL_GetError());
    return false;
  }

  SDL_Surface *iconSurf = IMG_Load("images/icon.png");
  if (!iconSurf) {
    printf("Icon load failed! err: %s\n", SDL_GetError());
  }
  if (!SDL_SetWindowIcon(g->window, iconSurf)) {
    printf("Set icon failed! err: %s\n", SDL_GetError());
    SDL_DestroySurface(iconSurf);
  }
  SDL_DestroySurface(iconSurf);
  return true;
}
/*--------------------------------------------------------------------------------------------------------------------*/
bool gameSDL_initMedia(GameState *g) {
  g->background = IMG_LoadTexture(g->renderer, "images/wall0.png");
  if (!g->background) {
    printf("Background texture init failed! err: %s\n", SDL_GetError());
    return false;
  }

  return true;
}
/*--------------------------------------------------------------------------------------------------------------------*/
void gameSDL_free(GameState **game) {
  if (*game) {
    GameState *g = *game;

    if (g->renderer) {
      SDL_DestroyRenderer(g->renderer);
      g->renderer = NULL;
    }
    if (g->background) {
      SDL_DestroyTexture(g->background);
      g->background = NULL;
    }
    if (g->window) {
      SDL_DestroyWindow(g->window);
      g->window = NULL;
    }

    TTF_Quit();
    SDL_Quit();

    free(g);
    g = NULL;
    *game = NULL;

    printf("gameSDL clear!\n");
  }
}

