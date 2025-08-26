#include "window.h"

#include <exception>

Window::Window(std::string name, int width, int height, SDL_WindowFlags window_flags)
{
	_window = SDL_CreateWindow(
		name.c_str(),
		width,
		height,
		window_flags
	);
}
Window::Window(const Window& copy)
{
	if (this->_window != nullptr)
	{
		SDL_DestroyWindow(this->_window);
	}

	if (copy._window != nullptr)
	{
		const char* copied_window_name = SDL_GetWindowTitle(copy._window);
		int copied_window_width = 0;
		int copied_window_height = 0;
		SDL_GetWindowSize(copy._window, &copied_window_width, &copied_window_height);
		SDL_WindowFlags copied_window_flags = SDL_GetWindowFlags(copy._window);

		this->_window = SDL_CreateWindow(
			copied_window_name,
			copied_window_width,
			copied_window_height,
			copied_window_flags
		);
	}
}
Window::Window(Window&& move)
{
	this->_window = move._window;
	move._window = nullptr;
}
Window::~Window()
{
	if (_window != nullptr)
	{
		SDL_DestroyWindow(_window);
	}
}

void Window::operator=(const Window& copy)
{
	if (this->_window != nullptr)
	{
		SDL_DestroyWindow(this->_window);
	}

	if (copy._window != nullptr)
	{
		const char* copied_window_name = SDL_GetWindowTitle(copy._window);
		int copied_window_width = 0;
		int copied_window_height = 0;
		SDL_GetWindowSize(copy._window, &copied_window_width, &copied_window_height);
		SDL_WindowFlags copied_window_flags = SDL_GetWindowFlags(copy._window);

		this->_window = SDL_CreateWindow(
			copied_window_name,
			copied_window_width,
			copied_window_height,
			copied_window_flags
		);
	}
}
void Window::operator=(Window&& move)
{

}