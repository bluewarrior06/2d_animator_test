#include "debug_updatable_object.h"

#include "rendering_server_utility.h"
#include "mesh_builder.h"
#include "runtime.h"
#include "material_standard_2d.h"

void DebugUpdatableObject::initialize()
{
}
void DebugUpdatableObject::destroy()
{

}

void DebugUpdatableObject::enter_scene()

{
	MaterialStandard2D material = MaterialStandard2D(
		"#version 430 \n"
		"\n"
		"layout(location = 0) in vec2 VERTEX_POSITION;\n"
		"layout(location = 1) in vec2 UV;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	gl_Position = vec4(VERTEX_POSITION, 0.0f, 1.0f);\n"
		"}\n",

		"#version 430 \n"
		"\n"
		"out vec4 color;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	color = vec4(1.0f);\n"
		"}\n"
	);

	material.use_program();
}