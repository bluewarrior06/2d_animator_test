#include "input_event.h"

InputEvent::InputEvent()
{

}
InputEvent::InputEvent(const InputEvent& copy)
{
	this->last_event = copy.last_event;
}
InputEvent::InputEvent(InputEvent&& move) noexcept
{
	this->last_event = move.last_event;
	move.last_event = SDL_Event();
}
InputEvent::~InputEvent()
{

}

void InputEvent::poll_events()
{
	while (SDL_PollEvent(&last_event))
	{
		event_handler.activate(last_event);
	}
}

void InputEvent::operator=(const InputEvent& copy)
{
	this->last_event = copy.last_event;
}
void InputEvent::operator=(InputEvent&& move) noexcept
{
	this->last_event = move.last_event;
	move.last_event = SDL_Event();
}