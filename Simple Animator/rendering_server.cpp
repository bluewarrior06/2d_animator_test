#include "rendering_server.h"
#include "runtime.h"

#include <sstream>

void gl_debug_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* user_param)
{
    std::stringstream debug_output;

    debug_output << "OpenGL has encountered an unexpected behavior!\n";

    debug_output << "\tSource: ";
    switch (source)
    {
    case GL_DEBUG_SOURCE_API:
        debug_output << "GL_DEBUG_SOURCE_API\n";
        break;
    case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
        debug_output << "GL_DEBUG_SOURCE_WINDOW_SYSTEM\n";
        break;
    case GL_DEBUG_SOURCE_SHADER_COMPILER:
        debug_output << "GL_DEBUG_SOURCE_SHADER_COMPILER\n";
        break;
    case GL_DEBUG_SOURCE_THIRD_PARTY:
        debug_output << "GL_DEBUG_SOURCE_THIRD_PARTY\n";
        break;
    case GL_DEBUG_SOURCE_APPLICATION:
        debug_output << "GL_DEBUG_SOURCE_APPLICATION\n";
        break;
    case GL_DEBUG_SOURCE_OTHER:
        debug_output << "GL_DEBUG_SOURCE_OTHER\n";
        break;
    }

    debug_output << "\tType: " << type << "\n";

    debug_output << "\tSeverity: ";
    switch (severity)
    {
    case GL_DEBUG_SEVERITY_HIGH:
        debug_output << "GL_DEBUG_SEVERITY_HIGH\n";
        break;
    case GL_DEBUG_SEVERITY_MEDIUM:
        debug_output << "GL_DEBUG_SEVERITY_MEDIUM\n";
        break;
    case GL_DEBUG_SEVERITY_LOW:
        debug_output << "GL_DEBUG_SEVERITY_LOW\n";
        break;
    case GL_DEBUG_SEVERITY_NOTIFICATION:
        debug_output << "GL_DEBUG_SEVERITY_NOTIFICATION\n";
        break;
    }

    debug_output << "\tID: " << id << "\n";

    debug_output << "\tMessage: \"" << message << "\"";

    debug_output << "\n";

    printf("%s\n", debug_output.str().c_str());
}

RenderingServer::RenderingServer(Runtime* runtime) : Server(runtime)
{
	if (runtime->get_global_builder().opengl_enabled == false)
	{
		return;
	}

	SDL_Window* window = runtime->get_window().get_sdl_window();
	_gl_context = SDL_GL_CreateContext(window);
	gladLoadGL();

	if (runtime->get_global_builder().opengl_enable_debug)
	{
        glDebugMessageCallback(gl_debug_callback, nullptr);
	}
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
