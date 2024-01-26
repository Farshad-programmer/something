#include <cassert>
#include <iostream>
#include "../src/Utils/Vec2D.h"
#include <SDL.h>
#include "Graphics/Screen.h"
#include "Shapes/Line2D.h"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 3; // using this instead f changing SCREEN_WIDTH and SCREEN_HEIGHT because we want to make screen bigger but keep the pixel resolution as same , just size of the pixel will be bigger

int main(int argc, char* argv[]) {

	Screen theScreen;
	theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);
	//theScreen.Draw(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, Color::Red());
	Line2D line = { Vec2D(70,70),Vec2D(100,100) };
	theScreen.Draw(line, Color::White());
	theScreen.SwapScreens();

	Vec2D start = Vec2D(line.GetP0());
	Vec2D end = Vec2D(line.GetP1().GetX(),line.GetP1().GetY());


	SDL_Event sdlEvent;
	bool running = true;
	while (running)
	{
		std::cout << "rotating ... " << std::endl;
		end.Rotate(50.f, start);
		Line2D line = { start,end };
		theScreen.Draw(line, Color::White());
		theScreen.SwapScreens();
		SDL_Delay(200);
		
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