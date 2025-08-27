#include <stdio.h>
#include <SDL3/SDL.h>
#include <glad/glad.h>

#include "updatable_scene.h"
#include "runtime.h"
#include "mesh_builder.h"

int main()
{
	
	GlobalRuntimeBuilder global_builder = GlobalRuntimeBuilder();
	global_builder.opengl_enabled = true;
	global_builder.opengl_context_major_version = 4;
	global_builder.opengl_context_minor_version = 6;
	global_builder.opengl_use_core = true;
	Runtime::initialize_globals(global_builder);

	RuntimeBuilder builder = RuntimeBuilder();
	builder.window_name = "Window";
	builder.window_width = 512;
	builder.window_height = 512;
	builder.window_flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL;

	Runtime runtime = Runtime(builder);
	
	GLuint vertex_shader = RenderingServerUtility::create_shader(GL_VERTEX_SHADER);
	GLuint fragment_shader = RenderingServerUtility::create_shader(GL_FRAGMENT_SHADER);

	RenderingServerUtility::set_shader_source(vertex_shader,
		"#version 430\n"
		"\n"
		"layout(location = 0) in vec3 VERTEX_POSITION;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	gl_Position = vec4(VERTEX_POSITION, 1.0f);\n"
		"}\n");
	RenderingServerUtility::set_shader_source(fragment_shader,
		"#version 430\n"
		"\n"
		"uniform vec4 input2;\n"
		"out vec4 fragment_color;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	fragment_color = input2 * vec4(1.0f);\n"
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
	
	std::vector<unsigned char> buffer = {};
	MeshBuilderAttributeVector2 vertex_component = MeshBuilderAttributeVector2();
	vertex_component.value = Vector2(10.0f, 4238493.0f);

	vertex_component.push_to_buffer(buffer);

	vertex_component.push_to_buffer(buffer);

	UpdatableObject& runtime_root = runtime.get_updatable_scene().get_root();

	runtime.begin();

	return 0;
}