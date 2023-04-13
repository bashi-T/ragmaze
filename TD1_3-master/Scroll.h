#pragma once
#include "Struct.h"

class Scroll {
public:
	Scroll();
	void Update(Vector2 position, Vector2 velocity, float width, float height);
public:
	Vector2 speed_;
	Vector2 scrollStart_;
	Vector2 scrollEnd_;
};
