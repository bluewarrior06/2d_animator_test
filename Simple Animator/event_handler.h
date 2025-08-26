#ifndef _EVENT_HANDLER_H_
#define _EVENT_HANDLER_H_

#include <vector>
#include "event.h"

/// <summary>
/// 
/// </summary>
/// <typeparam name="EventArguments">The type of Event class.</typeparam>
/// <typeparam name="EventType">The type of argument to send to Event</typeparam>
template <class EventType, class EventArguments>
class EventHandler
{
public:
	EventHandler()
	{

	}
	EventHandler(EventHandler& copy)
	{

	}
	EventHandler(EventHandler&& move) noexcept
	{

	}
	~EventHandler()
	{

	}

	std::vector<EventType> events;

	void activate(EventArguments arguments)
	{
		for (EventType& event : events)
		{
			event.activated(arguments);
		}
	}
};

#endif