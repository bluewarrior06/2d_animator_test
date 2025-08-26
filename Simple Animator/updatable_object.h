#ifndef _UPDATABLE_OBJECT_H_
#define _UPDATABLE_OBJECT_H_

#include <string>

/// <summary>
/// Stored inside of Runtime, and can then further be processed.
/// </summary>
class UpdatableObject
{
	friend class UpdatableScene;

public:
	UpdatableObject();
	UpdatableObject(const UpdatableObject& copy);
	~UpdatableObject();

private:
	/// <summary>
	/// A unique identifier for the object inside of the updatable scene.
	/// </summary>
	std::string _name = "";

protected:
	/// <summary>
	/// 
	/// </summary>
	virtual void update();
	virtual void draw();

public:
	void operator=(const UpdatableObject& copy);
};

#endif