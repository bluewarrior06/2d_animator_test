#include "runtime.h"

Runtime::Runtime()
{

}
Runtime::Runtime(Runtime& copy)
{

}
Runtime::Runtime(Runtime& move)
{

}
~Runtime::Runtime()
{

}

void Runtime::_mainloop()
{
	while (_is_running)
	{

	}
}

void Runtime::begin()
{
	_is_running = false;
	_mainloop();
}
void Runtime::end()
{
	_is_running = false;
}