#include "color.h"

Color::Color()
{

}
Color::Color(const Color& copy)
{
	this->r = copy.r;
	this->g = copy.g;
	this->b = copy.b;
	this->a = copy.a;
}
Color::Color(Color&& move) noexcept
{
	this->r = move.r;
	this->g = move.g;
	this->b = move.b;
	this->a = move.a;

	move.r = 0.0f;
	move.g = 0.0f;
	move.b = 0.0f;
	move.a = 0.0f;
}
Color::~Color()
{
	r = 0.0f;
	b = 0.0f;
	g = 0.0f;
	a = 0.0f;
}

void Color::operator=(const Color& copy)
{
	this->r = copy.r;
	this->g = copy.g;
	this->b = copy.b;
	this->a = copy.a;
}
void Color::operator=(Color&& move) noexcept
{
	this->r = move.r;
	this->g = move.g;
	this->b = move.b;
	this->a = move.a;

	move.r = 0.0f;
	move.g = 0.0f;
	move.b = 0.0f;
	move.a = 0.0f;
}

ColorInt::ColorInt()
{

}
ColorInt::ColorInt(const ColorInt& copy)
{
	this->r = copy.r;
	this->g = copy.g;
	this->b = copy.b;
	this->a = copy.a;
}
ColorInt::ColorInt(ColorInt&& move) noexcept
{
	this->r = move.r;
	this->g = move.g;
	this->b = move.b;
	this->a = move.a;

	move.r = 0;
	move.g = 0;
	move.b = 0;
	move.a = 0;
}
ColorInt::~ColorInt()
{
	r = 0;
	b = 0;
	g = 0;
	a = 0;
}

void ColorInt::operator=(const ColorInt& copy)
{
	this->r = copy.r;
	this->g = copy.g;
	this->b = copy.b;
	this->a = copy.a;
}

struct [[nodiscard]] E {

};

void ColorInt::operator=(ColorInt&& move) noexcept
{
	this->r = move.r;
	this->g = move.g;
	this->b = move.b;
	this->a = move.a;

	move.r = 0;
	move.g = 0;
	move.b = 0;
	move.a = 0;
}