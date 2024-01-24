#include "Screen.h"
#include <iostream>
#include "../Utils/Vec2D.h"
#include <SDL.h>
#include <cassert>


Screen::Screen()
	:m_width(0),m_height(0),m_window(nullptr),m_windowSurface(nullptr)
{

}

Screen::~Screen()
{
	if(m_window)
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
	if(m_window)
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

void Screen::ClearScreen()
{
	assert(m_window);
	if(m_window)
	{
		SDL_FillRect(m_windowSurface, nullptr, m_clearColor.GetPixelColor());
	}
}
