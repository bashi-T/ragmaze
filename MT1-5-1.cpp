#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
const char kWindowTitle[] = "LC1A_16_ツヅキバシマサミ_MT1";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	float box1X = 300;
	float box1Y = 50;
	float box2X;
	float box2Y;
	float box3X = 500;
	float box3Y = 100;
	float box4X;
	float box4Y;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		Novice::GetMousePosition;

		box2X = box1X * cosf(1 / 8.0f * M_PI) - box1Y * sinf(1 / 8.0f * M_PI);
		box2Y = box1Y * cosf(1 / 8.0f * M_PI) + box1X * sinf(1 / 8.0f * M_PI);
		box4X = box3X * cosf(1 / 4.0f * M_PI) - box3Y * sinf(1 / 4.0f * M_PI);
		box4Y = box3Y * cosf(1 / 4.0f * M_PI) + box3X * sinf(1 / 4.0f * M_PI);

		//box2X = box1X * cos(15 / 8.0f) * M_PI - box1Y * sin(15 / 8.0f) * M_PI;
		//box2Y = box1Y * cos(15 / 8.0f) * M_PI + box1X * sin(15 / 8.0f) * M_PI;
		//box4X = box3X * cos(7 / 4.0f) * M_PI - box3Y * sin(7 / 4.0f) * M_PI;
		//box4Y = box3Y * cos(7 / 4.0f) * M_PI + box3X * sin(7 / 4.0f) * M_PI;

		Novice::DrawBox(box1X, box1Y, 100, 100, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box2X, box2Y, 100, 100, 0.0f, RED, kFillModeSolid);
		Novice::DrawBox(box3X, box3Y, 100, 100, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box4X, box4Y, 100, 100, 0.0f, BLUE, kFillModeSolid);
		Novice::ScreenPrintf(10, 10, "box2X=%f boxY2=%f box4X=%f boxY4=%f", box2X, box2Y, box4X, box4Y);
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