#ifndef _UPDATABLE_SCENE_H_
#define _UPDATABLE_SCENE_H_

#include <vector>
#include "updatable_object.h"

/// <summary>
/// Used for storing, and updating UpdatableObjects.
/// </summary>
class UpdatableScene
{
public:
	UpdatableScene();
	~UpdatableScene();

private:
	/// <summary>
	/// The root of the scene.
	/// </summary>
	UpdatableObject _root = UpdatableObject();
	
public:
	/// <summary>
	/// Tells the root (if one exists) to update.
	/// </summary>
	void update_root();
	/// <summary>
	/// Tells the root (if on exists) to draw.
	/// </summary>
	void draw_root();

	UpdatableObject& get_root();
};

#endif