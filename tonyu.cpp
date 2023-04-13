#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <tonyu.h>
#include<switching.cpp>

const char kWindowTitle[] = "";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	
	for (int i = 0; i < max; i++) {
		tonyu.splashRX[i] = 2;
		tonyu.splashRY[i] = 2;
	}

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

	    currentTime = time(nullptr);

		///
		/// ↓更新処理ここから
		///
		
				
		if (keys[DIK_D]) {
			jiki.X += jiki.velX;
		}
		if (keys[DIK_A]) {
			jiki.X -= jiki.velX;
		}

		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && jiki.jumpcount == 0 && ground == 0) {
			jiki.velY += jiki.jumpheight;
			jiki.jumpcount = 1;
			yobi1 = jiki.radiusX;
			yobi2 = jiki.radiusY;
		}

		if (jiki.velY > 0) {
			jiki.radiusX--;
			jiki.radiusY++;
			if (jiki.radiusY > (yobi1 + yobi2) / 2) {
				jiki.radiusY = (yobi1 + yobi2) / 2;
			}
			if (jiki.radiusX < (yobi1 + yobi2) / 2) {
				jiki.radiusX = (yobi1 + yobi2) / 2;
			}
		}

		if (jiki.velY < 0) {
			jiki.radiusX--;
			jiki.radiusY++;
			if (jiki.radiusY > yobi1) {
				jiki.radiusY = yobi1;
			}
			if (jiki.radiusX < yobi2) {
				jiki.radiusX = yobi2;
			}
		}

		jiki.velY -= 1;
		jiki.Y -= jiki.velY;


		if (jiki.Y > 500) {//地面との当たり判定に変更
			jiki.Y = 500;
			jiki.velY = 0;
			if (jiki.jumpcount == 1) {
				yobi1 = jiki.radiusX;
				jiki.radiusX = jiki.radiusY;
				jiki.radiusY = yobi1;
				jiki.jumpcount = 0;
				ground = 1;
				for (int i = 0; i < splashmax; i++) {//飛沫
					srand(currentTime + i * i);
					tonyu.splashcount[i] = 0;

					tonyu.splashX[i] = jiki.X + (rand() % jiki.radiusX - jiki.radiusX / 2);
					tonyu.splashY[i] = jiki.Y;

					tonyu.splashVY[i] = 8;
					if (tonyu.splashX[i] > jiki.X) {
						tonyu.splashVX[i] = (tonyu.splashX[i] - jiki.X)/2;
					}
					if (tonyu.splashX[i] < jiki.X) {
						tonyu.splashVX[i] = (tonyu.splashX[i] - jiki.X)/2;
					}
				}
			}
		}

		if (ground == 1) {
			groundcount++;
		}

		if (groundcount > 10) {
			groundcount = 0;
			ground = 0;
		}


		for (int i = 0; i < splashmax; i++) {
			tonyu.splashVY[i] -= 1;
			if (tonyu.splashVY[i] < 0) {
				tonyu.splashVY[i] = 0;
			}
			tonyu.splashX[i] -= tonyu.splashVX[i];
			tonyu.splashY[i] -= tonyu.splashVY[i];
			tonyu.splashcount[i]++;
			if (tonyu.splashcount[i] > 11) {
				tonyu.splashcount[i] = 11;
			}
		}


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///


		if(ground==1) {
			Novice::DrawEllipse(
			  jiki.X, jiki.Y, jiki.radiusX + jiki.radiusY / 2, jiki.radiusY / 2, 0.0f, 0xffdeadff,
			  kFillModeSolid);
		} else if (keys[DIK_D] || keys[DIK_A]) {
			Novice::DrawEllipse(
			  jiki.X, jiki.Y, jiki.radiusX + 4, jiki.radiusY - 2, 0.0f, 0xffdeadff, kFillModeSolid);
		}else {
			Novice::DrawEllipse(
			  jiki.X, jiki.Y, jiki.radiusX, jiki.radiusY, 0.0f, 0xffdeadff, kFillModeSolid);
		}
		
		


		for (int i = 0; i < max; i++) {
			if (tonyu.splashcount[i] < 11) {
				Novice::DrawEllipse(
				  tonyu.splashX[i], tonyu.splashY[i], tonyu.splashRX[i], tonyu.splashRY[i],
				  0.0f, 0xffdeadff,  kFillModeSolid);
			}

		}  
			Novice::ScreenPrintf(10, 10, "%d,%d", jiki.radiusX, jiki.radiusY);
				 
	

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