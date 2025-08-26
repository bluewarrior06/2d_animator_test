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
	Window(Window&& move) noexcept;
	~Window();
	
private:
	SDL_Window* _window = nullptr;

public:
	SDL_Window* get_sdl_window();

	void operator=(const Window& copy);
	void operator=(Window&& move) noexcept;
};

#endif