#include "updatable_object.h"

#include <stdio.h>

UpdatableObject::UpdatableObject()
{
}
UpdatableObject::UpdatableObject(const UpdatableObject& copy)
{
	this->_name = copy._name;
}
UpdatableObject::~UpdatableObject()
{
}

void UpdatableObject::update()
{
}
void UpdatableObject::draw()
{
}

void UpdatableObject::operator=(const UpdatableObject& copy)
{
	this->_name = copy._name;
}