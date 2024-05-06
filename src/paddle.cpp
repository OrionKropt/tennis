#include "paddle.h"

Paddle::Paddle(const int& h, const int& w) : height(h), width(w) 
{
	rect.h = h;
	rect.w = w;
}


Paddle::Paddle(const int& h, const int& w, const Transform& trans) : height(h), width(w), transform(trans)
{
	rect.h = h;
	rect.w = w;
}

Paddle::Paddle() : height(0), width(0)
{
	rect.h = 0;
	rect.w = 0;
}


