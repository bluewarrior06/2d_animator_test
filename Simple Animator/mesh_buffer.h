#ifndef _MESH_BUFFER_H_
#define _MESH_BUFFER_H_

#include <glad/glad.h>
#include "rendering_server_utility.h"
#include "mesh_builder.h"

/// <summary>
/// Used to supply vertex information for a draw call.
/// 
/// ALL derived classes have to set up their vertex array to properly map to their associated vertex buffer.
/// </summary>
template <class TMeshBuilder >
class MeshBuffer
{
public:
	MeshBuffer()
	{

	}
	~MeshBuffer()
	{

	}

public:
	virtual void supply(TMeshBuilder& attrib_set)
	{
	}

	/// <summary>
	/// Checks to see if the MeshBuffer is currently in a usable state.
	/// </summary>
	/// <returns></returns>
	virtual bool usable()
	{
		return false;
	}

	virtual void bind()
	{
	}
};

class MeshBufferStandard2D : public MeshBuffer<MeshBuilderStandard2D>
{
public:
	MeshBufferStandard2D()
	{
		_vbo = RenderingServerUtility::create_buffer();
		_vao = RenderingServerUtility::create_vertex_array();
		RenderingServerUtility::associate_vbo_with_vao_as_standard_2d(_vao, _vbo);
	}
	~MeshBufferStandard2D()
	{
		RenderingServerUtility::destroy_buffer(_vbo);
		RenderingServerUtility::destroy_vertex_array(_vao);
	}

private:
	GLuint _vbo = 0;
	GLuint _vao = 0;

public:
	void supply(MeshBuilderStandard2D& attrib_set) override
	{
		std::vector<unsigned char> vertex_buffer = {};

		attrib_set.push_onto_buffer(vertex_buffer);

		RenderingServerUtility::set_vertex_buffer(_vbo, vertex_buffer);
	}

	bool usable()
	{
		return true;
	}

	void bind()
	{
		if (usable() == false)
		{

		}

		RenderingServerUtility::bind_vertex_array(_vao);
	}
};

#endif