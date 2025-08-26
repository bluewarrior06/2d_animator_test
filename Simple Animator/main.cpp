#include <stdio.h>
#include <SDL3/SDL.h>
#include <glad/glad.h>

#include "event_handler.h"
#include "sdl_event_event_handler.h"

int main()
{
	SDL_Window* window = SDL_CreateWindow("Window", 1280, 720, SDL_WINDOW_RESIZABLE);

	SDL_Event last_event = SDL_Event();

	SDLEventEventHandler sdl_event_event_handler = SDLEventEventHandler();
	sdl_event_event_handler.events.push_back(SDLEventEvent());

	bool running = true;
	while (running)
	{
		while (SDL_PollEvent(&last_event))
		{
			sdl_event_event_handler.activate(last_event);
		}
	}

	SDL_DestroyWindow(window);

	return 0;
}