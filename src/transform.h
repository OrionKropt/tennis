#pragma once
#include "vector2.h"

class Transform
{
public:
	Transform();
	Transform(const vector2& pos, const vector2& vel, const int& dir);
	vector2 position;
	vector2 velocity;
	int dir;
};