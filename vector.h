#pragma once
#include < Novice.h>
#include <assert.h>

typedef struct Matrix2x2 {
	float m[2][2];
} Matrix2x2;

typedef struct Matrix3x3 {
	float m[3][3];
} Matrix3x3;

typedef struct Vector2 {
	float x;
	float y;
} Vector2;

Matrix2x2 Add(Matrix2x2 a, Matrix2x2 b) {
	Matrix2x2 add;
	for (int x = 0; x < 2; x++) {
		for (int y = 0; y < 2; y++) {
			add.m[x][y] = a.m[x][y] + b.m[x][y];
		}
	}
	return add;
}
Matrix2x2 Subtract(Matrix2x2 a, Matrix2x2 b) {
	Matrix2x2 subtract;
	for (int x = 0; x < 2; x++) {
		for (int y = 0; y < 2; y++) {
			subtract.m[x][y] = a.m[x][y] - b.m[x][y];
		}
	}
	return subtract;
}
Matrix2x2 Multiply(Matrix2x2 a, Matrix2x2 b) {
	Matrix2x2 multiply;
	multiply.m[0][0] = (a.m[0][0] * b.m[0][0]) + (a.m[0][1] * b.m[1][0]);
	multiply.m[0][1] = (a.m[0][0] * b.m[0][1]) + (a.m[0][1] * b.m[1][1]);
	multiply.m[1][0] = (a.m[1][0] * b.m[0][0]) + (a.m[1][1] * b.m[1][0]);
	multiply.m[1][1] = (a.m[1][0] * b.m[0][1]) + (a.m[1][1] * b.m[1][1]);

	return multiply;
}

Vector2 Multiply(Vector2 v, Matrix2x2 b) {
	Vector2 multiply;
	multiply.x = (v.x * b.m[0][0]) + (v.y * b.m[1][0]);
	multiply.y = (v.x * b.m[0][1]) + (v.y * b.m[1][1]);
	return multiply;
}

Matrix3x3 Multiply(Matrix3x3 a, Matrix3x3 b) {
	Matrix3x3 multiply;
	multiply.m[0][0] = (a.m[0][0] * b.m[0][0]) + (a.m[0][1] * b.m[1][0]);
	multiply.m[0][1] = (a.m[0][0] * b.m[0][1]) + (a.m[0][1] * b.m[1][1]);
	multiply.m[0][2] = (a.m[0][0] * b.m[0][1]) + (a.m[0][1] * b.m[1][1]);
	multiply.m[1][0] = (a.m[1][0] * b.m[0][0]) + (a.m[1][1] * b.m[1][0]);
	multiply.m[1][1] = (a.m[1][0] * b.m[0][1]) + (a.m[1][1] * b.m[1][1]);
	multiply.m[1][2] = (a.m[1][0] * b.m[0][1]) + (a.m[1][1] * b.m[1][1]);
	multiply.m[2][0] = (a.m[1][0] * b.m[0][0]) + (a.m[1][1] * b.m[1][0]);
	multiply.m[2][1] = (a.m[1][0] * b.m[0][1]) + (a.m[1][1] * b.m[1][1]);
	multiply.m[2][2] = (a.m[1][0] * b.m[0][1]) + (a.m[1][1] * b.m[1][1]);

	return multiply;
}

static const int kRowHeight = 20;
static const int kcolumnWidth = 54;
void MatrixScreenPrintf(int x, int y, Matrix2x2 z) {
	for (int row = 0; row < 2; row++) {
		for (int column = 0; column < 2; column++) {
			Novice::ScreenPrintf(
			  x + column * kcolumnWidth, y + row * kRowHeight, "%.02f", z.m[row][column]);
		}
	}
}

void VectorScreenPrintf(int x, int y, Vector2 z) {
	Novice::ScreenPrintf(x, y, "%.02f", z.x);
	Novice::ScreenPrintf(x + kcolumnWidth, y, "%.02f", z.y);
}

float theta = (1.0 / 16.0f) * M_PI;

int kWorld = 500;


Matrix2x2 MakeRotateMatrix(float theta) {

	Matrix2x2 rotate;
	rotate.m[0][0] = cos(theta);
	rotate.m[0][1] = sin(theta);
	rotate.m[1][0] = -sin(theta);
	rotate.m[1][1] = cos(theta);

	return rotate;
};

Matrix3x3 makeRotateMatrix(float theta) {

	Matrix3x3 rotate;
	rotate.m[0][0] = cos(theta);
	rotate.m[1][0] = -sin(theta);
	rotate.m[2][0] = 0;
	rotate.m[0][1] = sin(theta);
	rotate.m[1][1] = cos(theta);
	rotate.m[2][1] = 0;
	rotate.m[0][2] = 0;
	rotate.m[1][2] = 0;
	rotate.m[2][2] = 1;

	return rotate;
};

Matrix3x3 MakeTranslateMatrix(Vector2 translate);

Vector2 Transform(Vector2 vector, Matrix3x3 matrix);


Matrix3x3 MakeTranslateMatrix(Vector2 translate) {
	Matrix3x3 result;
	result.m[0][0] = 1.0f;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;
	result.m[1][0] = 0.0f;
	result.m[1][1] = 1.0f;
	result.m[1][2] = 0.0f;
	result.m[2][0] = translate.x;
	result.m[2][1] = translate.y;
	result.m[2][2] = 1.0f;

	return result;
}

Vector2 Transform(Vector2 vector, Matrix3x3 matrix) {
	Vector2 result;
	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + 1.0f * matrix.m[2][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + 1.0f * matrix.m[2][1];
	float w = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + 1.0f * matrix.m[2][2];
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	return result;
}


Matrix2x2 Inverse(Matrix2x2 a) {
	Matrix2x2 result;
	float x = a.m[0][0] * a.m[1][1] - a.m[0][1] * a.m[1][0];
	if (x != 0) {
		result.m[0][0] = 1 / x * a.m[1][1];
		result.m[0][1] = 1 / x * -(a.m[0][1]);
		result.m[1][0] = 1 / x * -(a.m[1][0]);
		result.m[1][1] = 1 / x * a.m[0][0];
	}
	return result;
}

Matrix3x3 Inverse(Matrix3x3 a) { 
	Matrix3x3 result;
	float x = a.m[0][0] * a.m[1][1] * a.m[2][2] + a.m[0][1] * a.m[1][2] * a.m[2][1] +
	          a.m[0][2] * a.m[1][0] * a.m[2][1] - a.m[2][0] * a.m[1][1] * a.m[2][0] -
	          a.m[0][1] * a.m[2][1] * a.m[2][2] - a.m[0][0] * a.m[1][0] * a.m[2][1];
	if (x != 0 ) {
		result.m[0][0] = 1 / x * (a.m[1][1] * a.m[2][2] - a.m[1][2] * a.m[2][1]);
		result.m[0][1] = 1 / x * -(a.m[0][1] * a.m[2][2] - a.m[0][2] * a.m[2][1]);
		result.m[0][2] = 1 / x * (a.m[0][1] * a.m[1][2] - a.m[0][2] * a.m[1][1]);
		result.m[1][0] = 1 / x * -(a.m[1][0] * a.m[2][2] - a.m[1][2] * a.m[2][0]);
		result.m[1][1] = 1 / x * (a.m[0][0] * a.m[2][2] - a.m[0][2] * a.m[2][0]);
		result.m[1][2] = 1 / x * -(a.m[0][0] * a.m[1][2] - a.m[0][2] * a.m[1][0]);
		result.m[2][0] = 1 / x * (a.m[1][0] * a.m[2][1] - a.m[1][1] * a.m[2][0]);
		result.m[2][1] = 1 / x * -(a.m[0][0] * a.m[2][1] - a.m[0][1] * a.m[2][0]);
		result.m[2][2] = 1 / x * (a.m[0][0] * a.m[1][1] - a.m[0][1] * a.m[1][0]);
	}
	return result;
}

Matrix2x2 TransposeM1(Matrix2x2 a) { 
	Matrix2x2 result;
	result.m[0][0] = a.m[0][0];
	result.m[1][1] = a.m[1][1];
	result.m[0][1] = a.m[1][0];
	result.m[1][0] = a.m[0][1];
	return result;
}

Matrix3x3 TransposeM2(Matrix3x3 a) {
	Matrix3x3 result;
	result.m[0][0] = a.m[0][0];
	result.m[1][0] = a.m[0][1];
	result.m[2][0] = a.m[0][2];
	result.m[0][1] = a.m[1][0];
	result.m[1][1] = a.m[1][1];
	result.m[2][1] = a.m[1][2];
	result.m[0][2] = a.m[2][0];
	result.m[1][2] = a.m[2][1];
	result.m[2][2] = a.m[2][2];
	return result;
}


Matrix3x3 MakeOrthographicMatrix(float left, float top, float right, float bottom) {//正射影
	Matrix3x3 result;
	result.m[0][0] = 2.0f / (right - left);
	result.m[1][0] = 0;
	result.m[2][0] = (left + right) / (left - right);
	result.m[0][1] = 0;
	result.m[1][1] = 2.0f / (top - bottom);
	result.m[2][1] = (top + bottom) / (bottom - top);
	result.m[0][2] = 0;
	result.m[1][2] = 0;
	result.m[2][2] = 1;
	return result;
}
Matrix3x3 MakeViewportMatrix(float left, float top, float width, float height) { //ビューポート
	Matrix3x3 result; 
	result.m[0][0] = width / 2; 
	result.m[1][0] = 0;
	result.m[2][0] = left+width/2;
	result.m[0][1] = 0;
	result.m[1][1] = -height/2;
	result.m[2][1] = top+height/2;
	result.m[0][2] = 0;
	result.m[1][2] = 0;
	result.m[2][2] = 1;
	return result;
}
Matrix3x3 Inverse3x3(Matrix3x3 a) {
	Matrix3x3 result;
	result.m[2][0] = -a.m[2][0];
	result.m[2][1] = -a.m[2][1];
	return result;
};

Vector2 Lerp(const Vector2& a, const Vector2& b, float t) {
	Vector2 f;
	f.x = t * a.x + (1.0f - t) * b.x;
	f.y = t * a.y + (1.0f - t) * b.y;
	return f;

}

Vector2 Bezier(const Vector2& p0, const Vector2& p1, const Vector2& p2, float t) {
	Vector2 p0p1 = Lerp(p0, p1, t);
	Vector2 p1p2 = Lerp(p1, p2, t);
	Vector2 p = Lerp(p0p1, p1p2, t);
	return p;
}


//Matrix3x3 MakeAffinMatrix(Vector2{ a, b }, c, Vector2{ d, e }) {
//
//}











//static const int Y1 = 20;
//static const int Y2 = 40;

//		for (int i = 0; i < 2; i++) {
//	for (int j = 0; j < 2; j++) {
//		Novice::ScreenPrintf(i * 50, j * Y1, "%.02f ", m1.m[j][i]);
//	}
//}
//
//for (int i = 0; i < 3; i++) {
//	for (int j = 0; j < 3; j++) {
//		Novice::ScreenPrintf(i * 50, j * Y1 + 100, "%.02f ", m2.m[j][i]);
//	}
//}





