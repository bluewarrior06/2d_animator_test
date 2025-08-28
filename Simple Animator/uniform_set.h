#ifndef _UNIFORM_SET_H_
#define _UNIFORM_SET_H_

/// <summary>
/// Informs OpenGL on what uniforms to update.
/// </summary>
/// <typeparam name="TMaterial"></typeparam>
class UniformSet
{
public:
	UniformSet();
	UniformSet(UniformSet&& move) noexcept;

	virtual ~UniformSet();

	virtual void update_uniforms();

	void operator=(UniformSet&& move) noexcept;
};

class UniformSetStandard2D : public UniformSet
{
public:
	UniformSetStandard2D();
	UniformSetStandard2D(UniformSetStandard2D&& move) noexcept;
	~UniformSetStandard2D();

	void operator=(UniformSetStandard2D&& move) noexcept;
};

#endif