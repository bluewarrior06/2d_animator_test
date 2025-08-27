#ifndef _MESH_BUILDER_ATTRIBUTE_H_
#define _MESH_BUILDER_ATTRIBUTE_H_

#include <vector>
#include "vector2.h"

/// <summary>
/// Describes a signle attribute for a vertex.
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
class MeshBuilderAttribute
{
public:
	MeshBuilderAttribute()
	{
	}

	T value;

	/// <summary>
	/// Pushes each byte from "value" onto a byte buffer.
	/// The implementation in base class simply just goes through each individual byte
	/// in "value", ignoring any padding that may be added. This function can be overriden
	/// for more specific types that may add padding.
	///
	/// The base implementation doesn't add any padding or align
	/// </summary>
	/// <param name="buffer"></param>
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

/// <summary>
/// A vertex attribute of a floating point value.
/// </summary>
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
#endif