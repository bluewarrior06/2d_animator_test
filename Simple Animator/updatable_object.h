#ifndef _UPDATABLE_OBJECT_H_
#define _UPDATABLE_OBJECT_H_

#include <string>
#include <vector>

/// <summary>
/// Stored inside of Runtime, and can then further be processed.
/// </summary

class UpdatableObject
{
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

protected:
	virtual void update();
	virtual void draw();

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
};

#endif