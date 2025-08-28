#include "material_standard_2d.h"

#include "rendering_server_utility.h"

MaterialStandard2D::MaterialStandard2D(std::string vertex_source, std::string fragment_source) : Material()
{
	_vertex_shader = RenderingServerUtility::create_shader(GL_VERTEX_SHADER);
	_fragment_shader = RenderingServerUtility::create_shader(GL_FRAGMENT_SHADER);
	RenderingServerUtility::set_shader_source(_vertex_shader, vertex_source);
	RenderingServerUtility::set_shader_source(_fragment_shader, fragment_source);
	RenderingServerUtility::compile_shader(_vertex_shader);
	RenderingServerUtility::compile_shader(_fragment_shader);
	_vertex_shader_info_log = RenderingServerUtility::get_shader_info_log(_vertex_shader);
	_fragment_shader_info_log = RenderingServerUtility::get_shader_info_log(_fragment_shader);

	if (
		RenderingServerUtility::shader_is_compiled(_vertex_shader) == false
		or
		RenderingServerUtility::shader_is_compiled(_fragment_shader) == false)
	{
		
		_vertex_shader = 0;
		_fragment_shader = 0;
		return;
	}

	RenderingServerUtility::attach_shader(_program, _vertex_shader);
	RenderingServerUtility::attach_shader(_program, _fragment_shader);
	RenderingServerUtility::link_program(_program);

	_find_uniforms_in_program();
}

MaterialStandard2D::~MaterialStandard2D()
{
	RenderingServerUtility::destroy_shader(_vertex_shader);
	RenderingServerUtility::destroy_shader(_fragment_shader);
	RenderingServerUtility::destroy_program(_program);
}

bool MaterialStandard2D::usable()
{
	return _vertex_shader != 0 and _fragment_shader != 0;
}
void MaterialStandard2D::set_global_uniforms()
{

}

std::string MaterialStandard2D::get_vertex_shader_info_log()
{
	return _vertex_shader_info_log;
}
std::string MaterialStandard2D::get_fragment_shader_info_log()
{
	return _fragment_shader_info_log;
}