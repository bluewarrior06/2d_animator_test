#ifndef _DRAW_SET_H_
#define _DRAW_SET_H_

#include <glad/glad.h>
#include "mesh_builder.h"

/// <summary>
/// Informs OpenGL information on how to draw something.
/// 
/// This includes:
/// * mesh buffer
/// * type of primitive to draw
/// * number of vertices to draw
/// 
/// </summary>
/// <typeparam name="TMeshBuilder"></typeparam>
template <class TMeshBuilder>
class DrawSet
{
public:
	DrawSet()
	{

	}
	DrawSet(DrawSet&& move) noexcept
	{
		this->_primitive_type = move._primitive_type;
		this->_number_of_vertices = move._number_of_vertices;
	}
	~DrawSet()
	{

	}

protected:
	GLenum _primitive_type = GL_TRIANGLES;
	int _number_of_vertices = 0;
	
public:
	void set_draw_type(GLenum new_primitive_type)
	{
		switch (new_primitive_type)
		{
		case GL_TRIANGLES:
			_primitive_type = GL_TRIANGLES;
			break;
		default:
			break;
		}
	}

	void set_vertices_to_draw(int vertex_count)
	{
		_number_of_vertices = vertex_count;
	}

	virtual void draw()
	{

	}

	void operator=(DrawSet&& move) noexcept
	{
		this->_primitive_type = move._primitive_type;
		this->_number_of_vertices = move._number_of_vertices;
	}
};

class DrawSetStandard2D : public DrawSet<MeshBuilderStandard2D>
{
public:
	void draw() override
	{
		glDrawArrays(_primitive_type, 0, _number_of_vertices);
	}
};

#endif