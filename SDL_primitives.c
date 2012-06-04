#include "defines.h"

SDL_Surface* init_sdl(int width, int height)
{
    SDL_Init(SDL_INIT_VIDEO);
    return SDL_SetVideoMode(width, height, 0, SDL_HWSURFACE | SDL_FULLSCREEN);
}


void exit_sdl(SDL_Surface* surface)
{
    SDL_FreeSurface(surface);
    SDL_Quit();
}
