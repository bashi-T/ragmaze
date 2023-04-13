#include "Function.h"
#define _USE_MATH_DEFINES
#include <math.h>

float Distance(Vector2 pos1, Vector2 pos2) {
	float a = pos1.x - pos2.x;
	float b = pos1.y - pos1.y;
	float c = sqrt(a * a + b * b);
	return c;
}