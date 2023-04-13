#pragma once


void switchint(int& a, int b);
void switchint(int& a, int b) {
	int c = a;
	a = b;
	b = c;

}

void switchfloat(float a, float b);
void switchfloat(float a, float b) {
	float c = a;
	a = b;
	b = c;
}

