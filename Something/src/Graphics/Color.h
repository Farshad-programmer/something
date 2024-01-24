#pragma once

#include <stdint.h>

struct SDL_PixelFormat; // this is forward declaration


class Color
{
public:

	
	static const SDL_PixelFormat* m_format;
	static void InitColorFormat(SDL_PixelFormat* format);
	static Color Black() { return Color(0, 0, 0, 255); }
	static Color White() { return Color(255, 255, 255, 255); }
	static Color Blue() { return Color(0, 0, 255, 255); }
	static Color Red() { return Color(255, 0, 0, 255); }
	static Color Green() { return Color(0, 255, 0, 255); }
	static Color Yellow() { return Color(255, 255, 0, 255); }
	static Color Magenta() { return Color(255, 0, 255, 255); }
	static Color Cyan() { return Color(37, 240, 217, 255); }
	static Color Oink() { return Color(252, 197, 224, 255); }
	static Color Orange() { return Color(245, 190, 100, 255); }


	//Color():m_color(0){}
	Color() :Color(0) {} // when we create constructor with argument then we can use this mode instead normal constructor
	Color(uint32_t color):m_color(color){}
	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	// operators
	inline bool operator==(const Color& c) const{ return m_color == c.m_color; }
	inline bool operator!=(const Color& c) const { return !(*this == c);}

private:


	uint32_t m_color;


public:

	// getter and setters
	inline uint32_t GetPixelColor() const { return m_color; }

	void SetRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	void SetRed(uint8_t red);
	void SetGreen(uint8_t green);
	void SetBlue(uint8_t blue);
	void SetAlpha(uint8_t alpha);

	uint8_t GetRed() const;
	uint8_t GetGreen() const;
	uint8_t GetBlue() const;
	uint8_t GetAlpha() const;
};







