#pragma once

#include "transform.h"
#include <SDL.h>

class Paddle
{
public:
	
	Paddle();
	Paddle(const int& h, const int& w);
	Paddle(const int& h, const int& w, const Transform& trans);

	Transform transform;
	
	SDL_Rect rect;
	
	int height;
	int width;
	

};