#include "Blower.h"
#include "Enum.h"
#include "tofumap.h"

Blower::Blower() {
    position_ = {0, 0};
    velocity_ = { 0, 0 };
    width_ = 32;
    height_ = 32;
    speed_ = 2;
    type_ = 0;
}

void Blower::Update(Vector2& position, float width, float height, int& jump, int type, int mapnumber) {
	if (type == BEANS) {
		if (type_ == BLOWER_UP) {
			if (position.x < position_.x + width_ && position.x + width > position_.x) {
				if (position.y < position_.y) {
					int block = 0;
					for (int Y = int(position_.y / mapsize); Y > 0; Y--) {
						if (Map[mapnumber][Y][int(position_.x / mapsize)] == BLOCK || Map[mapnumber][Y][int(position_.x / mapsize)] == HOT) {
							block = Y * mapsize;
							break;
						}
					}
					if (position.y >= block + mapsize) {
						if (type == BEANS) {
							position.y -= speed_ * 2;
							jump = 2;
						}
						if (type == TOFU || type == FREEZ) {
							position.y -= speed_;
							jump = 2;
						}
					}
				}
			}
		}
		if (type_ == BLOWER_LEFT) {
			if (position.y <= position_.y + height && position.y + height >= position_.y) {
				if (position.x + width <= position_.x) {
					int block = 0;
					for (int X = int(position_.x / mapsize); X > 0; X--) {
						if (Map[mapnumber][int(position_.y / mapsize)][X] == BLOCK || Map[mapnumber][int(position_.y / mapsize)][X] == HOT) {
							block = X * mapsize;
							break;
						}

					}
					if (block + mapsize <= position.x) {
						if (type == BEANS) {
							position.x -= speed_ * 2;
						}
						if (type == TOFU || type == FREEZ) {
							position.x -= speed_;
						}
					}

				}
			}
		}
		if (type_ == BLOWER_RIGHT) {
			if (position.y <= position_.y + height && position.y + height >= position_.y) {
				if (position.x >= position_.x + width) {
					int block = 0;
					for (int X = int(position_.x / mapsize); X < map1X; X++) {
						if (Map[mapnumber][int(position_.y / mapsize)][X] == BLOCK || Map[mapnumber][int(position_.y / mapsize)][X] == HOT) {
							block = X * mapsize;
							break;
						}
					}
					if (position.x <= block) {
						if (type == BEANS) {
							position.x += speed_ * 2;
						}
						if (type == TOFU || type == FREEZ) {
							position.x += speed_;
						}
					}
				}
			}
		}
	}
	else if (type == TOFU || type == FREEZ) {
		if (type_ == BLOWER_UP) {

		}
		if (type_ == BLOWER_LEFT) {

		}
		if (type_ == BLOWER_RIGHT) {

		}
	}
}