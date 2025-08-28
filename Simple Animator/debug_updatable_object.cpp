#include "debug_updatable_object.h"

#include "rendering_server_utility.h"
#include "mesh_builder.h"
#include "runtime.h"
#include "material_standard_2d.h"
#include "mesh_buffer.h"

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

	material.usable();
	material.use_program();

	MeshBufferStandard2D buffer = MeshBufferStandard2D();
	
	MeshBuilderStandard2D standard = MeshBuilderStandard2D();
	
	MeshBuilderAttribSetStandard2D a = MeshBuilderAttribSetStandard2D();
	MeshBuilderAttribSetStandard2D b = MeshBuilderAttribSetStandard2D();
	MeshBuilderAttribSetStandard2D c = MeshBuilderAttribSetStandard2D();
	
	a.vertex_position.value = Vector2(-1.0f, -1.0f);
	b.vertex_position.value = Vector2(0.0f, 1.0f);
	c.vertex_position.value = Vector2(1.0f, -1.0f);

	standard.vertices.push_back(a);
	standard.vertices.push_back(b);
	standard.vertices.push_back(c);

	buffer.supply(standard);
	buffer.bind();
	
}