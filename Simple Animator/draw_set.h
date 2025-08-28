#ifndef _DRAW_SET_H_
#define _DRAW_SET_H_

#include <glad/glad.h>
#include "mesh_builder.h"

/// <summary>
/// Informs OpenGL on the type of primitive to draw, and how many vertices to draw.
/// </summary>
/// <typeparam name="TMeshBuilder"></typeparam>
template <class TMeshBuilder>
class DrawSet
{
public:
	DrawSet()
	{

	}
	~DrawSet()
	{

	}

protected:
	GLenum primitive_type = GL_TRIANGLES;
	int number_of_vertices = 0;
	
public:
	void set_draw_type(GLenum primitive_type)
	{
		switch (primitive_type)
		{
		case GL_TRIANGLES:
			primitive_type = GL_TRIANGLES;
			break;
		default:
			break;
		}
	}

	void set_vertices_to_draw(int vertex_count)
	{
		number_of_vertices = vertex_count;
	}

	virtual void draw()
	{

	}
};

class DrawSetStandard2D : public DrawSet<MeshBuilderStandard2D>
{
public:
	void draw() override
	{
		glDrawArrays(primitive_type, 0, number_of_vertices);
	}
};

#endif