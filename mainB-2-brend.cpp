#include <Novice.h>
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char kWindowTitle[] = "LC1B_21_ツヅキバシマサミ_AL2";


const int map1X = 50;
const int map1Y = 25;
int mapsize = 16;
int map1[map1Y][map1X] = {};


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);


	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	int sepalatex1 = 0;
	int sepalatey1 = 0;
	int sepalatex2 = 0;
	int sepalatey2 = 0;
	int sepalate = 0;
	int jiki1X = 0;
	int jiki1Y = 0;
	int jiki2X = 100;
	int jiki2Y = 0;
	int jikivel1x = 0;
	int jikivel1y = 0;
	int jikivel2x = 0;
	int jikivel2y = 0;
	int jiki3X = 400;
	int jiki3Y = 0;
	int jiki4X = 700;
	int jiki4Y = 0;
	int width = 20;
	int count = 0;
	int easecount = 0;
	int start = 0;
	int easeX1[30] = {0};
	int easeY1[30] = {0};
	int easeX2[30] = {0};
	int easeY2[30] = {0};
	int countHi = 61;

	int floor = Novice::LoadTexture("./lightResources/white.png");
	int X1 = Novice::LoadTexture("./lightResources/particle.png");
	int X2 = Novice::LoadTexture("./lightResources/floortile3.png");
	
	int offset = 40;
	int space = 148;
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
		jikivel1x = 0;
		jikivel1y = 0;

		if (keys[DIK_D]) {
			jikivel1x += 5;
		}

		if (keys[DIK_A]) {
			jikivel1x -= 5;
		}
		if (keys[DIK_W]) {
			jikivel1y += 5;
		}

		if (keys[DIK_S]) {
			jikivel1y -= 5;
		}


		jiki1X += jikivel1x;
		jiki1Y -= jikivel1y;

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		Novice::ScreenPrintf(offset + space * 2, 40, "s", "Normal");


		Novice::SetBlendMode(BlendMode::kBlendModeNormal);
		Novice::DrawSprite(jiki1X, jiki1Y, X1, 1, 1, 0.0f, 0xFFFFFF88);
		Novice::DrawSprite(jiki2X, jiki2Y, X1, 1, 1, 0.0f, 0xFFFFFF88);
		Novice::DrawSprite(jiki3X, jiki3Y, X1, 1, 1, 0.0f, 0xFFFFFF88);
		Novice::DrawSprite(jiki4X, jiki4Y, X1, 1, 1, 0.0f, 0xFFFFFF88);



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
