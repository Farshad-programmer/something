#include "Screen.h"
#include <iostream>
#include "../Utils/Vec2D.h"
#include <SDL.h>
#include <cassert>
#include <cmath>
#include "../Shapes/Line2D.h"


Screen::Screen()
	:m_width(0), m_height(0), m_window(nullptr), m_windowSurface(nullptr)
{

}

Screen::~Screen()
{
	if (m_window)
	{
		SDL_DestroyWindow(m_window);
		m_window = nullptr;
	}
	SDL_Quit();
}

SDL_Window* Screen::Init(uint32_t w, uint32_t h, uint32_t magnification)
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		std::cout << "STL INIT failed" << std::endl;
		return nullptr;
	}

	m_width = w;
	m_height = h;

	m_window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width * magnification, m_height * magnification, 0);
	if (m_window)
	{
		m_windowSurface = SDL_GetWindowSurface(m_window);
		if (m_windowSurface)
		{
			SDL_Surface* argbSurface = SDL_ConvertSurfaceFormat(m_windowSurface, SDL_PIXELFORMAT_ARGB8888, 0);
			SDL_PixelFormat* pixelFormat = argbSurface->format;
			std::cout << "The window pixel format is : " << SDL_GetPixelFormatName(pixelFormat->format);

			//uint32_t color = 0xFF0000;
			Color::InitColorFormat(pixelFormat);
			//Color c(255, 0, 0, 0);

			m_clearColor = Color::Black();
			m_backBuffer.Init(pixelFormat->format, m_width, m_height);
			m_backBuffer.Clear(m_clearColor);
		}
	}
	return m_window;
}

void Screen::SwapScreens()
{
	assert(m_window);
	if (m_window)
	{
		// clear the current front facing surface , not the back buffer
		// since  we use magnification we need use "SDL_BlitScaled" instead "SDL_BlitSurface"
		SDL_BlitScaled(m_backBuffer.GetSurface(), nullptr, m_windowSurface, nullptr); // this make a copy from the first argonment surface to the last argoment surface , nullptr means we want the full surface instead a certain rectangle 
		SDL_UpdateWindowSurface(m_window);
		m_backBuffer.Clear(m_clearColor);
	}
}

void Screen::Draw(int x, int y, const Color& color)
{
	assert(m_window);
	if (m_window)
	{
		m_backBuffer.SetPixel(color, x, y);
	}
}

void Screen::Draw(const Vec2D& point, const Color& color)
{
	assert(m_window);
	if (m_window)
	{
		m_backBuffer.SetPixel(color, point.GetX(), point.GetY());
	}
}

void Screen::Draw(const Line2D& line, const Color& color)
{
	assert(m_window);
	if (m_window)
	{
		//Bresenham


		int dx, dy;
		int x0 = roundf(line.GetP0().GetX());
		int y0 = roundf(line.GetP0().GetY());
		int x1 = roundf(line.GetP1().GetX());
		int y1 = roundf(line.GetP1().GetY());

		dx = x1 - x0;
		dy = y1 - y0;
		signed const char ix = (dx > 0) - (dx < 0); // evaluate to 1 or -1
		signed const char iy((dy > 0) - (dy < 0)); // evaluate to 1 or -1

		dx = abs(dx) * 2;
		dy = abs(dy) * 2;

		Draw(0, 0, color);

		if (dx >= dy)
		{
			// go along in the x
			std::cout << "go along in the x" << std::endl;
			int d = dy - dx / 2;
			while (x0 != x1)
			{
				if (d >= 0)
				{
					d -= dx;
					y0 += iy;
				}
				d += dy;
				x0 += ix;
				Draw(x0, y0, color);
			}
		}
		else
		{
			// go along in y
			std::cout << "go along in the y" << std::endl;
			int d = dx - dy / 2;
			while (y0 != y1)
			{
				if (d >= 0)
				{
					d -= dy;
					x0 += ix;
				}
				d += dx;
				y0 += iy;
				Draw(x0, y0, color);
			}
		}
	}
}

void Screen::ClearScreen()
{
	assert(m_window);
	if (m_window)
	{
		SDL_FillRect(m_windowSurface, nullptr, m_clearColor.GetPixelColor());
	}
}



/*
//Bresenham


int dx, dy;
int x0 = roundf(line.GetP0().GetX());
int y0 = roundf(line.GetP0().GetY());
int x1 = roundf(line.GetP1().GetX());
int y1 = roundf(line.GetP1().GetY());

dx = x1 - x0;
dy = y1 - y0;
signed const char ix = (dx > 0) - (dx < 0); // evaluate to 1 or -1
signed const char iy((dy > 0) - (dy < 0)); // evaluate to 1 or -1

dx = abs(dx) * 2;
dy = abs(dy) * 2;

Draw(0, 0, color);

if (dx >= dy)
{
	// go along in the x
	std::cout << "go along in the x" << std::endl;
	int d = dy - dx / 2;
	while (x0 != x1)
	{
		if (d >= 0)
		{
			d -= dx;
			y0 += iy;
		}
		d += dy;
		x0 += ix;
		Draw(x0, y0, color);
	}
}
else
{
	// go along in y
	std::cout << "go along in the y" << std::endl;
	int d = dx - dy / 2;
	while (y0 != y1)
	{
		if (d >= 0)
		{
			d -= dy;
			x0 += ix;
		}
		d += dx;
		y0 += iy;
		Draw(x0, y0, color);
	}
}

 */




/*
 DDL
 
int dx, dy;
float xInc, yInc;
float x0 = line.GetP0().GetX();
float y0 = line.GetP0().GetY();
float x1 = line.GetP1().GetX();
float y1 = line.GetP1().GetY();

dx = roundf(x1 - x0);
dy = roundf(y1 - y0);

float step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);



xInc = dx / step;
yInc = dy / step;

for (int i = 0; i < step; i++)
{
	x0 += xInc;
	y0 += yInc;
	Draw(roundf(x0), roundf(y0), color);
}

*/