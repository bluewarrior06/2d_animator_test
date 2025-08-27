#include <stdio.h>
#include <SDL3/SDL.h>
#include <glad/glad.h>

#include "updatable_scene.h"
#include "runtime.h"

int main()
{
	
	GlobalRuntimeBuilder global_builder = GlobalRuntimeBuilder();
	global_builder.opengl_enabled = true;
	global_builder.opengl_context_major_version = 4;
	global_builder.opengl_context_minor_version = 6;
	global_builder.opengl_use_core = true;
	Runtime::initialize_globals(global_builder);

	RuntimeBuilder builder = RuntimeBuilder();
	builder.window_name = "Window";
	builder.window_width = 512;
	builder.window_height = 512;
	builder.window_flags = SDL_WINDOW_RESIZABLE;

	Runtime runtime = Runtime(builder);
	
	UpdatableObject& runtime_root = runtime.get_updatable_scene().get_root();

	runtime.begin();

	return 0;
}