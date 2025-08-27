#ifndef _MESH_BUILDER_VERTEX_H_
#define _MESH_BUILDER_VERTEX_H_

#include <vector>
#include "vector2.h"

template<class T>
class MeshBuilderAttribute
{
public:
	MeshBuilderAttribute()
	{

	}

	T value;

	virtual void push_onto_buffer(std::vector<unsigned char>& buffer)
	{
		unsigned char* value_fragment = (unsigned char*)&value;
		int value_bytes = sizeof(T);

		for (int byte = 0; byte < value_bytes; byte++)
		{
			buffer.push_back(value_fragment[byte]);
		}
	};
};

class MeshBuilderAttributeFloat : public MeshBuilderAttribute<float>
{
public:
	MeshBuilderAttributeFloat()
	{
		value = 0.0f;
	}
};
class MeshBuilderAttributeUInt32 : public MeshBuilderAttribute<unsigned long>
{
public:
	MeshBuilderAttributeUInt32()
	{
		value = 0;
	}
};
class MeshBuilderAttributeInt32 : public MeshBuilderAttribute<signed long>
{
public:
	MeshBuilderAttributeInt32()
	{
		value = 0;
	}
};
// Possible padding/alignment issues.
class MeshBuilderAttributeVector2 : public MeshBuilderAttribute<Vector2>
{
public:
	MeshBuilderAttributeVector2()
	{
		value = Vector2(0.0f, 0.0f);
	}
};

/// <summary>
/// Base class for containing MeshBuilderAttributeVector2s.
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