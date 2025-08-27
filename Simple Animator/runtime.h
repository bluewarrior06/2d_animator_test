#ifndef _RUNTIME_H_
#define _RUNTIME_H_

#include "Input.h"
#include "window.h"
#include "updatable_scene.h"
#include "rendering_server.h"

/// <summary>
/// Holds properties to be passed int a Runtime object during construction.
/// </summary>
struct RuntimeBuilder
{
	std::string window_name = "Window";
	int window_width = 0;
	int window_height = 0;
	SDL_WindowFlags window_flags = 0;

	
};

struct GlobalRuntimeBuilder
{
	bool opengl_enabled = false;
	int opengl_context_major_version = 1;
	int opengl_context_minor_version = 1;
	bool opengl_enable_debug = false;
	bool opengl_use_compatibility = false;
	bool opengl_use_core = false;
	bool opengl_use_es = false;
};

/// <summary>
/// Encapsulates runtime logic into a single class.
/// </summary>
class Runtime
{
public:
	Runtime(RuntimeBuilder builder);
	~Runtime();

private:
	static GlobalRuntimeBuilder _global_builder;

	Window* _window = nullptr;
	SDL_GLContext _gl_context = nullptr;
	Input _input = Input();
	UpdatableScene _scene = UpdatableScene();

	RenderingServer rendering_server = RenderingServer(this);

	bool _is_running = false;
	
	void _mainloop();
	void _pre_update_servers();
	void _post_update_servers();

public:
	static void initialize_globals(GlobalRuntimeBuilder builder);

	// Begins the mainloop.
	void begin();
	// Ends the mainloop.
	// The mainloop will end once the loop is done processing a loop.
	void end();

	// If the runtime object is currently running.
	bool is_currently_running();

	UpdatableScene& get_updatable_scene();
	Input& get_input();
};

#endif