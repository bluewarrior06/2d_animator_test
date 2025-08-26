#ifndef _SDL_EVENT_EVENT_H_
#define _SDL_EVENT_EVENT_H_

#include <SDL3/SDL.h>
#include "event.h"

class SDLEventEvent : public Event<SDL_Event>
{
public:
	void activated(SDL_Event& arguments) override
	{

	}
};

#endif