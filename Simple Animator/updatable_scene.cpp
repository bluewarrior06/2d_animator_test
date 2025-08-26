#include "updatable_scene.h"

UpdatableScene::UpdatableScene()
{
	_root._name = "ROOT";
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
	_root.update();
}
void UpdatableScene::draw_root()
{
	_root.draw();
}

void UpdatableScene::operator=(const UpdatableScene& copy)
{

}
