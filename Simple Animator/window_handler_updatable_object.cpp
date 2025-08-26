#include "window_handler_updatable_object.h"
#include "runtime.h"

WindowHandlerUpdatableObject::WindowHandlerUpdatableObject()
{
	rename("window_handler");
}

void WindowHandlerUpdatableObject::update()
{
	Runtime* runtime = get_runtime();
	if (runtime == nullptr)
	{
		return;
	}

	for (SDL_Event& event : runtime->get_input().last_events)
	{
		if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED)
		{
			runtime->end();
		}
	}
}