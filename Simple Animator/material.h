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

private:
	std::string _program_info_log = "";
protected:
	GLuint _program = 0;
	std::vector<ProgramUniformInfo> _uniforms;

	/// <summary>
	/// Not automatically called.
	/// Derived classes have to call this function after successfully setting up.
	/// </summary>
	void _find_uniforms_in_program();
	/// <summary>
	/// Updates the stored _program_info_log with the programs current info log.
	/// Derived classes have to call this method when setting up.
	/// </summary>
	void _update_program_info_log();

public:
	void use_program();

	const std::vector<ProgramUniformInfo>& get_uniforms();

	virtual bool usable();
	virtual void set_global_uniforms();
	std::string get_program_info_log();
};

#endif