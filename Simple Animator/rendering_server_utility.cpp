#include "rendering_server_utility.h"

void RenderingServerUtility::update_viewport(int x, int y, int width, int height)
{
	glViewport(x, y, width, height);
}

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
std::vector<ProgramUniformInfo> RenderingServerUtility::get_active_uniforms(GLuint program)
{
	std::vector<ProgramUniformInfo> uniforms = {};

	int active_uniforms = 0;
	glGetProgramiv(program, GL_ACTIVE_UNIFORMS, &active_uniforms);
	for (int uniform_idx = 0; uniform_idx < active_uniforms; uniform_idx++)
	{
		uniforms.push_back(ProgramUniformInfo(program, uniform_idx));
	}

	return uniforms;
}

void RenderingServerUtility::set_uniform(ProgramUniformInfo& uniform_info, float value)
{
	glUniform1f(uniform_info.index, value);
}
void RenderingServerUtility::set_uniform(ProgramUniformInfo& uniform_info, Vector2 value)
{
	glUniform2f(uniform_info.index, value.x, value.y);
}

GLuint RenderingServerUtility::create_buffer()
{
	GLuint buffer = 0;
	glCreateBuffers(1, &buffer);
	return buffer;
}
void RenderingServerUtility::destroy_buffer(GLuint buffer)
{
	glDeleteBuffers(1, &buffer);
}
bool RenderingServerUtility::is_buffer_initialized(GLuint buffer)
{
	int is_initialized = GL_FALSE;
	glGetNamedBufferParameteriv(buffer, GL_BUFFER_SIZE, &is_initialized);
	return is_initialized == GL_TRUE;
}
void RenderingServerUtility::set_vertex_buffer(GLuint buffer, const std::vector<unsigned char>& data)
{
	bool buffer_already_initialized = is_buffer_initialized(buffer);
	if (buffer_already_initialized)
	
	{
		glNamedBufferSubData(buffer, 0, data.size(), data.data());
	}
	else
	{
		glNamedBufferData(buffer, data.size(), data.data(), GL_STATIC_DRAW);

	}
}

GLuint RenderingServerUtility::create_vertex_array()
{
	GLuint vertex_array_object = 0;
	glCreateVertexArrays(1, &vertex_array_object);
	return vertex_array_object;
}
void RenderingServerUtility::destroy_vertex_array(GLuint vertex_array)
{
	glDeleteVertexArrays(1, &vertex_array);
}
void RenderingServerUtility::associate_vbo_with_vao_as_standard_2d(GLuint vertex_array, GLuint vertex_buffer)
{
	glEnableVertexArrayAttrib(vertex_array, 0);
	glEnableVertexArrayAttrib(vertex_array, 1);

	glVertexArrayAttribFormat(vertex_array, 0, 2, GL_FLOAT, GL_FALSE, 0);
	glVertexArrayAttribFormat(vertex_array, 1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float));

	glVertexArrayVertexBuffer(vertex_array, 0, vertex_buffer, 0, 2 * sizeof(float) + 2 * sizeof(float));
	glVertexArrayAttribBinding(vertex_array, 0, 0);
	glVertexArrayAttribBinding(vertex_array, 1, 0);
}
void RenderingServerUtility::bind_vertex_array(GLuint vertex_array)
{
	glBindVertexArray(vertex_array);
}