#ifndef _WINDOW_HANDLER_UPDATABLE_OBJECT_H_
#define _WINDOW_HANDLER_UPDATABLE_OBJECT_H_

#include "updatable_object.h"

class WindowHandlerUpdatableObject : public UpdatableObject
{
public:
	WindowHandlerUpdatableObject();
	~WindowHandlerUpdatableObject();

	void update() override;
};

#endif