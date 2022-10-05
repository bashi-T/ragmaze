#include <Novice.h>
#define _USE_MATH_DEFINES
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<light-map.h>

const char kWindowTitle[] = "";



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
		Novice::Initialize(kWindowTitle, 1280, 720);

		int jikiX = 0;
	    int jikiY = 640;
	    int jikivelx = 50;
	    int jikively = 20;
	    int G = 1;

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
	
		jikivelx = 0;

		if (keys[DIK_D]) {
			jikivelx = 10;
		}
		if (keys[DIK_A] ) {
			jikivelx = -10;
		}
		/*
		if (
		  (utubohitx - whalehitx) * (utubohitx - whalehitx) <= 20164 && /*x=32 y=5 *csesahkmnbj
		  (utubohity - whalehity) * (utubohity - whalehity) <= 13225 && utubolife == 1) {
			whalelife -= 1;
			utubolife = 0;
			SEcount = -1;
		}
*/
		
		if (jikively == -20) {
			jikively = 20;
		}
		jikively -= G;
		jikiY -= jikively;
		jikiX += jikivelx;
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		for (int y = 0; y < MapY; y++) {
			for (int x = 0; x < MapX; x++) {
				if (Map[mapnumber][y][x] == 0) {
					//Novice::DrawQuad(
					//  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					//  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					//  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					//  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					//  mapsize, mapsize, floor, 0xFFFFFFFF);
					Novice::DrawBox(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1, mapsize, mapsize, 0.0f,
					  0x00000000, kFillModeSolid);
				}

				if (Map[mapnumber][y][x] == 1) {
					// Novice::DrawQuad(
					//   x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					//   x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					//   x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					//   x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0,
					//   0, mapsize, mapsize, floor, 0xFFFFFFFF);
					Novice::DrawBox(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1, mapsize, mapsize, 0.0f,
					  0xFFFFFFFF, kFillModeSolid);
				}

				if (Map[mapnumber][y][x] == 2) {
					//Novice::DrawQuad(
					//  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					//  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					//  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					//  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					//  mapsize, mapsize, floor, 0xFFFFFFFF);					
					Novice::DrawBox(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1, mapsize, mapsize, 0.0f,
					  0xFF0000FF, kFillModeSolid);
				}

				if (Map[mapnumber][y][x] == 3) {
					// Novice::DrawQuad(
					//   x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					//   x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					//   x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					//   x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0,
					//   0, mapsize, mapsize, floor, 0xFFFFFFFF);
					Novice::DrawBox(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1, mapsize, mapsize, 0.0f,
					  0x00FF00FF, kFillModeSolid);
				}
			}
		}
		Novice::DrawBox(
		  jikiX,jikiY, mapsize, mapsize, 0.0f, 0x0000FFFF,
		  kFillModeSolid);

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
