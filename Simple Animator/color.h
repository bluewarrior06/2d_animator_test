#ifndef _COLOR_H_
#define _COLOR_H_

/// <summary>
/// Holds RGBA colors, each as a float.
/// </summary>
struct Color
{
public:
	Color();
	Color(const Color& copy);
	Color(Color&& move) noexcept;
	~Color();

	float r = 0.0;
	float g = 0.0;
	float b = 0.0;
	float a = 0.0;

	void operator=(const Color& copy);
	void operator=(Color&& move) noexcept;
};

struct ColorInt
{
public:
	ColorInt();
	ColorInt(const ColorInt& copy);
	ColorInt(ColorInt&& move) noexcept;
	~ColorInt();

	unsigned char r = 0;
	unsigned char g = 0;
	unsigned char b = 0;
	unsigned char a = 0;

	void operator=(const ColorInt& copy);
	void operator=(ColorInt&& move) noexcept;
};
#endif