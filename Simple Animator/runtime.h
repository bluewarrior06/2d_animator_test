#ifndef _RUNTIME_H_
#define _RUNTIME_H_

#include "input_event.h"
#include "window.h"

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
	Runtime(const Runtime& copy);
	Runtime(const Runtime&& move);
	~Runtime();

private:
	Window* _window;
	InputEvent _input_events = InputEvent();
	
	bool _is_running = false;
	
	void _mainloop();

public:
	// Begins the mainloop.
	void begin();
	// Ends the mainloop.
	// The mainloop will end once the loop is done processing a loop.
	void end();

	bool is_currently_running();

};

#endif