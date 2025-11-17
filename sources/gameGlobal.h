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

extern int WINDOW_WIDTH; 
extern int WINDOW_HEIGHT; 
extern char WINDOW_TITLE;

#endif

