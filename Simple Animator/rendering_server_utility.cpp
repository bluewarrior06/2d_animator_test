#include "rendering_server_utility.h"

GLuint RenderingServerUtility::create_shader(GLenum shader_type)
{
	return glCreateShader(shader_type);
}
void RenderingServerUtility::destroy_shader(GLuint shader)
{
	glDeleteShader(shader);
}
void RenderingServerUtility::set_shader_source(GLuint shader, std::string source)
{
	const char* c_str = source.c_str();
	int source_length = source.length();
	glShaderSource(shader, 1, &c_str, &source_length);
}
void RenderingServerUtility::compile_shader(GLuint shader)
{
	glCompileShader(shader);
}
std::string RenderingServerUtility::get_shader_info_log(GLuint shader)
{
	int shader_info_log_length = 0;

	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &shader_info_log_length);
	if (shader_info_log_length == 0)
	{
		return "";
	}

	std::string info_log = "";
	info_log.resize(shader_info_log_length + 1, '\0');
	glGetShaderInfoLog(shader, shader_info_log_length, &shader_info_log_length, (GLchar*)info_log.c_str());
	return info_log;
}

GLuint RenderingServerUtility::create_program()
{
	return glCreateProgram();
}
void RenderingServerUtility::destroy_program(GLuint program)
{
	glDeleteProgram(program);
}
void RenderingServerUtility::attach_shader(GLuint program, GLuint shader)
{
	glAttachShader(program, shader);
}
void RenderingServerUtility::detach_shader(GLuint program, GLuint shader)
{
	glDetachShader(program, shader);
}
void RenderingServerUtility::link_program(GLuint program)
{
	glLinkProgram(program);
}
void RenderingServerUtility::validate_program(GLuint program)
{
	glValidateProgram(program);
}
void RenderingServerUtility::use_program(GLuint program)
{
	glUseProgram(program);
}