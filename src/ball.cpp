#pragma once
#include "ball.h"

Ball::Ball() : width(0), height(0) 
{
	rect.h = 0;
	rect.w = 0;
}
Ball::Ball(const int& h, const int& w, const Transform& trans) : height(h), width(w), transform(trans)
{
	rect.h = h;
	rect.w = w;
}

Ball::Ball(const int& h, const int& w) : height(h), width(w)
{
	rect.h = h;
	rect.w = w;
}

