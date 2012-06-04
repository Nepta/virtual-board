#include "defines.h"

void drawTrace(Position oldPosition, Position position, SDL_Surface* ecran)
{
	/*	AFFICHAGE NOUVEAU POINT	*/
	
	//# SDL_Surface *mouseTrace = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 255, 0, 0);
	Uint32 color = SDL_MapRGB(ecran->format, 180, 0, 0);
    // Hide real cursor



	drawDot(ecran, position.x, position.y, color);
    // Blit onto main surface
    //# SDL_BlitSurface(mouseTrace, NULL, ecran, &dst);

	
	
	/*	AFFICHAGE MOITIE (completion)	*/
	
	if (!seCroisent(position, oldPosition)){
	// calc milieu
	// afficher milieu
	// draw gauche
	// draw droite
		Position milieu;
		milieu.x = (position.x + oldPosition.x)/2;
		milieu.y = (position.y + oldPosition.y)/2;
		
		drawDot(ecran, milieu.x, milieu.y, color);
		
		
		drawTrace(position, milieu, ecran);
		drawTrace(milieu, oldPosition, ecran);
	}
	
}

void drawDot(SDL_Surface* ecran, int x, int y, Uint32 color)
{
	SDL_Rect dst;
	dst.w = 5;
	dst.h = 3;
	dst.x = LARGEUR - x;
	dst.y = y;
	SDL_FillRect(ecran, &dst, color);
	dst.w = 3;
	dst.h = 5;
	dst.x += 1;
	dst.y -= 1;
	SDL_FillRect(ecran, &dst, color);
}

int seCroisent(Position p1, Position p2){
	Position vecteur;
	vecteur.x = p2.x - p1.x;
	vecteur.y = p2.y - p1.y;
	int normeCarre = vecteur.x * vecteur.x + vecteur.y * vecteur.y;
	return normeCarre < 25;
//	return ((p1.x-p2.x <= 5 || p1.y - p2.y <= 5) || (p2.x-p1.x <= 5 || p2.y - p1.y <= 5));
}
