#ifndef DEFINES
#define DEFINES

#include "scan3D/webcam.h"
#include <SDL/SDL.h>

/*typedef struct Position {
	int x;
	int y;
} Position;
*/

Position getMousePosition();

void drawTrace(Position position, Position oldPosition, SDL_Surface* ecran);

SDL_Surface* init_sdl(int width, int height);

void exit_sdl(SDL_Surface* surface);

int seCroisent(Position p1, Position p2);

void drawDot(SDL_Surface* ecran, int x, int y, Uint32 color);

#endif
