#ifndef _UNIFORM_SET_H_
#define _UNIFORM_SET_H

#include "rendering_server_utility.h"
#include "vector_2.h"
#include "matrix_4.h"

#include "uniform.h"


/// <summary>
/// Holds multiple Uniform values to update OpenGL uniforms.
/// </summary>
/// <typeparam name="TMaterial"></typeparam>
class UniformSet
{
public:
	UniformSet();

	virtual ~UniformSet();

	/// <summary>	/// </summary>
	/// <param name="uniforms"></param>
	virtual void update_uniforms(const std::vector<ProgramUniformInfo>& uniform_info);

	void operator=(UniformSet&& move) noexcept;
};

class UniformSetStandard2D : public UniformSet
{
public:
	UniformSetStandard2D();
	~UniformSetStandard2D();

	UniformMatrix4 model_transform = UniformMatrix4("model");

	void update_uniforms(const std::vector<ProgramUniformInfo>& uniform_info);
};

#endif