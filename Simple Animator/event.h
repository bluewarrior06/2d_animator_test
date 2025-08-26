#ifndef _EVENT_H_
#define _EVENT_H_

#include <stdio.h>

/// <summary>
/// Events can be attached onto an EventHandler, which can then be activated.
/// </summary>
/// <typeparam name="EventArguments"></typeparam>
template <class EventArguments>
class Event
{
public:
	Event()
	{

	}
	Event(Event& copy)
	{

	}
	Event(Event&& move) noexcept
	{

	}
	~Event()
	{

	}

	virtual void activated(EventArguments& arguments)
	{
		printf("Listened!");
	}
};

#endif