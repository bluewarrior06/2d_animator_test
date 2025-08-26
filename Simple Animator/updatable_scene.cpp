#include "updatable_scene.h"

UpdatableScene::UpdatableScene()
{
	_root._name = "root";
}
UpdatableScene::UpdatableScene(const UpdatableScene& copy)
{
	printf("COPY\n");
	this->_root = copy._root;
}
UpdatableScene::~UpdatableScene()
{
}

void UpdatableScene::update_root()
{
	_root._update_and_propagate();
}
void UpdatableScene::draw_root()
{
	_root._draw_and_propagate();
}

UpdatableObject& UpdatableScene::get_root()
{
	return _root;
}

void UpdatableScene::operator=(const UpdatableScene& copy)
{

}