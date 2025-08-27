#include "mesh_builder_vertex.h"

void MeshBuilderAttribSet::push_onto_buffer(std::vector<unsigned char>& buffer)
{

}

void MeshBuilderAttribSetStandard2D::push_onto_buffer(std::vector<unsigned char>& buffer)
{
	vertex_position.push_onto_buffer(buffer);
	uv.push_onto_buffer(buffer);
}