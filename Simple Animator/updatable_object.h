#ifndef _UPDATABLE_OBJECT_H_
#define _UPDATABLE_OBJECT_H_

/// <summary>
/// Stored inside of Runtime, and can then further be processed.
/// </summary>
class UpdatableObject
{
public:
	UpdatableObject();
	UpdatableObject(const UpdatableObject& copy);
	UpdatableObject(UpdatableObject&& move) noexcept;
	~UpdatableObject();

	/// <summary>
	/// 
	/// </summary>
	virtual void _update();
	virtual void _draw();

	void operator=(const UpdatableObject& copy);
	void operator=(UpdatableObject&& move) noexcept;
};

#endif