#ifndef _RUNTIME_H_
#define _RUNTIME_H_

#include "input_event.h"
#include "window.h"
#include "updatable_scene.h"

/// <summary>
/// Holds properties to be passed int a Runtime object during construction.
/// </summary>
struct RuntimeBuilder
{
	std::string window_name = "Window";
	int window_width = 0;
	int window_height = 0;
	SDL_WindowFlags window_flags = SDL_WINDOW_RESIZABLE;
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
	Window* _window = nullptr;
	InputEvent _input_events = InputEvent();
	UpdatableScene scene = UpdatableScene();

	bool _is_running = false;
	
	void _mainloop();

public:
	// Begins the mainloop.
	void begin();
	// Ends the mainloop.
	// The mainloop will end once the loop is done processing a loop.
	void end();

	// If the runtime object is currently running.
	bool is_currently_running();

};

#endif