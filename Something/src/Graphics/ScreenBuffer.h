#pragma once
#include <stdint.h>
#include "Color.h"

struct SDL_Surface;

class ScreenBuffer

{
public:
	ScreenBuffer();

	// copy constructor
	ScreenBuffer(const ScreenBuffer& screenBuffer);

	~ScreenBuffer();

	ScreenBuffer& operator=(const ScreenBuffer& screenBuffer);

	void Init(uint32_t format, uint32_t width, uint32_t height);
	inline SDL_Surface* GetSurface() { return m_surface; }
	void Clear(const Color& c = Color::Black());
	void SetPixel(const Color& color, int x, int y);

private:
	SDL_Surface* m_surface;

	// r:row , c: column
	uint32_t GetIndex(int r, int c); 

};

