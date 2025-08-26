#include "Input.h"

Input::Input()
{

}
Input::Input(const Input& copy)
{
	this->last_event = copy.last_event;
}
Input::Input(Input&& move) noexcept
{
	this->last_event = move.last_event;
	move.last_event = SDL_Event();
}
Input::~Input()
{

}

void Input::poll_events()
{
	last_events.clear();
	while (SDL_PollEvent(&last_event))
	{
		event_handler.activate(last_event);
		last_events.push_back(last_event);
	}
}

void Input::operator=(const Input& copy)
{
	this->last_event = copy.last_event;
}
void Input::operator=(Input&& move) noexcept
{
	this->last_event = move.last_event;
	move.last_event = SDL_Event();
}