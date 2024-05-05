#pragma once
#include "transform.h"
#include <SDL.h>

class Ball
{
public:
	Transform transform;

	SDL_Rect rect;

	//auto get_height() -> int;
	//auto get_width() -> int;

	int height;
	int width;
private:
	
};