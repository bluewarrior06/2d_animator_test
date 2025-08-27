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
	gladLoadGL();
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

ProgramUniformInfo::ProgramUniformInfo(GLuint program, GLint index)
{
	(const_cast<GLuint&>(this->program)) = program;

	glGetActiveUniform(program, index, UNIFORM_MAX_BUFFER_SIZE, const_cast<GLsizei*>(&length), const_cast<GLint*>(&size), const_cast<GLenum*>(&type), nullptr);
	
	int uniform_name_size = 0;
	glGetActiveUniformName(program, index, UNIFORM_MAX_BUFFER_SIZE, &uniform_name_size, nullptr);
	name.resize(uniform_name_size + 1, '\0');
	glGetActiveUniformName(program, index, UNIFORM_MAX_BUFFER_SIZE, nullptr, (GLchar*)name.c_str());
}