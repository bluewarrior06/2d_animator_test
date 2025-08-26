#include <stdio.h>
#include <SDL3/SDL.h>
#include <glad/glad.h>

#include "updatable_scene.h"
#include "runtime.h"

class UpdatableObject2 : public UpdatableObject
{
	void operator=(UpdatableObject& copy)
	{
		printf("COPY 2.0!\n");
	}
};

int main()
{
	UpdatableScene scene = UpdatableScene();
	UpdatableScene scene2 = scene;

	return 0;
}