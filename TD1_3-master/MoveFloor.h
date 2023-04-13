#pragma once
#include "Struct.h"

class MoveFloor {
public:
	MoveFloor();
	void Update();
	void Draw(float scroll);
	void Collision(Vector2& position, Vector2& velocity, float width, float height, int& jump);
public:
	Vector2 position_;
	Vector2 velocity_;
	float width_;
	float height_;
	float returnLeft_;
	float returnRight_;
	float returnTop_;
	float returnBottom_;
	int isActive;
};