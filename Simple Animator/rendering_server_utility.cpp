#include "rendering_server_utility.h"

GLuint RenderingServer::create_shader(GLenum shader_type)
{
	return glCreateShader(shader_type);
}
void RenderingServer::destroy_shader(GLuint shader)
{
	glDeleteShader(shader);
}
void RenderingServer::set_shader_source(GLuint shader, std::string source)
{
	const char* c_str = source.c_str();
	int source_length = source.length();
	glShaderSource(shader, 1, &c_str, &source_length);
}
void RenderingServer::compile_shader(GLuint shader)
{
	glCompileShader(shader);
}
