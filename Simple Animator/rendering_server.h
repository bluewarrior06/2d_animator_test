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
/// ========================= Rendering ========================= //

/// One way to draw onto the screen is through Material batches.
/// A material batch combines a single material, and draw sets.
/// 
/// What is a material? A material instructs on how a single draw call will be done.
/// A material will hold an OpenGL program to draw.
/// A material has something called a global uniform requirement.
/// A global uniform requirement can be a uniform for a perspective matrix, or a camera matrix, a color, a texture, etc...
/// A global uniform requirement is "global", because it shouldn't be changed during a draw call, only before or after a set of draw calls are executed.
/// 
/// A draw set combines a mesh, uniform set, and a draw call.
/// The mesh is a vao with a vbo bound.
/// A uniform set is uniforms that are set inside of a uniform.
/// A draw call is simply an OpenGL draw call.
/// </summary>
/// 
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