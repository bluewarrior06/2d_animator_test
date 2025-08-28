#ifndef _UPDATABLE_OBJECT_H_
#define _UPDATABLE_OBJECT_H_

#include <string>
#include <vector>

class Runtime;

/// <summary>
/// Stored inside of Runtime.
/// Used to modify the data of Runtime.
/// </summary>
class UpdatableObject
{
	friend class Runtime;
	friend class UpdatableScene;

public:
	UpdatableObject();
	~UpdatableObject();

private:
	/// <summary>
	/// A unique identifier for the object inside of the updatable scene.
	/// </summary>
	std::string _name = "";
	std::vector<UpdatableObject*> _children = std::vector<UpdatableObject*>();

	Runtime* _sync_runtime = nullptr;

	/// <summary>
	/// If the UpdatableObject is currently inside of the scene.
	/// 
	/// If true, the scene can't be informed it has been added to a scene during a propagation.
	/// If false, the scene can't be informed that it has exited from a scene during a propagation.
	/// </summary>
	bool _is_in_scene = false;

	void _update_and_propagate();
	void _draw_and_propagate();
	void _enter_scene_and_propagate();
	void _exit_scene_and_propagate();

	/// <summary>
	/// For an updatable object to modify it's associated Runtime, the Runtime has to be propagated down to it.
	/// When a Runtime object is created, it's scene's root will be told to sync with the Runtime.
	/// When a child or sub-child, sub-sub-child, etc, is moved, added, or removed, the parent will instruct its child to then sync with its parent.
	/// </summary>
	/// <param name="runtime"></param>
	void _sync(Runtime* runtime);
	void _sync_and_propagate(Runtime* runtime);

protected:
	virtual void initialize();
	virtual void destroy();
	virtual void update();
	virtual void draw();
	virtual void enter_scene();
	virtual void exit_scene();
	
public:
	/// <summary>
	/// Checks to see if a child exists, based on its pointer.
	/// </summary>
	/// <param name="child"></param>
	/// <returns></returns>
	bool has_child(UpdatableObject* child);
	void add_child(UpdatableObject* child);
	/// <summary>
	/// Attempts to remove a child with a matching pointer.
	/// </summary>
	/// <param name="child"></param>
	void remove_child(UpdatableObject* child);

	void rename(std::string new_name);
	std::string get_name();

	/// <summary>
	/// Gets the runtime that was last propagated down to this updatable object.
	/// </summary>
	Runtime* get_runtime();
};

#endif