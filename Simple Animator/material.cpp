#include "material.h"

Material::Material()
{
	_program = RenderingServerUtility::create_program();
}
Material::~Material()
{
	RenderingServerUtility::destroy_program(_program);
}

void Material::_find_uniforms_in_program()
{
	_uniforms = RenderingServerUtility::get_active_uniforms(_program);
}

void Material::use_program()
{
	if (usable() == false)
	{
		return;
	}

	glUseProgram(_program);
}

const std::vector<ProgramUniformInfo>& Material::get_uniforms()
{
	return _uniforms;
}

bool Material::usable()
{
	return false;
}
void Material::set_global_uniforms()
{

}