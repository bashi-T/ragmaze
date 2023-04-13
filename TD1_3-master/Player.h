#pragma once
#include "Struct.h"

class Player {
public:
	void Update(char* keys, char* preKeys);
	void Jump();
	void Screen(float scroll);
	void Draw();
	
	Player();
public:
	Vector2 position_;
	Vector2 velocity_;
	Vector2 acceleration_;
	Vector2 speed_;
	Vector2 screenPosition;
	float width_;
	float height_;
	int jump_;
	int Alive_;
	int type_;

};