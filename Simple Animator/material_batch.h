#ifndef _MATERIAL_BATCH_H_
#define _MATERIAL_BATCH_H_

#include "material.h"

/// <summary>
/// Used to group draw sets, along with a material to group draw sets with a matching material.
/// </summary>
/// <typeparam name="TMaterial"></typeparam>
template <class TMaterial>
class MaterialBatch
{
public:
	MaterialBatch();
	~MaterialBatch();

protected:
	TMaterial material;
};

class MaterialBatchStandard2D : public MaterialBatch<Material>
{

};

#endif