#ifndef _SDL_EVENT_EVENT_H_
#define _SDL_EVENT_EVENT_H_

#include "event.h"
#include <SDL3/SDL.h>

/// <summary>
/// Base class for listening to sdl events during runtime.
/// </summary>
class SDLEventEvent : public Event<SDL_Event&>
{
public:
	SDLEventEvent()
	{
		printf("CTOR\n");
	}
	SDLEventEvent(SDLEventEvent& copy)
	{
	}
	SDLEventEvent(SDLEventEvent&& move) noexcept
	{

	}
	~SDLEventEvent()
	{

	}

public:
	void activated(SDL_Event event)
	{
		printf("Event Activated.\n");
	}
};

#endif