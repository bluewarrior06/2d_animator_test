#ifndef _INPUT_H_
#define _INPUT_H_

#include <SDL3/SDL.h>
#include "sdl_event_event_handler.h"

/// <summary>
/// Handles the polling of SDL input events.
/// </summary>
class Input
{
public:
	Input();
	Input(const Input& copy);
	Input(Input&& move) noexcept;
	~Input();

private:
	SDL_Event last_event = SDL_Event();

public:
	std::vector<SDL_Event> last_events = std::vector<SDL_Event>();

	/// <summary>
	/// Gets activated for every event found during poll_events.
	/// </summary>
	SDLEventEventHandler event_handler = SDLEventEventHandler();

	/// <summary>
	/// Poll events, and activate the event handler.
	/// </summary>
	void poll_events();

	void operator=(const Input& copy);
	void operator=(Input&& move) noexcept;
};

#endif