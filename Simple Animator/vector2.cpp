#include "vector2.h"

Vector2::Vector2()
{

}
Vector2::Vector2(float scalar)
{
	this->x = scalar;
	this->y = scalar;
}
Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}
Vector2::Vector2(const Vector2& copy)
{
	this->x = copy.x;
	this->y = copy.y;
}


void Vector2::operator=(const Vector2& copy)
{
	this->x = copy.x;
	this->y = copy.y;
}
