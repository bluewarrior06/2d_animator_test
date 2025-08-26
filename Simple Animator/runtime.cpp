#include "runtime.h"

Runtime::Runtime(RuntimeBuilder builder)
{
	_window = new Window(
		builder.window_name,
		builder.window_width,
		builder.window_height,
		builder.window_flags);
}
Runtime::Runtime(const Runtime& copy)
{
	if (copy._window != nullptr)
	{
		this->_window = new Window(*copy._window);
	}
	this->_input_events = copy._input_events;

}
Runtime::Runtime(const Runtime&& move)
{
	this->_window = move._window;
	this->_input_events = move._input_events;
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