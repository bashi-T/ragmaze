#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include<assert.h>
#include<vector.h>

const char kWindowTitle[] = "LC1A_16_ツヅキバシマサミ_AL1-2";
	


    // Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	Vector2 speed = {200, 200};
	int square = Novice::LoadTexture("white1x1.png");
	static const int Y1 = 20;
	static const int Y2 = 40;

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

		Matrix2x2 m1;
		m1.m[0][0] = 1.0f;
		m1.m[0][1] = 2.0f;
		m1.m[1][0] = 3.0f;
		m1.m[1][1] = 4.0f;

		Matrix3x3 m2;
		m2.m[0][0] = 1.0f;
		m2.m[0][1] = 2.0f;
		m2.m[0][2] = 0.0f;
		m2.m[1][0] = 3.0f;
		m2.m[1][1] = 4.0f;
		m2.m[1][2] = 0.0f;
		m2.m[2][0] = 5.0f;
		m2.m[2][1] = 6.0f;
		m2.m[2][2] = 1.0f;

		m1 = TransposeM1(m1);
		m2 = TransposeM2(m2);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				Novice::ScreenPrintf(i * 50, j * Y1, "%.02f ", m1.m[j][i]);
			}
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				Novice::ScreenPrintf(i * 50, j * Y1 + 100, "%.02f ", m2.m[j][i]);
			}
		}

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

