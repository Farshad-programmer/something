#include "Color.h"
#include <SDL.h>



const SDL_PixelFormat* Color::m_format = nullptr;

void Color::InitColorFormat(SDL_PixelFormat* format)
{
	Color::m_format = format;
}

// the third constructor
Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	SetRGBA(r, g, b, a);
}


void Color::SetRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	m_color = SDL_MapRGBA(m_format, r, g, b, a);
}

void Color::SetRed(uint8_t red)
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_color, m_format, &r, &g, &b, &a);
	SetRGBA(red, g, b, a);
}

void Color::SetGreen(uint8_t green)
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_color, m_format, &r, &g, &b, &a);
	SetRGBA(r, green, b, a);
}

void Color::SetBlue(uint8_t blue)
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_color, m_format, &r, &g, &b, &a); // SDL_GetRGBA dade m_color ro migire va mirize to adress haye r,g,b,a va dar khate bad in dade haye jadid ro set mikonim 
	SetRGBA(r, g, blue, a);
}

void Color::SetAlpha(uint8_t alpha)
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_color, m_format, &r, &g, &b, &a);
	SetRGBA(r, g, b, alpha);
}

uint8_t Color::GetRed() const
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_color, m_format, &r, &g, &b, &a);
	return r;
}

uint8_t Color::GetGreen() const
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_color, m_format, &r, &g, &b, &a);
	return g;
}

uint8_t Color::GetBlue() const
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_color, m_format, &r, &g, &b, &a);
	return b;
}

uint8_t Color::GetAlpha() const
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(m_color, m_format, &r, &g, &b, &a);
	return a;
}
