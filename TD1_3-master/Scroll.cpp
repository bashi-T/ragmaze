#include "Scroll.h"

Scroll::Scroll() {
	speed_ = { 0, 0 };
	scrollStart_ = { 200.0f , 0};
	scrollEnd_ = { 996.0f, 0 };
}


void Scroll::Update(Vector2 position, Vector2 velocity, float width, float height) {
	if (position.x + width > scrollStart_.x && position.x + width < scrollEnd_.x) {
		speed_.x += velocity.x;
	}
}