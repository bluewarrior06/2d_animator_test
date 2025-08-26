#include <stdio.h>
#include <SDL3/SDL.h>
#include <glad/glad.h>

#include "event_handler.h"
#include "sdl_event_event_handler.h"

#include "runtime.h"

int main()
{
	
	Runtime runtime = Runtime();

	runtime.window_width_on_begin = 512;
	runtime.window_height_on_begin = 512;

	runtime.begin();

	return 0;
}