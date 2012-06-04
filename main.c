#include "defines.h"

CvCapture* initCV();
void go();

int main()
{
	CvCapture *capture = initCV();
	
	if(!capture){
		return -1;	
	}
	
//	cvNamedWindow("ANAGRAMME",0);
	
	Position hand, oldhand, temphand;
	char c;

	SDL_Surface *ecran = init_sdl(LARGEUR/COMPRESSION, HAUTEUR/COMPRESSION);
    SDL_ShowCursor(0);
    // Clear surface
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

	go();
	SDL_Event event;
	while (c != 'q')
	{
		SDL_PollEvent(&event);
		if(event.type == SDL_KEYDOWN){
			switch(event.key.keysym.sym){
				case SDLK_c:
				 c = 'c';
				 break;
				case SDLK_q:
				 c = 'q';
				 break;
				default:
				 c = 0;
				 break;
			}
		}
		
		if(c == 'c'){
			SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
			c = 0;
		}
		
		// Swap main surface buffers
	    SDL_Flip(ecran);
	    
		temphand = findGreenDot(capture);
		
		if(temphand.x + temphand.y < 0){
			oldhand = temphand;
			//printf("%d,%d\n", oldhand.x, oldhand.y);
			continue;
		}
		
		if(oldhand.x + oldhand.y < 0){
			oldhand = temphand;
		}
		else{
			oldhand = hand;
		}
		
		hand = temphand;
		
		drawTrace(oldhand, hand, ecran);
		
	}
	
	exit_sdl(ecran);
	cvReleaseCapture(&capture);
	return 0;
}

CvCapture* initCV(){
	CvCapture *capture = cvCreateCameraCapture(0);

	if(!capture){
		return NULL;
	}
	cvSetCaptureProperty(capture,CV_CAP_PROP_FRAME_WIDTH,LARGEUR);
	cvSetCaptureProperty(capture,CV_CAP_PROP_FRAME_HEIGHT,HAUTEUR);
	return capture;
}

void go(){
	SDL_Event event;
	do{
		SDL_PollEvent(&event);
	}while(!(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE));
}
