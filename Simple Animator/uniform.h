#ifndef _UNIFORM_H_
#define _UNIFORM_H_

#include "rendering_server_utility.h"
#include <glad/glad.h>
#include "vector_2.h"
#include "matrix_4.h"
#include "matrix_2x3.h"

/// <summary>
/// Base class for storing information to supply an OpenGL uniform with.
/// </summary>
/// <typeparam name="T"></typeparam>
template <class T>
struct Uniform
{
	Uniform(std::string name)
	{
		this->name = name;
	}
	~Uniform()
	{

	}

protected:
	GLint size = 0;
	GLenum type = GL_FALSE;

public:
	std::string name = "";
	T value;

	bool matches_program_uniform(const ProgramUniformInfo& uniform_info)
	{
		printf("%d, %d", this->size, uniform_info.size);
		bool a = this->size == uniform_info.size;
		bool b = this->type == uniform_info.type;
		bool c = this->name == uniform_info.name;

		return
			this->size == uniform_info.size and
			this->type == uniform_info.type and
			this->name == uniform_info.name;
	}

	virtual void attempt_supply_uniform(const ProgramUniformInfo& uniform_info)
	{
	}
};

struct UniformVector2 : public Uniform<Vector2>
{
	UniformVector2(std::string name) : Uniform(name)
	{
		size = 2;
		type = GL_FLOAT;
	}
	void attempt_supply_uniform(const ProgramUniformInfo& uniform_info)
	{
		if (matches_program_uniform(uniform_info) == false)
		{
			return;
		}

		glUniform2f(uniform_info.index, value.x, value.y);
	}
};
struct UniformMatrix4 : public Uniform<Matrix4>
{
	UniformMatrix4(std::string name) : Uniform(name)
	{
		size = 1;
		type = GL_FLOAT_MAT4;
	}
	void attempt_supply_uniform(const ProgramUniformInfo& uniform_info)
	{
		if (matches_program_uniform(uniform_info) == false)
		{
			return;
		}

		glUniformMatrix4fv(uniform_info.index, 1, GL_FALSE, (const GLfloat*)&value);
	}
};
struct UniformMatrix2x3 : public Uniform<Matrix2x3>
{
	UniformMatrix2x3(std::string name) : Uniform(name)
	{
		size = 1;
		type = GL_FLOAT_MAT2x3;
	}
	void attempt_supply_uniform(const ProgramUniformInfo& uniform_info)
	{
		if (matches_program_uniform(uniform_info) == false)
		{
			return;
		}

		glUniformMatrix2x3fv(uniform_info.index, 1, GL_FALSE, (const GLfloat*)&value);
	}
};

#endif