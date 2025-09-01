#ifndef _DEBUG_UPDATABLE_OBJECT_H_
#define _DEBUG_UPDATABLE_OBJECT_H_

#include "updatable_object.h"

class DebugUpdatableObject : public UpdatableObject
{
public:
	void enter_scene() override;
};

#endif