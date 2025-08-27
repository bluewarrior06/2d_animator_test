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
/// 
/// Holds a window to display visuals.
/// Holds an Input for reading input.
/// Holds an UpdatableScene for dynamic objects.
/// 
/// Holds Servers for individualized processing. Each server will process its own information.
/// </summary>
class Runtime
{
public:
	Runtime(RuntimeBuilder builder);
	~Runtime();

private:
	static GlobalRuntimeBuilder _global_builder;

	RuntimeBuilder _builder;

	Window _window;

	Input _input = Input();
	UpdatableScene _scene = UpdatableScene();

	RenderingServer _rendering_server;

	bool _is_running = false;
	
	void _mainloop();
	void _pre_update_servers();
	void _post_update_servers();

public:
	static void initialize_globals(GlobalRuntimeBuilder builder);

	// Begins the mainloop.
	void begin();
	// Ends the mainloop.
	// The mainloop will fully end once the mainloop is done its cycle.
	void end();

	// If the runtime object is currently running.
	// Will begin returning right after false, though the program may still be running,
	// since the application only will truly stop running once the mainloop finishes its cycle.
	bool is_currently_running();

	const GlobalRuntimeBuilder& get_global_builder();
	const RuntimeBuilder& get_builder();

	UpdatableScene& get_updatable_scene();
	Input& get_input();
	Window& get_window();
};

#endif