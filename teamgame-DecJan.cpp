#include <Novice.h>
#define _USE_MATH_DEFINES
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<tofumap.h>

const char kWindowTitle[] = "team number.1125";



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, mapsize * map1X, mapsize * map1Y);

	int square = Novice::LoadTexture("white1x1.png");
	int bottun = Novice::LoadTexture("./lightREsources/maptile0.png");
	int floor = Novice::LoadTexture("./lightREsources/maptile1.png");
	int floor2 = Novice::LoadTexture("./lightREsources/maptile2.png");
	int player = Novice::LoadTexture("./lightREsources/floortile1.png");

	float jikiX = 50;
	float jikiY = 400;
	float jikivelx = 0;
	float jikively = 0;
	int jikicount = 1;
	float MapTipCenterX = 0;
	float MapTipCenterY = 0;
	float jikiCenterX = 0;
	float jikiCenterY = 0;
	int jumpcount = 0;
	int reverse = 0;
	int hit = 0;
	int wallHit = 0;
	int switchcount = 0;
	int G = 1;
	int speed = 8;
	int standcount = 0;

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
		wallHit = 0;
		/* if (standcount == 0) {
			jikively -= G;
		}*/
		jikivelx = 0;
		jikively = 0;

		if (keys[DIK_D]) {
			jikivelx = speed;
		}

		if (keys[DIK_A]) {
			jikivelx = -speed;
		}
		if (keys[DIK_W]) {
			jikively = speed;
		}

		if (keys[DIK_S]) {
			jikively = -speed;
		}
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && standcount == 1) {
			jikively = 14;
			standcount = 0;
		}

		if (keys[DIK_1]) {
			mapnumber = 1;
		}

		if (keys[DIK_2]) {
			mapnumber = 2;
		}

		if (keys[DIK_3]) {
			mapnumber = 3;
		}

		if (keys[DIK_4]) {
			mapnumber = 4;
		}
		if (keys[DIK_0]) {
			mapnumber = 0;
		}

		/* for (int x = 0; x < map1X; x++) {
			for (int y = 0; y < map1Y; y++) {
				if (Map[mapnumber][y][x] == 1) {
					if (((jikiX + jikivelx) + mapsize / 2) - (x * mapsize + mapsize / 2) < mapsize &&
					  ((jikiX + jikivelx) + mapsize / 2) - (x * mapsize + mapsize / 2) > -mapsize) {

						if (((jikiY - jikively) + mapsize / 2) - (y * mapsize + mapsize / 2) <mapsize &&
						  ((jikiY - jikively) + mapsize / 2) - (y * mapsize + mapsize / 2) >-mapsize) {
							wallHit = 1;
							if (wallHit == 1) {
								if (keys[DIK_D] || keys[DIK_A]) {
									//jikivelx = 0;
								}
								if (standcount == 0) {
									jikively = 0;
								}
							}
							 if (keys[DIK_D] && jikively == 0) {
								jikiX = mapsize * x;
								jikiX -= mapsize;
							}
							if (keys[DIK_A] && jikively == 0) {
								jikiX = mapsize * x;
								jikiX += mapsize;
							}
							if (jikively > 0 && keys[DIK_A] == 0 && keys[DIK_D] == 0) {
								jikiY = mapsize * y;
								jikiY += mapsize;
							}
							if (jikively < 0 && keys[DIK_A] == 0 && keys[DIK_D] == 0) {
								jikiY = mapsize * y;
								jikiY -= mapsize;
							}
						}

						if (((jikiY - jikively) + mapsize / 2)-(y * mapsize + mapsize / 2) > mapsize) {
							standcount = 1;
							jikively = 0;
						}
					} 
				}

				if (Map[mapnumber][y][x] == 2) {
					if (
					  ((jikiY - jikively) + mapsize / 2) - (y * mapsize + mapsize / 2) < mapsize &&
					  ((jikiY - jikively) + mapsize / 2) - (y * mapsize + mapsize / 2) > -mapsize &&
					  ((jikiX + jikivelx) + mapsize / 2) - (x * mapsize + mapsize / 2) < mapsize &&
					  ((jikiX + jikivelx) + mapsize / 2) - (x * mapsize + mapsize / 2) > -mapsize) {

						switch (jikicount) {
						case 1:
							jikiX = 400;
							jikiX = 100;
							break;

						case 3:
							jikiX = 400;
							jikiX = 100;
							break;

						case 4:
							break;
						case 2:
							break;
						}
					}
				}

				if (Map[mapnumber][y][x] == 3) {
					if (
					  jikiY < y * mapsize &&
					  ((jikiX + jikivelx) + mapsize / 2) - (x * mapsize + mapsize / 2) < mapsize &&
					  ((jikiX + jikivelx) + mapsize / 2) - (x * mapsize + mapsize / 2) > -mapsize) {

						switch (jikicount) {
						case 1:
							jikiY -= 5;
							break;

						case 3:
							jikiY -= 5;
							break;

						case 4:
							jikiY -= 5;
							break;
						case 2:
							break;
						}
					}
				}
				if (Map[mapnumber][y][x] == 4) {
					if (
					  ((jikiY - jikively) + mapsize / 2) - (y * mapsize + mapsize / 2) < mapsize &&
					  ((jikiY - jikively) + mapsize / 2) - (y * mapsize + mapsize / 2) > -mapsize &&
					  ((jikiX + jikivelx) + mapsize / 2) - (x * mapsize + mapsize / 2) < mapsize &&
					  ((jikiX + jikivelx) + mapsize / 2) - (x * mapsize + mapsize / 2) > -mapsize) {

						switch (jikicount) {
						case 1:
							jikively = 0;
							jikivelx = 0;
							break;

						case 2:
							break;

						case 3:
							jikively = 0;
							jikivelx = 0;
							break;

						case 4:
							jikively = 0;
							jikivelx = 0;
							break;
						}
					}
				}

			}
		}*/
		jikiX += jikivelx;
		jikiY -= jikively;

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		for (int y = 0; y < map1Y; y++) {
			for (int x = 0; x < map1X; x++) {

				if (Map[mapnumber][y][x] == 1) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, square, 0xFFFFFFFF);
				}
				if (Map[mapnumber][y][x] == 2) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, bottun, 0xFFFFFFFF);
				}
				if (Map[mapnumber][y][x] == 3) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, floor, 0xFFFFFFFF);
				}
				if (Map[mapnumber][y][x] == 4) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, floor2, 0xFFFFFFFF);
				}
				if (Map[mapnumber][y][x] == 5) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, square, 0x00FFFFFF);
				}
				if (Map[mapnumber][y][x] == 6) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, bottun, 0x00FFFFFF);
				}
				if (Map[mapnumber][y][x] == 8) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, floor2, 0x00FFFFFF);
				}
				if (Map[mapnumber][y][x] == 9) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, floor, 0x00FFFFFF);
				}
				if (Map[mapnumber][y][x] == 10) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, bottun, 0xFF00FFFF);
				}
				if (Map[mapnumber][y][x] == 11) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, floor, 0xFF00FFFF);
				}
				if (Map[mapnumber][y][x] == 12) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, floor2, 0xFF00FFFF);
				}
				if (Map[mapnumber][y][x] == 13) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, square, 0xFF00FFFF);
				}
				if (Map[mapnumber][y][x] == 7) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, player, 0xFF00FFFF);
				}
			}
		}

		if (jikicount == 1) {
			Novice::DrawBox(
			  jikiX + sepalatex1, jikiY + sepalatey1, mapsize, mapsize, 0.0f, RED, kFillModeSolid);
		}
		if (jikicount == 2) {
			Novice::DrawBox(
			  jikiX + sepalatex1, jikiY + sepalatey1, mapsize, mapsize, 0.0f, GREEN,
			  kFillModeSolid);
		}
		if (jikicount == 3) {
			Novice::DrawBox(
			  jikiX + sepalatex1, jikiY + sepalatey1, mapsize, mapsize, 0.0f, BLUE, kFillModeSolid);
		}
		if (jikicount == 4) {
			Novice::DrawBox(
			  jikiX + sepalatex1, jikiY + sepalatey1, mapsize, mapsize, 0.0f, BLACK,
			  kFillModeSolid);
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
