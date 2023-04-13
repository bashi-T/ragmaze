#include <Novice.h>
#define _USE_MATH_DEFINES
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<map.h>

const char kWindowTitle[] = "";



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1400, 700);
	int goalh = Novice::LoadTexture("./TenDays/goal_line1.png");
	int goalw = Novice::LoadTexture("./TenDays/goal_line2.png");
	int jiki1 = Novice::LoadTexture("./TenDays/player_move_down0.png");
	int jiki2 = Novice::LoadTexture("./TenDays/player_move_down1.png");
	int jiki3 = Novice::LoadTexture("./TenDays/player_move_down2.png");
	int jiki4 = Novice::LoadTexture("./TenDays/player_move_down3.png");
	int jiki5 = Novice::LoadTexture("./TenDays/player_move_left0.png");
	int jiki6 = Novice::LoadTexture("./TenDays/player_move_left1.png");
	int jiki7 = Novice::LoadTexture("./TenDays/player_move_left2.png");
	int jiki8 = Novice::LoadTexture("./TenDays/player_move_left3.png");
	int jiki9 = Novice::LoadTexture("./TenDays/player_move_right0.png");
	int jiki10 = Novice::LoadTexture("./TenDays/player_move_right1.png");
	int jiki11 = Novice::LoadTexture("./TenDays/player_move_right2.png");
	int jiki12 = Novice::LoadTexture("./TenDays/player_move_right3.png");
	int jiki13 = Novice::LoadTexture("./TenDays/player_move_up0.png");
	int jiki14 = Novice::LoadTexture("./TenDays/player_move_up1.png");
	int jiki15 = Novice::LoadTexture("./TenDays/player_move_up2.png");
	int jiki16 = Novice::LoadTexture("./TenDays/player_move_up3.png");

	int aibo1 = Novice::LoadTexture("./TenDays/player2_move_down0.png");
	int aibo2 = Novice::LoadTexture("./TenDays/player2_move_down1.png");
	int aibo3 = Novice::LoadTexture("./TenDays/player2_move_down2.png");
	int aibo4 = Novice::LoadTexture("./TenDays/player2_move_down3.png");
	int aibo5 = Novice::LoadTexture("./TenDays/player2_move_left0.png");
	int aibo6 = Novice::LoadTexture("./TenDays/player2_move_left1.png");
	int aibo7 = Novice::LoadTexture("./TenDays/player2_move_left2.png");
	int aibo8 = Novice::LoadTexture("./TenDays/player2_move_left3.png");
	int aibo9 = Novice::LoadTexture("./TenDays/player2_move_right0.png");
	int aibo10 = Novice::LoadTexture("./TenDays/player2_move_right1.png");
	int aibo11 = Novice::LoadTexture("./TenDays/player2_move_right2.png");
	int aibo12 = Novice::LoadTexture("./TenDays/player2_move_right3.png");
	int aibo13 = Novice::LoadTexture("./TenDays/player2_move_up0.png");
	int aibo14 = Novice::LoadTexture("./TenDays/player2_move_up1.png");
	int aibo15 = Novice::LoadTexture("./TenDays/player2_move_up2.png");
	int aibo16 = Novice::LoadTexture("./TenDays/player2_move_up3.png");

	int jikipic = jiki1;
	int aibo = aibo1;
	int aibocount = 0;
	int floor = Novice::LoadTexture("./TenDays/floor0.png");
	int wall = Novice::LoadTexture("./TenDays/wall0.png");
	int SWITCH1 = 0;
	int SWITCH2 = 0;
	int SWITCH3 = 0;
	int SWITCH4 = 0;
	int switchcount1 = 0;
	int switchcount2 = 0;
	int switchcount3 = 0;
	int switchcount4 = 0;
	int switch0 = Novice::LoadTexture("./TenDays/switch0.png");
	int switch1 = Novice::LoadTexture("./TenDays/switch1.png");
	int switch2 = Novice::LoadTexture("./TenDays/switch2.png");
	int switchwall11 = 0;
	int switchwall12 = 0;
	int switchwall13 = 0;
	int switchwall14 = 0;
	int switchwall15 = 0;
	int switchwall16 = 0;
	int switchwall0 = Novice::LoadTexture("./TenDays/stonewall0.png");
	int switchwall1 = Novice::LoadTexture("./TenDays/stonewall1.png");
	int switchwall2 = Novice::LoadTexture("./TenDays/stonewall2.png");
	int acccount = 0;
	int acctile0 = Novice::LoadTexture("./TenDays/map_move0.png");
	int acctile1 = Novice::LoadTexture("./TenDays/map_move1.png");
	int acctile2 = Novice::LoadTexture("./TenDays/map_move2.png");
	int acctile3 = Novice::LoadTexture("./TenDays/map_move3.png");
	int aibovecA = 0;
	int aibovecB = 0;
	int veccount = 0;
	int aibovecx1 = -100;
	int aibovecy1 = -100;
	int aibovecx2 = -100;
	int aibovecy2 = -100;
	int aibovec0 = Novice::LoadTexture("./TenDays/movemark0.png");
	int aibovec2 = Novice::LoadTexture("./TenDays/movemark2.png");
	int aibovec4 = Novice::LoadTexture("./TenDays/movemark4.png");
	int aibovec6 = Novice::LoadTexture("./TenDays/movemark6.png");
	int jikiX = 0;
	int jikiY = 32;
	int jikivelx = 0;
	int jikively = 0;
	int jikicount = 0;
	int jikistop = 0;
	int aiboX = 0;
	int aiboY = 32;
	int aibovelX = 0;
	int aibovelY = 0;
	int aibovelx1 = 0;
	int aibovely1 = 0;
	int aibovelx2 = 0;
	int aibovely2 = 0;
	int pushcount = 0;
	int wallcount1 = 0;
	int wallcount2 = 0;
	int switching = 0;
	int dashcount1 = 0;
	int dashcount2 = 0;
	int mapsize = 32;
	int movecount = 0;
	int movetime = 0;
	int clearcount = 0;
	int mapnumber = 0;
	int scene = 0;
	int keypush = 0;
	int sepalatex1 = 150;
	int sepalatey1 = 110;
	int sepalatex2 = 770;
	int sepalatey2 = 110;
	int sepalatex3 = 630;
	int sepalatey3 = 590;
	int sepalatex4 = 0;
	int sepalatey4 = 0;
	int sepalatey5 = 0;

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
		/// 					
		if (scene == 0) {
			//mapnumber = 7;

			for (int x = 0; x < map1X; x++) {
				for (int y = 0; y < map1Y; y++) {
					if (map1[mapnumber][y][x] == 5) {
						jikiX = x * mapsize;
						jikiY = y * mapsize;
						break;
					}
				}
			}

			for (int x = 0; x < map2X; x++) {
				for (int y = 0; y < map2Y; y++) {
					if (map2[mapnumber][y][x] == 5) {
						aiboX = x * mapsize;
						aiboY = y * mapsize;
						break;
					}
				}
			}
		}
		scene = 1;
		switch (scene) {

		case 1:
			movetime = 0;
			if (dashcount2 == 0) {
			keypush = 0;
			}
			// if () {
			// }
			jikicount += 1;
			aibocount += 1;
			acccount += 1;
			veccount += 1;
			jikistop -= 1;
			if (jikistop < 0) {
				jikistop = 0;
			}
			if (acccount == 20) {
				acccount = 0;
			}
			if (veccount == 20) {
				veccount = 0;
			}
			jikivelx = 0;
			jikively = 0;
			if (jikicount == 40) {
				jikicount = 0;
			}
			if (aibocount == 40) {
				aibocount = 0;
			}

			if (dashcount1 == 0 && dashcount2 == 0) {
				if (keys[DIK_D] && preKeys[DIK_D] == 0) {
					keypush = 1;
					jikivelx = mapsize;
					pushcount += 1;
					movetime = 1;
					jikicount = 0;
					jikipic == jiki9;
					if (switchcount3 == 1) {
						wallcount1 += 1;
					}
				}
				if (keys[DIK_A] && preKeys[DIK_A] == 0) {
					jikivelx = -mapsize;
					keypush = 11;
					pushcount += 1;
					movetime = 1;
					jikicount = 0;
					jikipic = jiki5;
					if (switchcount3 == 1) {
						wallcount1 += 1;
					}
				}
				if (keys[DIK_S] && preKeys[DIK_S] == 0) {
					jikively = mapsize;
					keypush = 21;
					pushcount += 1;
					movetime = 1;
					jikicount = 0;
					jikipic = jiki1;
					if (switchcount3 == 1) {
						wallcount1 += 1;
					}
				}
				if (keys[DIK_W] && preKeys[DIK_W] == 0) {
					jikively = -mapsize;
					keypush = 31;
					pushcount += 1;
					movetime = 1;
					jikicount = 0;
					jikipic = jiki13;
					if (switchcount3 == 1) {
						wallcount1 += 1;
					}
				}

				if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0) {
					jikivelx = mapsize;
					keypush = 1;
					pushcount += 1;
					movetime = 1;
					jikicount = 0;
					jikipic == jiki9;
					if (switchcount3 == 1) {
						wallcount1 += 1;
					}
				}
				if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0) {
					jikivelx = -mapsize;
					keypush = 11;
					pushcount += 1;
					movetime = 1;
					jikicount = 0;
					jikipic = jiki5;
					if (switchcount3 == 1) {
						wallcount1 += 1;
					}
				}
				if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0) {
					jikively = mapsize;
					keypush = 21;
					pushcount += 1;
					movetime = 1;
					jikicount = 0;
					jikipic = jiki1;
					if (switchcount3 == 1) {
						wallcount1 += 1;
					}
				}
				if (keys[DIK_UP] && preKeys[DIK_UP] == 0) {
					jikively = -mapsize;
					keypush = 31;
					pushcount += 1;
					movetime = 1;
					jikicount = 0;
					jikipic = jiki13;
					if (switchcount3 == 1) {
						wallcount1 += 1;
					}
				}
				if (jikicount >= 0 && jikicount <= 9) {
					if (jikipic == jiki4) {
						jikipic = jiki1;
					}
					if (jikipic == jiki8) {
						jikipic = jiki5;
					}
					if (jikipic == jiki12) {
						jikipic = jiki9;
					}
					if (jikipic == jiki16) {
						jikipic = jiki13;
					}
				}

				if (jikicount >= 10 && jikicount <= 19) {
					if (jikipic == jiki1) {
						jikipic = jiki2;
					}
					if (jikipic == jiki5) {
						jikipic = jiki6;
					}
					if (jikipic == jiki9) {
						jikipic = jiki10;
					}
					if (jikipic == jiki13) {
						jikipic = jiki14;
					}
				}
				if (jikicount >= 20 && jikicount <= 29) {
					if (jikipic == jiki2) {
						jikipic = jiki3;
					}
					if (jikipic == jiki6) {
						jikipic = jiki7;
					}
					if (jikipic == jiki10) {
						jikipic = jiki11;
					}
					if (jikipic == jiki14) {
						jikipic = jiki15;
					}
				}
				if (jikicount >= 30 && jikicount <= 39) {
					if (jikipic == jiki3) {
						jikipic = jiki4;
					}
					if (jikipic == jiki7) {
						jikipic = jiki8;
					}
					if (jikipic == jiki11) {
						jikipic = jiki12;
					}
					if (jikipic == jiki15) {
						jikipic = jiki16;
					}
				}

				if (wallcount1 == 5) {
					wallcount1 = 0;
					switchcount3 = 0;
					for (int x = 0; x < map1X; x++) {
						for (int y = 0; y < map1Y; y++) {
							if (map1[mapnumber][y][x] == 44) {
								map1[mapnumber][y][x] = 34;
							}
						}
					}
				}
				if (wallcount2 == 5) {
					wallcount2 = 0;
					switchcount4 = 0;
					for (int x = 0; x < map2X; x++) {
						for (int y = 0; y < map2Y; y++) {
							if (map2[mapnumber][y][x] == 44) {
								map2[mapnumber][y][x] = 34;
							}
						}
					}
				}

				if (pushcount == 2) {
					pushcount = 0;
				}
			}

			if (dashcount1 == 0 && dashcount2 == 0) {
				if (pushcount == 0 && movetime == 1) {
					aibovelx1 = jikivelx;
					aibovely1 = jikively;
					veccount = 0;
				}

				if (pushcount == 1 && movetime == 1) {
					aibovelx2 = jikivelx;
					aibovely2 = jikively;
					veccount = 0;
				}

				if (pushcount == 0 && movetime == 1) {
					aibovelX = aibovelx2;
					aibovelY = aibovely2;
					if (switchcount4 == 1) {
						wallcount2 += 1;
					}
				}
				if (pushcount == 1 && movetime == 1) {
					aibovelX = aibovelx1;
					aibovelY = aibovely1;
					if (switchcount4 == 1) {
						wallcount2 += 1;
					}
				}

				//相棒のモーション
				if (movetime == 1) {
					if (aibovelX > 0 && aibovelY == 0) {
						aibocount = 0;
						aibo = aibo9;
					}
					if (aibovelX < 0 && aibovelY == 0) {
						aibocount = 0;
						aibo = aibo5;
					}
					if (aibovelX == 0 && aibovelY > 0) {
						aibocount = 0;
						aibo = aibo1;
					}
					if (aibovelX == 0 && aibovelY < 0) {
						aibocount = 0;
						aibo = aibo13;
					}
				}

				if (aibocount >= 0 && aibocount <= 9) {
					if (aibo == aibo12) {
						aibo = aibo9;
					}
					if (aibo == aibo8) {
						aibo = aibo5;
					}
					if (aibo == aibo4) {
						aibo = aibo1;
					}
					if (aibo == aibo16) {
						aibo = aibo13;
					}
				}

				if (aibocount >= 10 && aibocount <= 19) {
					if (aibo == aibo9) {
						aibo = aibo10;
					}
					if (aibo == aibo5) {
						aibo = aibo6;
					}

					if (aibo == aibo1) {
						aibo = aibo2;
					}
					if (aibo == aibo13) {
						aibo = aibo14;
					}
				}
				if (aibocount >= 20 && aibocount <= 29) {
					if (aibo == aibo10) {
						aibo = aibo11;
					}
					if (aibo == aibo6) {
						aibo = aibo7;
					}
					if (aibo == aibo2) {
						aibo = aibo3;
					}
					if (aibo == aibo14) {
						aibo = aibo15;
					}
				}

				if (aibocount >= 30 && aibocount <= 39) {
					if (aibo == aibo11) {
						aibo = aibo12;
					}
					if (aibo == aibo7) {
						aibo = aibo8;
					}
					if (aibo == aibo3) {
						aibo = aibo4;
					}
					if (aibo == aibo15) {
						aibo = aibo16;
					}
				}
			}

			if (jikivelx > 0 && jikively == 0) {
				aibovecB = aibovec2;
			}
			if (jikivelx < 0 && jikively == 0) {
				aibovecB = aibovec4;
			}
			if (jikivelx == 0 && jikively > 0) {
				aibovecB = aibovec0;
			}
			if (jikivelx == 0 && jikively < 0) {
				aibovecB = aibovec6;
			}

			if (dashcount1 == 1) {
				jikivelx = mapsize;
			}

			if (dashcount2 == 1) {
				movetime = 1;
				aibovelX = mapsize;
				aibovelY = 0;
			}

			if (dashcount1 == 11) {
				jikivelx = -mapsize;
			}

			if (dashcount2 == 11) {
				movetime = 1;
				aibovelX = -mapsize;
				aibovelY = 0;
			}

			if (dashcount1 == 21) {
				jikively = mapsize;
			}

			if (dashcount2 == 21) {
				movetime = 1;
				aibovelX = 0;
				aibovelY = mapsize;
			}

			if (dashcount1 == 31) {
				jikively = -mapsize;
			}

			if (dashcount2 == 31) {
				movetime = 1;
				aibovelX = 0;
				aibovelY = -mapsize;
			}

			if (jikivelx > 0 && jikively == 0) {
				jikipic = jiki9;
			}
			if (jikivelx < 0 && jikively == 0) {
				jikipic = jiki5;
			}
			if (jikively > 0 && jikivelx == 0) {
				jikipic = jiki1;
			}
			if (jikively < 0 && jikivelx == 0) {
				jikipic = jiki13;
			}

			//当たり判定
			if (map1[mapnumber][(jikiY + jikively) / mapsize][(jikiX + jikivelx) / mapsize] == 2) {
				jikivelx = 0;
				jikively = 0;
				dashcount1 = 0;
			}

			if (map2[mapnumber][(aiboY + aibovelY) / mapsize][(aiboX + aibovelX) / mapsize] == 2) {
				aibovelX = 0;
				aibovelY = 0;
				dashcount2 = 0;
			}

			if (map1[mapnumber][(jikiY + jikively) / mapsize][(jikiX + jikivelx) / mapsize] == 3) {
				dashcount1 = 1;
			}

			if (map1[mapnumber][(jikiY + jikively) / mapsize][(jikiX + jikivelx) / mapsize] == 13) {
				dashcount1 = 11;
			}

			if (map1[mapnumber][(jikiY + jikively) / mapsize][(jikiX + jikivelx) / mapsize] == 23) {
				dashcount1 = 21;
			}

			if (map1[mapnumber][(jikiY + jikively) / mapsize][(jikiX + jikivelx) / mapsize] == 33) {
				dashcount1 = 31;
			}


			if (map1[mapnumber][(jikiY + jikively) / mapsize][(jikiX + jikivelx) / mapsize] ==4) { //スイッチ1
				if (switchcount1 == 0) {
					jikivelx = 0;
					jikively = 0;
					dashcount1 = 0;
				}
			}

			if (map2[mapnumber][(aiboY + aibovelY) / mapsize][(aiboX + aibovelX) / mapsize] == 4) {
				if (switchcount2 == 0) {
					aibovelX = 0;
					aibovelY = 0;
					dashcount2 = 0;
				}
			}

			if (map1[mapnumber][(jikiY) / mapsize][(jikiX) / mapsize] == 14) { //スイッチ1
				switchcount2 = 1;
			}

			if (map2[mapnumber][(aiboY) / mapsize][(aiboX) / mapsize] == 14) {
				switchcount1 = 1;
			}
			/*
			if (map1[mapnumber][(jikiY) / mapsize][(jikiX) / mapsize] == 24) { //スイッチ2
				switchcount4 = 1;
				for (int x = 0; x < map1X; x++) {
					for (int y = 0; y < map1Y; y++) {
						if (map2[mapnumber][y][x] == 34) {
							map2[mapnumber][y][x] = 44;
						}
						if (map2[mapnumber][y][x] == 54) {
							map2[mapnumber][y][x] = 64;
						}
					}
				}
			}

			if (map2[mapnumber][(aiboY) / mapsize][(aiboX) / mapsize] == 24) {
				switchcount3 = 1;
				for (int x = 0; x < map1X; x++) {
					for (int y = 0; y < map1Y; y++) {
						if (map1[mapnumber][y][x] == 34) {
							map1[mapnumber][y][x] = 44;
						}
						if (map1[mapnumber][y][x] == 54) {
							map1[mapnumber][y][x] = 64;
						}
					}
				}
			}

			if (switchcount3 == 0) {
				for (int x = 0; x < map1X; x++) {
					for (int y = 0; y < map1Y; y++) {
						if (map1[mapnumber][y][x] == 44) {
							map1[mapnumber][y][x] = 34;
						}
						if (map1[mapnumber][y][x] == 64) {
							map1[mapnumber][y][x] = 54;
						}
					}
				}
			}

			if (switchcount4 == 0) {
				for (int x = 0; x < map1X; x++) {
					for (int y = 0; y < map1Y; y++) {
						if (map2[mapnumber][y][x] == 44) {
							map2[mapnumber][y][x] = 34;
						}
						if (map2[mapnumber][y][x] == 64) {
							map2[mapnumber][y][x] = 54;
						}
					}
				}
			}
			if (
			  map1[mapnumber][(jikiY + jikively) / mapsize][(jikiX + jikivelx) / mapsize] ==
			  34) { //スイッチ壁
				if (switchcount3 == 0) {
					jikivelx = 0;
					jikively = 0;
					dashcount1 = 0;
				}
			}

			if (map2[mapnumber][(aiboY + aibovelY) / mapsize][(aiboX + aibovelX) / mapsize] == 34) {
				if (switchcount4 == 0) {
					aibovelX = 0;
					aibovelY = 0;
					dashcount2 = 0;
				}
			}
			if (
			  map1[mapnumber][(jikiY + jikively) / mapsize][(jikiX + jikivelx) / mapsize] ==
			  64) { //スイッチ壁
				if (switchcount3 == 1) {
					jikivelx = 0;
					jikively = 0;
					dashcount1 = 0;
				}
			}

			if (map2[mapnumber][(aiboY + aibovelY) / mapsize][(aiboX + aibovelX) / mapsize] == 64) {
				if (switchcount4 == 1) {
					aibovelX = 0;
					aibovelY = 0;
					dashcount2 = 0;
				}
			}*/

			jikiX += jikivelx;
			jikiY += jikively;
			if (movetime == 1) {
				aiboX += aibovelX;
				aiboY += aibovelY;
			}
			if (map2[mapnumber][(aiboY ) / mapsize][(aiboX ) / mapsize] == 3) {
				dashcount2 = 1;
			}

			if (map2[mapnumber][(aiboY ) / mapsize][(aiboX ) / mapsize] == 13) {
				dashcount2 = 11;
			}

			if (map2[mapnumber][(aiboY ) / mapsize][(aiboX) / mapsize] == 23) {
				dashcount2 = 21;
			}

			if (map2[mapnumber][(aiboY ) / mapsize][(aiboX ) / mapsize] == 33) {
				dashcount2 = 31;
			}

			if (keypush == 1) {
				aibovecx2 = aiboX + sepalatex2 + mapsize;
				aibovecy2 = aiboY + sepalatey2;
			}
			if (keypush == 11) {
				aibovecx2 = aiboX + sepalatex2 - mapsize;
				aibovecy2 = aiboY + sepalatey2;
			}
			if (keypush == 21) {
				aibovecx2 = aiboX + sepalatex2;
				aibovecy2 = aiboY + sepalatey2 + mapsize;
			}
			if (keypush == 31) {
				aibovecx2 = aiboX + sepalatex2;
				aibovecy2 = aiboY + sepalatey2 - mapsize;
			}
			if (keypush == 1) {
				aibovecx2 = aiboX + sepalatex2 + mapsize;
				aibovecy2 = aiboY + sepalatey2;
			}
			if (keypush == 11) {
				aibovecx2 = aiboX + sepalatex2 - mapsize;
				aibovecy2 = aiboY + sepalatey2;
			}
			if (keypush == 21) {
				aibovecx2 = aiboX + sepalatex2;
				aibovecy2 = aiboY + sepalatey2 + mapsize;
			}
			if (keypush == 31) {
				aibovecx2 = aiboX + sepalatex2;
				aibovecy2 = aiboY + sepalatey2 - mapsize;
			}

			if (jikiX < 0) {
				jikiX = 0;
			}
			if (jikiX > sepalatex3) {
				jikiX = sepalatex3;
			}
			if (jikiY < 0) {
				jikiY = 0;
			}
			if (jikiY > sepalatey3) {
				jikiY = sepalatey3;
			}

			if (aiboX < 0) {
				aiboX = 0;
			}
			if (aiboX > sepalatex3) {
				aiboX = sepalatex3;
			}
			if (aiboY < 0) {
				aiboY = 0;
			}
			if (aiboY > sepalatey3) {
				aiboY = sepalatey3;
			}
			//ステージ遷移　mapnumberが現在のステージ
			if (map1[mapnumber][jikiY / mapsize][jikiX / mapsize] == 1) {
				if (map2[mapnumber][aiboY / mapsize][aiboX / mapsize] == 1) {
					clearcount = 1;
					aibovelX = 0;
					aibovelY = 0;
					aibovelx1 = 0;
					aibovely1 = 0;
					aibovelx2 = 0;
					aibovely2 = 0;
					SWITCH1 = 0;
					SWITCH2 = 0;
					SWITCH3 = 0;
					SWITCH4 = 0;
					switchcount1 = 0;
					switchcount2 = 0;
					switchcount3 = 0;
					switchcount4 = 0;
					dashcount1 = 0;
					dashcount2 = 0;
					/* aibo = aibo3;
					jikipic = jiki9;*/
					mapnumber += 1;
					aibovecx2 = 1100;
					aibovecy2 = 1100;
				}

				if (clearcount == 1) {
					for (int x = 0; x < map1X; x++) {
						for (int y = 0; y < map1Y; y++) {
							if (map1[mapnumber][y][x] == 5) {
								jikiX = x * mapsize;
								jikiY = y * mapsize;
								break;
							}
						}
					}
					for (int x = 0; x < map2X; x++) {
						for (int y = 0; y < map2Y; y++) {
							if (map2[mapnumber][y][x] == 5) {
								aiboX = x * mapsize;
								aiboY = y * mapsize;
								break;
							}
						}
					}
				}
				clearcount = 0;
			}
			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		Novice::DrawBox(0, 0, 1500, 720, 0.0f, 0x000000FF, kFillModeSolid);

		for (int y = 0; y < map1Y; y++) {
			for (int x = 0; x < map1X; x++) {
				if (map1[mapnumber][y][x] == 0) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize,
					  0, 0, mapsize, mapsize, floor, 0xFFFFFFFF);
				}
				if (map1[mapnumber][y][x] == 1) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, floor, 0xFFFFFFFF);
				}

				if (map1[mapnumber][y][x] == 2) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, wall, 0xFFFFFFFF);
				}

				if (map1[mapnumber][y][x] == 3) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, acctile1, 0xFFFFFFFF);
				}

				if (map1[mapnumber][y][x] == 13) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, acctile2, 0xFFFFFFFF);
				}

				if (map1[mapnumber][y][x] == 23) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, acctile0, 0xFFFFFFFF);
				}

				if (map1[mapnumber][y][x] == 33) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, acctile3, 0xFFFFFFFF);
				}

				if (map1[mapnumber][y][x] == 4) {
					if (switchcount1 == 1) {
						switchwall11 = switchwall2;
					}
					if (switchcount1 == 0) {
						switchwall11 = switchwall0;
					}
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, switchwall11, 0xFFFFFFFF);
				}
				if (map1[mapnumber][y][x] == 14) {
					if (switchcount2 == 1) {
						SWITCH1 = switch2;
					}
					if (switchcount2 == 0) {
						SWITCH1 = switch0;
					}
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, SWITCH1, 0xFFFFFFFF);
				}

				if (map1[mapnumber][y][x] == 24) {
					if (switchcount3 == 1) {
						SWITCH2 = switch1;
					}
					if (switchcount3 == 0) {
						SWITCH2 = switch0;
					}
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, SWITCH2, 0xFFFFFFFF);
				}
				if (map1[mapnumber][y][x] == 34) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, switchwall0, 0xFFFFFFFF);
				}
				if (map1[mapnumber][y][x] == 44) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, switchwall2, 0xFFFFFFFF);
				}
				if (map1[mapnumber][y][x] == 54) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, switchwall2, 0xFFFFFFFF);
				}
				if (map1[mapnumber][y][x] == 64) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, switchwall0, 0xFFFFFFFF);
				}
				if (map1[mapnumber][y][x] == 5) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, floor, 0xFFFFFFFF);
				}
				if (map1[mapnumber][y][x] == 9) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, goalh, 0xFFFFFFFF);
				}
				if (map1[mapnumber][y][x] == 19) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1,
					  x * mapsize + sepalatex1, y * mapsize + sepalatey1 + mapsize,
					  x * mapsize + sepalatex1 + mapsize, y * mapsize + sepalatey1 + mapsize, 0, 0,
					  mapsize, mapsize, goalw, 0xFFFFFFFF);
				}






				if (map2[mapnumber][y][x] == 0) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2 + mapsize,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2 + mapsize, 0, 0,
					  mapsize, mapsize, floor, 0xFFFFFFFF);
				}
				if (map2[mapnumber][y][x] == 1) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2 + mapsize,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2 + mapsize, 0, 0,
					  mapsize, mapsize, floor, 0xFFFFFFFF);
				}

				if (map2[mapnumber][y][x] == 2) {
					Novice::DrawQuad(

					  x * mapsize + sepalatex2, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2 + mapsize,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2 + mapsize, 0, 0,
					  mapsize, mapsize, wall, 0xFFFFFFFF);
				}

				if (map2[mapnumber][y][x] == 3) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2 + mapsize,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2 + mapsize, 0, 0,
					  mapsize, mapsize, acctile1, 0xFFFFFFFF);
				}

				if (map2[mapnumber][y][x] == 13) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2 + mapsize,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2 + mapsize, 0, 0,
					  mapsize, mapsize, acctile2, 0xFFFFFFFF);
				}

				if (map2[mapnumber][y][x] == 23) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2 + mapsize,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2 + mapsize, 0, 0,
					  mapsize, mapsize, acctile0, 0xFFFFFFFF);
				}

				if (map2[mapnumber][y][x] == 33) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2 + mapsize,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2 + mapsize, 0, 0,
					  mapsize, mapsize, acctile3, 0xFFFFFFFF);
				}

				if (map2[mapnumber][y][x] == 4) {
					if (switchcount2 == 1) {
						switchwall12 = switchwall2;
					}
					if (switchcount2 == 0) {
						switchwall12 = switchwall0;
					}
					Novice::DrawQuad(
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2 + mapsize,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2 + mapsize, 0, 0,
					  mapsize, mapsize, switchwall12, 0xFFFFFFFF);
				}
				if (map2[mapnumber][y][x] == 14) {
					if (switchcount1 == 1) {
						SWITCH3 = switch2;
					}
					if (switchcount1 == 0) {
						SWITCH3 = switch0;
					}
					Novice::DrawQuad(
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2 + mapsize,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2 + mapsize, 0, 0,
					  mapsize, mapsize, SWITCH3, 0xFFFFFFFF);
				}
				if (map2[mapnumber][y][x] == 24) {
					if (switchcount4 == 1) {
						SWITCH4 = switch1;
					}
					if (switchcount4 == 0) {
						SWITCH4 = switch0;
					}
					Novice::DrawQuad(
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2 + mapsize,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2 + mapsize, 0, 0,
					  mapsize, mapsize, SWITCH4, 0xFFFFFFFF);
				}
				if (map2[mapnumber][y][x] == 34) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2 + mapsize,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2 + mapsize, 0, 0,
					  mapsize, mapsize, switchwall0, 0xFFFFFFFF);
				}
				if (map2[mapnumber][y][x] == 44) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2 + mapsize,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2 + mapsize, 0, 0,
					  mapsize, mapsize, switchwall2, 0xFFFFFFFF);
				}
				if (map2[mapnumber][y][x] == 54) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2 + mapsize,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2 + mapsize, 0, 0,
					  mapsize, mapsize, switchwall2, 0xFFFFFFFF);
				}
				if (map2[mapnumber][y][x] == 64) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2 + mapsize,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2 + mapsize, 0, 0,
					  mapsize, mapsize, switchwall0, 0xFFFFFFFF);
				}
				if (map2[mapnumber][y][x] == 5) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2 + mapsize,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2 + mapsize, 0, 0,
					  mapsize, mapsize, floor, 0xFFFFFFFF);
				}
				if (map2[mapnumber][y][x] == 9) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2 + mapsize,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2 + mapsize, 0, 0,
					  mapsize, mapsize, goalh, 0xFFFFFFFF);
				}
				if (map2[mapnumber][y][x] == 19) {
					Novice::DrawQuad(
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2,
					  x * mapsize + sepalatex2, y * mapsize + sepalatey2 + mapsize,
					  x * mapsize + sepalatex2 + mapsize, y * mapsize + sepalatey2 + mapsize, 0, 0,
					  mapsize, mapsize, goalw, 0xFFFFFFFF);
				}


			}
		}

		Novice::DrawQuad(
		  jikiX + sepalatex1, jikiY + sepalatey1,
		  jikiX + sepalatex1 + mapsize, jikiY + sepalatey1,
		  jikiX + sepalatex1, jikiY + sepalatey1 + mapsize, 
		  jikiX + sepalatex1 + mapsize,jikiY + sepalatey1 + mapsize,
		  0, 0, mapsize, mapsize, jikipic, 0xFFFFFFFF);
		Novice::DrawQuad(
		  aibovecx2, aibovecy2, aibovecx2 + mapsize, aibovecy2, 
		  aibovecx2, aibovecy2 + mapsize, aibovecx2 + mapsize, aibovecy2 + mapsize,
		  0, 0, mapsize, mapsize, aibovecB, 0xFFFFFF40);
		Novice::DrawQuad(
		  aiboX + sepalatex2, aiboY + sepalatey2, 
		  aiboX + sepalatex2 + mapsize, aiboY + sepalatey2,
		  aiboX + sepalatex2, aiboY + sepalatey2 + mapsize, 
		  aiboX + sepalatex2 + mapsize,aiboY + sepalatey2 + mapsize,
		  0, 0, mapsize, mapsize, aibo, 0xFFFFFFFF);

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
