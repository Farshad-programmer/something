#pragma once
#include <stdint.h>
#include "ScreenBuffer.h"
#include "Color.h"

struct SDL_Window;
struct SDL_Surface;
class Vec2D;

class Screen
{
public:
	Screen();
	~Screen();

	SDL_Window* Init(uint32_t w, uint32_t h, uint32_t magnification);
	void SwapScreens();

	// draw methods go here
	void Draw(int x, int y, const Color& color);
	void Draw(const Vec2D& point, const Color& color);

private:

	// copy constructor
	Screen(const Screen& screen);
	Screen& operator=(const Screen& screen);

	void ClearScreen();

	uint32_t m_width;
	uint32_t m_height;

	Color m_clearColor;
	ScreenBuffer m_backBuffer;

	SDL_Window* m_window;
	SDL_Surface* m_windowSurface;


public:
	// Getter and setter
	inline void SetClearColor(const Color& clearColor) { m_clearColor = clearColor; }
	inline uint32_t GetWidth()const { return m_width; }
	inline uint32_t GetHeight()const { return m_height; }
};

