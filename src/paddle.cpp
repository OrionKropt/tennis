#include "paddle.h"

Paddle::Paddle(const int& h, const int& w) : height(h), width(w)
{
	transform = Transform();
}

Paddle::Paddle() : height(0), width(0)
{
}

//auto Paddle::get_height() -> int
//{
//	return height;
//}
//
//auto Paddle::get_width() -> int
//{
//	return width;
//}
