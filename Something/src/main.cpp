#include <cassert>
#include <iostream>
#include "../src/Utils/Vec2D.h"
#include <SDL.h>
#include "Graphics/Color.h"
#include "Graphics/ScreenBuffer.h"

// just for test 

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 287;


int main(int argc, char* argv[]) {


	if (SDL_Init(SDL_INIT_VIDEO))
	{
		std::cout << "STL INIT failed" << std::endl;
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (window == nullptr)
	{
		std::cout << "Could not create window! here is an error :" << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Surface* surface = SDL_GetWindowSurface(window);
	if(surface)
	{

		SDL_Surface* argbSurface = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_ARGB8888, 0);
	
		SDL_PixelFormat* pixelFormat = argbSurface->format;
		std::cout << "The window pixel format is : " << SDL_GetPixelFormatName(pixelFormat->format);

		//uint32_t color = 0xFF0000;
		Color::InitColorFormat(pixelFormat);
		//Color c(255, 0, 0, 0);


		ScreenBuffer screenBuffer;
		screenBuffer.Init(pixelFormat->format, surface->w, surface->h);
		screenBuffer.SetPixel(Color::Red(), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		SDL_BlitSurface(screenBuffer.GetSurface(), nullptr, surface, nullptr);
		
		SDL_UpdateWindowSurface(window);

		// Clean up the original surface
		SDL_FreeSurface(surface);
	}

	SDL_Event sdlEvent;
	bool running = true;

	while (running)
	{
		while (SDL_PollEvent(&sdlEvent))
		{
			switch (sdlEvent.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;

}































//Vec2D v1(4, 3);
//Vec2D v2(10, 1);
//Vec2D v3(5, 6);
//Vec2D v4(15, 16);
//Vec2D v5(10, 5);
//Vec2D v6(3, 4);
//v6 *= 8;
//Vec2D v7(10, 20);

//Vec2D newVec = v6.operator*(3);
//Vec2D newVec2 = 3 * v6;

//bool result1 = (v1 == v2); 
//bool result2 = (v1 != v3);


//std::cout << result1 << std::endl;
//std::cout << result2 << std::endl;
//std::cout << -v4 << std::endl;
//std::cout << v5 / 2 << std::endl;
//std::cout << v6  << std::endl;
//std::cout << newVec << std::endl;
//std::cout << v7 + v3 << std::endl;
//std::cout << v3 - v2 << std::endl;
//std::cout << v2.GetUnitVec() << std::endl;
//std::cout << v7.Normalize() << std::endl;
//std::cout << v1.Distance(v4) << std::endl;
//std::cout << v2.GetUnitVec() << std::endl;
// std::cout << "projectile : "<< v1.ProjectOnto(v2) << std::endl;
  //std::cout << v2.GetUnitVec() << std::endl;
 //std::cout << "angle : "<< v1.AngleBetween(v2) << std::endl;
/* v1.Rotate(45.0f, v2);
 std::cout << "rotate around  : " << v1.RotationResult(45.f,v2) << std::endl;*/