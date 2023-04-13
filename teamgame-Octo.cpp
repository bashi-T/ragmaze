#include <Novice.h>
#define _USE_MATH_DEFINES
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<light-map.h>

const char kWindowTitle[] = "team number.1125";



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
		Novice::Initialize(kWindowTitle, 1280, 720);

		float jikiX = 50;
	    float jikiY = 400;
	    int jumpheight = 14;
	    float jikivelx = 50;
	    float jikively = jumpheight;
	    float G = 1;
	    float MapTipCenterX = 0;
	    float MapTipCenterY = 0;
	    float jikiCenterX = 0;
	    float jikiCenterY = 0;
	    int jumpcount = 0;
	    int reverse = 0;
	    int lightCount = 0;//0は闇・1は光
	    int hit = 0;
	    int wallHit = 0;
	    int battery = 0;
	    int switchcount = 0;
	    int bottun = Novice::LoadTexture("./lightREsources/white.png");
	    int floor = Novice::LoadTexture("./lightREsources/maptile0.png");
	    int floor1 = Novice::LoadTexture("./lightREsources/maptile2.png");
	    int step = Novice::LoadTexture("./lightREsources/maptile3.png");
	    int floor3 = Novice::LoadTexture("./lightREsources/floortile4.png");
	    int floor4 = Novice::LoadTexture("./lightREsources/floortile5.png");
	    int wall = Novice::LoadTexture("./lightREsources/maptile1.png");



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
		mapnumber = 2;
		if (keys[DIK_L]) {
			switchcount = 1;
		}

		jikivelx = 0;

		if (keys[DIK_D]) {
			jikivelx = 8;
		}
		if (keys[DIK_A]) {
			jikivelx = -8;
		}
		//バッテリー
		if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] && lightCount == 0&&battery<3601) {
			lightCount = 1;
		}else if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] && lightCount == 1||battery>=3601) {
			lightCount = 0;
		}
		if (battery > 4000) {
			battery = 4000;
		}
		if (lightCount == 1) {
			battery++;
		}

		if (lightCount == 0) { //明暗
			for (int y = 0; y < MapY; y++) {
				for (int x = 0; x < MapX; x++) {
					if (Map[mapnumber][y][x] == 10) {
						Map[mapnumber][y][x] = 11;
					}
					if (Map[mapnumber][y][x] == 41) {
						Map[mapnumber][y][x] = 40;
					}
				}
			}
		}
		if (lightCount == 1) {
			for (int y = 0; y < MapY; y++) {
				for (int x = 0; x < MapX; x++) {

					if (Map[mapnumber][y][x] == 11) {
						Map[mapnumber][y][x] = 10;
					}
					if (Map[mapnumber][y][x] == 40) {
						Map[mapnumber][y][x] = 41;
					}
				}
			}
		}
		//性質逆転タイル
		if (lightCount == 0 && switchcount == 0) {//通行不可
			for (int y = 0; y < MapY; y++) {
				for (int x = 0; x < MapX; x++) {
					if (Map[mapnumber][y][x] == 15) {
						Map[mapnumber][y][x] = 5;
					}
					if (Map[mapnumber][y][x] == 35) {
						Map[mapnumber][y][x] = 25;
					}
				}
			}
		}
		if (lightCount == 1 && switchcount == 0) {//通行可
			for (int y = 0; y < MapY; y++) {
				for (int x = 0; x < MapX; x++) {

					if (Map[mapnumber][y][x] == 5) {
						Map[mapnumber][y][x] = 15;
					}
					if (Map[mapnumber][y][x] == 25) {
						Map[mapnumber][y][x] = 35;
					}
				}
			}
		}
		if (lightCount == 0 && switchcount == 1) {//通行不可
			for (int y = 0; y < MapY; y++) {
				for (int x = 0; x < MapX; x++) {
					if (Map[mapnumber][y][x] == 55) {
						Map[mapnumber][y][x] = 45;
					}
					if (Map[mapnumber][y][x] == 75) {
						Map[mapnumber][y][x] = 65;
					}
				}
			}
		}
		if (lightCount == 1&&switchcount==1) {//通行可
			for (int y = 0; y < MapY; y++) {
				for (int x = 0; x < MapX; x++) {

					if (Map[mapnumber][y][x] == 45) {
						Map[mapnumber][y][x] = 55;
					}
					if (Map[mapnumber][y][x] == 65) {
						Map[mapnumber][y][x] = 75;
					}
				}
			}
		}			for (int y = 0; y < MapY; y++) {
				for (int x = 0; x < MapX; x++) {

					if (Map[mapnumber][y][x] == 45) {
						Map[mapnumber][y][x] = 55;
					}
					if (Map[mapnumber][y][x] == 65) {
						Map[mapnumber][y][x] = 75;
					}
				}
			}

		//出現タイル
		if (switchcount == 1) {
			for (int y = 0; y < MapY; y++) {
				for (int x = 0; x < MapX; x++) {
					if (lightCount == 0) {
						if (Map[mapnumber][y][x] == 6) {
							Map[mapnumber][y][x] = 16;
						}
					}
					if (lightCount == 1) {
						if (Map[mapnumber][y][x] == 36) {
							Map[mapnumber][y][x] = 46;
						}
					}
				}
			}
		}

		if (lightCount == 0 && switchcount == 1) {//通行可
			for (int y = 0; y < MapY; y++) {
				for (int x = 0; x < MapX; x++) {
					if (Map[mapnumber][y][x] == 20) {
						Map[mapnumber][y][x] = 21;
					}
					if (Map[mapnumber][y][x] == 31) {
						Map[mapnumber][y][x] = 30;
					}
				}
			}
		}
		if (lightCount == 1 && switchcount == 1) {//通行不可
			for (int y = 0; y < MapY; y++) {
				for (int x = 0; x < MapX; x++) {

					if (Map[mapnumber][y][x] == 21) {
						Map[mapnumber][y][x] = 20;
					}
					if (Map[mapnumber][y][x] == 30) {
						Map[mapnumber][y][x] = 31;
					}
				}
			}
		}






		jikively -= G;//重力
		if (jikively < -jumpheight) {
			jikively = -jumpheight;
		}
		jikiY -= jikively;
		jikiX += jikivelx;

		jikiCenterX = jikiX + mapsize / 2;
		jikiCenterY = jikiY + mapsize / 2;

		 
		for (int y = 0; y < MapY; y++) {
			for (int x = 0; x < MapX; x++) {
				MapTipCenterX = x*mapsize+mapsize/2;
				MapTipCenterY = y*mapsize+mapsize/2;

				if (Map[mapnumber][y][x] == 1) {
					if (
					  MapTipCenterX - jikiCenterX < mapsize &&
					  MapTipCenterX - jikiCenterX > -mapsize &&
					  MapTipCenterY - jikiCenterY < mapsize &&
					  MapTipCenterY - jikiCenterY > -mapsize) {
						hit = 1;
						if (jikively < 0 && hit == 1) {
							jikiY = y * mapsize - mapsize;
							jumpcount = 1;
							hit = 0;
						}
						if (jikively > 0 && hit == 1) {
							jikiY = y * mapsize + mapsize;
							jikively = 0;
							hit = 0;
						}
						if (jikivelx > 0&&jumpcount==0) {
							jikiX = (x - 1) * mapsize;
						}
						if (jikivelx < 0 && jumpcount == 0) {
							jikiX = (x + 1) * mapsize;
						}
						if (jikivelx == 0 && jumpcount == 0) {
							jikiX = (x + 1) * mapsize;
							if (x >= 15) {
								jikiX = (x - 1) * mapsize;
							}
						}
						if (jumpcount == 1) {
						}
					}
				}

				if (Map[mapnumber][y][x] == 11) {
					if (
					  MapTipCenterX - jikiCenterX < mapsize &&
					  MapTipCenterX - jikiCenterX > -mapsize &&
					  MapTipCenterY - jikiCenterY < mapsize &&
					  MapTipCenterY - jikiCenterY > -mapsize) {
						hit = 1;
						if (jikively < 0 && hit == 1) {
							jikiY = y * mapsize - mapsize;
							jumpcount = 1;
							hit = 0;
						}
						if (jikively > 0 && hit == 1) {
							jikiY = y * mapsize + mapsize;
							jikively = 0;
							hit = 0;
						}
						if (jikivelx > 0 && jumpcount == 0) {
							jikiX = (x - 1) * mapsize;
						}
						if (jikivelx < 0 && jumpcount == 0) {
							jikiX = (x + 1) * mapsize;
						}
						if (jikivelx == 0 && jumpcount == 0) {
							jikiX = (x + 1) * mapsize;
							if (x >= 15) {
								jikiX = (x - 1) * mapsize;
							}
						}
					}
				}

				if (Map[mapnumber][y][x] == 41) {
					if (
					  MapTipCenterX - jikiCenterX < mapsize &&
					  MapTipCenterX - jikiCenterX > -mapsize &&
					  MapTipCenterY - jikiCenterY < mapsize &&
					  MapTipCenterY - jikiCenterY > -mapsize) {
						hit = 1;
						if (jikively < 0 && hit == 1) {
							jikiY = y * mapsize - mapsize;
							jumpcount = 1;
							hit = 0;
						}
						if (jikively > 0 && hit == 1) {
							jikiY = y * mapsize + mapsize;
							jikively = 0;
							hit = 0;
						}
						if (jikivelx > 0 && jumpcount == 0) {
							jikiX = (x - 1) * mapsize;
						}
						if (jikivelx < 0 && jumpcount == 0) {
							jikiX = (x + 1) * mapsize;
						}
						if (jikivelx == 0 && jumpcount == 0) {
							jikiX = (x + 1) * mapsize;
							if (x >= 15) {
								jikiX = (x - 1) * mapsize;
							}
						}
					}
				}
				if (Map[mapnumber][y][x] == 31) {
					if (
					  MapTipCenterX - jikiCenterX < mapsize &&
					  MapTipCenterX - jikiCenterX > -mapsize &&
					  MapTipCenterY - jikiCenterY < mapsize &&
					  MapTipCenterY - jikiCenterY > -mapsize) {
						hit = 1;
						if (jikively < 0 && hit == 1) {
							jikiY = y * mapsize - mapsize;
							jumpcount = 1;
							hit = 0;
						}
						if (jikively > 0 && hit == 1) {
							jikiY = y * mapsize + mapsize;
							jikively = 0;
							hit = 0;
						}
						if (jikivelx > 0 && jumpcount == 0) {
							jikiX = (x - 1) * mapsize;
						}
						if (jikivelx < 0 && jumpcount == 0) {
							jikiX = (x + 1) * mapsize;
						}
						if (jikivelx == 0 && jumpcount == 0) {
							jikiX = (x + 1) * mapsize;
							if (x >= 15) {
								jikiX = (x - 1) * mapsize;
							}
						}
					}
				}
				if (Map[mapnumber][y][x] == 21) {
					if (
					  MapTipCenterX - jikiCenterX < mapsize &&
					  MapTipCenterX - jikiCenterX > -mapsize &&
					  MapTipCenterY - jikiCenterY < mapsize &&
					  MapTipCenterY - jikiCenterY > -mapsize) {
						hit = 1;
						if (jikively < 0 && hit == 1) {
							jikiY = y * mapsize - mapsize;
							jumpcount = 1;
							hit = 0;
						}
						if (jikively > 0 && hit == 1) {
							jikiY = y * mapsize + mapsize;
							jikively = 0;
							hit = 0;
						}
						if (jikivelx > 0 && jumpcount == 0) {
							jikiX = (x - 1) * mapsize;
						}
						if (jikivelx < 0 && jumpcount == 0) {
							jikiX = (x + 1) * mapsize;
						}
						if (jikivelx == 0 && jumpcount == 0) {
							jikiX = (x + 1) * mapsize;
							if (x >= 15) {
								jikiX = (x - 1) * mapsize;
							}
						}
					}
				}
				if (Map[mapnumber][y][x] == 4) {
					if (
					  MapTipCenterX - jikiCenterX < mapsize &&
					  MapTipCenterX - jikiCenterX > -mapsize &&
					  MapTipCenterY - jikiCenterY < mapsize/2 &&
					  MapTipCenterY - jikiCenterY > -mapsize/2) {
						if (lightCount == 0) {
							for (int y = 0; y < MapY; y++) {
								for (int x = 0; x < MapX; x++) {
									if (Map[mapnumber][y][x] == 36) {
										Map[mapnumber][y][x] = 30;
									}
									if (Map[mapnumber][y][x] == 35) {
										Map[mapnumber][y][x] = 75;
									}
									if (Map[mapnumber][y][x] == 76) {
										Map[mapnumber][y][x] = 46;
									}
								}
							}
						}
						if (lightCount == 1) {
							for (int y = 0; y < MapY; y++) {
								for (int x = 0; x < MapX; x++) {
									if (Map[mapnumber][y][x] == 5) {
										Map[mapnumber][y][x] = 45;
									}
									if (Map[mapnumber][y][x] == 15) {
										Map[mapnumber][y][x] = 55;
									}
									if (Map[mapnumber][y][x] == 6) {
										Map[mapnumber][y][x] = 20;
									}
								}
							}
						}
					}
				}





			}
		}

		if (jikivelx == 0 && keys[DIK_D] || jikivelx == 0 && keys[DIK_A]) {
			wallHit = 1;
		}

		if (jumpcount == 1 && wallHit == 0) {
			jikively = jumpheight;
			jumpcount = 0;
		}

		if (jikiY > 800) {
			jikiY = 0;
		}

		wallHit = 0;

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		for (int y = 0; y < MapY; y++) {
			for (int x = 0; x < MapX; x++) {
				if (Map[mapnumber][y][x] == 0) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, wall, 0xFFFFFFFF);
				}

				if (Map[mapnumber][y][x] == 1) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize,
						0,0, mapsize, mapsize, step, 0xFFFFFFFF);
				}

				if (Map[mapnumber][y][x] == 11) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, floor1, 0xFFFFFFFF);
				}
				if (Map[mapnumber][y][x] == 10) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, wall, 0xFFFFFFFF);
				}

				if (Map[mapnumber][y][x] == 21) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, floor, 0xFFFFFFFF);
				}
				if (Map[mapnumber][y][x] == 20) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, wall, 0xFFFFFFFF);
				}
				if (Map[mapnumber][y][x] == 31) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, floor, 0xFFFFFFFF);
				}
				if (Map[mapnumber][y][x] == 30) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, wall, 0xFFFFFFFF);
				}
				if (Map[mapnumber][y][x] == 41) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, floor, 0xFFFFFFFF);
				}
				if (Map[mapnumber][y][x] == 40) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, wall, 0xFFFFFFFF);
				}

			}
		}
		if (lightCount == 0) {
			Novice::DrawBox(
			  0 + sepalatex1, 0 + sepalatey1, mapsize * MapX, mapsize * MapY, 0.0f, 0x000000a0,
			  kFillModeSolid);
		}

		Novice::DrawQuad(
		     jikiX + sepalatex1, jikiY  + sepalatey1,
		  jikiX + mapsize + sepalatex1, jikiY  + sepalatey1,
		  jikiX + sepalatex1, jikiY + sepalatey1 + mapsize,
		  jikiX + sepalatex1 + mapsize, jikiY  + sepalatey1 + mapsize,
			0, 0, mapsize, mapsize, floor4, 0xFFFFFFFF);

		Novice::ScreenPrintf(10, 10, "%d,%d,%f,%f",hit,lightCount,jikivelx,jikively);
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
