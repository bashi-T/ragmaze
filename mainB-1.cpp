#include <Novice.h>
#define _USE_MATH_DEFINES
#include <AL2_1-1_1_maptip.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char kWindowTitle[] = "LC1A_16_ツヅキバシマサミ_AL1-2";



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 800, 800);

	

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};



	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		int jiki1 = Novice::LoadTexture("./TenDays/player_move_down0.png");
		//int jiki2 = Novice::LoadTexture("./TenDays/player_move_down1.png");
		//int jiki3 = Novice::LoadTexture("./TenDays/player_move_down2.png");
		//int jiki4 = Novice::LoadTexture("./TenDays/player_move_down3.png");
		//int jiki5 = Novice::LoadTexture("./TenDays/player_move_left0.png");
		//int jiki6 = Novice::LoadTexture("./TenDays/player_move_left1.png");
		//int jiki7 = Novice::LoadTexture("./TenDays/player_move_left2.png");
		//int jiki8 = Novice::LoadTexture("./TenDays/player_move_left3.png");
		//int jiki9 = Novice::LoadTexture("./TenDays/player_move_right0.png");
		//int jiki10 = Novice::LoadTexture("./TenDays/player_move_right1.png");
		//int jiki11 = Novice::LoadTexture("./TenDays/player_move_right2.png");
		//int jiki12 = Novice::LoadTexture("./TenDays/player_move_right3.png");
		//int jiki13 = Novice::LoadTexture("./TenDays/player_move_up0.png");
		//int jiki14 = Novice::LoadTexture("./TenDays/player_move_up1.png");
		//int jiki15 = Novice::LoadTexture("./TenDays/player_move_up2.png");
		//int jiki16 = Novice::LoadTexture("./TenDays/player_move_up3.png");
		int jikipic = jiki1;

		int mapsize = 32;
		int movecount = 0;
		int movetime = 0;
		int clearcount = 0;
		int mapnumber = 0;
		int scene = 0;
		int keypush = 0;
		int sepalatex1 = 0;
		int sepalatey1 = 0;
		int jikiX = 32;
		int jikiY = 32;
		int jikivelx = 0;
		int jikively = 0;


		int floor = Novice::LoadTexture("./TenDays/floor0.png");
		int wall = Novice::LoadTexture("./TenDays/wall0.png");

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
	
		jikiX += jikivelx;
		jikiY += jikively;

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

	for (int y = 0; y < map1Y; y++) {
			for (int x = 0; x < map1X; x++) {
				if (map1[y][x] == 0) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, floor, 0xFFFFFFFF);
				}
				if (map1[y][x] == 1) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, wall, 0xFFFFFFFF);
				}

			}
	}
	Novice::DrawQuad(
	  jikiX + sepalatex1, jikiY + sepalatey1, jikiX + sepalatex1 + mapsize, jikiY + sepalatey1,
	  jikiX + sepalatex1, jikiY + sepalatey1 + mapsize, jikiX + sepalatex1 + mapsize,
	  jikiY + sepalatey1 + mapsize, 0, 0, mapsize, mapsize, jikipic, 0xFFFFFFFF);

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
