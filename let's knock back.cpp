#include <Novice.h>
#define _USE_MATH_DEFINES
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

const char kWindowTitle[] = "LET'S KNOCK BACK! ";



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	int jikipic = Novice::LoadTexture("./Resources/jiki1-1.png");
	int title = Novice::LoadTexture("./Resources/title.png");
	int bullet = Novice::LoadTexture("./Resources/bullet1-1.png");
	int jikideath = Novice::LoadTexture("./Resources/jikideath.png");
	int haikei = Novice::LoadTexture("./Resources/haikei.png");
	int sousahou = Novice::LoadTexture("./Resources/sousahou.png");
	int color = 0;
	int scene = 0;
	int sceneboxX[7] = {1280, 0, 1280, 0, 1280, 0};
	int sceneboxvel[7] = {-25, 25, -25, 25, -25, 25};
	int startstaytime = 0;
	float jikiX = 435;
	float jikiY = 325;
	int movecount = 0;
	int movetime = 0;
	int staytime = 0;
	int bulletX = -720;
	int bulletY = -720;
	int bulvelX = 0;
	int bulvelY = 0;
	float enemyX[7] = {1280,1280,1280,1280,1280,1280};
	float enemyY[7] = {1280,1280,12801280,1280,1280};
	int enemyLife[7] = {1, 1, 1, 1, 1, 1};
	int enemymove[7] = {0};
	int playerlife = 2;
	float enemyvelX[7] = {0};
	float enemyvelY[7] = {0};
	int enemyflag[6] = {0};
	float runbavelX = 0;
	float runbavelY = 0;
	int enemycount = 0;
	int enemypop = 0;
	int enemycooltime = 0;
	int repopcooltime[7] = {0};
	int enemybullet[7] = {0};
	float razorX[7] = {-100, -100, -100, -100, -100, -100};
	float razorY[7] = {-100, -100, -100, -100, -100, -100};
	float razorvelX[7] = {0};
	float razorvelY[7] = {0};
	int modX = 0;
	int modY = 0;
	int score = 0;
	int scoreY=-50;
	int bustered = 0;
	int enemypic[7] = {0};
	float jikihitX = 0;
	float jikihitY = 0;
	float bulhitX = 0;
	float bulhitY = 0;
	float enemyhitX[7] = {25000, 25000, 25000, 25000, 25000, 25000, 25000};
	float enemyhitY[7] = {25000, 25000, 25000, 25000, 25000, 25000, 25000};
	float razorhitX[7] = {25000, 25000, 25000, 25000, 25000, 25000, 25000};
	float razorhitY[7] = {25000, 25000, 25000, 25000, 25000, 25000, 25000};
	float DISTbulX[7] = {25000, 25000, 25000, 25000, 25000, 25000, 25000};
	float DISTeneX[7] = {25000, 25000, 25000, 25000, 25000, 25000, 25000}; 
	float DISTrazX[7] = {25000, 25000, 25000, 25000, 25000, 25000, 25000};
	float DISTbulY[7] = {25000, 25000, 25000, 25000, 25000, 25000, 25000};
	float DISTeneY[7] = {25000, 25000, 25000, 25000, 25000, 25000, 25000};
	float DISTrazY[7] = {25000, 25000, 25000, 25000, 25000, 25000, 25000};
	int enemy1[7] = {0};
	int boxY = -720;
	int boxYvel = 20;
	int enemyappare = 0;
	int entersound = Novice::LoadAudio("./Sounds/enter.wav");
	int gunsound = Novice::LoadAudio("./Sounds/shot.wav");
	int enter2sound = Novice::LoadAudio("./Sounds/enter2.wav");
	int killsound = Novice::LoadAudio("./Sounds/killsound.wav");
	int deathsound = Novice::LoadAudio("./Sounds/deathsound.wav");
	int enter3sound = Novice::LoadAudio("./Sounds/enter3.wav");
	int datasound = Novice::LoadAudio("./Sounds/data.wav");
	int BGM = Novice::LoadAudio("./Sounds/normalBGM.wav");
	int battleBGM = Novice::LoadAudio("./Sounds/battleBGM.wav");
	int playsound[10]{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	unsigned int currentTime = time(nullptr);
	srand(currentTime);

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

		// スタート画面

		if (keys[DIK_SPACE] && scene == 0) {
			scene = 1;
		}
		if (scene == 1) {
			startstaytime += 1;
			if (startstaytime >= 30) {
				sceneboxX[0] += sceneboxvel[0];
				sceneboxX[1] += sceneboxvel[1];
				sceneboxX[2] += sceneboxvel[2];
				sceneboxX[3] += sceneboxvel[3];
				sceneboxX[4] += sceneboxvel[4];
				sceneboxX[5] += sceneboxvel[5];
			}
		}

		if (playerlife < 0) {
			playerlife = 3;
		}
		if (startstaytime == 200 && playerlife == 2) {
			playerlife += -1;
			scene = 2;
		}
		//ゲーム画面
		bulvelX = 0;
		bulvelY = 0;
		if (playerlife == 1) {

			staytime += 1;
			if (staytime == 60) {
				staytime = 0;
			}
			if (movecount == 0) {
				bulletX = -720;
				bulletY = -720;
			}
			
			if (keys[DIK_D] && movecount == 0) {
				movecount = 1;
				bulletX = jikiX + 51;
				bulletY = jikiY + 1;
		        jikiX = jikiX + 100;
			}
			if (keys[DIK_A] && movecount == 0) {
				movecount = 2;
				bulletX = jikiX + 51;
				bulletY = jikiY + 1;
				jikiX = jikiX - 100;
			}
			if (keys[DIK_S] && movecount == 0) {
				movecount = 3;
				bulletX = jikiX + 1;
				bulletY = jikiY + 51;
				jikiY = jikiY + 100;
			}
			if (keys[DIK_W] && movecount == 0) {
				movecount = 4;
				bulletX = jikiX + 1;
				bulletY = jikiY + 51;
				jikiY = jikiY - 100;
			}
			if (keys[DIK_RIGHT] && movecount == 0) {
				movecount = 1;
				jikiX = jikiX + 100;
				bulletX = jikiX + 51;
				bulletY = jikiY + 1;
			}
			if (keys[DIK_LEFT] && movecount == 0) {
				movecount = 2;
				jikiX = jikiX - 100;
				bulletX = jikiX + 51;
				bulletY = jikiY + 1;
			}
			if (keys[DIK_DOWN] && movecount == 0) {
				movecount = 3;
				jikiY = jikiY + 100;
				bulletX = jikiX + 1;
				bulletY = jikiY + 51;
			}
			if (keys[DIK_UP] && movecount == 0) {
				movecount = 4;
				jikiY = jikiY - 100;
				bulletX = jikiX + 1;
				bulletY = jikiY + 51;
			}
			if (movecount > 0) {
				movetime += 1;
			}
			if (movetime == 20) {
				movecount = 0;
				movetime = 0;
			}
			if (movecount == 0) {
				bulletX = jikiX;
				bulletY = jikiY;
			}
			if (movecount == 1) {
				bulvelX = -20;
				bulletX += bulvelX;
				bulletY += bulvelY;
				bullet = Novice::LoadTexture("./Resources/bullet1-2.png");
			}
			if (movecount == 2) {
				bulvelX = 20;
				bulletX += bulvelX;
				bulletY += bulvelY;
				bullet = Novice::LoadTexture("./Resources/bullet1-1.png");
			}
			if (movecount == 3) {
				bulvelY = -20;
				bulletX += bulvelX;
				bulletY += bulvelY;
				bullet = Novice::LoadTexture("./Resources/bullet1-3.png");
			}
			if (movecount == 4) {
				bulvelY = 20;
				bulletX += bulvelX;
				bulletY += bulvelY;
				bullet = Novice::LoadTexture("./Resources/bullet1-4.png");
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
			}

			if (jikiX <= 35) {
				jikiX = 35;
			}
			if (jikiX >= 835) {
				jikiX = 835;
			}
			if (jikiY <= 25) {
				jikiY = 25;
			}
			if (jikiY >= 625) {
				jikiY = 625;
			}
			jikihitX = jikiX + 32;
			jikihitY = jikiY - 32;
			bulhitX = bulletX + 16;
			bulhitY = bulletY - 16;
			//ここまで自機の関連----------------------------------------------------------

			//ここから敵*******************************************************************
			if (enemycooltime < 60) {
				enemycooltime++;
			}

			if (enemycooltime == 60) {
				enemypop++;
				enemycooltime = 0;
			}
			if (enemypop == 7) {
				enemypop = 6;
			}
			if (enemypop == 6 && enemyflag[0] + enemyflag[1] + enemyflag[2] + enemyflag[3] + enemyflag[4] + enemyflag[5]  == 6) {
			 enemypop = 0;
			 enemyflag[0] = 0;
			 enemyflag[1] = 0;
			 enemyflag[2] = 0;
			 enemyflag[3] = 0;
			 enemyflag[4] = 0;
			 enemyflag[5] = 0;
			}
			
			if (scene >= 2) {

				//ランダムのやつで敵の配置
				if (enemypop < 6 && enemycooltime == 59) {
					int numX = rand();
					enemyLife[0] = 1;
					enemyLife[1] = 1;
					enemyLife[2] = 1;
					enemyLife[3] = 1;
					enemyLife[4] = 1;
					enemyLife[5] = 1;
					modX = numX % 9 + 1;
					if (modX == 1) {
						enemyX[enemypop] = 50;
					}
					if (modX == 2) {
						enemyX[enemypop] = 150;
					}
					if (modX == 3) {
						enemyX[enemypop] = 250;
					}
					if (modX == 4) {
						enemyX[enemypop] = 350;
					}
					if (modX == 5) {
						enemyX[enemypop] = 450;
					}
					if (modX == 6) {
						enemyX[enemypop] = 550;
					}
					if (modX == 7) {
						enemyX[enemypop] = 650;
					}
					if (modX == 8) {
						enemyX[enemypop] = 750;
					}
					if (modX == 9) {
						enemyX[enemypop] = 850;
					}

					int numY = rand();
					modY = numY % 7 + 1;
					if (modY == 1) {
						enemyY[enemypop] = 45;
					}
					if (modY == 2) {
						enemyY[enemypop] = 145;
					}
					if (modY == 3) {
						enemyY[enemypop] = 245;
					}
					if (modY == 4) {
						enemyY[enemypop] = 345;
					}
					if (modY == 5) {
						enemyY[enemypop] = 445;
					}
					if (modY == 6) {
						enemyY[enemypop] = 545;
					}
					if (modY == 7) {
						enemyY[enemypop] = 645;
					}
					//敵を端に配置＆移動
					int enemyrepop = rand();
					enemyappare = enemyrepop % 4 + 1;
					if (enemyappare == 1) {
						enemyvelX[enemypop] = -3.0f;
						enemyvelY[enemypop] = 0;
					}
					if (enemyappare == 2) {
						enemyvelX[enemypop] = 3.0f;
						enemyvelY[enemypop] = 0;
					}
					if (enemyappare == 3) {
						enemyvelX[enemypop] = 0;
						enemyvelY[enemypop] = 3.0f;
					}
					if (enemyappare == 4) {
						enemyvelX[enemypop] = 0;
						enemyvelY[enemypop] = -3.0f;
					}
					if (enemypop == 0) {
						if (enemyappare == 1) {
							enemyX[0] = 915;
						}
						if (enemyappare == 2) {
							enemyX[0] = -20;
						}
						if (enemyappare == 3) {
							enemyY[0] = -20;
						}
						if (enemyappare == 4) {
							enemyY[0] = 720;
						}
					}
					if (enemypop == 1) {
						if (enemyappare == 1) {
							enemyX[1] = 915;
						}
						if (enemyappare == 2) {
							enemyX[1] = -20;
						}
						if (enemyappare == 3) {
							enemyY[1] = -20;
						}
						if (enemyappare == 4) {
							enemyY[1] = 720;
						}
					}
					if (enemypop == 2) {
						if (enemyappare == 1) {
							enemyX[2] = 915;
						}
						if (enemyappare == 2) {
							enemyX[2] = -20;
						}
						if (enemyappare == 3) {
							enemyY[2] = -20;
						}
						if (enemyappare == 4) {
							enemyY[2] = 720;
						}
					}
					if (enemypop == 3) {
						if (enemyappare == 1) {
							enemyX[3] = 915;

							if (enemyappare == 2) {
								enemyX[3] = -20;
							}
							if (enemyappare == 3) {
								enemyY[3] = -20;
							}
							if (enemyappare == 4) {
								enemyY[3] = 720;
							}
						}
						if (enemypop == 4) {
							if (enemyappare == 1) {
								enemyX[4] = 915;
							}
							if (enemyappare == 2) {
								enemyX[4] = -20;
							}
							if (enemyappare == 3) {
								enemyY[4] = -20;
							}
							if (enemyappare == 4) {
								enemyY[4] = 720;
							}
						}
						if (enemypop == 5) {
							if (enemyappare == 1) {
								enemyX[5] = 915;
							}
							if (enemyappare == 2) {
								enemyX[5] = -20;
							}
							if (enemyappare == 3) {
								enemyY[5] = -20;
							}
							if (enemyappare == 4) {
								enemyY[5] = 720;
							}
						}
					}
					int enemytype1 = rand();
					enemy1[enemypop] = enemytype1 % 3 + 1;
					
				}
				//-------------------------------------------------------------------------------------------------------------
				enemycount = 0;
				while (enemycount < enemypop) {
					if (repopcooltime[enemycount] >= 60) {
						repopcooltime[enemycount] = 0;
						repopcooltime[enemycount] += 0;
					}
					if (enemy1[enemypop] == 2 && enemypop == enemycount) {
						enemyLife[enemypop] = 2;
					}
					//敵の移動

					//敵の反射移動
					if (enemyvelX[enemycount] > 0 && enemyX[enemycount] >= 850) {
						enemyvelX[enemycount] = -1 * enemyvelX[enemycount];
						enemyvelY[enemycount] = 0;
					}
					if (enemyvelX[enemycount] < 0 && enemyX[enemycount] <= 50) {
						enemyvelX[enemycount] = -1 * enemyvelX[enemycount];
						enemyvelY[enemycount] = 0;
					}
					if (enemyvelY[enemycount] > 0 && enemyY[enemycount] >= 645) {
						enemyvelY[enemycount] = -1 * enemyvelY[enemycount];
						enemyvelX[enemycount] = 0;
					}
					if (enemyvelY[enemycount] < 0 && enemyY[enemycount] <= 45) {
						enemyvelY[enemycount] = -1 * enemyvelY[enemycount];
						enemyvelX[enemycount] = 0;
					}
					if (enemy1[enemycount] == 2) {
					
					 if (enemymove[enemycount] == 0) {
						razorvelX[enemycount] = enemyvelX[enemycount] * 1.5;
						razorvelY[enemycount] = enemyvelY[enemycount] * 1.5;
					 }
					 if (enemymove[enemycount] >= 1 && enemymove[enemycount] <= 50) {
						razorvelX[enemycount] += razorX[enemycount];
						razorvelY[enemycount] += razorY[enemycount];
					 }
					  razorX[enemycount] += razorvelX[enemycount];
					  razorY[enemycount] += razorvelY[enemycount];
				    }
					if (bustered % 10 + 1 == 10 && enemycooltime == 59) {
						enemyvelX[enemycount] += enemyvelX[enemycount] * 0.1;
						enemyvelY[enemycount] += enemyvelY[enemycount] * 0.1;
					}

					enemymove[enemycount] += 1;
					if (enemymove[enemycount] == 60) {
						enemymove[enemycount] = 0;
					}
					//当たり判定　四角の中心点同士の距離で判定
				 if (enemyLife[enemycount] >= 1) {
				  enemyhitX[enemycount] = enemyX[enemycount] + 16;
				  enemyhitY[enemycount] = enemyY[enemycount] - 16;

				  DISTbulX[enemycount] = enemyhitX[enemycount] - bulhitX;
				  DISTeneX[enemycount] = enemyhitX[enemycount] - jikihitX;
				  DISTbulY[enemycount] = enemyhitY[enemycount] - bulhitY;
				  DISTeneY[enemycount] = enemyhitY[enemycount] - jikihitY;
					 if(enemy1[enemycount] == 2){
					  enemyhitX[enemycount] = enemyX[enemycount] + 32;
					  enemyhitY[enemycount] = enemyY[enemycount] - 32;
					 }				
                    if(DISTeneX[enemycount] <= 32 && DISTeneX[enemycount] >= -32 &&
					  DISTeneY[enemycount] <= 32 && DISTeneY[enemycount] >= -32) {
						playerlife = 0;
					}
					
					if(DISTbulX[enemycount] <= 24 && DISTbulX[enemycount] >= -24 &&
					  DISTbulY[enemycount] <= 24 && DISTbulY[enemycount] >= -24) {
						enemyLife[enemycount] = enemyLife[enemycount] - 1;
						bulletX = -720;
						bulletY = -720;
						bulvelX = 0;
						bulvelY = 0;
						if (enemyLife[enemycount] == 0) {
						 enemyflag[enemycount] = 1;
						 bustered += 1;
						 score += 100;
						 playsound[9] = -1;
					    }					 
					} 
                 }
					//敵の描写

					if (enemycount <= 6 && scene >= 2 && enemyLife[enemycount] >= 1) {
						if (enemy1[enemycount] == 1) {
							if (
							  enemyvelX[enemycount] > 0 && enemymove[enemycount] >= 0 &&
							  enemymove[enemycount] <= 14) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/ballrobot1.png");
							}
							if (
							  enemyvelX[enemycount] > 0 && enemymove[enemycount] >= 15 &&
							  enemymove[enemycount] <= 29) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/ballrobot2.png");
							}
							if (
							  enemyvelX[enemycount] > 0 && enemymove[enemycount] >= 30 &&
							  enemymove[enemycount] <= 44) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/ballrobot3.png");
							}
							if (
							  enemyvelX[enemycount] > 0 && enemymove[enemycount] >= 45 &&
							  enemymove[enemycount] <= 59) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/ballrobot4.png");
							}
							if (
							  enemyvelY[enemycount] > 0 && enemymove[enemycount] >= 0 &&
							  enemymove[enemycount] <= 14) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/ball1-1.png");
							}
							if (
							  enemyvelY[enemycount] > 0 && enemymove[enemycount] >= 15 &&
							  enemymove[enemycount] <= 29) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/ball1-2.png");
							}
							if (
							  enemyvelY[enemycount] > 0 && enemymove[enemycount] >= 30 &&
							  enemymove[enemycount] <= 44) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/ball1-3.png");
							}
							if (
							  enemyvelY[enemycount] > 0 && enemymove[enemycount] >= 45 &&
							  enemymove[enemycount] <= 59) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/ball1-4.png");
							}
							if (
							  enemyvelX[enemycount] < 0 && enemymove[enemycount] >= 0 &&
							  enemymove[enemycount] <= 14) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/ballrobot5.png");
							}
							if (enemyvelX[enemycount] < 0 && enemymove[enemycount] >= 15 &&
							  enemymove[enemycount] <= 29) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/ballrobot6.png");
							  
							}
							if (
							  enemyvelX[enemycount] < 0 && enemymove[enemycount] >= 30 &&
							  enemymove[enemycount] <= 44) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/ballrobot7.png");
							}
							if (
							  enemyvelX[enemycount] < 0 && enemymove[enemycount] >= 45 &&
							  enemymove[enemycount] <= 59) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/ballrobot8.png");
							}
							if (
							  enemyvelY[enemycount] < 0 && enemymove[enemycount] >= 0 &&
							  enemymove[enemycount] <= 14) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/ball1-5.png");
							}
							if (
							  enemyvelY[enemycount] < 0 && enemymove[enemycount] >= 15 &&
							  enemymove[enemycount] <= 29) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/ball1-6.png");
							}
							if (
							  enemyvelY[enemycount] < 0 && enemymove[enemycount] >= 30 &&
							  enemymove[enemycount] <= 44) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/ball1-5.png");
							}
							if (
							  enemyvelY[enemycount] < 0 && enemymove[enemycount] >= 45 &&
							  enemymove[enemycount] <= 59) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/ball1-6.png");
							}
						}
						  if (enemy1[enemycount] == 2) {
							if (
							  enemyvelX[enemycount] > 0 && enemymove[enemycount] >= 0 &&
							  enemymove[enemycount] <= 14) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/enemyrobot1-1.png");
							}
							if (
							  enemyvelX[enemycount] > 0 && enemymove[enemycount] >= 15 &&
							  enemymove[enemycount] <= 29) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/enemyrobot1-2.png");
							}
							if (
							  enemyvelX[enemycount] > 0 && enemymove[enemycount] >= 30 &&
							  enemymove[enemycount] <= 44) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/enemyrobot1-3.png");
							}
							if (
							  enemyvelX[enemycount] > 0 && enemymove[enemycount] >= 45 &&
							  enemymove[enemycount] <= 59) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/enemyrobot1-4.png");
							}
							if (
							  enemyvelX[enemycount] < 0 && enemymove[enemycount] >= 0 &&
							  enemymove[enemycount] <= 14) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/enemyrobot2-5.png");
							}
							if (
							  enemyvelX[enemycount] < 0 && enemymove[enemycount] >= 15 &&
							  enemymove[enemycount] <= 29) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/enemyrobot2-2.png");
							}
							if (
							  enemyvelX[enemycount] < 0 && enemymove[enemycount] >= 30 &&
							  enemymove[enemycount] <= 44) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/enemyrobot2-3.png");
							}
							if (
							  enemyvelX[enemycount] < 0 && enemymove[enemycount] >= 45 &&
							  enemymove[enemycount] <= 59) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/enemyrobot2-4.png");
							}
							if (
							  enemyvelY[enemycount] > 0 && enemymove[enemycount] >= 0 &&
							  enemymove[enemycount] <= 14) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/enemyrobot1.png");
							}
							if (
							  enemyvelY[enemycount] > 0 && enemymove[enemycount] >= 15 &&
							  enemymove[enemycount] <= 29) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/enemyrobot2.png");
							}
							if (
							  enemyvelY[enemycount] > 0 && enemymove[enemycount] >= 30 &&
							  enemymove[enemycount] <= 44) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/enemyrobot3.png");
							}
							if (
							  enemyvelY[enemycount] > 0 && enemymove[enemycount] >= 45 &&
							  enemymove[enemycount] <= 59) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/enemyrobot4.png");
							}
							if (
							  enemyvelY[enemycount] < 0 && enemymove[enemycount] >= 0 &&
							  enemymove[enemycount] <= 14) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/enemyrobot4-2.png");
							}
							if (
							  enemyvelY[enemycount] < 0 && enemymove[enemycount] >= 15 &&
							  enemymove[enemycount] <= 29) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/enemyrobot4-3.png");
							}
							if (
							  enemyvelY[enemycount] < 0 && enemymove[enemycount] >= 30 &&
							  enemymove[enemycount] <= 44) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/enemyrobot4-4.png");
							}
							if (
							  enemyvelY[enemycount] < 0 && enemymove[enemycount] >= 45 &&
							  enemymove[enemycount] <= 59) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/enemyrobot4-5.png");
							}
							
						  }
						if (enemy1[enemycount] == 3) {
							enemyX[enemycount] += enemyvelX[enemycount] * 2;
							enemyY[enemycount] += enemyvelY[enemycount] * 2;
							if (
							  enemyvelY[enemycount] == 0 && enemymove[enemycount] >= 0 &&
							  enemymove[enemycount] <= 14) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/runba1.png");
							}
							if (
							  enemyvelY[enemycount] == 0 && enemymove[enemycount] >= 15 &&
							  enemymove[enemycount] <= 29) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/runba2.png");
							}
							if (
							  enemyvelY[enemycount] == 0 && enemymove[enemycount] >= 30 &&
							  enemymove[enemycount] <= 44) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/runba3.png");
							}
							if (
							  enemyvelY[enemycount] == 0 && enemymove[enemycount] >= 45 &&
							  enemymove[enemycount] <= 60) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/runba4.png");
							}
							if (
							  enemyvelX[enemycount] == 0 && enemymove[enemycount] >= 0 &&
							  enemymove[enemycount] <= 14) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/runba1.png");
							}
							if (
							  enemyvelX[enemycount] == 0 && enemymove[enemycount] >= 15 &&
							  enemymove[enemycount] <= 29) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/runba2.png");
							}
							if (
							  enemyvelX[enemycount] == 0 && enemymove[enemycount] >= 30 &&
							  enemymove[enemycount] <= 44) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/runba3.png");
							}
							if (
							  enemyvelX[enemycount] == 0 && enemymove[enemycount] >= 45 &&
							  enemymove[enemycount] <= 59) {
								enemypic[enemycount] =
								  Novice::LoadTexture("./Resources/runba4.png");
							}
						}
					}
					enemyX[enemycount] = enemyX[enemycount] + enemyvelX[enemycount];
					enemyY[enemycount] = enemyY[enemycount] + enemyvelY[enemycount];

					if (enemyLife[enemycount] == 0) {
						enemypic[enemycount] = 0;
						enemypic[enemycount] = Novice::LoadTexture("./Resources/Explosion1.png");
						repopcooltime[enemycount] += 1;
						enemymove[enemycount] = 0;
						enemyvelX[enemycount] = 0;
						enemyvelY[enemycount] = 0;
						
						if (enemyLife[enemycount] == 0 && repopcooltime[enemycount] >= 10 &&repopcooltime[enemycount] <= 19) {
						  enemy1[enemycount] = 4;
                            enemypic[enemycount] = 0;
							enemypic[enemycount] = Novice::LoadTexture("./Resources/Explosion2.png");
							enemyvelX[enemycount] = 0;
							enemyvelY[enemycount] = 0;
							
						}
						if (enemyLife[enemycount] == 0 && repopcooltime[enemycount] >= 20 &&
						  repopcooltime[enemycount] <= 29) {
							enemypic[enemycount] =
							  Novice::LoadTexture("./Resources/Explosion3.png");
							enemyvelX[enemycount] = 0;
							enemyvelY[enemycount] = 0;
						  
						}
						if (enemyLife[enemycount] == 0 && repopcooltime[enemycount] >= 30 &&
						  repopcooltime[enemycount] <= 39) {
							enemypic[enemycount] =
							  Novice::LoadTexture("./Resources/Explosion4.png");
							enemyvelX[enemycount] = 0;
							enemyvelY[enemycount] = 0;
						  
						}
						if (enemyLife[enemycount] == 0 && repopcooltime[enemycount] >= 40 &&
						  repopcooltime[enemycount] <= 49) {
							
							enemypic[enemycount] =
							  Novice::LoadTexture("./Resources/Explosion5.png");
							
							enemyvelX[enemycount] = 0;
							enemyvelY[enemycount] = 0;
						  
						}
						if (enemyLife[enemycount] == 0 && repopcooltime[enemycount] >= 50 &&
						  repopcooltime[enemycount] <= 59) {
							enemypic[enemycount] =
							  Novice::LoadTexture("./Resources/Explosion6.png");
							enemyvelX[enemycount] = 0;
							enemyvelY[enemycount] = 0;
						  
						}
						if (enemyLife[enemycount] == 0 && repopcooltime[enemycount] >= 60) {
							enemypic[enemycount] = 0;
							enemyX[enemycount] = -720;
							enemyY[enemycount] = -720;
						}
						
					}
					enemycount++;
				}
			}
		}
		//死亡処理
		if (playerlife == 0 && scene == 2) {
			scene = 3;
			staytime = 0;
		}
		if (playerlife == 0) {

			staytime += 1;
		}

		if (playerlife == 0 && staytime == 1) {
			jikipic = 0;
			jikipic = Novice::LoadTexture("./Resources/Explosion1.png");
		}
		if (playerlife == 0 && staytime == 11) {
			jikipic = Novice::LoadTexture("./Resources/Explosion2.png");
		}
		if (playerlife == 0 && staytime == 21) {
			jikipic = Novice::LoadTexture("./Resources/Explosion3.png");
		}
		if (playerlife == 0 && staytime == 31) {
			jikipic = Novice::LoadTexture("./Resources/Explosion4.png");
		}
		if (playerlife == 0 && staytime == 41) {
			jikipic = Novice::LoadTexture("./Resources/Explosion5.png");
		}
		if (playerlife == 0 && staytime == 51) {
			jikipic = Novice::LoadTexture("./Resources/Explosion6.png");
		}
		if (playerlife == 0 && staytime == 61) {
			jikipic = 0;
		}

		//スコア表示
		if (playerlife == 0 && staytime >= 91) {
			boxY += boxYvel;
			if (boxY == 0) {
				boxYvel = 0;
				scoreY += 10;
			}
			if (scoreY >= 300) {
				scoreY = 300;
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		if (scene < 2) {
			Novice::DrawSprite(0, 0, title, 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (startstaytime >= 80) {
			Novice::DrawSprite(0, 0, haikei, 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (scene == 0 && Novice::IsPlayingAudio(playsound[0]) == 0 && playsound[0] == -1) {
			playsound[0] = Novice::PlayAudio(BGM, true, 0.2f);
		}
		if (scene == 1) {
			Novice::StopAudio(playsound[0]);
			if (Novice::IsPlayingAudio(playsound[1]) == 0 && playsound[1] == -1 && keys[DIK_SPACE]) {
				playsound[0] = -1;
				playsound[1] = Novice::PlayAudio(enter2sound, false, 0.5f);
			}
		}
		if (startstaytime >= 30 && Novice::IsPlayingAudio(playsound[2]) == 0 && playsound[2] == -1) {
			playsound[1] = -1;
			playsound[2] = Novice::PlayAudio(datasound, false, 0.5f);
		}
		  
		if (startstaytime <= 80) {
			Novice::DrawSprite(0, 0, title, 1, 1, 0.0f, 0xFFFFFFFF);
		}

		
	    if (playerlife == 1 && Novice::IsPlayingAudio(playsound[4]) == 0 && playsound[4] == -1) {
			playsound[4] = Novice::PlayAudio(battleBGM, true, 0.2f);
		}
		
		if ( movecount==1) {
			Novice::StopAudio(playsound[3]);
			playsound[3] = -1;
			if (Novice::IsPlayingAudio(playsound[3]) == 0 && playsound[3] == -1 &&movetime==1) {
				playsound[3] = Novice::PlayAudio(gunsound, false, 1.0f);
			}
		}
		if (movecount == 2) {
			Novice::StopAudio(playsound[3]);
			playsound[3] = -1;
			if (Novice::IsPlayingAudio(playsound[3]) == 0 && playsound[3] == -1 && movetime == 1) {
				playsound[3] = Novice::PlayAudio(gunsound, false, 1.0f);
			}
		}
		if (movecount == 3) {
			Novice::StopAudio(playsound[3]);
			playsound[3] = -1;
			if (Novice::IsPlayingAudio(playsound[3]) == 0 && playsound[3] == -1 && movetime == 1) {
				playsound[3] = Novice::PlayAudio(gunsound, false, 1.0f);
			}
		}
		if (movecount == 4) {
			Novice::StopAudio(playsound[3]);
			playsound[3] = -1;
			if (Novice::IsPlayingAudio(playsound[3]) == 0 && playsound[3] == -1 && movetime == 1) {
				playsound[3] = Novice::PlayAudio(gunsound, false, 1.0f);
			}
		}
		
		
		
		if (movecount > 5) {
		}
		if (movecount > 0 && movecount < 5) {
			Novice::DrawSprite(bulletX, bulletY, bullet, 2, 2, 0.0f, 0xFFFFFFFF);
		}

		if (playerlife == 1) {
			Novice::DrawSprite(jikiX, jikiY, jikipic, 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (playerlife == 0) {
			Novice::DrawSprite(jikiX, jikiY, jikideath, 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (playerlife == 0) {
			Novice::DrawSprite(jikiX - 90, jikiY - 90, jikipic, 2, 2, 0.0f, 0xFFFFFFFF);
			Novice::StopAudio(playsound[4]);
			playsound[8] = -1;
			if (Novice::IsPlayingAudio(playsound[8]) == 0 && playsound[8] == -1 && staytime==1) {				
				playsound[8] = Novice::PlayAudio(deathsound, false, 0.5f);
			}
		}

		if (enemy1[0] == 1 && enemyLife[0] <= 1) {
	        Novice::DrawSprite(enemyX[0], enemyY[0], enemypic[0], 1, 1, 0.0f, 0xFFFFFFFF);
        }
		if (enemy1[1] == 1 && enemyLife[1] <= 1) {
			Novice::DrawSprite(enemyX[1], enemyY[1], enemypic[1], 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (enemy1[2] == 1 && enemyLife[2] <= 1) {
			Novice::DrawSprite(enemyX[2], enemyY[2], enemypic[2], 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (enemy1[3] == 1 && enemyLife[3] <= 1) {
			Novice::DrawSprite(enemyX[3], enemyY[3], enemypic[3], 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (enemy1[4] == 1 && enemyLife[4] <= 1) {
			Novice::DrawSprite(enemyX[4], enemyY[4], enemypic[4], 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (enemy1[5] == 1 && enemyLife[5] <= 1) {
			Novice::DrawSprite(enemyX[5], enemyY[5], enemypic[5], 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (enemy1[0] == 3 && enemyLife[0] <= 1) {
			Novice::DrawSprite(enemyX[0], enemyY[0], enemypic[0], 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (enemy1[1] == 3 && enemyLife[1] <= 1) {
			Novice::DrawSprite(enemyX[1], enemyY[1], enemypic[1], 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (enemy1[2] == 3 && enemyLife[2] <= 1) {
			Novice::DrawSprite(enemyX[2], enemyY[2], enemypic[2], 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (enemy1[3] == 3 && enemyLife[3] <= 1) {
			Novice::DrawSprite(enemyX[3], enemyY[3], enemypic[3], 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (enemy1[4] == 3 && enemyLife[4] <= 1) {
			Novice::DrawSprite(enemyX[4], enemyY[4], enemypic[4], 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (enemy1[5] == 3 && enemyLife[5] <= 1) {
			Novice::DrawSprite(enemyX[5], enemyY[5], enemypic[5], 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (enemy1[0] == 2 && enemyLife[0] <= 1) {
			Novice::DrawSprite(enemyX[0]-12, enemyY[0]-32, enemypic[0], 1, 1, 0.0f, 0xFFFFFFFF);
			
		}
		if (enemy1[1] == 2 && enemyLife[1] <= 1) {
			Novice::DrawSprite(enemyX[1] - 12, enemyY[1]-32, enemypic[1], 1, 1, 0.0f, 0xFFFFFFFF);
			
		}
		if (enemy1[2] == 2 && enemyLife[2] <= 1) {
			Novice::DrawSprite(enemyX[2] - 12, enemyY[2]-32, enemypic[2], 1, 1, 0.0f, 0xFFFFFFFF);
			
		}
		if (enemy1[3] == 2 && enemyLife[3] <= 1) {
			Novice::DrawSprite(enemyX[3] - 12, enemyY[3]-32, enemypic[3], 1, 1, 0.0f, 0xFFFFFFFF);
			
		}
		if (enemy1[4] == 2 && enemyLife[4] <= 1) {
			Novice::DrawSprite(enemyX[4] - 12, enemyY[4]-32, enemypic[4], 1, 1, 0.0f, 0xFFFFFFFF);
			
		}
		if (enemy1[5] == 2 && enemyLife[5] <= 1) {
			Novice::DrawSprite(enemyX[5] - 12, enemyY[5]-32, enemypic[5], 1, 1, 0.0f, 0xFFFFFFFF);
			
		}	   
		    if (enemyLife[0] == 0 && repopcooltime[0] < 60) {
			    Novice::DrawSprite(enemyX[0]-15, enemyY[0]-20, enemypic[0], 0.5, 0.5, 0.0f, 0xFFFFFFFF);
			    Novice::StopAudio(playsound[9]);
				
			    if (Novice::IsPlayingAudio(playsound[9]) == 0 && playsound[9] == -1 &&repopcooltime[0] < 60) {
					playsound[9] = Novice::PlayAudio(killsound, false, 0.5f);
			    }
		    }
		    if (enemyLife[1] == 0 && repopcooltime[1] < 60) {
			    Novice::DrawSprite(
			      enemyX[1] - 15, enemyY[1] - 20, enemypic[1], 0.5, 0.5, 0.0f, 0xFFFFFFFF);
			    Novice::StopAudio(playsound[9]);
				
			    if ( Novice::IsPlayingAudio(playsound[9]) == 0 && playsound[9] == -1 && repopcooltime[1] < 60) {
				   playsound[9] = Novice::PlayAudio(killsound, false, 0.5f); 
			     
			    }
		    }
		    if (enemyLife[2] == 0 && repopcooltime[2] < 60) {
			    Novice::DrawSprite(
			      enemyX[2] - 15, enemyY[2] - 20, enemypic[2], 0.5, 0.5, 0.0f, 0xFFFFFFFF);
			     Novice::StopAudio(playsound[9]);
			     
			    if ( Novice::IsPlayingAudio(playsound[9]) == 0 && playsound[9] == -1 &&repopcooltime[2] < 60) {
					playsound[9] = Novice::PlayAudio(killsound, false, 0.5f); 
			      
			    }
			      
		    }
		    if (enemyLife[3] == 0 && repopcooltime[3] < 60) {
			    Novice::DrawSprite(
			      enemyX[3] - 15, enemyY[3] - 20, enemypic[3], 0.5, 0.5, 0.0f, 0xFFFFFFFF);
			    Novice::StopAudio(playsound[9]);
			    if (Novice::IsPlayingAudio(playsound[9]) == 0 && playsound[9] == -1 && repopcooltime[3] < 60) {
					 playsound[9] = Novice::PlayAudio(killsound, false, 0.5f);
				  
			    }
		    }
		    if (enemyLife[4] == 0 && repopcooltime[4] < 60) {
			    Novice::DrawSprite(
			      enemyX[4] - 15, enemyY[4] - 20, enemypic[4], 0.5, 0.5, 0.0f, 0xFFFFFFFF);
			    Novice::StopAudio(playsound[9]);
			    
			    if (Novice::IsPlayingAudio(playsound[9]) == 0 && playsound[9] == -1 &&
			      repopcooltime[4] < 60) {
				    playsound[9] = Novice::PlayAudio(killsound, false, 0.5f);
			    }
			      
		    }
		    if (enemyLife[5] == 0 && repopcooltime[5] < 60) {
			    Novice::DrawSprite(
			      enemyX[5] - 15, enemyY[5] - 20, enemypic[5], 0.5, 0.5, 0.0f, 0xFFFFFFFF);
			    Novice::StopAudio(playsound[9]);
			    
			    if (Novice::IsPlayingAudio(playsound[9]) == 0 && playsound[9] == -1 &&
			      repopcooltime[5] < 60) {
					playsound[9] = Novice::PlayAudio(killsound, false, 0.5f);      
			    }
		    }
	        if (startstaytime >= 80) { //画面遷移（スタート）
		        Novice::DrawBox(915, 0, 400, 720, 0.0f, BLACK, kFillModeSolid);
		        if (startstaytime >= 80) {
			        Novice::DrawSprite(915, 360, sousahou, 0.8, 1, 0.0f, 0xFFFFFFFF);
		        }
		        Novice::ScreenPrintf(920, 220, "score=%d", score);
	        }
	        if (scene == 1 && startstaytime <= 180) {
		        Novice::DrawBox(sceneboxX[0], 0, 1300, 120, 0.0f, BLACK, kFillModeSolid);
		        Novice::DrawBox(sceneboxX[1], 120, -1300, 120, 0.0f, BLACK, kFillModeSolid);
		        Novice::DrawBox(sceneboxX[2], 240, 1300, 120, 0.0f, BLACK, kFillModeSolid);
		        Novice::DrawBox(sceneboxX[3], 360, -1300, 120, 0.0f, BLACK, kFillModeSolid);
		        Novice::DrawBox(sceneboxX[4], 480, 1300, 120, 0.0f, BLACK, kFillModeSolid);
		        Novice::DrawBox(sceneboxX[5], 600, -1300, 120, 0.0f, BLACK, kFillModeSolid);
            }
			if (playerlife == 0 && staytime >= 90) {
				Novice::DrawBox(0, boxY, 1280, 720, 0.0f, 0x000000FA, kFillModeSolid);
			    Novice::StopAudio(playsound[3]);
			    if (Novice::IsPlayingAudio(playsound[5]) == 0 && playsound[5] == -1) {
				    playsound[5] = -1;
				    playsound[5] = Novice::PlayAudio(datasound, false, 0.5f);
			    }
			}
			if (boxY == 0) {
				Novice::ScreenPrintf(100, scoreY, " score= %d     thank you for playing!", score);
			}
		    if (scoreY == 300) {
			    Novice::StopAudio(playsound[6]);
			    if (Novice::IsPlayingAudio(playsound[6]) == 0 && playsound[6] == -1) {
				    playsound[6] = -1;
				    playsound[6] = Novice::PlayAudio(enter2sound, false, 0.5f);
			    }
		    }
		    Novice::StopAudio(playsound[6]);
		    if (Novice::IsPlayingAudio(playsound[6]) == 0 && playsound[6] == -1) {
			    playsound[6] = -1;
			    playsound[6] = Novice::PlayAudio(enter2sound, false, 0.5f);
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