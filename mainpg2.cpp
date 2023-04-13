#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "player.cpp"
#include "enemy.cpp"
#include "shot.cpp"
#include "hit.cpp"



const char kWindowTitle[] = "LC1B_21_ツヅキバシマサミ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	screenedgeX = 600;
	screenedgeY = 600;
	int scene = 0;
	
	Player* player = new Player();
	player->GetX();
	player->GetY();
	player->GetSpeedX();
	player->GetSpeedY();
	player->GetRadius();
	player->GetLife();
	player->bulletRadius = 5;
	player->bulletCount = 0;
	player->shotcount = 0;

	for (int i = 0; i < fullbullet; i++) {
		player->bulletX[i] = player->GetX();
		player->bulletY[i] = player->GetY();
		player->bulletSpeed[i] = 0;
		player->bulletFlag[i] = 0;
		player->bulletroute[i] = 0;
		player->bulletshot[i] = {0};
	}

	Enemy* enemy = new Enemy();
	enemy->GetX();
	enemy->GetY();
	enemy->GetSpeedX();
	enemy->GetSpeedY();
	enemy->GetRadius();
	enemy->GetLife();

	player->SetPlayer(
	  player->GetX(), player->GetY(), player->GetSpeedX(), player->GetSpeedY(), player->GetRadius(),
	  player->GetLife());
	enemy->SetEnemy(
	  enemy->GetX(), enemy->GetY(), enemy->GetSpeedX(), enemy->GetSpeedY(), enemy->GetRadius(),
	  enemy->GetLife());

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, screenedgeX, screenedgeY);

	// キー入力結果を受け取る箱

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

	  switch (scene) {
		case 0:
			player->Move(
			  player->GetX(), player->GetY(), player->GetSpeedX(), player->GetSpeedY(),
			  player->GetRadius());
			player->Shoot(player->GetX(), player->GetY(), enemy->GetX());
			
			if (keys[DIK_SPACE]) {
				player->shotcount++;
				if (player->shotcount == 1) {
					player->bulletCount++;
					for (int i = 0; i < player->bulletCount; i++) {
						if (player->bulletFlag[i] == 0) {
							player->bulletFlag[i] = 1;
						}
						if (player->bulletX[i] != player->bulletX[i - 1]&&i!=0) {
							player->bulletFlag[i] = 1;
						}
					}
					
				}

				if (player->bulletCount > 20) {
					player->bulletCount = 20;
				}

				if (player->shotcount > 19) {
					player->shotcount = 0;
				}

				player->Shoot(player->GetX(), player->GetY(), enemy->GetX());
			} else {
				player->shotcount = 0;
				for (int i = 0; i < player->bulletCount; i++) {
					player->bulletFlag[i] = 0;
					player->bulletroute[i] = 0;
					player->bulletSpeed[i] = 0;
					player->bulletshot[i] = 0;
					player->bulletY[i] = player->GetY();
					player->bulletX[i] = player->GetX();
				}
				player->bulletCount = 0;
			}

			player->BulletMove();
			for (int i = 0; i < player->bulletCount; i++) {
				if (player->bulletFlag[i] != 0) {
					enemy->bulletHit(
					  player->bulletX[i], player->bulletY[i], player->bulletRadius, enemy->GetX(),
					  enemy->GetY(), enemy->GetRadius(), enemy->GetLife());
					
					if (
					  player->bulletX[i] - enemy->GetX() <
					    player->bulletRadius + enemy->GetRadius() &&
					  player->bulletX[i] - enemy->GetX() >
					    -player->bulletRadius - enemy->GetRadius() &&
					  player->bulletY[i] - enemy->GetY() <
					    player->bulletRadius + enemy->GetRadius() &&
					  player->bulletY[i] - enemy->GetY() >
					    -player->bulletRadius - enemy->GetRadius()) {
						player->bulletFlag[i] = 0;
						player->bulletroute[i] = 0;
						player->bulletSpeed[i] = 0;
						player->bulletshot[i] = 0;
						player->bulletY[i] = player->GetY();
						player->bulletX[i] = player->GetX();


					}
				}
			}

			if (enemy->GetLife() < 50) {
				scene = 1;
			}

			break;

		case 1:
			player->Move(
			  player->GetX(), player->GetY(), player->GetSpeedX(), player->GetSpeedY(),
			  player->GetRadius());
			enemy->Move(
			  enemy->GetX(), enemy->GetY(), enemy->GetSpeedX(), enemy->GetSpeedY(),
			  enemy->GetRadius(), player->GetX());

			if (keys[DIK_SPACE]) {
				player->shotcount++;
				if (player->shotcount == 1) {
					player->bulletCount++;
					for (int i = 0; i < player->bulletCount; i++) {
						if (player->bulletFlag[i] == 0) {
							player->bulletFlag[i] = 1;
						}
						if (player->bulletX[i] != player->bulletX[i - 1] && i != 0) {
							player->bulletFlag[i] = 1;
						}
					}
				}

				if (player->bulletCount > 20) {
					player->bulletCount = 20;
				}

				if (player->shotcount > 19) {
					player->shotcount = 0;
				}

				player->Shoot(player->GetX(), player->GetY(), enemy->GetX());
			} else {
				player->shotcount = 0;
				for (int i = 0; i < player->bulletCount; i++) {
					player->bulletFlag[i] = 0;
					player->bulletroute[i] = 0;
					player->bulletSpeed[i] = 0;
					player->bulletshot[i] = 0;
					player->bulletY[i] = player->GetY();
					player->bulletX[i] = player->GetX();
				}
				player->bulletCount = 0;

			}
			player->BulletMove();
			player->enemyHit(
			  player->GetX(), player->GetY(), player->GetRadius(), enemy->GetX(), enemy->GetY(),
			  enemy->GetRadius(), player->GetLife());

			if (player->GetLife() == 0) {
				scene = 3;
			}

			for (int i = 0; i < player->bulletCount; i++) {
				if (player->bulletFlag[i] != 0) {
					enemy->bulletHit(
					  player->bulletX[i], player->bulletY[i], player->bulletRadius, enemy->GetX(),
					  enemy->GetY(), enemy->GetRadius(), enemy->GetLife());
					if (
					  player->bulletX[i] - enemy->GetX() <
					  player->bulletRadius + enemy->GetRadius() &&
					  player->bulletX[i] - enemy->GetX() >
					 -player->bulletRadius - enemy->GetRadius() &&
					  player->bulletY[i] - enemy->GetY() <
					  player->bulletRadius + enemy->GetRadius() &&
					  player->bulletY[i] - enemy->GetY() >
					 -player->bulletRadius - enemy->GetRadius()) {
						player->bulletFlag[i] = 0;
						player->bulletroute[i] = 0;
						player->bulletSpeed[i] = 0;
						player->bulletshot[i] = 0;
						player->bulletY[i] = player->GetY();
						player->bulletX[i] = player->GetX();

					}
				}
			}
			if (enemy->GetLife() <= 0) {
				scene = 2;
			}
			break;

		case 2:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				scene = 0;
				player->Reset(
				  player->GetX(), player->GetY(), player->GetSpeedX(), player->GetSpeedY(),
				  player->GetRadius(), player->GetLife());
				enemy->Reset(
				  enemy->GetX(), enemy->GetY(), enemy->GetSpeedX(), enemy->GetSpeedY(),
				  enemy->GetRadius(), enemy->GetLife());

				for (int i = 0; i < player->bulletCount; i++) {
					player->bulletFlag[i] = 0;
					player->bulletroute[i] = 0;
					player->bulletSpeed[i] = 0;
					player->bulletshot[i] = 0;
					player->bulletY[i] = player->GetY();
					player->bulletX[i] = player->GetX();

				}
				player->bulletCount = 0;


			}
			break;

		case 3:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE]==0) {
				scene = 0;
				player->Reset(
				  player->GetX(), player->GetY(), player->GetSpeedX(), player->GetSpeedY(),
				  player->GetRadius(), player->GetLife());
				enemy->Reset(
				  enemy->GetX(), enemy->GetY(), enemy->GetSpeedX(), enemy->GetSpeedY(),
				  enemy->GetRadius(), enemy->GetLife());

				for (int i = 0; i < player->bulletCount; i++) {
					player->bulletFlag[i] = 0;
					player->bulletroute[i] = 0;
					player->bulletSpeed[i] = 0;
					player->bulletshot[i] = 0;
				}
				player->bulletCount = 0;

			}
			break;
	  }

		player->bulletDraw();
		player->Draw(player->GetX(), player->GetY(), player->GetRadius());
		enemy->Draw(enemy->GetX(), enemy->GetY(), enemy->GetRadius());

		if (scene == 0) {
			Novice::ScreenPrintf(100, 400, "PRESS SPACE TO SHOT");
			Novice::ScreenPrintf(100, 420, "PRESS WASD TO MOVE");
			Novice::ScreenPrintf(100, 440, "SHOOT ENEMY TO START");
		}
		if (scene == 2) {
			Novice::ScreenPrintf(100, 300, "GAME CLEAR");
			Novice::ScreenPrintf(100, 400, "PRESS SPACE TO RESTART");
		}
		if (scene == 3) {
			Novice::ScreenPrintf(100,300, "GAME OVER");
			Novice::ScreenPrintf(100, 400, "PRESS SPACE TO RESTART");
		}

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete player;
	delete enemy;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
