#ifndef _RENDERING_SERVER_H_
#define _RENDERING_SERVER_H_

#include <string>
#include <SDL3/SDL.h>
#include <glad/glad.h>
#include "server.h"
#include "rendering_server_utility.h"

/// <summary>
/// Coordinates many rendering commands into a single class.
/// 
/// The rendering server heavily revolves around OpenGL's DSA, so the latest OpenGL version should be used.
/// 
/// </summary>
class RenderingServer : public Server
{

public:
	RenderingServer(Runtime* runtime);
	~RenderingServer() override;

private:
	SDL_GLContext _gl_context = nullptr;

public:

	// The minimum version of OpenGL required.
	static const int OPENGL_MINIMUM_VERSION = 4;
	// The maximum version of OpenGL required.
	static const int OPENGL_MAXIMUM_VERSION = 6;

	void pre_update(Runtime* runtime) override;
	void post_update(Runtime* runtime) override;
};

#endif