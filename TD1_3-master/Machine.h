#pragma once
#include "Struct.h"

class Machine {
public:
	Machine();
	void Update(Vector2& position, Vector2& velocity, float width, float height,  int& type);
	void Draw(float scroll);
	void Collision(Vector2& position, Vector2& velocity, float width, float height, int& jump);
public:
	Vector2 position_;
	float width_;
	float height_;
	int color_;
	int type_;
};