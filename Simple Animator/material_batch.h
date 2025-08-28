#ifndef _MATERIAL_BATCH_H_
#define _MATERIAL_BATCH_H_

#include "material_standard_2d.h"
#include "mesh_buffer.h"
#include "draw_set.h"
#include "uniform_set.h"

/// <summary>
/// Used to group draw sets, along with a material to group draw sets with a matching material.
/// </summary>
/// <typeparam name="TMaterial"></typeparam>
template <class TMaterial, class TMeshBuffer, class TDrawSet, class TUniformSet>
class MaterialBatch
{
public:
	MaterialBatch()
	{

	}
	virtual ~MaterialBatch()
	{

	}

protected:
	/// <summary>
	/// Contains information enough for a single draw instruction.
	/// </summary>
	struct Draw
	{
		TMeshBuffer mesh_buffer;
		TDrawSet draw_set;
		TUniformSet uniform_set;

	};

protected:
	//Note: Try to find a way to not have this be a pointer!
	TMaterial* _material;

public:
	std::vector<Draw*> draws;

	TMaterial* get_material()
	{
		return _material;
	}

	/// <summary>
	/// If the MaterialBatch is in a usable state.
	/// </summary>
	/// <returns></returns>
	virtual bool usable()
	{
		return false;
	}

	void draw_batch()
	{
		if (_material == nullptr)
		{
			return;
		}

		_material->use_program();
		_material->set_global_uniforms();

		for (Draw* draw : draws)
		{
			draw->mesh_buffer.bind();
			draw->uniform_set.update_uniforms(_material->get_uniforms());
			draw->draw_set.draw();
		}
	}
};

class MaterialBatchStandard2D : public MaterialBatch<MaterialStandard2D, MeshBufferStandard2D, DrawSetStandard2D, UniformSetStandard2D>
{
public:
	MaterialBatchStandard2D(std::string vertex_source, std::string fragment_source) : MaterialBatch()
	{
		_material = new MaterialStandard2D(vertex_source, fragment_source);
	}
	~MaterialBatchStandard2D()
	{
		if (_material != nullptr)
		{
			delete _material;
		}

		for (Draw* draw : draws)
		{
			delete draw;
		}
		draws.clear();
	}

public:
	struct DrawStandard2D : public MaterialBatch::Draw
	{
	};
};

#endif