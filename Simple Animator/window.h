#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <SDL3/sdl.h>
#include <string>

/// <summary>
/// Encapsulates an SDL window.
/// </summary>
class Window
{
public:
	Window(std::string name, int width, int height, SDL_WindowFlags window_flags);
	Window(const Window& copy);
	Window(Window&& move);
	~Window();
	
private:
	SDL_Window* _window = nullptr;
};

class WindowErrorException : public std::exception
{

};

#endif