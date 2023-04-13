#include <Novice.h>
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

const char kWindowTitle[] = "LC1B_21_ツヅキバシマサミ_AL2";


const int map1X = 50;
const int map1Y = 25;
int mapsize = 32;
int map1[map1Y][map1X] = {};


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, mapsize*25, 800);

	FILE* fp;
	
	fopen_s(&fp, "mapSample.csv", "r");
	if (fp == 0) {
		printf("ファイルが開けません");
		return 0;
	}
	for (int y = 0; y < map1Y; y++) {
		for (int x = 0; x < map1X; x++) {
			fscanf_s(fp, "%d,", &map1[y][x]);
		}
	}
	fclose(fp);
	
	 //キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	int jiki1 = Novice::LoadTexture("./lightResources/ball.png");
	int jikipic = jiki1;
	int speed = 4;
	int movecount = 0;
	int movetime = 0;
	int mapnumber = 0;
	int scene = 0;
	int keypush = 0;
	int sepalatex1 = 0;
	int sepalatey1 = 0;
	int sepalate = 0;
	int jikiX = 32;
	int jikiY = 32;
	float jikivelx = 0;
	float jikively = 0;
	int hitx = 0;
	int hity = 0;
	int hitxy = 0;
	float theta = (1.0 / 2.0f) * M_PI;
	float xvec = 0;
	float yvec = 0;
	int RbottomX = 0;
	int RbottomY = 0;
	int RtopX = 0;
	int RtopY = 0;
	int LbottomX = 0;
	int LbottomY = 0;
	int LtopX = 0;
	int LtopY = 0;

	int floor = Novice::LoadTexture("./lightResources/maptile1.png");
	int wall = Novice::LoadTexture("./lightResources/maptile6.png");

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
		jikively = 0;
		hitx = 0;
		hity = 0;
		hitxy = 0;
		if (sepalate == 0 || sepalate == 81) {
			if (keys[DIK_D]) {
				theta = (0.0f) * M_PI;
				jikivelx = speed;
			}

			if (keys[DIK_A]) {
				jikivelx = speed;
				theta = M_PI;
			}

			if (keys[DIK_W]) {
				jikively = speed;
				theta = (3.0 / 2.0f) * M_PI;
			}

			if (keys[DIK_S]) {
				jikively = speed;
				theta = (1.0 / 2.0f) * M_PI;
			}

			if (keys[DIK_D] && keys[DIK_W]) {
				theta = (7.0 / 4.0f) * M_PI;
			}
			if (keys[DIK_A] && keys[DIK_W]) {
				theta = (5.0 / 4.0f) * M_PI;
			}
			if (keys[DIK_A] && keys[DIK_S]) {
				theta = (3.0 / 4.0f) * M_PI;
			}
			if (keys[DIK_D] && keys[DIK_S]) {
				theta = (1.0 / 4.0f) * M_PI;
			}
		}
		xvec = cosf(theta);
		yvec = sinf(theta);

		    for (int x = 0; x < map1X; x++) {
			    for (int y = 0; y < map1Y; y++) {
				    if (map1[y][x] == 1) {
					    if (
					      ((jikiY + jikively * yvec) + mapsize / 2) - (y * mapsize + mapsize / 2) <
					        mapsize &&
					      ((jikiY + jikively * yvec) + mapsize / 2) - (y * mapsize + mapsize / 2) >
					        -mapsize &&
					      ((jikiX + jikivelx * xvec) + mapsize / 2) - (x * mapsize + mapsize / 2) <
					        mapsize &&
					      ((jikiX + jikivelx * xvec) + mapsize / 2) - (x * mapsize + mapsize / 2) >
					        -mapsize) {
						    jikively = 0;
						    jikivelx = 0;

						    if (keys[DIK_D] && keys[DIK_S] == 0 && keys[DIK_W] == 0) {
							    jikiX = mapsize * x;
							    jikiX -= mapsize;
						    }
						    if (keys[DIK_A] && keys[DIK_S] == 0 && keys[DIK_W] == 0) {
							    jikiX = mapsize * x;
							    jikiX += mapsize;
						    }
						    if (keys[DIK_W] && keys[DIK_A] == 0 && keys[DIK_D] == 0) {
							    jikiY = mapsize * y;
							    jikiY += mapsize;
						    }
						    if (keys[DIK_S] && keys[DIK_A] == 0 && keys[DIK_D]==0) {
							    jikiY = mapsize * y;
							    jikiY -= mapsize;
						    }
					    }
				    }
			    }
		    }

			jikiX += jikivelx * xvec;
			jikiY += jikively * yvec;
		    if (jikiX > 800 && sepalatex1 == 0 && keys[DIK_D]) {
			    sepalate = 0;
				sepalate++;
		    }
		    if (sepalate > 0 && sepalate<81) {
			    sepalatex1 -= 10;
		    }
		    if (sepalatex1 == -800) {
			    sepalate = 81;
		    }
		    if (jikiX < 768 && sepalatex1 == -800 && keys[DIK_A]) {
			    sepalate = 81;
			    sepalate++;
		    }
		    if (sepalate > 81 && sepalate < 162) {
			    sepalatex1 += 10;
		    }
		    if (sepalatex1 == 0) {
			    sepalate = 0;
		    }


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
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize,
						0, 0, mapsize, mapsize, floor, 0xFFFFFFFF);
				}
					 
				if (map1[y][x] == 1) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize,
						0, 0, mapsize, mapsize, wall, 0xFFFFFFFF);
				}
			}
		}
		Novice::DrawQuad(
		  jikiX + sepalatex1, jikiY + sepalatey1,
			jikiX + sepalatex1 + mapsize, jikiY + sepalatey1,
		  jikiX + sepalatex1, jikiY + sepalatey1 + mapsize,
			jikiX + sepalatex1 + mapsize, jikiY + sepalatey1 + mapsize,
		  0, 0, mapsize, mapsize, jikipic, 0xFFFFFFFF);

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
