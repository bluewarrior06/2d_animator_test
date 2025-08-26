#include "updatable_object.h"

#include <stdio.h>

UpdatableObject::UpdatableObject()
{
	_name = "updatable_object";
}
UpdatableObject::~UpdatableObject()
{
	for (UpdatableObject* child : _children)
	{
		delete child;
	}
}

void UpdatableObject::update()
{
}
void UpdatableObject::draw()
{
}

bool UpdatableObject::has_child(UpdatableObject* child)
{
	for (UpdatableObject* existing_child : _children)
	{
		if (existing_child == child)
		{
			return true;
		}
	}
	return false;
}
void UpdatableObject::add_child(UpdatableObject* child)
{
	_children.push_back(child);
}
void UpdatableObject::remove_child(UpdatableObject* child)
{
	for (int index = 0; index < _children.size(); index++)
	{
		UpdatableObject* existing_child = _children[index];
		if (existing_child == child)
		{
			_children.erase(_children.begin() + index);
			break;
		}
	}
}

void UpdatableObject::rename(std::string new_name)
{
	_name = new_name;
}
std::string UpdatableObject::get_name()
{
	return _name;
}