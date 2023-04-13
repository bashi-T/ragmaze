#include <Novice.h>

const char kWindowTitle[] = "LC1A_16_ツヅキバシマサミ_AL1-2";
	typedef struct Matrix2x2 {
		float m[2][2];
	}Matrix2x2;
	
	typedef struct Vector2 {
		float x;
		float y;
	}Vector2;

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

    // Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);


	

	//struct Matrix2x2 matrix2x2 = {
	//  Add(matrix2x2.m1, matrix2x2.m2),
	//  Subtract(matrix2x2.m1, matrix2x2.m2),
	//  Multiply(matrix2x2.m1, matrix2x2.m2),
	//};
	//struct Vector2 vector2 = {
	Vector2 v = {10, 20};
	//    Multiply(vector2.v, matrix2x2.m1),
    //};

	Matrix2x2 m1;
	m1.m[0][0] = 1.0f;
	m1.m[0][1] = 2.0f;
	m1.m[1][0] = 3.0f;
	m1.m[1][1] = 4.0f;

	Matrix2x2 m2;
	m2.m[0][0] = 5.0f;
	m2.m[0][1] = 6.0f;
	m2.m[1][0] = 7.0f;
	m2.m[1][1] = 8.0f;



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
		Matrix2x2 resultAdd = Add(m1, m2);
		Matrix2x2 resultSubtract = Subtract(m1, m2);
		Matrix2x2 resultMultiply = Multiply(m1, m2);
		Vector2 resultVector = Multiply(v, m1);
		
		
		
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		MatrixScreenPrintf(0, kRowHeight * 0, resultAdd);
		MatrixScreenPrintf(0, kRowHeight * 2+10, resultSubtract);
		MatrixScreenPrintf(0, kRowHeight * 4+20, resultMultiply);
		VectorScreenPrintf(0, kRowHeight * 6+30, resultVector);
	
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
