#ifndef _MESH_BUILDER_H_
#define _MESH_BUILDER_H_

#include "mesh_builder_attrib_set.h"

/// <summary>
/// Holds a vector of type MeshBuilderAttribSet.
/// 
/// The primary purpose of this class is to allow for an easy way to generate and modify a collection of vertices (a mesh).
/// </summary>
template <class TAttrib>
class MeshBuilder
{
public:
	std::vector<TAttrib> vertices;

	virtual void push_onto_buffer(std::vector<unsigned char>& buffer)
	{

	}
};

class MeshBuilderStandard2D : public MeshBuilder<MeshBuilderAttribSetStandard2D>
{
public:
	void push_onto_buffer(std::vector<unsigned char>& buffer)
	{
		for (MeshBuilderAttribSetStandard2D& vertex : vertices)
		{
			vertex.push_onto_buffer(buffer);
		}
	}
};
#endif