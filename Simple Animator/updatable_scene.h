#ifndef _UPDATABLE_SCENE_H_
#define _UPDATABLE_SCENE_H_

/// <summary>
/// Used for managing all updatable objects contained.
/// </summary>
class UpdatableScene
{
public:
	UpdatableScene();
	UpdatableScene(const UpdatableScene& copy);
	UpdatableScene(UpdatableScene&& move) noexcept;
	~UpdatableScene();

	void operator=(const UpdatableScene& copy);
	void operator=(UpdatableScene&& move) noexcept;
};

#endif