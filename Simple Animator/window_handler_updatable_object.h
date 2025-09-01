#ifndef _WINDOW_HANDLER_UPDATABLE_OBJECT_H_
#define _WINDOW_HANDLER_UPDATABLE_OBJECT_H_

#include "updatable_object.h"

class WindowHandlerUpdatableObject : public UpdatableObject
{
protected:
	void update() override;
};

#endif