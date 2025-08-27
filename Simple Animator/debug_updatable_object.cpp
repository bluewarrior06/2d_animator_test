#include "debug_updatable_object.h"

#include "rendering_server_utility.h"
#include "mesh_builder.h"
#include "runtime.h"

void DebugUpdatableObject::initialize()
{
}
void DebugUpdatableObject::destroy()
{

}

void DebugUpdatableObject::enter_scene()
{
	Runtime* runtime = get_runtime();
	GLuint vertex_shader = RenderingServerUtility::create_shader(GL_VERTEX_SHADER);
	GLuint fragment_shader = RenderingServerUtility::create_shader(GL_FRAGMENT_SHADER);

	RenderingServerUtility::set_shader_source(vertex_shader,
		"#version 430\n"
		"\n"
		"layout(location = 0) in vec2 VERTEX_POSITION;\n"
		"layout(location = 1) in vec2 UV;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	gl_Position = vec4(VERTEX_POSITION, 1.0f, 1.0f);\n"
		"}\n");
	RenderingServerUtility::set_shader_source(fragment_shader,
		"#version 430\n"
		"\n"
		"out vec4 fragment_color;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	fragment_color = vec4(1.0f);\n"
		"}\n"
	);

	RenderingServerUtility::compile_shader(vertex_shader);
	RenderingServerUtility::compile_shader(fragment_shader);

	std::string vertex_compile_result = std::string("vertex result: ") + RenderingServerUtility::get_shader_info_log(vertex_shader);
	std::string fragment_compile_result = std::string("fragment result: ") + RenderingServerUtility::get_shader_info_log(fragment_shader);
	printf("%s\n", vertex_compile_result.c_str());
	printf("%s\n", fragment_compile_result.c_str());

	GLuint program = RenderingServerUtility::create_program();
	RenderingServerUtility::attach_shader(program, vertex_shader);
	RenderingServerUtility::attach_shader(program, fragment_shader);
	RenderingServerUtility::link_program(program);
	RenderingServerUtility::use_program(program);
	std::vector<ProgramUniformInfo> uniforms = RenderingServerUtility::get_active_uniforms(program);

	MeshBuilderStandard2D standard = MeshBuilderStandard2D();

	MeshBuilderAttribSetStandard2D vertex_a;
	vertex_a.vertex_position.value = Vector2(-1.0, -1.0);
	MeshBuilderAttribSetStandard2D vertex_b;
	vertex_b.vertex_position.value = Vector2(0.0, 1.0);
	MeshBuilderAttribSetStandard2D vertex_c;
	vertex_c.vertex_position.value = Vector2(1.0, -1.0);

	standard.vertices.push_back(vertex_a);
	standard.vertices.push_back(vertex_b);
	standard.vertices.push_back(vertex_c);

	std::vector<unsigned char> vertex_buffer;
	standard.push_onto_buffer(vertex_buffer);

	GLuint vbo = RenderingServerUtility::create_buffer();
	RenderingServerUtility::set_vertex_buffer(vbo, vertex_buffer);

	GLuint vao = RenderingServerUtility::create_vertex_array();
	RenderingServerUtility::associate_vbo_with_vao_as_standard_2d(vao, vbo);

	RenderingServerUtility::bind_vertex_array(vao);
	printf("%d\n", glGetError());

	SDL_Event event;

	while (true)
	{
		glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		SDL_GL_SwapWindow(runtime->get_window().get_sdl_window());

		while (SDL_PollEvent(&event))
		{
		}
	}
}