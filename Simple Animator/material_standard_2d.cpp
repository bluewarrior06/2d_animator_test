#include "material_standard_2d.h"

#include "rendering_server_utility.h"

MaterialStandard2D::MaterialStandard2D(std::string vertex_source, std::string fragment_source) : Material()
{
	_vertex_shader = RenderingServerUtility::create_shader(GL_VERTEX_SHADER);
	_fragment_shader = RenderingServerUtility::create_shader(GL_FRAGMENT_SHADER);
	RenderingServerUtility::compile_shader(_vertex_shader);
	RenderingServerUtility::compile_shader(_fragment_shader);

	if (
		RenderingServerUtility::shader_is_compiled(_vertex_shader) == false
		or
		RenderingServerUtility::shader_is_compiled(_fragment_shader) == false)
	{
		glDeleteShader(_vertex_shader);
		glDeleteShader(_fragment_shader);
		return;
	}

	glAttachShader(_program, _vertex_shader);
	glAttachShader(_program, _fragment_shader);
	glLinkProgram(_program);
	_find_uniforms_in_program();

	glDeleteShader(_vertex_shader);
	glDeleteShader(_fragment_shader);
}

bool MaterialStandard2D::usable()
{
	return _vertex_shader != 0 and _fragment_shader != 0;
}
void MaterialStandard2D::set_global_uniforms()
{

}