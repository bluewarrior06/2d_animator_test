#ifndef _VECTOR_2_H_
#define _VECTOR_2_H_

/// <summary>
/// (The cornerstone of the 2D cartesian coordiante system!)
/// A vector value that holds an X and Y value.
/// </summary>
struct Vector2
{
	Vector2();
	Vector2(float scalar);
	Vector2(float x, float y);
	Vector2(const Vector2& copy);

	float x = 0.0f;
	float y = 0.0f;

	void operator=(const Vector2& copy);
};

#endif