#ifndef _RENDERING_SERVER_UTILITY_H_
#define _RENDERING_SERVER_UTILITY_H_

#include <vector>
#include <string>
#include <glad/glad.h>

#define UNIFORM_MAX_BUFFER_SIZE ((GLint)512)

/// <summary>
/// A single uniform found using RenderingServerUtility::get_active_uniforms(...).
/// Shouldn't be moved or copied.
/// </summary>
struct ProgramUniformInfo
{
	ProgramUniformInfo(GLuint program, GLint index);

	// The program that the uniform is associated with.
	const GLuint program = 0;
	const GLsizei length = 0;
	const GLint size = 0;
	const GLenum type = 0;
	std::string name = "";
};

/// <summary>
/// Houses many methods for managing OpenGL objects, and some RenderingServer properties.
/// </summary>
struct RenderingServerUtility
{

	GLuint static create_shader(GLenum shader_type);
	void static destroy_shader(GLuint shader);
	void static set_shader_source(GLuint shader, std::string source);
	void static compile_shader(GLuint shader);
	std::string static get_shader_info_log(GLuint shader);

	GLuint static create_program();
	void static destroy_program(GLuint program);
	void static attach_shader(GLuint program, GLuint shader);
	void static detach_shader(GLuint program, GLuint shader);
	void static link_program(GLuint program);
	void static validate_program(GLuint program);
	void static use_program(GLuint program);
	std::vector<ProgramUniformInfo> static get_active_uniforms(GLuint program);
};

#endif

