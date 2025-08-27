#include "rendering_server.h"
#include "runtime.h"

RenderingServer::RenderingServer(Runtime* runtime) : Server(runtime)
{
	if (runtime->get_global_builder().opengl_enabled == false)
	{
		return;
	}

	SDL_Window* window = runtime->get_window().get_sdl_window();
	_gl_context = SDL_GL_CreateContext(window);
	int load_result = gladLoadGL();

	printf("%d\n", load_result);
	printf("\n");
}
RenderingServer::~RenderingServer()
{
	SDL_GL_DestroyContext(_gl_context);
}

void RenderingServer::pre_update(Runtime* runtime)
{

}
void RenderingServer::post_update(Runtime* runtime)
{

}

