#ifndef _EVENT_HANDLER_H_
#define _EVENT_HANDLER_H_

#include <vector>
#include "event.h"

template <class EventArguments>
class EventHandler
{
public:
	EventHandler()
	{

	}
	EventHandler(EventHandler& copy)
	{

	}
	EventHandler(EventHandler&& move)
	{

	}
	~EventHandler()
	{

	}

	std::vector<Event<EventArguments>> events;

	void activate(EventArguments arguments)
	{
		for (Event<EventArguments>& event : events)
		{
			event.activated(arguments);
		}
	}
};

#endif