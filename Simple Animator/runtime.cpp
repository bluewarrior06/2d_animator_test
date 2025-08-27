#include "runtime.h"

#include "window_handler_updatable_object.h"
#include "rendering_server_updatable_object.h"

GlobalRuntimeBuilder Runtime::_global_builder = GlobalRuntimeBuilder();

Runtime::Runtime(RuntimeBuilder builder)
	: _window(
		builder.window_name,
		builder.window_width,
		builder.window_height,
		builder.window_flags)

	,_rendering_server(this)
{
	_scene.get_root()._sync(this);

	WindowHandlerUpdatableObject* window_handler = new WindowHandlerUpdatableObject();
	RenderingServerUpdatableObject* rendering_server = new RenderingServerUpdatableObject();
	
	_scene.get_root().add_child(window_handler);
	_scene.get_root().add_child(rendering_server);

	_builder = builder;
}
Runtime::~Runtime()
{
	SDL_Quit();
}

void Runtime::_mainloop()
{
	while (_is_running)
	{
		_pre_update_servers();
		_input.poll_events();
		_scene.update_root();
		_scene.draw_root();
		_post_update_servers();
	}
}
void Runtime::_pre_update_servers()
{
	_rendering_server.pre_update(this);
}
void Runtime::_post_update_servers()
{
	_rendering_server.post_update(this);
}

void Runtime::initialize_globals(GlobalRuntimeBuilder builder)
{
	SDL_Init(SDL_INIT_VIDEO);

	if (builder.opengl_enabled)
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, builder.opengl_context_major_version);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, builder.opengl_context_minor_version);

		int opengl_flags = 0;
		int opengl_profile_flags = 0;
		if (builder.opengl_enable_debug)
		{
			opengl_flags |= SDL_GL_CONTEXT_DEBUG_FLAG;
		}

		if (builder.opengl_use_compatibility)
		{
			opengl_profile_flags |= SDL_GL_CONTEXT_PROFILE_COMPATIBILITY;
		}
		if (builder.opengl_use_core)
		{
			opengl_profile_flags |= SDL_GL_CONTEXT_PROFILE_CORE;
		}
		if (builder.opengl_use_es)
		{
			opengl_profile_flags |= SDL_GL_CONTEXT_PROFILE_ES;
		}
	
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, opengl_flags);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, opengl_profile_flags);
	}

	_global_builder = builder;
}

void Runtime::begin()
{
	_is_running = true;
	_mainloop();
}
void Runtime::end()
{
	_is_running = false;
}

bool Runtime::is_currently_running()
{
	return _is_running;
}

const GlobalRuntimeBuilder& Runtime::get_global_builder()
{
	return _global_builder;
}
const RuntimeBuilder& Runtime::get_builder()
{
	return _builder;
}
UpdatableScene& Runtime::get_updatable_scene()
{
	return _scene;
}
Input& Runtime::get_input()
{
	return _input;
}
Window& Runtime::get_window()
{
	return _window;
}