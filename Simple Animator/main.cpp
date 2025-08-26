#include <stdio.h>
#include <SDL3/SDL.h>
#include <glad/glad.h>

int main()
{
	SDL_Window* window = SDL_CreateWindow("Window", 1280, 720, SDL_WINDOW_RESIZABLE);

	SDL_Event last_event = SDL_Event();

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