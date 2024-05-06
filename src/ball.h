#pragma once
#include "transform.h"
#include <SDL.h>

class Ball
{
public:

	Ball();
	Ball(const int& h, const int& w, const Transform& trans);
	Ball(const int& h, const int& w);

	Transform transform;

	SDL_Rect rect;

	int height;
	int width;
	
};