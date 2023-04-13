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

	Vector2 speed = {0.0f, 0.0f};
	int square = Novice::LoadTexture("white1x1.png");
	int x = 32;//分割数
	const Vector2& p0 = {100, (100 - 720) * -1};
	const Vector2& p1 = {400, (400 - 720) * -1};
	const Vector2& p2 = {700, (100 - 720) * -1};




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



		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		for (int i = 0; i < x; i++) {
			float t0 = i / float(x);
			float t1 = (i + 1) / float(x);
			Vector2 bezier0 = Bezier(p0, p1, p2, t0);
			Vector2 bezier1 = Bezier(p0, p1, p2, t1);
			Novice::DrawLine(bezier0.x, bezier0.y, bezier1.x, bezier1.y, 0xffffffff);
			//Novice::ScreenPrintf(
			//  10, 15*i, "%f,%f,%f,%f", bezier0.x, bezier0.y, bezier1.x, bezier1.y );

		}

		//Novice::DrawLine(p0.x, p0.y, p1.x, p1.y, 0x000000ff);
		//Novice::DrawLine(p1.x, p1.y, p2.x, p2.y, 0x000000ff);
		Novice::DrawEllipse(p0.x, p0.y, 10, 10, 0.0f, 0xff0000ff, kFillModeSolid);
		Novice::DrawEllipse(p1.x, p1.y, 10, 10, 0.0f, 0xff0000ff, kFillModeSolid);
		Novice::DrawEllipse(p2.x, p2.y, 10, 10, 0.0f, 0xff0000ff, kFillModeSolid);
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

