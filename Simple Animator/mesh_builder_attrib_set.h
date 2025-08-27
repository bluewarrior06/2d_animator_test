#ifndef _MESH_BUILDER_ATTRIB_SET_H_
#define _MESH_BUILDER_ATTRIB_SET_H_

#include <vector>
#include "vector2.h"

#include "mesh_builder_attribute.h"

/// <summary>
/// Combines one or multiple MeshBuilderAttributes to form a single vertex.
/// </summary>
class MeshBuilderAttribSet
{
public:
	virtual void push_onto_buffer(std::vector<unsigned char>& buffer);
};

class MeshBuilderAttribSetStandard2D : public MeshBuilderAttribSet
{
public:
	MeshBuilderAttributeVector2 vertex_position;
	MeshBuilderAttributeVector2 uv;

	void push_onto_buffer(std::vector<unsigned char>& buffer) override;
};
#endif