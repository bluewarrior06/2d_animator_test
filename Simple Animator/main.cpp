#include <stdio.h>
#include <SDL3/SDL.h>
#include <glad/glad.h>

#include "updatable_scene.h"
#include "runtime.h"

class A
{
public:
	A()
	{
		printf("A CTOR\n");
	}
	virtual void a()
	{
		printf("A\n");
	}
};
class B : public A
{
public:
	B()
	{
		printf("B CTOR\n");
	}
	void a() override
	{
		printf("B\n");
	}
};

int main()
{
	RuntimeBuilder builder = RuntimeBuilder();
	builder.window_name = "Window";
	builder.window_width = 512;
	builder.window_height = 512;
	builder.window_flags = SDL_WINDOW_RESIZABLE;

	Runtime runtime = Runtime(builder);
	runtime.begin();

	return 0;
}