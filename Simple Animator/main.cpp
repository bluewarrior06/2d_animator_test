#include <stdio.h>
#include <SDL3/SDL.h>
#include <glad/glad.h>

#include "event_handler.h"
#include "sdl_event_event_handler.h"

#include "runtime.h"

int main()
{
	RuntimeBuilder runtime_builder = RuntimeBuilder();
	runtime_builder.window_name = "Window";
	runtime_builder.window_width = 512;
	runtime_builder.window_height = 512;
	runtime_builder.window_flags = SDL_WINDOW_RESIZABLE;

	Runtime runtime = Runtime(runtime_builder);
	runtime.begin();
	
	return 0;
}