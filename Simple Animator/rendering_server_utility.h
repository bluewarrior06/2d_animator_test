#ifndef _RENDERING_SERVER_UTILITY_H_
#define _RENDERING_SERVER_UTILITY_H_

#include <string>
#include <glad/glad.h>

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
};

#endif

