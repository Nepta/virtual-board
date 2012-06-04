#include "defines.h"

// Chopped down even function
//sets the position of the cursor
Position getMousePosition()
{
	Position position;
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_MOUSEMOTION:
                position.x = event.motion.x;
                position.y = event.motion.y;
            break;
//            case SDL_QUIT: return 0;
        }
    }
    return position;
}
