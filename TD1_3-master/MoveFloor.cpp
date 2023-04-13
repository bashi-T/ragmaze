#include "MoveFloor.h"
#include "Novice.h"

MoveFloor::MoveFloor() {
	position_ = { 0, 0 };
	velocity_ = { 2.0f, 0 };
	width_ = 96.0f;
	height_ = 32.0f;
	returnLeft_ = 0;
	returnRight_ = 0;
	returnTop_ = 0;
	returnBottom_ = 0;
	isActive = 0;
}

void MoveFloor::Update() {
	if (velocity_.x != 0) {
		position_.x += velocity_.x;
	}
	if (velocity_.y != 0) {
		position_.y += velocity_.y;
	}
	
	if (position_.x < returnLeft_ || position_.x > returnRight_) {
		velocity_.x *= -1;
	}
	if (position_.y < returnTop_ || position_.y > returnBottom_) {
		velocity_.y *= -1;
	}

}

void MoveFloor::Collision(Vector2& position, Vector2& velocity, float width, float height, int& jump) {
	if (position.x <= position_.x + width_ && position.x + width >= position_.x) {
		if (position.y + height >= position_.y && position.y + height < position_.y + height_) {
			position.y = position_.y - height;
			jump = 0;
			position.x += velocity_.x;
			velocity.x += velocity_.x;
			position.y += velocity_.y;
			velocity.y = 0;
		}
		if (position.y <= position_.y + height_ && position.y + height >= position_.y + height) {
			position.y = position_.y + height_;
			velocity.y = 0;
		}
	}
}

void MoveFloor::Draw(float scroll) {
	Novice::DrawBox(position_.x - scroll, position_.y, width_, height_, 0.0f, 0x44832FF, kFillModeSolid);
}