#include <stdio.h>
#include <SDL3/SDL.h>
#include <glad/glad.h>

#include "updatable_scene.h"
#include "runtime.h"
#include "mesh_builder.h"
#include "debug_updatable_object.h"

int main()
{
	GlobalRuntimeBuilder global_builder = GlobalRuntimeBuilder();
	global_builder.opengl_enabled = true;
	global_builder.opengl_context_major_version = 4;
	global_builder.opengl_context_minor_version = 6;
	global_builder.opengl_use_core = true;
	global_builder.opengl_enable_debug = true;
	Runtime::initialize_globals(global_builder);

	RuntimeBuilder builder = RuntimeBuilder();
	builder.window_name = "Window";
	builder.window_width = 512;
	builder.window_height = 512;
	builder.window_flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL;

	Runtime runtime = Runtime(builder);

	runtime.get_updatable_scene().get_root().add_child(new DebugUpdatableObject());

	runtime.begin();

	return 0;
}