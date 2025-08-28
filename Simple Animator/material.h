#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include <glad/glad.h>
#include "rendering_server_utility.h"

/// <summary>
/// Base class for materials.
/// 
/// When creating global uniforms, members should be named: "global_uniform_*"
/// </summary>
class Material
{
public:
	Material();
	virtual ~Material();

protected:
	GLuint _program = 0;
	std::vector<ProgramUniformInfo> _uniforms;

	/// <summary>
	/// Not automatically called.
	/// Derived classes have to call this function after successfully setting up.
	/// </summary>
	void _find_uniforms_in_program();

public:
	void use_program();

	const std::vector<ProgramUniformInfo>& get_uniforms();

	virtual bool usable();
	virtual void set_global_uniforms();
};

#endif