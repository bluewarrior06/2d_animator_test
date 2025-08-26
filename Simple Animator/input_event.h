#ifndef _INPUT_EVENT_H_
#define _INPUT_EVENT_H_

#include <SDL3/SDL.h>
#include "sdl_event_event_handler.h"

/// <summary>
/// Handles the polling of SDL input events.
/// </summary>
class InputEvent
{
public:
	InputEvent();
	InputEvent(const InputEvent& copy);
	InputEvent(InputEvent&& move) noexcept;
	~InputEvent();

private:
	SDL_Event last_event = SDL_Event();

public:
	/// <summary>
	/// Gets activated for every event found during poll_events.
	/// </summary>
	SDLEventEventHandler event_handler = SDLEventEventHandler();

	/// <summary>
	/// Poll events, and activate the event handler.
	/// </summary>
	void poll_events();

	void operator=(const InputEvent& copy);
	void operator=(InputEvent&& move) noexcept;
};

#endif