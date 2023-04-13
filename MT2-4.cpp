#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include<assert.h>

const char kWindowTitle[] = "LC1A_16_ツヅキバシマサミ_AL1-2";
	


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

	Matrix2x2 MakeRotateMatrix(float theta);

    Matrix2x2 MakeRotateMatrix(float R){
	
			Matrix2x2 rotate;
	    rotate.m[0][0] = cos(theta);
	        rotate.m[0][1] = sin(theta);
	    rotate.m[1][0] = -sin(theta);
	        rotate.m[1][1] = cos(theta);

	
	return rotate;
	
	};

	Matrix3x3 MakeTranslateMatrix(Vector2 translate);


    Vector2 Transform(Vector2 vector, Matrix3x3 matrix);


    Vector2 leftTop = {-100, -50};
    Vector2 rightTop = {100, -50};
    Vector2 leftbottom = {-100, 50};
    Vector2 rightbottom = {100, 50};
    //Vector2 speed = {200, 200};
    Matrix2x2 rotateMatrix = MakeRotateMatrix(theta);

	Vector2 rotatedLeftTop = Multiply(leftTop, rotateMatrix);
    Vector2 rotatedRightTop = Multiply(rightTop, rotateMatrix);
    Vector2 rotatedLeftBottom = Multiply(leftbottom, rotateMatrix);
    Vector2 rotatedRightBottom = Multiply(rightbottom, rotateMatrix);

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





	Vector2 Transform(Vector2 vector, Matrix3x3 matrix){ 
		Vector2 result;
	    result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + 1.0f * matrix.m[2][0];
	    result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + 1.0f * matrix.m[2][1];
	    float w = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + 1.0f * matrix.m[2][2];
	    assert(w != 0.0f);
	    result.x /= w;
	    result.y /= w;
	    return result;
	}




    // Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	Vector2 speed = {200,200};
	int square = Novice::LoadTexture("white1x1.png");





	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};



	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		
	    Vector2 rotatedLeftTop = Multiply(leftTop, rotateMatrix);
		Vector2 rotatedRightTop = Multiply(rightTop, rotateMatrix);
		Vector2 rotatedLeftBottom = Multiply(leftbottom, rotateMatrix);
		Vector2 rotatedRightBottom = Multiply(rightbottom, rotateMatrix);

		leftTop = rotatedLeftTop;
		rightTop = rotatedRightTop;
		leftbottom = rotatedLeftBottom;
		rightbottom = rotatedRightBottom;

		rotatedLeftTop.x += 400.0f;
		rotatedLeftTop.y += 100.0f;
		rotatedRightTop.x += 400.0f;
		rotatedRightTop.y += 100.0f;
		rotatedLeftBottom.x += 400.0f;
		rotatedLeftBottom.y += 100.0f;
		rotatedRightBottom.x += 400.0f;
		rotatedRightBottom.y += 100.0f;
		

		
	if (keys[DIK_D]) {
		    speed.x += 10.0f;
		}
		if (keys[DIK_A]) {
			speed.x -= 10.0f;
		}
		if (keys[DIK_S]) {
			speed.y -= 10.0f;
		}
		if (keys[DIK_W]) {
			speed.y += 10.0f;
		}
	           Matrix3x3 translateMatrix = MakeTranslateMatrix(speed);

		Vector2 translateLeftTop = Transform(leftTop, translateMatrix);
		Vector2 translateRightTop = Transform(rightTop, translateMatrix);
		Vector2 translateLeftBottom = Transform(leftbottom, translateMatrix);
		Vector2 translaterightbottom = Transform(rightbottom, translateMatrix);




		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
				 Novice::DrawQuad(
		  translateLeftTop.x, translateLeftTop.y * (-1) + kWorld,
			 translateRightTop.x, translateRightTop.y * (-1) + kWorld,
		  translateLeftBottom.x,translateLeftBottom.y * (-1) + kWorld,
		   translaterightbottom.x,translaterightbottom.y * (-1) + kWorld,
		   0, 0, 200, 100, square, 0xFFFFFFFF);


		///
		/// ↑描画処理ここまで
		///

			// フレームの終了
			Novice::EndFrame();

			// ESCキーが押されたらループを抜ける
			if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
				break;
			}
		
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}


