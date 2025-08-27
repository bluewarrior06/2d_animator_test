#ifndef _RENDERING_SERVER_H_
#define _RENDERING_SERVER_H_

#include <string>
#include <glad/glad.h>
#include "server.h"
#include "rendering_server_supplier.h"

/// <summary>
/// Coordinates many rendering commands into a single class.
/// 
/// The rendering server heavily revolves around OpenGL's DSA, so the latest OpenGL version should be used.
/// 
/// </summary>
class RenderingServer : public Server
{

public:
	RenderingServer(Runtime* server);
	~RenderingServer() override;

public:
	// The minimum version of OpenGL required.
	static const int OPENGL_MINIMUM_VERSION = 4;
	// The maximum version of OpenGL required.
	static const int OPENGL_MAXIMUM_VERSION = 6;

};

#endif