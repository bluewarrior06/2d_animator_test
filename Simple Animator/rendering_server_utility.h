#ifndef _RENDERING_SERVER_UTILITY_H_
#define _RENDERING_SERVER_UTILITY_H_

#include <vector>
#include <string>
#include <glad/glad.h>
#include "mesh_builder_attrib_set.h"

#define UNIFORM_MAX_BUFFER_SIZE ((GLint)512)

/// <summary>
/// A single uniform found using RenderingServerUtility::get_active_uniforms(...).
/// 
/// Gets the information of an active uniform, inside a program, at a specified index.
/// 
/// </summary>
struct ProgramUniformInfo
{
	ProgramUniformInfo(GLuint program, GLint index);

	// The program that the uniform is associated with.
	const GLuint program = 0;
	const GLsizei length = 0;
	const GLint size = 0;
	const GLenum type = 0;
	const GLint index = 0;
	const std::string name = "";
};

/// <summary>
/// Houses many methods for managing OpenGL objects, and some RenderingServer properties.
/// </summary>
struct RenderingServerUtility
{

	static void update_viewport(int x, int y, int width, int height);

	static GLuint create_shader(GLenum shader_type);
	static void destroy_shader(GLuint shader);
	static void set_shader_source(GLuint shader, std::string source);
	static void compile_shader(GLuint shader);
	static std::string get_shader_info_log(GLuint shader);
	static bool shader_is_compiled(GLuint shader);

	static GLuint create_program();
	static void destroy_program(GLuint program);
	static void attach_shader(GLuint program, GLuint shader);
	static void detach_shader(GLuint program, GLuint shader);
	static void link_program(GLuint program);
	static std::string get_program_info_log(GLuint program);
	static void validate_program(GLuint program);
	static void use_program(GLuint program);
	static std::vector<ProgramUniformInfo> get_active_uniforms(GLuint program);

	/// <summary>
	/// Sets the uniform for the currently bound program.
	/// The "program" property  in the uniform_info argument isn't checked against
	/// the current program; The one calling this function is in charge in determining
	/// if the current program is currently set.
	/// 
	/// This function simply calls glUniform* for the uniform location stored inside
	/// of the uniform_info argument.
	/// 
	/// </summary>
	/// <param name="uniform_info"></param>
	/// <param name="value"></param>
	static void set_uniform(ProgramUniformInfo& uniform_info, float value);
	static void set_uniform(ProgramUniformInfo& uniform_info, Vector2 value);

	static GLuint create_buffer();
	static void destroy_buffer(GLuint buffer);
	static bool is_buffer_initialized(GLuint buffer);
	/// <summary>
	/// Initializes the buffer with GL_STATIC_DRAW flag, if buffer isn't initialized.
	/// Will update the buffer if already initialized.
	/// </summary>
	/// <param name="buffer"></param>
	/// <param name="data"></param>
	static void set_vertex_buffer(GLuint buffer, const std::vector<unsigned char>& data);

	static GLuint create_vertex_array();
	static void destroy_vertex_array(GLuint vertex_array);
	/// <summary>
	/// A
	/// </summary>
	/// <param name="vertex_array"></param>
	/// <param name="vertex_buffer"></param>
	static void associate_vbo_with_vao_as_standard_2d(GLuint vertex_array, GLuint vertex_buffer);
	static void bind_vertex_array(GLuint vertex_array);
};

#endif

