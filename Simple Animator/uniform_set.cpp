#include "uniform_set.h"

UniformSet::UniformSet()
{

}

UniformSet::~UniformSet()
{

}

void UniformSet::update_uniforms(const std::vector<ProgramUniformInfo>& uniform_info)
{

}

UniformSetStandard2D::UniformSetStandard2D()
{

}

UniformSetStandard2D::~UniformSetStandard2D()
{

}

void UniformSetStandard2D::update_uniforms(const std::vector<ProgramUniformInfo>& uniform_info)
{
	for (const ProgramUniformInfo& individual_uniform_info : uniform_info)
	{
		model_transform.attempt_supply_uniform(individual_uniform_info);
	}
}