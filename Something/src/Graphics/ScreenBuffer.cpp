#include "ScreenBuffer.h"
#include <SDL.h>
#include <cassert>


ScreenBuffer::ScreenBuffer()
	:m_surface(nullptr)
{

}

ScreenBuffer::ScreenBuffer(const ScreenBuffer& screenBuffer)
{
	m_surface = SDL_CreateRGBSurfaceWithFormat(0, screenBuffer.m_surface->w, screenBuffer.m_surface->h, 0, screenBuffer.m_surface->format->format);
	SDL_BlitSurface(screenBuffer.m_surface, nullptr, m_surface, nullptr); // copy all of the surface from the fþrst surface to the second surface
}

void ScreenBuffer::Init(uint32_t format, uint32_t width, uint32_t height)
{
	m_surface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 0, format);
	Clear();
}

void ScreenBuffer::Clear(const Color& c)
{
	assert(m_surface);
	if(m_surface)
	{
		SDL_FillRect(m_surface, nullptr, c.GetPixelColor());
	}
}

ScreenBuffer::~ScreenBuffer()
{
	if(m_surface)
	{
		SDL_FreeSurface(m_surface);
	}
}

ScreenBuffer& ScreenBuffer::operator=(const ScreenBuffer& screenBuffer)
{
	if(this == &screenBuffer)
	{
		return *this;
	}
	if(m_surface != nullptr)
	{
		SDL_FreeSurface(m_surface);
		m_surface = nullptr;
	}

	if(screenBuffer.m_surface != nullptr)
	{
		m_surface = SDL_CreateRGBSurfaceWithFormat(0, screenBuffer.m_surface->w, screenBuffer.m_surface->h, 0, screenBuffer.m_surface->format->format);
		SDL_BlitSurface(screenBuffer.m_surface, nullptr, m_surface, nullptr);
	}
	return *this;
}


void ScreenBuffer::SetPixel(const Color& color, int x, int y)
{
	assert(m_surface);
	if(m_surface && y < m_surface->h && y >= 0 && x >= 0 && x < m_surface->w)
	{
		SDL_LockSurface(m_surface);

		uint32_t* pixels = (uint32_t*)m_surface->pixels; // this is a 1D array of all the pixels on the surface
		size_t index = GetIndex(y, x); // since want the pixels as x and y , we transfered it to index
		pixels[index] = color.GetPixelColor();

		SDL_UnlockSurface(m_surface);
	}
}

uint32_t ScreenBuffer::GetIndex(int r, int c)
{
	assert(m_surface);
	if(m_surface)
	{
		return r * m_surface->w + c;
	}
	return 0;
}
