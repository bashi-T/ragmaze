#pragma once
#include "Struct.h"


class Blower {
public:
    Blower();
    void Update(Vector2& position, float width, float height, int& jump, int type, int mapnumber);
public:
    Vector2 position_;
    Vector2 velocity_;
    float width_;
    float height_;
    float speed_;
    int type_;
};