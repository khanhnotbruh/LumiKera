#ifndef GAME_GLOBAL_H
#define GAME_GLOBAL_H

#include <SDL3/SDL.h>
#include <stdbool.h>
#include <SDL3/SDL_main.h>


typedef struct{
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *background;
  SDL_Event event;
  bool is_running;
}GameState;

#define SDL_FLAGS SDL_INIT_VIDEO
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "skibidi"

#endif

