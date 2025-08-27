#ifndef _RENDERING_SERVER_H_
#define _RENDERING_SERVER_H_

#include <string>
#include <glad/glad.h>
#include "server.h"

/// <summary>
/// Coordinates many rendering commands into a single class.
/// 
/// </summary>
class RenderingServer : public Server
{
public:
	RenderingServer(Runtime* server);
	~RenderingServer() override;

	void pre_update(Runtime* runtime) override;
	void post_update(Runtime* runtime) override;

	GLuint create_shader(GLenum shader_type);
	void destroy_shader(GLuint shader);
	void set_shader_source(GLuint shader, std::string source);
	void compile_shader(GLuint shader);

};

#endif