#ifndef _CLOSE_WINDOW_SDL_EVENT_H_
#define _CLOSE_WINDOW_SDL_EVENT_H_

#include "window_sdl_event.h"

class CloseWindowSDLEvent : public WindowSDLEvent
{
	void activate(SDL_Event& event)
	{
		if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED)
		{

		}
	}
};
#endif