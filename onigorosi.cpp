#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <onigorosi.h>

const char kWindowTitle[] = "エフェクトウェポン";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

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

		unsigned int currentTime = time(nullptr);

		///
		/// ↓更新処理ここから
		///

		if (hitTime == 0) {
			if (keys[DIK_D]) {
				jikiX += jikivelX;
			}
			if (keys[DIK_A]) {
				jikiX -= jikivelX;
			}
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && jumpcount == 0) {
				jikivelY += jumpheight;
				jumpcount = 1;
			}
			jikivelY -= 1;
			jikiY -= jikivelY;
			if (jikiY > 500) {
				jikiY = 500;
				jikivelY = 0;
				jumpcount = 0;
			}
		}
		if (
		  (jikiY + mapsize / 2) - (oniY + mapsize / 2) < mapsize &&
		  (jikiY + mapsize / 2) - (oniY + mapsize / 2) > -mapsize &&
		  (jikiX + mapsize / 2) - (oniX + mapsize / 2) < mapsize &&
		  (jikiX + mapsize / 2) - (oniX + mapsize / 2) > -mapsize&&
			bustercount==0) {
			bustercount = 1;
		}
		if (bustercount > 0) {
			hitTime += 1;
		}
		if (bustercount == 0) {
			hitTime = 0;
		}
		if (bustercount == 1) {
			for (int i = 0; i < effect; i++) {
				srand(currentTime+i*i);

				randamX[i] = rand();
				randamY[i] = rand();

				bloodX[i] = oniX + mapsize / 2;
				//-2;
				bloodY[i] = oniY + mapsize / 2;
				//-2;

				bloodvelX[i] = randamX[i] % splashX - splashX/2;
				bloodvelY[i] = randamY[i] % splashY;
			}
			if (hitTime < 60 && hitTime % 4 == 3) {
				sepalateX = 5;
			}else if (hitTime < 60 && hitTime % 4 == 1) {
				sepalateX = -5;
			} else {
				sepalateX = 0;
			}
			
		}
		if (hitTime > 60) {
			bustercount = 2;
			sepalateX = 0;
		}
		if (bustercount == 2) {
			for (int i = 0; i < effect; i++) {
				bloodvelY[i] -= 2;
				bloodX[i] += bloodvelX[i];
				bloodY[i] -= bloodvelY[i];
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		///
		Novice::DrawBox(jikiX, jikiY, mapsize, mapsize, 0.0f, BLUE, kFillModeSolid);

		if (bustercount != 2) {
			Novice::DrawBox(
			  oniX + sepalateX, oniY + sepalateY, mapsize, mapsize, 0.0f, RED, kFillModeSolid);
		}
		if (bustercount == 2) {
			for (int i = 0; i < effect; i++) {
				//Novice::DrawQuad(
				//  bloodX[i], bloodY[i], bloodX[i], bloodY[i] + 8, bloodX[i] + 8, bloodY[i],
				//  bloodX[i] + 8, bloodY[i] + 8, 0, 0, 8, 8, floor, 0xFFFFFFFF);
				Novice::DrawEllipse(
				  bloodX[i], bloodY[i], radius, radius, 0.0f, RED,kFillModeSolid);
				  

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