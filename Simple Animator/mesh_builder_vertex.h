#ifndef _MESH_BUILDER_VERTEX_H_
#define _MESH_BUILDER_VERTEX_H_

#include <vector>

template<class T, T default_value>
class MeshBuilderComponent
{
public:
	int value = default_value;

	virtual void push_to_buffer(std::vector<unsigned char>& buffer)
	{
		unsigned char* value_fragment = (unsigned char*)&value;
		int value_bytes = sizeof(T);

		for (int byte = 0; byte < value_bytes; byte++)
		{
			buffer.push_back(value_fragment[byte]);
		}
	};
};

class MeshBuilderComponentFloat : public MeshBuilderComponent<float, 0.0f>
{
};
class MeshBuilderComponentUInt32 : public MeshBuilderComponent<unsigned long, 1000>
{
};
class MeshBuilderComponentInt32 : public MeshBuilderComponent<signed long, 1000>
{

};

/// <summary>
/// A single vertex in a mesh builder.
/// </summary>
class MeshBuilderVertex
{

};

#endif