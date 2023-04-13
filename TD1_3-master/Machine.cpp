#include "Novice.h"
#include "Machine.h"
#include "Enum.h"

Machine::Machine() {
	position_ = { 0, 0 };
	width_ = 64.0f;
	height_ = 64.0f;
	color_ = 0xFFFFFFFF;
	type_ = 0;
}

void Machine::Update(Vector2& position, Vector2& velocity, float width, float height, int& type) {
	if (type_ == MILKMC) {
		if (position.x <= position_.x + width_ && position.x + width >= position_.x) {
			if (position.y <= position_.y + height_ && position.y >= position_.y && type == BEANS) {
				type = SOYMILK;
			}
		}
	}
	if (type_ == TOFUMC) {
		if (position.x <= position_.x + width_ && position.x + width >= position_.x) {
			if (position.y <= position_.y + height_ && position.y >= position_.y && type == BEANS) {
				type = TOFUMC;
			}
		}
	}
	if (type_ == FREEZMC) {
		if (position.x <= position_.x + width_ && position.x + width >= position_.x) {
			if (position.y <= position_.y + height_ && position.y >= position_.y && type == BEANS) {
				type = FREEZ;
			}
		}
	}
	
}

void Machine::Collision(Vector2& position, Vector2& velocity, float width, float height, int& jump) {
	if (position.x <= position_.x + width_ - 1 && position.x + width >= position_.x) {
		if (position.y + height >= position_.y && position.y + height < position_.y + height_) {
			position.y = position_.y - height;
			velocity.y = 0;
			jump = 0;
		}
	}
}

void Machine::Draw(float scroll) {
	Novice::DrawBox(position_.x - scroll, position_.y, width_, height_, 0.0f, color_, kFillModeSolid);
}