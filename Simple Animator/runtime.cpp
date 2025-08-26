#include "runtime.h"

Runtime::Runtime()
{
}
Runtime::Runtime(const Runtime& copy)
{
	this->_window = new Window(*copy._window);
	this->_input_events = copy._input_events;

}
Runtime::Runtime(const Runtime&& move)
{

}
Runtime::~Runtime()
{
	if (_window != nullptr)
	{
		delete _window;
	}
}

void Runtime::_mainloop()
{
	while (_is_running)
	{
		_input_events.poll_events();
	}
}

void Runtime::begin()
{
	_window = new Window(
		window_name_on_begin,
		window_width_on_begin,
		window_height_on_begin,
		window_flags_on_begin);
	
	_input_events.event_handler.events.push_back(SDLEventEvent());

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