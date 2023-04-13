#include "Player.h"
#include "Novice.h"
#include "Enum.h"
#include "Scroll.h"

Player::Player() {
	position_ = { 0, 0 };
	velocity_ = { 0, 0 };
	screenPosition = { 0, 0 };
	acceleration_ = { 0, 1.0f };
	speed_ = {5.0f, 20.0f };
	width_ = 32.0f;
	height_ = 32.0f;
	jump_ = 0;
	Alive_ = 0;
	type_ = BEANS;
}
void Player::Update(char* keys, char* preKeys) {
	velocity_.x = 0;
	if (keys[DIK_LEFT]) {
		velocity_.x -= speed_.x;
		position_.x += velocity_.x;
	}
	if (keys[DIK_RIGHT]) {
		velocity_.x += speed_.x;
		position_.x += velocity_.x;
	}
	if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0 && jump_ == 0) {
		velocity_.y = -speed_.y;
		jump_ = 1;
	}
}

void Player::Jump() {
	if (velocity_.y < 30.0f && jump_ != 2) {
		velocity_.y += acceleration_.y;
	}
	position_.y += velocity_.y * Alive_;
}

void Player::Screen(float scroll) {
	screenPosition.x = position_.x - scroll;
	screenPosition.y = position_.y;
}

void Player::Draw() {
	
	if (Alive_ == 1) {
		if (type_ == BEANS) {
			Novice::DrawEllipse(screenPosition.x + width_ / 2, screenPosition.y + height_ / 2, width_ / 2, height_ / 2, 0.0f, 0x665400FF, kFillModeSolid);
		}
		if (type_ == SOYMILK) {
			Novice::DrawTriangle(screenPosition.x + width_ / 2, screenPosition.y, screenPosition.x, screenPosition.y + height_, screenPosition.x + width_, screenPosition.y + height_, 0xFFFFFAFF, kFillModeSolid);
		}
		if (type_ == TOFU) {
			Novice::DrawBox(screenPosition.x, screenPosition.y, width_, height_, 0.0f, WHITE, kFillModeSolid);
		}
		if (type_ == FREEZ) {
			Novice::DrawBox(screenPosition.x, screenPosition.y, width_, height_, 0.0f, 0x02669CFF, kFillModeSolid);
		}

	}
}