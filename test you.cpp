#include <Novice.h>
#define _USE_MATH_DEFINES
#include<stdlib.h>
#include<time.h>
const char kWindowTitle[] = "LC1A_16_ツヅキバシマサミ_MT1";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	float jikiX = 430;
	float jikiY = 325;
	int movecount = 0;
	int movetime = 0;
	int bulletX = 600;
	int bulletY = 600;
	int bulvelX = 0;
	int bulvelY = 0;
	float enemyX[6] = {0};
	float enemyY[6] = {0};
	int enemyLife[6] = {0};
	int enemymove[6] = {0};
	int playerlife = 1;
	float enemyvelX[6] = {10};
	float enemyvelY[6] = {10};
	float runbavelX = 0;
	float runbavelY = 0;
	int enemycount = 0;
	int enemycooltime = 0;
	int enemybullet[6] = {Novice::LoadTexture("./Resources/razor1.png")};
	float razorX[6] = {-100};
	float razorY[6] = {-100};
	int modX = 0;
	int modY = 0;
	int score = 0;
	int bustered = 0;
	int enemypic[6] = {0};
	enum Enemy1 { ball1, android1, runba1 };
	enum Enemy2 { ball2, android2, runba2 };
	enum Enemy3 { ball3, android3, runba3 };
	enum Enemy4 { ball4, android4, runba4 };
	enum Enemy5 { ball5, android5, runba5 };
	enum Enemy6 { ball6, android6, runba6 };

	enum Enemyappare { light, reft, abobe, below };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		Novice::GetMousePosition;
		Enemy1 enemy1 = ball1;
		if (enemycooltime < 30) {
			enemycooltime++;
		}
		if (enemycooltime == 30) {
			enemycooltime = 0;
		}
		Enemyappare enemyappare = light;
		bulvelX = 0;
		bulvelY = 0;
		if (enemycount < 6 && enemycooltime == 10) {
			//ランダムのやつで敵の配置
			unsigned int currentTime = time(nullptr);
			srand(currentTime);
			int numX = rand();
			modX = numX % 9;
			if (modX == 0) {
				modX = 9;
			}
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
			modY = numY % 7;
			if (modY == 0) {
				modY = 7;
			}
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

			int enemyrepop = rand();
			enemyappare == enemyrepop % 4;

			switch (enemyappare) {
			case light:
				enemyX[enemycount] = 935;
				enemyvelX[enemycount] = -10;
				enemyvelY[enemycount] = 0;
				break;
			case reft:
				enemyX[enemycount] = -40;
				enemyvelX[enemycount] = 10;
				enemyvelY[enemycount] = 0;
				break;
			case abobe:
				enemyY[enemycount] = -40;
				enemyvelX[enemycount] = 0;
				enemyvelY[enemycount] = 10;
				break;
			case below:
				enemyY[enemycount] = 730;
				enemyvelX[enemycount] = 0;
				enemyvelY[enemycount] = -10;
				break;
			}

			if (enemyX[enemycount] >= 935 && enemyY[enemycount] <= -40) {
				enemyX[enemycount] = 835;
				enemyvelX[enemycount] = -10;
				enemyvelY[enemycount] = 0;
			}
			if (enemyX[enemycount] >= 935 && enemyY[enemycount] >= 730) {
				enemyX[enemycount] = 835;
				enemyvelX[enemycount] = -10;
				enemyvelY[enemycount] = 0;
			}
			if (enemyX[enemycount] <= -40 && enemyY[enemycount] <= -40) {
				enemyX[enemycount] = 40;
				enemyvelX[enemycount] = 10;
				enemyvelY[enemycount] = 0;
			}
			if (enemyX[enemycount] <= -40 && enemyY[enemycount] >= 730) {
				enemyX[enemycount] = 40;
				enemyvelX[enemycount] = 10;
				enemyvelY[enemycount] = 0;
			}

			if (enemymove[enemycount] == 60) {
				enemymove[enemycount] = 0;
			}
			if (enemyvelX[enemycount] >= 10 && enemyX[enemycount] >= 875) {
				enemyvelX[enemycount] *= -1;
			}
			if (enemyvelX[enemycount] <= -10 && enemyX[enemycount] <= 0) {
				enemyvelX[enemycount] *= -1;
			}
			if (enemyvelY[enemycount] >= 10 && enemyX[enemycount] >= 700) {
				enemyvelX[enemycount] *= -1;
			}
			if (enemyvelX[enemycount] <= -10 && enemyX[enemycount] <= 0) {
				enemyvelX[enemycount] *= -1;
			}
			int enemytype = rand();

			if (enemycount == 0) {
				enemy1 == enemytype % 3;
				switch (enemy1) {
				case ball1:
					if (enemyvelX[0] == 30 && enemymove[0] == 0) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelX[0] == 30 && enemymove[0] == 15) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot2.png");
					}
					if (enemyvelX[0] == 30 && enemymove[0] == 30) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot3.png");
					}
					if (enemyvelX[0] == 30 && enemymove[0] == 45) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot4.png");
					}
					if (enemyvelY[0] == 30 && enemymove[0] == 0) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelY[0] == 30 && enemymove[0] == 15) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelY[0] == 30 && enemymove[0] == 30) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelY[0] == 30 && enemymove[0] == 45) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelX[0] == -30 && enemymove[0] == 0) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot5.png");
					}
					if (enemyvelX[0] == -30 && enemymove[0] == 15) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot6.png");
					}
					if (enemyvelX[0] == -30 && enemymove[0] == 30) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot7.png");
					}
					if (enemyvelX[0] == -30 && enemymove[0] == 45) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot8.png");
					}
					if (enemyvelY[0] == -30 && enemymove[0] == 0) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot1.png");
					}
					if (enemyvelY[0] == -30 && enemymove[0] == 15) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot2.png");
					}
					if (enemyvelY[0] == -30 && enemymove[0] == 30) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot3.png");
					}
					if (enemyvelY[0] == -30 && enemymove[0] == 45) {
						enemypic[0] = Novice::LoadTexture("./Resources/ballrobot4.png");
					}
					break;
				case android1:
					if (enemyvelX[0] >= 30 && enemymove[0] == 0) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot1-1.png");
					}
					if (enemyvelX[0] >= 30 && enemymove[0] == 15) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot1-2.png");
					}
					if (enemyvelX[0] >= 30 && enemymove[0] == 30) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot1-3.png");
					}
					if (enemyvelX[0] >= 30 && enemymove[0] == 45) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot1-4.png");
					}
					if (enemyvelX[0] <= -30 && enemymove[0] == 0) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot2-1.png");
					}
					if (enemyvelX[0] <= -30 && enemymove[0] == 15) {
						enemypic[0] = Novice::LoadTexture("./Resourcesenemyrobot2-2.png");
					}
					if (enemyvelX[0] <= -30 && enemymove[0] == 30) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot2-3.png");
					}
					if (enemyvelX[0] <= -30 && enemymove[0] == 45) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot2-4.png");
					}
					if (enemyvelY[0] >= 30 && enemymove[0] == 0) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot1.png");
					}
					if (enemyvelY[0] >= 30 && enemymove[0] == 15) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot2.png");
					}
					if (enemyvelY[0] >= 30 && enemymove[0] == 30) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot3.png");
					}
					if (enemyvelY[0] >= 30 && enemymove[0] == 45) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot4.png");
					}
					if (enemyvelY[0] <= -30 && enemymove[0] == 0) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot1.png");
					}
					if (enemyvelY[0] <= -30 && enemymove[0] == 15) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot2.png");
					}
					if (enemyvelY[0] <= -30 && enemymove[0] == 30) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot3.png");
					}
					if (enemyvelY[0] <= -30 && enemymove[0] == 45) {
						enemypic[0] = Novice::LoadTexture("./Resources/enemyrobot4.png");
					}
					if (enemyvelX[0] >= 30 && enemymove[0] == 0) {
						enemybullet[0] = Novice::LoadTexture("./Resources/razor2.png");
					}
					if (enemyvelX[0] <= -30 && enemymove[0] == 0) {
						enemybullet[0] = Novice::LoadTexture("./Resources/razor2.png");
					}
					if (enemyvelY[0] >= 30 && enemymove[0] == 0) {
						enemybullet[0] = Novice::LoadTexture("./Resources/razor1.png");
					}
					if (enemyvelY[0] <= -30 && enemymove[0] == 0) {
						enemybullet[0] = Novice::LoadTexture("./Resources/razor1.png");
					}
					break;
				case runba1:
					enemyX[0] += enemyvelX[0] * 2;
					enemyY[0] += enemyvelY[0] * 2;
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
			}
		}
			Novice::ScreenPrintf(10, 10, "movecount=%d", movecount);
			Novice::ScreenPrintf(10, 30, "movetime=%d", movetime);
			Novice::ScreenPrintf(10, 50, "enemyX=%f", enemyX[0]);
			Novice::ScreenPrintf(10, 70, "enemyY=%f", enemyY[0]);
			Novice::ScreenPrintf(10, 90, "enemy1=%d", enemy1);
			Novice::ScreenPrintf(10, 130, "enemycooltime=%d", enemycooltime);
			Novice::ScreenPrintf(10, 150, "enemycount=%d", enemycount);

			Novice::DrawSprite(enemyX[0], enemyY[0], enemypic[0], 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(enemyX[1], enemyY[1], enemypic[1], 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(enemyX[2], enemyY[2], enemypic[2], 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(enemyX[3], enemyY[3], enemypic[3], 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(enemyX[4], enemyY[4], enemypic[4], 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(enemyX[5], enemyY[5], enemypic[5], 1, 1, 0.0f, 0xFFFFFFFF);

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
