#include <stdio.h>
#include <SDL3/SDL.h>
#include <glad/glad.h>

#include "event_handler.h"

int main()
{
	SDL_Window* window = SDL_CreateWindow("Window", 1280, 720, SDL_WINDOW_RESIZABLE);

	SDL_Event last_event = SDL_Event();

	EventHandler<float> arguments;
	arguments.events.push_back(Event<float>());
	arguments.activate(10.0f);

	bool running = true;
	while (running)
	{
		while (SDL_PollEvent(&last_event))
		{
		}
	}

	SDL_DestroyWindow(window);

	return 0;
}