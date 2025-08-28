#ifndef _MATERIAL_STANDARD_2D_H_
#define _MATERIAL_STANDARD_2D_H_

#include <string>
#include "material.h"

/// <summary>
/// Standard material for 2D rendering.
/// </summary>
class MaterialStandard2D : public Material
{
public:
	MaterialStandard2D(std::string vertex_source, std::string fragment_source);

private:
	GLuint _vertex_shader = 0;
	GLuint _fragment_shader = 0;

public:
	bool usable() override;
	void set_global_uniforms() override;
};

#endif