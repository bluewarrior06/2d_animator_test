#ifndef _WINDOW_SDL_EVENT_H_
#define _WINDOW_SDL_EVENT_H_

#include "sdl_event_event.h"

/// <summary>
/// Adds functionality to handling an sdl window.
/// </summary>
class WindowSDLEvent : public SDLEventEvent
{
public:
	WindowSDLEvent()
	{
	}
	WindowSDLEvent(WindowSDLEvent& copy)
	{
		this->window = copy.window;
	}
	WindowSDLEvent(WindowSDLEvent&& move) noexcept
	{
		this->window = move.window;

		move.window = nullptr;
	}
	~WindowSDLEvent()
	{

	}
	SDL_Window* window = nullptr;

	void activate(SDL_Event& event)
	{
	}
};


#endif