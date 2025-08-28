#include "updatable_object.h"

#include <stdio.h>

UpdatableObject::UpdatableObject()
{
	_name = "updatable_object";
	initialize();
}
UpdatableObject::~UpdatableObject()
{
	_exit_scene_and_propagate();
	destroy();
	for (UpdatableObject* child : _children)
	{
		delete child;
	}
}

void UpdatableObject::_update_and_propagate()
{
	update();
	for (UpdatableObject* child : _children)
	{
		child->_update_and_propagate();
	}
}
void UpdatableObject::_draw_and_propagate()
{
	draw();
	for (UpdatableObject* child : _children)
	{
		child->_draw_and_propagate();
	}
}
void UpdatableObject::_enter_scene_and_propagate()
{
	if (_is_in_scene == false)
	{
		enter_scene();
		_is_in_scene = true;
	}
	for (UpdatableObject* child : _children)
	{
		child->_enter_scene_and_propagate();
	}
}
void UpdatableObject::_exit_scene_and_propagate()
{
	if (_is_in_scene)
	{
		exit_scene();
		_is_in_scene = false;
	}
	for (UpdatableObject* child : _children)
	{
		child->_exit_scene_and_propagate();
	}
}

void UpdatableObject::_sync(Runtime* runtime)
{
	this->_sync_runtime = runtime;
}

void UpdatableObject::_sync_and_propagate(Runtime* runtime)
{
	_sync(runtime);
	for (UpdatableObject* child : _children)
	{
		child->_sync_and_propagate(_sync_runtime);
	}
}



void UpdatableObject::initialize()
{

}
void UpdatableObject::destroy()
{

}
void UpdatableObject::update()
{
}
void UpdatableObject::draw()
{
}
void UpdatableObject::enter_scene()
{

}
void UpdatableObject::exit_scene()
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
	child->_sync_and_propagate(_sync_runtime);
	child->_enter_scene_and_propagate();
}
void UpdatableObject::remove_child(UpdatableObject* child)
{
	for (int index = 0; index < _children.size(); index++)
	{
		UpdatableObject* existing_child = _children[index];
		if (existing_child == child)
		{
			_children.erase(_children.begin() + index);
			child->_sync_and_propagate(_sync_runtime);
			child->_exit_scene_and_propagate();
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

Runtime* UpdatableObject::get_runtime()
{
	return _sync_runtime;
}