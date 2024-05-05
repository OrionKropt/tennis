#include "transform.h"

Transform::Transform() : dir(0)
{
	position = vector2();
	velocity = vector2();
}

Transform::Transform(const vector2& pos, const vector2& vel, const int& dir)
{
	position = pos;
	velocity = vel;
	this->dir = dir;
}
