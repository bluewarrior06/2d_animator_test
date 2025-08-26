#include <stdio.h>
#include <SDL3/SDL.h>
#include <glad/glad.h>

#include "event_handler.h"
#include "sdl_event_event_handler.h"
#include "window_sdl_event.h"

#include "runtime.h"

int main()
{
	SDL_Window* window = SDL_CreateWindow("Window", 1280, 720, SDL_WINDOW_RESIZABLE);

	SDL_Event last_event = SDL_Event();

	EventHandler<WindowSDLEvent, SDL_Event> window_events = EventHandler<WindowSDLEvent, SDL_Event>();
	WindowSDLEvent window_event = WindowSDLEvent();
	window_event.window = window;
	window_events.events.push_back(std::move(window_event));

	Runtime runtime = Runtime();

	runtime.begin();

	bool running = true;
	while (running)
	{
		while (SDL_PollEvent(&last_event))
		{
			window_events.activate(last_event);
		}
	}

	SDL_DestroyWindow(window);

	return 0;
}