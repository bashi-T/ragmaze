#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <onigorosi.h>
#include<switchfloor.h>

const char kWindowTitle[] = "";

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
		int floor = Novice::LoadTexture("./lightREsources/floortile4.png");

		unsigned int currentTime = time(nullptr);

		///
		/// ↓更新処理ここから
		///
		jikivelY -= 1;
		if (jikivelY < -10) {
			jikivelY = -10;
		}

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


			jikiY -= jikivelY;
			if (jikiY > 500) {
				jikiY = 500;
				jikivelY = 0;
				jumpcount = 0;
			}
		}
		if (
		  (jikiY + mapsize / 2) - (bottun.Y + mapsize / 2) < mapsize &&
		  (jikiY + mapsize / 2) - (bottun.Y + mapsize / 2) > -mapsize &&
		  (jikiX + mapsize / 2) - (bottun.X + mapsize / 2) < mapsize &&
		  (jikiX + mapsize / 2) - (bottun.X + mapsize / 2) > -mapsize && bottun.count == 0) {
			bottun.count = 1;
		}

		if (bottun.count == 1) {
			movefloor.slide++;
			if (movefloor.slide > 179) {
				movefloor.slide = 0;
			}

			if (movefloor.slide < 6 && movefloor.slide != 0) {
				movefloor.velX++;
			}
			if (movefloor.slide > 50 && movefloor.slide < 96) {
				movefloor.velX--;
			}
			if (movefloor.slide > 55 && movefloor.slide < 91) {
				movefloor.velX = 0;
			}
			if (movefloor.slide > 140) {
				movefloor.velX++;
			}
			if (movefloor.slide > 145) {
				movefloor.velX = 0;
			}
			movefloor.X += movefloor.velX;
		}


		if (
		  (jikiY + mapsize / 2) - (movefloor.Y + mapsize / 2) < mapsize &&
		  (jikiY + mapsize / 2) - (movefloor.Y + mapsize / 2) > -mapsize &&
		  (jikiX + mapsize / 2) - (movefloor.X + mapsize / 2) < mapsize &&
		  (jikiX + mapsize / 2) - (movefloor.X + mapsize / 2) > -mapsize) {
			if (jikivelY > 0) {
				jikiY = movefloor.Y + mapsize;
				jikivelY = 0;
			}
			if (jikivelY < 0) {
				jikiY = movefloor.Y - mapsize;
				jikivelY = 0;
				jumpcount = 0;
			}
		}
		if (
		  (jikiY + mapsize / 2) - (movefloor.Y + mapsize / 2) < mapsize &&
		  (jikiY + mapsize / 2) - (movefloor.Y + mapsize / 2) > -mapsize &&
		  (jikiX + mapsize / 2) - (movefloor.X + mapsize / 2) < mapsize &&
		  (jikiX + mapsize / 2) - (movefloor.X + mapsize / 2) > -mapsize) {
			if (keys[DIK_D]) {
				jikiX = movefloor.X - mapsize;
			}
			if (keys[DIK_A]) {
				jikiX = movefloor.X + mapsize;
			}
		}

		if (jikiY == movefloor.Y - mapsize) {
			jikiX += movefloor.velX;
		}


		if (bottun.count == 1) {
			shutter.count = 1;
			movefloor.count = 1;
		}


		if (shutter.count == 0) {
			if (
			  (jikiY + mapsize / 2) - (shutter.Y + mapsize / 2) < mapsize &&
			  (jikiY + mapsize / 2) - (shutter.Y + mapsize / 2) > -mapsize &&
			  (jikiX + mapsize / 2) - (shutter.X + mapsize / 2) < mapsize &&
			  (jikiX + mapsize / 2) - (shutter.X + mapsize / 2) > -mapsize && jikivelX != 0) {
				if (jikivelY > 0) {
					jikiY = shutter.Y + mapsize;
					jikivelY = 0;
				}
				if (jikivelY < 0) {
					jikiY = shutter.Y - mapsize;
					jikivelY = 0;
					jumpcount = 0;
				}
			}
			if (
			  (jikiY + mapsize / 2) - (shutter.Y + mapsize / 2) < mapsize &&
			  (jikiY + mapsize / 2) - (shutter.Y + mapsize / 2) > -mapsize &&
			  (jikiX + mapsize / 2) - (shutter.X + mapsize / 2) < mapsize &&
			  (jikiX + mapsize / 2) - (shutter.X + mapsize / 2) > -mapsize && jikivelX != 0) {
				if (keys[DIK_D]) {
					jikiX = shutter.X - mapsize;
				}
				if (keys[DIK_A]) {
					jikiX = shutter.X + mapsize;
				}
			}
		}
		if (shutter.count == 1) {
			shutter.Y += 8;
			shutter.slide++;
			if (shutter.slide > mapsize / 2) {
				shutter.Y -= 8;
				shutter.slide--;
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Novice::DrawBox(jikiX, jikiY, mapsize, mapsize, 0.0f, BLUE, kFillModeSolid);
		Novice::DrawBox(shutter.X, shutter.Y, mapsize, mapsize, 0.0f, RED, kFillModeSolid);
		Novice::DrawBox(movefloor.X, movefloor.Y, mapsize, mapsize, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(bottun.X, bottun.Y, mapsize, mapsize, 0.0f, GREEN, kFillModeSolid);

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