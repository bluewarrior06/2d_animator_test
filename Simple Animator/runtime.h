#ifndef _RUNTIME_H_
#define _RUNTIME_H_

#include "input_event.h"
#include "window.h"

/// <summary>
/// Encapsulates runtime logic into a single class.
/// </summary>
class Runtime
{
public:
	Runtime();
	Runtime(const Runtime& copy);
	Runtime(const Runtime&& move);
	~Runtime();

private:
	Window* _window;
	InputEvent _input_events = InputEvent();
	
	bool _is_running = false;
	
	void _mainloop();

public:
	std::string window_name_on_begin = "Window";
	int window_width_on_begin = 0;
	int window_height_on_begin = 0;
	int window_flags_on_begin = SDL_WINDOW_RESIZABLE;

	// Constructs critical features and begins the mainloop.

	void begin();
	// Ends the mainloop.
	// The mainloop will end once the loop is done processing a loop.
	void end();

	bool is_currently_running();

};

#endif