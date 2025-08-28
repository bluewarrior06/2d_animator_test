#include "debug_updatable_object.h"

#include "rendering_server_utility.h"
#include "mesh_builder.h"
#include "runtime.h"
#include "material_standard_2d.h"
#include "mesh_buffer.h"
#include "draw_set.h"
#include "material_batch.h"

void DebugUpdatableObject::initialize()
{
}
void DebugUpdatableObject::destroy()
{

}

void DebugUpdatableObject::enter_scene()
{

	MaterialBatchStandard2D batch = MaterialBatchStandard2D(
		"#version 430 \n"
		"\n"
		"layout(location = 0) in vec2 VERTEX_POSITION;\n"
		"layout(location = 1) in vec2 UV;\n"
		"\n"
		"uniform mat4 model;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	gl_Position = model * vec4(VERTEX_POSITION, 0.0f, 1.0f);\n"
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

	MaterialBatchStandard2D::DrawStandard2D* draw = new MaterialBatchStandard2D::DrawStandard2D();
	batch.draws.push_back(draw);
	draw->draw_set.set_vertices_to_draw(3);

	MeshBuilderStandard2D mesh_builder = MeshBuilderStandard2D();

	MeshBuilderAttribSetStandard2D a = MeshBuilderAttribSetStandard2D();
	MeshBuilderAttribSetStandard2D b = MeshBuilderAttribSetStandard2D();
	MeshBuilderAttribSetStandard2D c = MeshBuilderAttribSetStandard2D();

	a.vertex_position.value = Vector2(-1.0f, -1.0f);
	b.vertex_position.value = Vector2(0.0f, 1.0f);
	c.vertex_position.value = Vector2(1.0f, -1.0f);

	mesh_builder.vertices.push_back(a);
	mesh_builder.vertices.push_back(b);
	mesh_builder.vertices.push_back(c);

	draw->mesh_buffer.supply(mesh_builder);

	SDL_Event events;
	while (true)
	{
		while (SDL_PollEvent(&events)) {};

		batch.draw_batch();
	
		SDL_GL_SwapWindow(get_runtime()->get_window().get_sdl_window());
	}
}