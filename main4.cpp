#include <Novice.h>
#define _USE_MATH_DEFINES
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

const char kWindowTitle[] = "KNOCK BACK JACK";



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 800, 720);

//	int jikipic = Novice::LoadTexture("./Resources/jiki1-1.png");
//	int haikei = Novice::LoadTexture("./Resources/haikei.png");
//	int bullet = Novice::LoadTexture("./Resources/bullet1.png");
//	int jikideath = Novice::LoadTexture("./Resources/jikideath.png");
	int jikiX = 0;
	int jikiY = 400;
	int jikivelx = 0;
	int jikively = 0;
	const int mapX=20;
	const int mapY=18;
	int mapsize = 40;
	int movecount = 0;
	int movetime = 0;
	int staytime = 0;
	int bulletX = 600;
	int bulletY = 600;
	int bulvelX = 0;
	int bulvelY = 0;
	float enemyX[6] = {0};
	float enemyY[6] = {0};
	int enemyLife[6] = {1};
	int enemymove[6] = {0};
	int playerlife = 1;
	float enemyvelX[6] = {0};
	float enemyvelY[6] = {0};
	float runbavelX=0;
	float runbavelY=0;
	int enemycount = 0;
	int enemycooltime = 0;
	int repopcooltime = 0;
	//int enemybullet[6] = {Novice::LoadTexture("./Resources/razor1.png")};
	float razorX[6] = {-100};
	float razorY[6] = {-100};
	int modX = 0;
	int modY = 0;
	

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
		
		int map[mapY][mapX]{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
		                    2,0,2,0,0,0,0,0,0,0,0,0,0,2,0,2,0,0,0,2,
		                    2,0,2,2,2,2,2,2,0,2,2,0,0,2,0,0,0,2,0,2,
		                    2,0,0,0,0,0,0,0,0,2,2,0,2,2,0,2,0,0,0,2,
		                    2,0,2,0,2,2,0,2,0,2,0,0,0,0,0,2,0,2,2,2,
		                    2,0,2,0,2,2,0,2,0,0,0,0,2,2,0,2,0,2,2,2,
		                    2,0,2,0,0,0,0,2,0,2,2,0,0,2,0,2,0,2,2,2,
		                    2,0,2,2,2,2,0,0,0,2,2,2,0,2,0,2,0,0,0,2,
		                    2,0,0,0,0,2,0,2,2,2,2,0,0,2,0,2,2,2,0,0,
		                    2,2,2,2,2,2,0,2,2,2,2,0,2,2,0,2,2,2,2,2,
		                    0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,2,0,0,2,2,
		                    2,2,2,2,2,2,0,2,2,2,2,2,2,0,0,0,0,0,0,2,
		                    2,0,2,2,0,2,0,2,0,0,0,0,2,0,0,0,2,2,0,2,
		                    2,0,0,0,0,2,0,2,0,0,0,0,2,2,2,0,2,2,0,2,
		                    2,0,2,2,2,2,0,2,0,0,0,2,2,2,2,0,2,2,0,2,
		                    2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		                    2,2,0,0,0,2,2,2,0,0,0,2,2,2,2,2,0,0,2,2,
				            2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,};

		if (jikiX == mapX * mapsize && jikiY == mapY * mapsize) {
			map[mapY][mapX] = 1;
		}
		jikivelx = 0;
		jikively = 0;		
		
		if (keys[DIK_D] ) {
			 jikivelx = 5;
		}
		if (keys[DIK_A]) {
			jikivelx = -5;
		}
		if (keys[DIK_S] ) {
			jikively = 5;
		}
		if (keys[DIK_W] ) {
			jikively = -5;
		}
		if (keys[DIK_RIGHT]) {
			jikivelx = 5;
			
		}
		if (keys[DIK_LEFT] ) {
			jikivelx = -5;
			
		}
		if (keys[DIK_DOWN] ) {
			jikively = 5;
		}
		if (keys[DIK_UP]) {
			jikively = -5;
		}
		
		//当たり判定
		//if (map[(jikiY+jikively) / mapsize][(jikiX+jikivelx) / mapsize] == 2) {
		//	jikivelx = 0;
		//	jikively = 0;
		//}

	    /* for (int x = 0; x < mapX; x++) {
			for (int y = 0; y < mapY; y++) {
				if (map[y][x] == 2) {
					if (
					  (jikiY + jikively + 20) - (y * mapsize + 20) < 40 &&
					  (jikiY + jikively + 20) - (y * mapsize + 20) >
					    -40&&(jikiX + jikivelx + 20) - (x * mapsize + 20) < 40 &&
					  (jikiX + jikivelx + 20) - (x * mapsize + 20) > -40) {
						jikively = 0;
						jikivelx = 0;
					}
					//if ((jikiX + jikivelx + 20) - (x*mapsize + 20) < 40 && (jikiX + jikivelx + 20) - (x*mapsize + 20) > -40) {
					  
					//}
				}
			}
		}*/
		
		
		
		
		
		
		
		
		
		/*
		if (movecount == 0) {
			bulletX = jikiX;
			bulletY = jikiY;
		}
		if (movecount == 1) {
			bulvelX = -30;
			bulletX += bulvelX;
			bulletY += bulvelY;
			bullet = Novice::LoadTexture("./Resources/bullet2.png");
		}
		if (movecount == 2) {
			bulvelX = 30;
			bulletX += bulvelX;
			bulletY += bulvelY;
			bullet = Novice::LoadTexture("./Resources/bullet1.png");
		}
		if (movecount == 3) {
			bulvelY = -30;
			bulletX += bulvelX;
			bulletY += bulvelY;
			bullet = Novice::LoadTexture("./Resources/bullet3.png");
		}
		if (movecount == 4) {
			bulvelY = 30;
			bulletX += bulvelX;
			bulletY += bulvelY;
			bullet = Novice::LoadTexture("./Resources/bullet4.png");
		}
		 if (movecount == 1 && movetime < 11) {
			jikipic = Novice::LoadTexture("./Resources/jiki2-5.png");
		}
		if (movecount == 1 && movetime >= 11) {
			jikipic = Novice::LoadTexture("./Resources/jiki2-1.png");
		}
		if (movecount == 2 && movetime < 11) {
			jikipic = Novice::LoadTexture("./Resources/jiki3-5.png");
		}
		if (movecount == 2 && movetime >= 11) {
			jikipic = Novice::LoadTexture("./Resources/jiki3-1.png");
		}
		if (movecount == 3 && movetime < 11) {
			jikipic = Novice::LoadTexture("./Resources/jiki5-5.png");
		}
		if (movecount == 3 && movetime >= 11) {
			jikipic = Novice::LoadTexture("./Resources/jiki5-1.png");
		}
		if (movecount == 4 && movetime < 11) {
			jikipic = Novice::LoadTexture("./Resources/jiki1-5.png");
		}
		if (movecount == 4 && movetime >= 11) {
			jikipic = Novice::LoadTexture("./Resources/jiki1-1.png");
		}
		if (jikipic == Novice::LoadTexture("./Resources/jiki2-1.png") && staytime == 15) {
			jikipic = Novice::LoadTexture("./Resources/jiki2-2.png");
		}
		if (jikipic == Novice::LoadTexture("./Resources/jiki2-2.png") && staytime == 30) {
			jikipic = Novice::LoadTexture("./Resources/jiki2-3.png");
		}
		if (jikipic == Novice::LoadTexture("./Resources/jiki2-3.png") && staytime == 45) {
			jikipic = Novice::LoadTexture("./Resources/jiki2-4.png");
		}
		if (jikipic == Novice::LoadTexture("./Resources/jiki2-4.png") && staytime == 0) {
			jikipic = Novice::LoadTexture("./Resources/jiki2-1.png");
		}

		if (jikipic == Novice::LoadTexture("./Resources/jiki3-1.png") && staytime == 15) {
			jikipic = Novice::LoadTexture("./Resources/jiki3-2.png");
		}
		if (jikipic == Novice::LoadTexture("./Resources/jiki3-2.png") && staytime == 30) {
			jikipic = Novice::LoadTexture("./Resources/jiki3-3.png");
		}
		if (jikipic == Novice::LoadTexture("./Resources/jiki3-3.png") && staytime == 45) {
			jikipic = Novice::LoadTexture("./Resources/jiki3-4.png");
		}
		if (jikipic == Novice::LoadTexture("./Resources/jiki3-4.png") && staytime == 0) {
			jikipic = Novice::LoadTexture("./Resources/jiki3-1.png");
		}

		if (jikipic == Novice::LoadTexture("./Resources/jiki1-1.png") && staytime == 15) {
			jikipic = Novice::LoadTexture("./Resources/jiki1-2.png");
		}
		if (jikipic == Novice::LoadTexture("./Resources/jiki1-2.png") && staytime == 30) {
			jikipic = Novice::LoadTexture("./Resources/jiki1-3.png");
		}
		if (jikipic == Novice::LoadTexture("./Resources/jiki1-3.png") && staytime == 45) {
			jikipic = Novice::LoadTexture("./Resources/jiki1-4.png");
		}
		if (jikipic == Novice::LoadTexture("./Resources/jiki1-4.png") && staytime == 0) {
			jikipic = Novice::LoadTexture("./Resources/jiki1-1.png");
		}

		if (jikipic == Novice::LoadTexture("./Resources/jiki5-1.png") && staytime == 15) {
			jikipic = Novice::LoadTexture("./Resources/jiki5-2.png");
		}
		if (jikipic == Novice::LoadTexture("./Resources/jiki5-2.png") && staytime == 30) {
			jikipic = Novice::LoadTexture("./Resources/jiki5-3.png");
		}
		if (jikipic == Novice::LoadTexture("./Resources/jiki5-3.png") && staytime == 45) {
			jikipic = Novice::LoadTexture("./Resources/jiki5-4.png");
		}
		if (jikipic == Novice::LoadTexture("./Resources/jiki5-4.png") && staytime == 0) {
			jikipic = Novice::LoadTexture("./Resources/jiki5-1.png");
		}*/

		if (jikiX <= 0) {
			jikiX = 0;
		}
		if (jikiX >= 800) {
			jikiX = 800;
		}
		if (jikiY <= 0) {
			jikiY = 0;
		}
		if (jikiY >= 680) {
			jikiY = 680;
		}

		//ここまで自機の関連----------------------------------------------------------
		
		//ここから敵*******************************************************************
		/* if (enemycooltime < 60) {
				enemycooltime++;
	    }
	    if (enemycooltime == 60) {
			enemycount++;
		 enemycooltime = 0;
	    }
		if (enemycount == 7) {
			enemycount = 6;
		}
		
		
         //ランダムのやつで敵の配置
		if (enemycount < 6 && enemycooltime == 59) {
			int numX = rand();
			modX = numX % 9+1;
			if (modX == 1) {
				enemyX[enemycount] = 35;
			}
			if (modX == 2) {
				enemyX[enemycount] = 135;
			}
			if (modX == 3) {
				enemyX[enemycount] = 235;
			}
			if (modX == 4) {
				enemyX[enemycount] = 335;
			}
			if (modX == 5) {
				enemyX[enemycount] = 435;
			}
			if (modX == 6) {
				enemyX[enemycount] = 535;
			}
			if (modX == 7) {
				enemyX[enemycount] = 635;
			}
			if (modX == 8) {
				enemyX[enemycount] = 735;
			}
			if (modX == 9) {
				enemyX[enemycount] = 835;
			}

			int numY = rand();
			modY = numY % 7+1;
			if (modY == 1) {
				enemyY[enemycount] = 30;
			}
			if (modY == 2) {
				enemyY[enemycount] = 130;
			}
			if (modY == 3) {
				enemyY[enemycount] = 230;
			}
			if (modY == 4) {
				enemyY[enemycount] = 330;
			}
			if (modY == 5) {
				enemyY[enemycount] = 430;
			}
			if (modY == 6) {
				enemyY[enemycount] = 530;
			}
			if (modY == 7) {
				enemyY[enemycount] = 630;
			}
			//敵を端に配置
			 int enemyrepop = rand();
			enemyappare == enemyrepop % 4;
			 
			if (enemyappare == 0) {
				enemyX[enemycount] = 935;
			}
			if (enemyappare == 1) {
				enemyX[enemycount] = -40;
			}
			if (enemyappare == 2) {
				enemyY[enemycount] = -40;
			}
			if (enemyappare == 3) {
				enemyY[enemycount] = 730;
			}
		}
		
		//敵の入場
		if (enemyX[enemycount]== 935) {
			enemyvelX[enemycount] = -10;
			enemyvelY[enemycount] = 0;
		}
		if (enemyX[enemycount] == -40) {
			enemyvelX[enemycount] = 10;
			enemyvelY[enemycount] = 0;
		}
		if (enemyY[enemycount] == -40) {
			enemyvelX[enemycount] = 0;
			enemyvelY[enemycount] = 10;
		}
		if (enemyY[enemycount] == 730) {
			enemyvelX[enemycount] = 0;
			enemyvelY[enemycount] = -10;
		}
			
			//当たり判定　四角の中心から半径Xで判定
			/// if(){
			///
			///}
			/// DIST1=
			///if(DIST<=)
	  }
		//敵の描写
			int enemytype1 = rand();

			if (enemycount == 0) {
			    enemy1 == enemytype1 % 3;
		    }
				if (enemy1 == 0) {
					if (enemyvelX[0] >= 10 && enemymove[0] == 0) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelX[0] >= 10 && enemymove[0] == 15) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot2.png");
					}
					if (enemyvelX[0] >= 10 && enemymove[0] == 30) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot3.png");
					}
					if (enemyvelX[0] >= 10 && enemymove[0] == 45) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot4.png");
					}
					if (enemyvelY[0] >= 10 && enemymove[0] == 0) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelY[0] >= 10 && enemymove[0] == 15) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelY[0] >= 10 && enemymove[0] == 30) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelY[0] >= 10 && enemymove[0] == 45) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelX[0] <= -10 && enemymove[0] == 0) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot5.png");
					}
					if (enemyvelX[0] <= -10 && enemymove[0] == 15) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot6.png");
					}
					if (enemyvelX[0] <= -10 && enemymove[0] == 30) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot7.png");
					}
					if (enemyvelX[0] <= -10 && enemymove[0] == 45) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot8.png");
					}
					if (enemyvelY[0] <= -10 && enemymove[0] == 0) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelY[0] <= -10 && enemymove[0] == 15) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot2.png");
					}
					if (enemyvelY[0] <= -10 && enemymove[0] == 30) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot3.png");
					}
					if (enemyvelY[0] <= -10 && enemymove[0] == 45) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot4.png");
					}
				}
				if (enemy1 == 1) {
					if (enemyvelX[0] >= 10 && enemymove[0] == 0) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot1-1.png");
					}
					if (enemyvelX[0] >= 10 && enemymove[0] == 15) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot1-2.png");
					}
					if (enemyvelX[0] >= 10 && enemymove[0] == 30) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot1-3.png");
					}
					if (enemyvelX[0] >= 10 && enemymove[0] == 45) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot1-4.png");
					}
					if (enemyvelX[0] <= -10 && enemymove[0] == 0) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot2-1.png");
					}
					if (enemyvelX[0] <= -10 && enemymove[0] == 15) {
						enemypic[0] = Novice::LoadTexture("./Resourcesenemyrobot2-2.png");
					}
					if (enemyvelX[0] <= -10 && enemymove[0] == 30) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot2-3.png");
					}
					if (enemyvelX[0] <= -10 && enemymove[0] == 45) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot2-4.png");
					}
					if (enemyvelY[0] >= 10 && enemymove[0] == 0) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot1.png");
					}
					if (enemyvelY[0] >= 10 && enemymove[0] == 15) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot2.png");
					}
					if (enemyvelY[0] >= 10 && enemymove[0] == 30) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot3.png");
					}
					if (enemyvelY[0] >= 10 && enemymove[0] == 45) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot4.png");
					}
					if (enemyvelY[0] <= -10 && enemymove[0] == 0) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot1.png");
					}
					if (enemyvelY[0] <= -10 && enemymove[0] == 15) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot2.png");
					}
					if (enemyvelY[0] <= -10 && enemymove[0] == 30) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot3.png");
					}
					if (enemyvelY[0] <= -10 && enemymove[0] == 45) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot4.png");
					}
					if (enemyvelX[0] >= 10 && enemymove[0] == 0) {
						enemybullet[0] = Novice::LoadTexture("./Resources/razor2.png");
					}
					if (enemyvelX[0] <= -10 && enemymove[0] == 0) {
						enemybullet[0] = Novice::LoadTexture("./Resources/razor2.png");
					}
					if (enemyvelY[0] >= 10 && enemymove[0] == 0) {
						enemybullet[0] = Novice::LoadTexture("./Resources/razor1.png");
					}
					if (enemyvelY[0] <= -10 && enemymove[0] == 0) {
						enemybullet[0] = Novice::LoadTexture("./Resources/razor1.png");
					}
				}
				if (enemy1==2){
					enemyX[0]+=enemyvelX[0] * 2;
					enemyY[0]+=enemyvelY[0] * 2;
					if (enemyvelY[0] == 0 && enemymove[0] == 0) {
						enemypic[0] = Novice::LoadTexture("./Resources/runba1.png");
					}
					if (enemyvelY[0] == 0 && enemymove[0] == 15) {
						enemypic[0] = Novice::LoadTexture("./Resources/runba2.png");
					}
					if (enemyvelY[0] == 0 && enemymove[0] == 30) {
						enemypic[0] = Novice::LoadTexture("./Resources/runbat3.png");
					}
					if (enemyvelY[0] == 0 && enemymove[0] == 45) {
						enemypic[0] = Novice::LoadTexture("./Resources/runba4.png");
					}
					if (enemyvelX[0] == 0 && enemymove[0] == 0) {
						enemypic[0] = Novice::LoadTexture("./Resources/runba1.png");
					}
					if (enemyvelX[0] == 0 && enemymove[0] == 15) {
						enemypic[0] = Novice::LoadTexture("./Resources/runba2.png");
					}
					if (enemyvelX[0] == 0 && enemymove[0] == 30) {
						enemypic[0] = Novice::LoadTexture("./Resources/runba3.png");
					}
					if (enemyvelX[0] == 0 && enemymove[0] == 45) {
						enemypic[0] = Novice::LoadTexture("./Resources/runba4.png");
					}
					break;
				}
			
			int enemytype2 = rand();

			if (enemycount == 1) {
			    enemy2 == enemytype2 % 3;
		    }
				if (enemy2 == 0) {
					if (enemyvelX[1] >= 10 && enemymove[1] == 0) {
						enemypic[1] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelX[1] >= 10 && enemymove[1] == 15) {
						enemypic[1] = Novice::LoadTexture("./Resources/ballrobot2.png");
					}
					if (enemyvelX[1] >= 10 && enemymove[1] == 30) {
						enemypic[1] = Novice::LoadTexture("./Resources/ballrobot3.png");
					}
					if (enemyvelX[1] >= 10 && enemymove[1] == 45) {
						enemypic[1] = Novice::LoadTexture("./Resources/ballrobot4.png");
					}
					if (enemyvelY[1] >= 10 && enemymove[1] == 0) {
						enemypic[1] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelY[1] >= 10 && enemymove[1] == 15) {
						enemypic[1] = Novice::LoadTexture("./Resources/ballrobot2.png");
					}
					if (enemyvelY[1] >= 10 && enemymove[1] == 30) {
						enemypic[1] = Novice::LoadTexture("./Resources/ballrobot3.png");
					}
					if (enemyvelY[1] >= 10 && enemymove[1] == 45) {
						enemypic[1] = Novice::LoadTexture("./Resources/ballrobot4.png");
					}
					if (enemyvelX[1] <= -10 && enemymove[1] == 0) {
						enemypic[1] = Novice::LoadTexture("./Resources/ballrobot5.png");
					}
					if (enemyvelX[1] <= -10 && enemymove[1] == 15) {
						enemypic[1] = Novice::LoadTexture("./Resources/ballrobot6.png");
					}
					if (enemyvelX[1] <= -10 && enemymove[1] == 30) {
						enemypic[1] = Novice::LoadTexture("./Resources/ballrobot7.png");
					}
					if (enemyvelX[1] <= -10 && enemymove[1] == 45) {
						enemypic[1] = Novice::LoadTexture("./Resources/ballrobot8.png");
					}
					if (enemyvelY[1] <= -10 && enemymove[1] == 0) {
						enemypic[1] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelY[1] <= -10 && enemymove[1] == 15) {
						enemypic[1] = Novice::LoadTexture("./Resources/ballrobot2.png");
					}
					if (enemyvelY[1] <= -10 && enemymove[1] == 30) {
						enemypic[1] = Novice::LoadTexture("./Resources/ballrobot3.png");
					}
					if (enemyvelY[1] <= -10 && enemymove[1] == 45) {
						enemypic[1] = Novice::LoadTexture("./Resources/ballrobot4.png");
					}
				}
				if (enemy2 == 1) {
					if (enemyvelX[1] >= 10 && enemymove[1] == 0) {
						enemypic[1] = Novice::LoadTexture("./Resources/enemyrobot1-1.png");
					}
					if (enemyvelX[1] >= 10 && enemymove[1] == 15) {
						enemypic[1] = Novice::LoadTexture("./Resources/enemyrobot1-2.png");
					}
					if (enemyvelX[1] >= 10 && enemymove[1] == 30) {
						enemypic[1] = Novice::LoadTexture("./Resources/enemyrobot1-3.png");
					}
					if (enemyvelX[1] >= 10 && enemymove[1] == 45) {
						enemypic[1] = Novice::LoadTexture("./Resources/enemyrobot1-4.png");
					}
					if (enemyvelX[1] <= -10 && enemymove[1] == 0) {
						enemypic[1] = Novice::LoadTexture("./Resources/enemyrobot2-1.png");
					}
					if (enemyvelX[1] <= -10 && enemymove[1] == 15) {
						enemypic[1] = Novice::LoadTexture("./Resourcesenemyrobot2-2.png");
					}
					if (enemyvelX[1] <= -10 && enemymove[1] == 30) {
						enemypic[1] = Novice::LoadTexture("./Resources/enemyrobot2-3.png");
					}
					if (enemyvelX[1] <= -10 && enemymove[1] == 45) {
						enemypic[1] = Novice::LoadTexture("./Resources/enemyrobot2-4.png");
					}
					if (enemyvelY[1] >= 10 && enemymove[1] == 0) {
						enemypic[1] = Novice::LoadTexture("./Resources/enemyrobot1.png");
					}
					if (enemyvelY[1] >= 10 && enemymove[1] == 15) {
						enemypic[1] = Novice::LoadTexture("./Resources/enemyrobot2.png");
					}
					if (enemyvelY[1] >= 10 && enemymove[1] == 30) {
						enemypic[1] = Novice::LoadTexture("./Resources/enemyrobot3.png");
					}
					if (enemyvelY[1] >= 10 && enemymove[1] == 45) {
						enemypic[1] = Novice::LoadTexture("./Resources/enemyrobot4.png");
					}
					if (enemyvelY[1] <= -10 && enemymove[1] == 0) {
						enemypic[1] = Novice::LoadTexture("./Resources/enemyrobot1.png");
					}
					if (enemyvelY[1] <= -10 && enemymove[1] == 15) {
						enemypic[1] = Novice::LoadTexture("./Resources/enemyrobot2.png");
					}
					if (enemyvelY[1] <= -10 && enemymove[1] == 30) {
						enemypic[1] = Novice::LoadTexture("./Resources/enemyrobot3.png");
					}
					if (enemyvelY[1] <= -10 && enemymove[1] == 45) {
						enemypic[1] = Novice::LoadTexture("./Resources/enemyrobot4.png");
					}
					if (enemyvelX[1] >= 10 && enemymove[1] == 0) {
						enemybullet[1] = Novice::LoadTexture("./Resources/razor2.png");
					}
					if (enemyvelX[1] <= -10 && enemymove[1] == 0) {
						enemybullet[1] = Novice::LoadTexture("./Resources/razor2.png");
					}
					if (enemyvelY[1] >= 10 && enemymove[1] == 0) {
						enemybullet[1] = Novice::LoadTexture("./Resources/razor1.png");
					}
					if (enemyvelY[1] <= -10 && enemymove[1] == 0) {
						enemybullet[1] = Novice::LoadTexture("./Resources/razor1.png");
					}
				}
				if (enemy2==2){
					enemyX[1] += enemyvelX[1] * 2;
					enemyY[1] += enemyvelY[1] * 2;
					if (enemyvelY[1] == 0 && enemymove[1] == 0) {
						enemypic[1] = Novice::LoadTexture("./Resources/runba1.png");
					}
					if (enemyvelY[1] == 0 && enemymove[1] == 15) {
						enemypic[01] = Novice::LoadTexture("./Resources/runba2.png");
					}
					if (enemyvelY[1] == 0 && enemymove[1] == 30) {
						enemypic[1] = Novice::LoadTexture("./Resources/runbat3.png");
					}
					if (enemyvelY[1] == 0 && enemymove[1] == 45) {
						enemypic[1] = Novice::LoadTexture("./Resources/runba4.png");
					}
					if (enemyvelX[1] == 0 && enemymove[1] == 0) {
						enemypic[1] = Novice::LoadTexture("./Resources/runba1.png");
					}
					if (enemyvelX[1] == 0 && enemymove[1] == 15) {
						enemypic[1] = Novice::LoadTexture("./Resources/runba2.png");
					}
					if (enemyvelX[1] == 0 && enemymove[1] == 30) {
						enemypic[1] = Novice::LoadTexture("./Resources/runba3.png");
					}
					if (enemyvelX[1] == 0 && enemymove[1] == 45) {
						enemypic[1] = Novice::LoadTexture("./Resources/runba4.png");
					}
				}
			
			int enemytype3 = rand();

			if (enemycount == 2) {
			    enemy3 == enemytype3 % 3;
		    }
				if (enemy3 == 0) {
					if (enemyvelX[2] >= 10 && enemymove[2] == 0) {
						enemypic[2] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelX[2] >= 10 && enemymove[2] == 15) {
						enemypic[2] = Novice::LoadTexture("./Resources/ballrobot2.png");
					}
					if (enemyvelX[2] >= 10 && enemymove[2] == 30) {
						enemypic[2] = Novice::LoadTexture("./Resources/ballrobot3.png");
					}
					if (enemyvelX[2] >= 10 && enemymove[2] == 45) {
						enemypic[2] = Novice::LoadTexture("./Resources/ballrobot4.png");
					}
					if (enemyvelY[2] >= 10 && enemymove[2] == 0) {
						enemypic[2] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelY[2] >= 10 && enemymove[2] == 15) {
						enemypic[2] = Novice::LoadTexture("./Resources/ballrobot2.png");
					}
					if (enemyvelY[2] >= 10 && enemymove[2] == 30) {
						enemypic[2] = Novice::LoadTexture("./Resources/ballrobot3.png");
					}
					if (enemyvelY[2] >= 10 && enemymove[2] == 45) {
						enemypic[2] = Novice::LoadTexture("./Resources/ballrobot4.png");
					}
					if (enemyvelX[2] <= -10 && enemymove[2] == 0) {
						enemypic[2] = Novice::LoadTexture("./Resources/ballrobot5.png");
					}
					if (enemyvelX[2] <= -10 && enemymove[2] == 15) {
						enemypic[2] = Novice::LoadTexture("./Resources/ballrobot6.png");
					}
					if (enemyvelX[2] <= -10 && enemymove[2] == 30) {
						enemypic[2] = Novice::LoadTexture("./Resources/ballrobot7.png");
					}
					if (enemyvelX[2] <= -10 && enemymove[2] == 45) {
						enemypic[2] = Novice::LoadTexture("./Resources/ballrobot8.png");
					}
					if (enemyvelY[2] <= -10 && enemymove[2] == 0) {
						enemypic[2] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelY[2] <= -10 && enemymove[2] == 15) {
						enemypic[2] = Novice::LoadTexture("./Resources/ballrobot2.png");
					}
					if (enemyvelY[2] <= -10 && enemymove[2] == 30) {
						enemypic[2] = Novice::LoadTexture("./Resources/ballrobot3.png");
					}
					if (enemyvelY[2] <= -10 && enemymove[2] == 45) {
						enemypic[2] = Novice::LoadTexture("./Resources/ballrobot4.png");
					}
				}
				if (enemy3 == 1) {
					if (enemyvelX[2] >= 10 && enemymove[2] == 0) {
						enemypic[2] = Novice::LoadTexture("./Resources/enemyrobot1-1.png");
					}
					if (enemyvelX[2] >= 10 && enemymove[2] == 15) {
						enemypic[2] = Novice::LoadTexture("./Resources/enemyrobot1-2.png");
					}
					if (enemyvelX[2] >= 10 && enemymove[2] == 30) {
						enemypic[2] = Novice::LoadTexture("./Resources/enemyrobot1-3.png");
					}
					if (enemyvelX[2] >= 10 && enemymove[2] == 45) {
						enemypic[2] = Novice::LoadTexture("./Resources/enemyrobot1-4.png");
					}
					if (enemyvelX[2] <= -10 && enemymove[2] == 0) {
						enemypic[2] = Novice::LoadTexture("./Resources/enemyrobot2-1.png");
					}
					if (enemyvelX[2] <= -10 && enemymove[2] == 15) {
						enemypic[2] = Novice::LoadTexture("./Resourcesenemyrobot2-2.png");
					}
					if (enemyvelX[2] <= -10 && enemymove[2] == 30) {
						enemypic[2] = Novice::LoadTexture("./Resources/enemyrobot2-3.png");
					}
					if (enemyvelX[2] <= -10 && enemymove[2] == 45) {
						enemypic[2] = Novice::LoadTexture("./Resources/enemyrobot2-4.png");
					}
					if (enemyvelY[2] >= 10 && enemymove[2] == 0) {
						enemypic[2] = Novice::LoadTexture("./Resources/enemyrobot1.png");
					}
					if (enemyvelY[2] >= 10 && enemymove[2] == 15) {
						enemypic[2] = Novice::LoadTexture("./Resources/enemyrobot2.png");
					}
					if (enemyvelY[2] >= 10 && enemymove[2] == 30) {
						enemypic[2] = Novice::LoadTexture("./Resources/enemyrobot3.png");
					}
					if (enemyvelY[2] >= 10 && enemymove[2] == 45) {
						enemypic[2] = Novice::LoadTexture("./Resources/enemyrobot4.png");
					}
					if (enemyvelY[2] <= -10 && enemymove[2] == 0) {
						enemypic[2] = Novice::LoadTexture("./Resources/enemyrobot1.png");
					}
					if (enemyvelY[2] <= -10 && enemymove[2] == 15) {
						enemypic[2] = Novice::LoadTexture("./Resources/enemyrobot2.png");
					}
					if (enemyvelY[2] <= -10 && enemymove[2] == 30) {
						enemypic[2] = Novice::LoadTexture("./Resources/enemyrobot3.png");
					}
					if (enemyvelY[2] <= -10 && enemymove[2] == 45) {
						enemypic[2] = Novice::LoadTexture("./Resources/enemyrobot4.png");
					}
					if (enemyvelX[2] >= 10 && enemymove[2] == 0) {
						enemybullet[2] = Novice::LoadTexture("./Resources/razor2.png");
					}
					if (enemyvelX[2] <= -10 && enemymove[2] == 0) {
						enemybullet[2] = Novice::LoadTexture("./Resources/razor2.png");
					}
					if (enemyvelY[2] >= 10 && enemymove[2] == 0) {
						enemybullet[2] = Novice::LoadTexture("./Resources/razor1.png");
					}
					if (enemyvelY[2] <= -10 && enemymove[2] == 0) {
						enemybullet[2] = Novice::LoadTexture("./Resources/razor1.png");
					}
				}
				if (enemy3==2){
					enemyX[2] += enemyvelX[2] * 2;
					enemyY[2] += enemyvelY[2] * 2;
					if (enemyvelY[2] == 0 && enemymove[2] == 0) {
						enemypic[2] = Novice::LoadTexture("./Resources/runba1.png");
					}
					if (enemyvelY[2] == 0 && enemymove[2] == 15) {
						enemypic[2] = Novice::LoadTexture("./Resources/runba2.png");
					}
					if (enemyvelY[2] == 0 && enemymove[2] == 30) {
						enemypic[2] = Novice::LoadTexture("./Resources/runbat3.png");
					}
					if (enemyvelY[2] == 0 && enemymove[2] == 45) {
						enemypic[2] = Novice::LoadTexture("./Resources/runba4.png");
					}
					if (enemyvelX[2] == 0 && enemymove[2] == 0) {
						enemypic[2] = Novice::LoadTexture("./Resources/runba1.png");
					}
					if (enemyvelX[2] == 0 && enemymove[2] == 15) {
						enemypic[2] = Novice::LoadTexture("./Resources/runba2.png");
					}
					if (enemyvelX[2] == 0 && enemymove[2] == 30) {
						enemypic[2] = Novice::LoadTexture("./Resources/runba3.png");
					}
					if (enemyvelX[2] == 0 && enemymove[2] == 45) {
						enemypic[2] = Novice::LoadTexture("./Resources/runba4.png");
					}
				}
			
			int enemytype4 = rand();

			if (enemycount == 3) {
			    enemy4 == enemytype4 % 3;
		    }
				if (enemy4 == 0) {
					if (enemyvelX[3] >= 10 && enemymove[3] == 0) {
						enemypic[3] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelX[3] >= 10 && enemymove[3] == 15) {
						enemypic[3] = Novice::LoadTexture("./Resources/ballrobot2.png");
					}
					if (enemyvelX[3] >= 10 && enemymove[3] == 30) {
						enemypic[3] = Novice::LoadTexture("./Resources/ballrobot3.png");
					}
					if (enemyvelX[3] >= 10 && enemymove[3] == 45) {
						enemypic[3] = Novice::LoadTexture("./Resources/ballrobot4.png");
					}
					if (enemyvelY[3] >= 10 && enemymove[3] == 0) {
						enemypic[3] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelY[3] >= 10 && enemymove[3] == 15) {
						enemypic[3] = Novice::LoadTexture("./Resources/ballrobot2.png");
					}
					if (enemyvelY[3] >= 10 && enemymove[3] == 30) {
						enemypic[3] = Novice::LoadTexture("./Resources/ballrobot3.png");
					}
					if (enemyvelY[3] >= 10 && enemymove[3] == 45) {
						enemypic[3] = Novice::LoadTexture("./Resources/ballrobot4.png");
					}
					if (enemyvelX[3] <= -10 && enemymove[3] == 0) {
						enemypic[3] = Novice::LoadTexture("./Resources/ballrobot5.png");
					}
					if (enemyvelX[3] <= -10 && enemymove[3] == 15) {
						enemypic[3] = Novice::LoadTexture("./Resources/ballrobot6.png");
					}
					if (enemyvelX[3] <= -10 && enemymove[3] == 30) {
						enemypic[3] = Novice::LoadTexture("./Resources/ballrobot7.png");
					}
					if (enemyvelX[3] <= -10 && enemymove[3] == 45) {
						enemypic[3] = Novice::LoadTexture("./Resources/ballrobot8.png");
					}
					if (enemyvelY[3] <= -10 && enemymove[3] == 0) {
						enemypic[3] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelY[3] <= -10 && enemymove[3] == 15) {
						enemypic[3] = Novice::LoadTexture("./Resources/ballrobot2.png");
					}
					if (enemyvelY[3] <= -10 && enemymove[3] == 30) {
						enemypic[3] = Novice::LoadTexture("./Resources/ballrobot3.png");
					}
					if (enemyvelY[3] <= -10 && enemymove[3] == 45) {
						enemypic[3] = Novice::LoadTexture("./Resources/ballrobot4.png");
					}
				}
				if (enemy4 == 1) {
					if (enemyvelX[3] >= 10 && enemymove[3] == 0) {
						enemypic[3] = Novice::LoadTexture("./Resources/enemyrobot1-1.png");
					}
					if (enemyvelX[3] >= 10 && enemymove[3] == 15) {
						enemypic[3] = Novice::LoadTexture("./Resources/enemyrobot1-2.png");
					}
					if (enemyvelX[3] >= 10 && enemymove[3] == 30) {
						enemypic[3] = Novice::LoadTexture("./Resources/enemyrobot1-3.png");
					}
					if (enemyvelX[3] >= 10 && enemymove[3] == 45) {
						enemypic[3] = Novice::LoadTexture("./Resources/enemyrobot1-4.png");
					}
					if (enemyvelX[3] <= -10 && enemymove[3] == 0) {
						enemypic[3] = Novice::LoadTexture("./Resources/enemyrobot2-1.png");
					}
					if (enemyvelX[3] <= -10 && enemymove[3] == 15) {
						enemypic[3] = Novice::LoadTexture("./Resourcesenemyrobot2-2.png");
					}
					if (enemyvelX[3] <= -10 && enemymove[3] == 30) {
						enemypic[3] = Novice::LoadTexture("./Resources/enemyrobot2-3.png");
					}
					if (enemyvelX[3] <= -10 && enemymove[3] == 45) {
						enemypic[3] = Novice::LoadTexture("./Resources/enemyrobot2-4.png");
					}
					if (enemyvelY[3] >= 10 && enemymove[3] == 0) {
						enemypic[3] = Novice::LoadTexture("./Resources/enemyrobot1.png");
					}
					if (enemyvelY[3] >= 10 && enemymove[3] == 15) {
						enemypic[3] = Novice::LoadTexture("./Resources/enemyrobot2.png");
					}
					if (enemyvelY[3] >= 10 && enemymove[3] == 30) {
						enemypic[3] = Novice::LoadTexture("./Resources/enemyrobot3.png");
					}
					if (enemyvelY[3] >= 10 && enemymove[3] == 45) {
						enemypic[3] = Novice::LoadTexture("./Resources/enemyrobot4.png");
					}
					if (enemyvelY[3] <= -10 && enemymove[3] == 0) {
						enemypic[3] = Novice::LoadTexture("./Resources/enemyrobot1.png");
					}
					if (enemyvelY[3] <= -10 && enemymove[3] == 15) {
						enemypic[3] = Novice::LoadTexture("./Resources/enemyrobot2.png");
					}
					if (enemyvelY[3] <= -10 && enemymove[3] == 30) {
						enemypic[3] = Novice::LoadTexture("./Resources/enemyrobot3.png");
					}
					if (enemyvelY[3] <= -10 && enemymove[3] == 45) {
						enemypic[3] = Novice::LoadTexture("./Resources/enemyrobot4.png");
					}
					if (enemyvelX[3] >= 10 && enemymove[3] == 0) {
						enemybullet[3] = Novice::LoadTexture("./Resources/razor2.png");
					}
					if (enemyvelX[3] <= -10 && enemymove[3] == 0) {
						enemybullet[3] = Novice::LoadTexture("./Resources/razor2.png");
					}
					if (enemyvelY[3] >= 10 && enemymove[3] == 0) {
						enemybullet[3] = Novice::LoadTexture("./Resources/razor1.png");
					}
					if (enemyvelY[3] <= -10 && enemymove[3] == 0) {
						enemybullet[3] = Novice::LoadTexture("./Resources/razor1.png");
					}
				}
				if (enemy4==2){
					enemyX[3] += enemyvelX[3] * 2;
					enemyY[3] += enemyvelY[3] * 2;
					if (enemyvelY[3] == 0 && enemymove[3] == 0) {
						enemypic[3] = Novice::LoadTexture("./Resources/runba1.png");
					}
					if (enemyvelY[3] == 0 && enemymove[3] == 15) {
						enemypic[3] = Novice::LoadTexture("./Resources/runba2.png");
					}
					if (enemyvelY[3] == 0 && enemymove[3] == 30) {
						enemypic[3] = Novice::LoadTexture("./Resources/runbat3.png");
					}
					if (enemyvelY[3] == 0 && enemymove[3] == 45) {
						enemypic[3] = Novice::LoadTexture("./Resources/runba4.png");
					}
					if (enemyvelX[3] == 0 && enemymove[3] == 0) {
						enemypic[3] = Novice::LoadTexture("./Resources/runba1.png");
					}
					if (enemyvelX[3] == 0 && enemymove[3] == 15) {
						enemypic[3] = Novice::LoadTexture("./Resources/runba2.png");
					}
					if (enemyvelX[3] == 0 && enemymove[3] == 30) {
						enemypic[3] = Novice::LoadTexture("./Resources/runba3.png");
					}
					if (enemyvelX[3] == 0 && enemymove[3] == 45) {
						enemypic[3] = Novice::LoadTexture("./Resources/runba4.png");
					}
					
				}
			
			int enemytype5 = rand();

			if (enemycount == 4) {
			    enemy5 == enemytype5 % 3;
		    }
				if (enemy5 == 0) {
					if (enemyvelX[4] == 10 && enemymove[4] == 0) {
						enemypic[4] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelX[4] == 10 && enemymove[4] == 15) {
						enemypic[4] = Novice::LoadTexture("./Resources/ballrobot2.png");
					}
					if (enemyvelX[4] == 10 && enemymove[4] == 30) {
						enemypic[4] = Novice::LoadTexture("./Resources/ballrobot3.png");
					}
					if (enemyvelX[4] == 10 && enemymove[4] == 45) {
						enemypic[4] = Novice::LoadTexture("./Resources/ballrobot4.png");
					}
					if (enemyvelY[4] == 10 && enemymove[4] == 0) {
						enemypic[4] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelY[4] == 10 && enemymove[4] == 15) {
						enemypic[4] = Novice::LoadTexture("./Resources/ballrobot2.png");
					}
					if (enemyvelY[4] == 10 && enemymove[4] == 30) {
						enemypic[4] = Novice::LoadTexture("./Resources/ballrobot3.png");
					}
					if (enemyvelY[4] == 10 && enemymove[4] == 45) {
						enemypic[4] = Novice::LoadTexture("./Resources/ballrobot4.png");
					}
					if (enemyvelX[4] == -10 && enemymove[4] == 0) {
						enemypic[4] = Novice::LoadTexture("./Resources/ballrobot5.png");
					}
					if (enemyvelX[4] == -10 && enemymove[4] == 15) {
						enemypic[4] = Novice::LoadTexture("./Resources/ballrobot6.png");
					}
					if (enemyvelX[4] == -10 && enemymove[4] == 30) {
						enemypic[4] = Novice::LoadTexture("./Resources/ballrobot7.png");
					}
					if (enemyvelX[4] == -10 && enemymove[4] == 45) {
						enemypic[4] = Novice::LoadTexture("./Resources/ballrobot8.png");
					}
					if (enemyvelY[4] == -10 && enemymove[4] == 0) {
						enemypic[4] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelY[4] == -10 && enemymove[4] == 15) {
						enemypic[4] = Novice::LoadTexture("./Resources/ballrobot2.png");
					}
					if (enemyvelY[4] == -10 && enemymove[4] == 30) {
						enemypic[4] = Novice::LoadTexture("./Resources/ballrobot3.png");
					}
					if (enemyvelY[4] == -10 && enemymove[4] == 45) {
						enemypic[4] = Novice::LoadTexture("./Resources/ballrobot4.png");
					}
				}
				if (enemy5 == 1) {
					if (enemyvelX[4] >= 10 && enemymove[4] == 0) {
						enemypic[4] = Novice::LoadTexture("./Resources/enemyrobot1-1.png");
					}
					if (enemyvelX[4] >= 10 && enemymove[4] == 15) {
						enemypic[4] = Novice::LoadTexture("./Resources/enemyrobot1-2.png");
					}
					if (enemyvelX[4] >= 10 && enemymove[4] == 30) {
						enemypic[4] = Novice::LoadTexture("./Resources/enemyrobot1-3.png");
					}
					if (enemyvelX[4] >= 10 && enemymove[4] == 45) {
						enemypic[4] = Novice::LoadTexture("./Resources/enemyrobot1-4.png");
					}
					if (enemyvelX[4] <= -10 && enemymove[4] == 0) {
						enemypic[4] = Novice::LoadTexture("./Resources/enemyrobot2-1.png");
					}
					if (enemyvelX[4] <= -10 && enemymove[4] == 15) {
						enemypic[4] = Novice::LoadTexture("./Resourcesenemyrobot2-2.png");
					}
					if (enemyvelX[4] <= -10 && enemymove[4] == 30) {
						enemypic[4] = Novice::LoadTexture("./Resources/enemyrobot2-3.png");
					}
					if (enemyvelX[4] <= -10 && enemymove[4] == 45) {
						enemypic[4] = Novice::LoadTexture("./Resources/enemyrobot2-4.png");
					}
					if (enemyvelY[4] >= 10 && enemymove[4] == 0) {
						enemypic[4] = Novice::LoadTexture("./Resources/enemyrobot1.png");
					}
					if (enemyvelY[4] >= 10 && enemymove[4] == 15) {
						enemypic[4] = Novice::LoadTexture("./Resources/enemyrobot2.png");
					}
					if (enemyvelY[4] >= 10 && enemymove[4] == 30) {
						enemypic[4] = Novice::LoadTexture("./Resources/enemyrobot3.png");
					}
					if (enemyvelY[4] >= 10 && enemymove[4] == 45) {
						enemypic[4] = Novice::LoadTexture("./Resources/enemyrobot4.png");
					}
					if (enemyvelY[4] <= -10 && enemymove[4] == 0) {
						enemypic[4] = Novice::LoadTexture("./Resources/enemyrobot1.png");
					}
					if (enemyvelY[4] <= -10 && enemymove[4] == 15) {
						enemypic[4] = Novice::LoadTexture("./Resources/enemyrobot2.png");
					}
					if (enemyvelY[4] <= -10 && enemymove[4] == 30) {
						enemypic[4] = Novice::LoadTexture("./Resources/enemyrobot3.png");
					}
					if (enemyvelY[4] <= -10 && enemymove[4] == 45) {
						enemypic[4] = Novice::LoadTexture("./Resources/enemyrobot4.png");
					}
					if (enemyvelX[4] >= 10 && enemymove[4] == 0) {
						enemybullet[4] = Novice::LoadTexture("./Resources/razor2.png");
					}
					if (enemyvelX[4] <= -10 && enemymove[4] == 0) {
						enemybullet[4] = Novice::LoadTexture("./Resources/razor2.png");
					}
					if (enemyvelY[4] >= 10 && enemymove[4] == 0) {
						enemybullet[4] = Novice::LoadTexture("./Resources/razor1.png");
					}
					if (enemyvelY[4] <= -10 && enemymove[4] == 0) {
						enemybullet[4] = Novice::LoadTexture("./Resources/razor1.png");
					}
				}
				if (enemy5==2){
					enemyX[4]+=enemyvelX[4] * 2;
					enemyY[4]+=enemyvelY[4] * 2;
					if (enemyvelY[4] == 0 && enemymove[4] == 0) {
						enemypic[4] = Novice::LoadTexture("./Resources/runba1.png");
					}
					if (enemyvelY[4] == 0 && enemymove[4] == 15) {
						enemypic[4] = Novice::LoadTexture("./Resources/runba2.png");
					}
					if (enemyvelY[4] == 0 && enemymove[4] == 30) {
						enemypic[4] = Novice::LoadTexture("./Resources/runbat3.png");
					}
					if (enemyvelY[4] == 0 && enemymove[4] == 45) {
						enemypic[4] = Novice::LoadTexture("./Resources/runba4.png");
					}
					if (enemyvelX[4] == 0 && enemymove[4] == 0) {
						enemypic[4] = Novice::LoadTexture("./Resources/runba1.png");
					}
					if (enemyvelX[4] == 0 && enemymove[4] == 15) {
						enemypic[4] = Novice::LoadTexture("./Resources/runba2.png");
					}
					if (enemyvelX[4] == 0 && enemymove[4] == 30) {
						enemypic[4] = Novice::LoadTexture("./Resources/runba3.png");
					}
					if (enemyvelX[4] == 0 && enemymove[4] == 45) {
						enemypic[4] = Novice::LoadTexture("./Resources/runba4.png");
					}
				
				}
			
			int enemytype6 = rand();

			if (enemycount == 5) {
			    enemy6 == enemytype6 % 3;
		    }
				if (enemy6 == 0) {
					if (enemyvelX[5] >= 10 && enemymove[5] == 0) {
						enemypic[5] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelX[5] >= 10 && enemymove[5] == 15) {
						enemypic[5] = Novice::LoadTexture("./Resources/ballrobot2.png");
					}
					if (enemyvelX[5] >= 10 && enemymove[5] == 30) {
						enemypic[5] = Novice::LoadTexture("./Resources/ballrobot3.png");
					}
					if (enemyvelX[5] >= 10 && enemymove[5] == 45) {
						enemypic[5] = Novice::LoadTexture("./Resources/ballrobot4.png");
					}
					if (enemyvelY[5] >= 10 && enemymove[5] == 0) {
						enemypic[5] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelY[5] >= 10 && enemymove[5] == 15) {
						enemypic[5] = Novice::LoadTexture("./Resources/ballrobot2.png");
					}
					if (enemyvelY[5] >= 10 && enemymove[5] == 30) {
						enemypic[5] = Novice::LoadTexture("./Resources/ballrobot3.png");
					}
					if (enemyvelY[5] >= 10 && enemymove[5] == 45) {
						enemypic[5] = Novice::LoadTexture("./Resources/ballrobot4.png");
					}
					if (enemyvelX[5] <= -10 && enemymove[5] == 0) {
						enemypic[5] = Novice::LoadTexture("./Resources/ballrobot5.png");
					}
					if (enemyvelX[5] <= -10 && enemymove[5] == 15) {
						enemypic[5] = Novice::LoadTexture("./Resources/ballrobot6.png");
					}
					if (enemyvelX[5] <= -10 && enemymove[5] == 30) {
						enemypic[5] = Novice::LoadTexture("./Resources/ballrobot7.png");
					}
					if (enemyvelX[5] <= -10 && enemymove[5] == 45) {
						enemypic[5] = Novice::LoadTexture("./Resources/ballrobot8.png");
					}
					if (enemyvelY[5] <= -10 && enemymove[5] == 0) {
						enemypic[5] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelY[5] <= -10 && enemymove[5] == 15) {
						enemypic[5] = Novice::LoadTexture("./Resources/ballrobot2.png");
					}
					if (enemyvelY[5] <= -10 && enemymove[5] == 30) {
						enemypic[5] = Novice::LoadTexture("./Resources/ballrobot3.png");
					}
					if (enemyvelY[5] <= -10 && enemymove[5] == 45) {
						enemypic[5] = Novice::LoadTexture("./Resources/ballrobot4.png");
					}
				}
				if (enemy6 == 1) {
					if (enemyvelX[5] >= 10 && enemymove[5] == 0) {
						enemypic[5] = Novice::LoadTexture("./Resources/enemyrobot1-1.png");
					}
					if (enemyvelX[5] >= 10 && enemymove[5] == 15) {
						enemypic[5] = Novice::LoadTexture("./Resources/enemyrobot1-2.png");
					}
					if (enemyvelX[5] >= 10 && enemymove[5] == 30) {
						enemypic[5] = Novice::LoadTexture("./Resources/enemyrobot1-3.png");
					}
					if (enemyvelX[5] >= 10 && enemymove[5] == 45) {
						enemypic[5] = Novice::LoadTexture("./Resources/enemyrobot1-4.png");
					}
					if (enemyvelX[5] <= -10 && enemymove[5] == 0) {
						enemypic[5] = Novice::LoadTexture("./Resources/enemyrobot2-1.png");
					}
					if (enemyvelX[5] <= -10 && enemymove[5] == 15) {
						enemypic[5] = Novice::LoadTexture("./Resourcesenemyrobot2-2.png");
					}
					if (enemyvelX[5] <= -10 && enemymove[5] == 30) {
						enemypic[5] = Novice::LoadTexture("./Resources/enemyrobot2-3.png");
					}
					if (enemyvelX[5] <= -10 && enemymove[5] == 45) {
						enemypic[5] = Novice::LoadTexture("./Resources/enemyrobot2-4.png");
					}
					if (enemyvelY[5] >= 10 && enemymove[5] == 0) {
						enemypic[5] = Novice::LoadTexture("./Resources/enemyrobot1.png");
					}
					if (enemyvelY[5] >= 10 && enemymove[5] == 15) {
						enemypic[5] = Novice::LoadTexture("./Resources/enemyrobot2.png");
					}
					if (enemyvelY[5] >= 10 && enemymove[5] == 30) {
						enemypic[5] = Novice::LoadTexture("./Resources/enemyrobot3.png");
					}
					if (enemyvelY[5] >= 10 && enemymove[5] == 45) {
						enemypic[5] = Novice::LoadTexture("./Resources/enemyrobot4.png");
					}
					if (enemyvelY[5] <= -10 && enemymove[5] == 0) {
						enemypic[5] = Novice::LoadTexture("./Resources/enemyrobot1.png");
					}
					if (enemyvelY[5] <= -10 && enemymove[5] == 15) {
						enemypic[5] = Novice::LoadTexture("./Resources/enemyrobot2.png");
					}
					if (enemyvelY[5] <= -10 && enemymove[5] == 30) {
						enemypic[5] = Novice::LoadTexture("./Resources/enemyrobot3.png");
					}
					if (enemyvelY[5] <= -10 && enemymove[5] == 45) {
						enemypic[5] = Novice::LoadTexture("./Resources/enemyrobot4.png");
					}
					if (enemyvelX[5] >= 10 && enemymove[5] == 0) {
						enemybullet[5] = Novice::LoadTexture("./Resources/razor2.png");
					}
					if (enemyvelX[5] <= -10 && enemymove[5] == 0) {
						enemybullet[5] = Novice::LoadTexture("./Resources/razor2.png");
					}
					if (enemyvelY[5] >= 10 && enemymove[5] == 0) {
						enemybullet[5] = Novice::LoadTexture("./Resources/razor1.png");
					}
					if (enemyvelY[5] <= -10 && enemymove[5] == 0) {
						enemybullet[5] = Novice::LoadTexture("./Resources/razor1.png");
					}
				}
				if (enemy6==2){
					enemyX[5]+=enemyvelX[5] * 2;
					enemyY[5]+=enemyvelY[5] * 2;
					if (enemyvelY[5] == 0 && enemymove[5] == 0) {
						enemypic[5] = Novice::LoadTexture("./Resources/runba1.png");
					}
					if (enemyvelY[5] == 0 && enemymove[5] == 15) {
						enemypic[5] = Novice::LoadTexture("./Resources/runba2.png");
					}
					if (enemyvelY[5] == 0 && enemymove[5] == 30) {
						enemypic[5] = Novice::LoadTexture("./Resources/runbat3.png");
					}
					if (enemyvelY[5] == 0 && enemymove[5] == 45) {
						enemypic[5] = Novice::LoadTexture("./Resources/runba4.png");
					}
					if (enemyvelX[5] == 0 && enemymove[5] == 0) {
						enemypic[5] = Novice::LoadTexture("./Resources/runba1.png");
					}
					if (enemyvelX[5] == 0 && enemymove[5] == 15) {
						enemypic[5] = Novice::LoadTexture("./Resources/runba2.png");
					}
					if (enemyvelX[5] == 0 && enemymove[5] == 30) {
						enemypic[5] = Novice::LoadTexture("./Resources/runba3.png");
					}
					if (enemyvelX[5] == 0 && enemymove[5] == 45) {
						enemypic[5] = Novice::LoadTexture("./Resources/runba4.png");
					}
				}
			
		
		
			///  if(playerlife==0){
			///   jikipic = Novice::LoadTexture("./gamepicture/whale.png");
			///  }
			
		//敵の移動
		
		//敵の反射移動
		if (enemyvelX[enemycount] >= 10 && enemyX[enemycount] >= 875) {
			        enemyvelX[enemycount] = enemyvelX[enemycount] * -1;
		}
		if (enemyvelX[enemycount] <= -10 && enemyX[enemycount] <= 0) {
			enemyvelX[enemycount] = enemyvelX[enemycount] * -1;
		}
		if (enemyvelY[enemycount] >= 10 && enemyY[enemycount] >= 700) {
			enemyvelY[enemycount] = enemyvelY[enemycount] * -1;
		}
		if (enemyvelY[enemycount] <= -10 && enemyY[enemycount] <= 0) {
			enemyvelY[enemycount] = enemyvelY[enemycount] * -1;
		}

		if (enemymove[enemycount] == 60) {
			enemymove[enemycount] = 0;
		}
			enemymove[enemycount]+=1;

		    if (enemymove[enemycount] == 0) {
			    razorX[enemycount] = enemyvelX[enemycount] * 1.5;
			    razorY[enemycount] = enemyvelY[enemycount] * 1.5;
		    }
		    if (enemymove[enemycount] >= 1 && enemymove[enemycount] <= 50) {
			    razorX[enemycount]++;
			    razorY[enemycount]++;
		    }
			
		    if (repopcooltime == 60) {
			    repopcooltime = 0;
			    
		    }
			   
		        if (bustered % 10+1 == 10&&enemycooltime==59) {
			     enemyvelX[enemycount] = enemyvelX[enemycount] * 1.1;
			     enemyvelY[enemycount] = enemyvelY[enemycount] * 1.1;
		        }
		    
		        enemyX[0] = enemyX[0] + enemyvelX[0];
		        enemyY[0] = enemyY[0] + enemyvelY[0];
				 enemyX[1] = enemyX[1] + enemyvelX[1];
		       enemyY[1] = enemyY[1] + enemyvelY[1];
				enemyX[2] = enemyX[2] + enemyvelX[2];
		        enemyY[2] = enemyY[2] + enemyvelY[2];
		         enemyX[3] = enemyX[3] + enemyvelX[3];
		        enemyY[3] = enemyY[3] + enemyvelY[3];
		       enemyX[4] = enemyX[4] + enemyvelX[4];
		        enemyY[4] = enemyY[4] + enemyvelY[4];
		        enemyX[5] = enemyX[5] + enemyvelX[5];
		        enemyY[5] = enemyY[5] + enemyvelY[5];
		       */ 
		       

		jikiX += jikivelx;
		jikiY += jikively;
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		//Novice::DrawSprite(0, 0, haikei, 1, 1, 0.0f, 0xFFFFFFFF);

		//Novice::ScreenPrintf(10, 10, "movecount=%d", movecount);
		//Novice::ScreenPrintf(10, 30, "movetime=%d", movetime);
		//Novice::ScreenPrintf(10, 50, "enemyX=%f", enemyX[0] );
		//Novice::ScreenPrintf(10, 70, "enemyY=%f", enemyY[0]);
		//Novice::ScreenPrintf(10, 90, "enemyvelX=%f", enemyvelX[0]);
		//Novice::ScreenPrintf(10, 110, "enemyvelY=%f", enemyvelY[0]);
		//Novice::ScreenPrintf(10, 130, "enemycooltime=%d", enemycooltime);
		//Novice::ScreenPrintf(10, 150, "enemycount=%d", enemycount);

		
		for (int x = 0; x < mapX; x++) {
			for (int y = 0; y < mapY; y++) {
				if (map[y][x] == 0) {
					Novice::DrawBox(
					  x * mapsize, y * mapsize, mapsize, mapsize, 0.0f, BLACK, kFillModeSolid);
				}
				if (map[y][x] == 2) {
					Novice::DrawBox(
					  x * mapsize, y * mapsize, mapsize, mapsize, 0.0f, WHITE, kFillModeSolid);
				}
				
			}
		}
		

		
			Novice::DrawBox(jikiX, jikiY, 40, 40, 0.0f, RED, kFillModeSolid);
		

		 
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
