#define _USE_MATH_DEFINES
#include <math.h>
#include <Novice.h>
#include <stdio.h>
#include <stdlib.h>
#include "Scroll.h"
#include "Player.h"
#include "tofumap.h"
#include "Enum.h"
#include "MoveFloor.h"
#include "Machine.h"
#include "MapVariable.h"
#include "Blower.h"

const char kWindowTitle[] = "LC1A_21_マキユキノリ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//ウィンドウサイズ
	const int kwindowWidth = 800;
	const int kwindowHeight = 800;

	struct Vector2 {
		float x;
		float y;
	};


	/*int map[25][50] = { 
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,1,1,5,5,5,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,1,
        1,0,0,4,4,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,9,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 
	};*/

	

	const float scrollstart = 200;
	const float scrollend = 996;

	/*int map1X = sizeof(map[0]) / sizeof(map[0][0]);
	int map1Y = sizeof(map) / sizeof(map[0]);*/

	

	/*enum Type {
		BEANS,
		SOYMILK,
		TOFU,
		FREEZ
	};

	enum Scene {
		TITLE,
		SELECT,
		PLAY,
		RESULT
	};*/



	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kwindowWidth, kwindowHeight);
	Player* player = new Player;
	Scroll* scroll = new Scroll;
	Machine* machine[3];
	for (int i = 0; i < 3; i++) {
		machine[i] = new Machine;
	}
	MoveFloor* moveFloor[5];
	for (int i = 0; i < 5; i++) {
		moveFloor[i] = new MoveFloor;
	}
	Blower* blower[5];
	for (int i = 0; i < 5; i++) {
		blower[i] = new Blower;
	}


	//Novice::SetWindowMode(kFullscreen);
	//struct Player {
	//	Vector2 position;
	//	Vector2 velocity;
	//	Vector2 acceleration;
	//	int jump;
	//	int Alive;
	//	float radius;
	//	int type;
	//};
	//struct point {
	//	int x;
	//	int y;
	//};
	////プレイヤー
	//Player player = {
	//	{64.0f , 100.0f},
	//	{0, 0},
	//	{0, 1.0f},
	//	0,
	//	0,
	//	16.0f,
	//	BEANS
	//};

	//Vector2 scsplayer = {
	//	0, 0
	//};
	//Vector2 tentativeplayer{
	//	0, 0
	//};
	//point leftTop = {
	//	0, 0
	//};
	//point leftBottom = {
	//	0, 0
	//};
	//point rightTop = {
	//	0, 0
	//};
	//point rightBottom = {
	//	0, 0
	//};
	//int direction = 0;

	//int x = 0;
	//int y = 0;
	//int jumpflag = 0;
	//int ecount = 0;
	//int clearflag = 0;
	//int overflag = 0;
	//int scene = TITLE;
	//int end = 0;
	//int cheak = 0;
	//Vector2 screenpos{
	//	0, 0
	//};
	//Vector2 scrollspeed{
	//	0, 0
	//};
	//int pTime = 0;
	//int pMove = 0;

	//
	//Vector2 Goal{
	//	0.0f, 0.0f
	//};
	//Vector2 MILKM{
	//	236.0f, 192.0f
	//};
	//Vector2 TOFUM{
	//	849.0f, 704.0f
	//};
	//Vector2 FREEZM{
	//	1423.0f, 416.0f
	//};
	//struct MoveFloor {
	//	Vector2 position;
	//	float speed;
	//	Vector2 LeftReturn;
	//	Vector2 RightReturn;
	//};
	//MoveFloor movefloor{
	//	{0, 0},
	//	2.0f,
	//	{0, 0},
	//	{0, 0}
	//};

	//struct Par {
	//	Vector2 pos;
	//	Vector2 vel;
	//	Vector2 radius;
	//	int isActive;
	//	int color; 
	//};

	//Par par[50]{
	//	{0, 0},
	//	{0, 0},
	//	{0, 0},
	//	0,
	//	0
	//};

	Vector2 frame{
		0, 0
	};
	float scrollspeed = 0;
	//左上
	Vector2Int leftTop = { 0, 0 };
	//左下
	Vector2Int leftBottom = { 0, 0 };
	//右上
	Vector2Int rightTop = { 0, 0 };
	//右下
	Vector2Int rightBottom = { 0, 0 };
	
	int scene = TITLE;
	
	//ブロック
	const int kblocksize = 32;
	
	//リソース
	int Title = Novice::LoadTexture("./resource/TOFUT.png");
	int Select = Novice::LoadTexture("./resource/stageSelect.png");
	int Result = Novice::LoadTexture("./resource/RESULTTOFU.png");
	int Stage1 = Novice::LoadTexture("./resource/stage1.png");
	int Stage2 = Novice::LoadTexture("./resource/stage2.png");
	int Stage3 = Novice::LoadTexture("./resource/stage3.png");
	int Stage4 = Novice::LoadTexture("./resource/stage4.png");
	int Stage5 = Novice::LoadTexture("./resource/stage5.png");

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

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
		/*if (pTime > 0) {
			pTime -= 1;
			if (pTime % 5 == 0) {
				if (player.Alive == 1) {
					player.Alive = 0;
				}
				else {
					player.Alive = 1;
				}
			}
		}
		else {
			player.Alive = 1;
		}*/
		
		float a = 0;
		float b = 0;
		float c = 0;
		switch (scene) {
		case TITLE:
			if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
				scene = SELECT;
			}
			break;
		case SELECT:
			if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
				scene = PLAY;
			}
			if (keys[DIK_LEFT] != 0 && preKeys[DIK_LEFT] == 0) {
				mapnumber -= 1;
				if (mapnumber < 0) {
					mapnumber = 4;
				}
			}
			if (keys[DIK_RIGHT] != 0 && preKeys[DIK_RIGHT] == 0) {
				mapnumber += 1;
				if (mapnumber > 4) {
					mapnumber = 0;
				}
			}
			if (mapnumber == 0) {
				frame = { 25.0f, 125.0f };
			}
			if (mapnumber == 1) {
				frame = { 275.0f, 125.0f };
			}
			if (mapnumber == 2) {
				frame = { 525.0f, 125.0f };
			}
			if (mapnumber == 3) {
				frame = { 150.0f, 475.0f };
			}
			if (mapnumber == 4) {
				frame = { 400.0f, 475.0f };
			}
			break;
		case PLAY:
			if (player->Alive_ == 0) {
				for (int Y = 0; Y < map1Y; Y++) {
					for (int X = 0; X < map1X; X++) {
						if (Map[mapnumber][Y][X] == START) {
							player->position_.x = X * mapsize;
							player->position_.y = Y * mapsize;
							player->Alive_ = 1;
						}
						if (Map[mapnumber][Y][X] == MILKMC) {
							machine[0]->position_.x = X * mapsize;
							machine[0]->position_.y = Y * mapsize - mapsize;
							machine[0]->type_ = MILKMC;
						}
						if (Map[mapnumber][Y][X] == TOFUMC) {
							machine[1]->position_.x = X * mapsize;
							machine[1]->position_.y = Y * mapsize - mapsize;
							machine[1]->type_ = TOFUMC;
						}
						if (Map[mapnumber][Y][X] == FREEZMC) {
							machine[2]->position_.x = X * mapsize;
							machine[2]->position_.y = Y * mapsize - mapsize;
							machine[2]->type_ = FREEZMC;
						}
						if (Map[mapnumber][Y][X] == MOVEFLOOR) {
							for (int i = 0; i < 5; i++) {
								if (moveFloor[i]->isActive == 0) {
									moveFloor[i]->position_.x = X * mapsize;
									moveFloor[i]->position_.y = Y * mapsize;
									moveFloor[i]->returnLeft_ = X * mapsize;
									moveFloor[i]->returnRight_ = X * mapsize + 300.0f;
									moveFloor[i]->isActive = 1;
									break;
								}
							}
						}
						if (Map[mapnumber][Y][X] == BLOWER_UP || Map[mapnumber][Y][X] == BLOWER_LEFT || Map[mapnumber][Y][X] == BLOWER_RIGHT) {
							for (int i = 0; i < 5; i++) {
								if (blower[i]->type_ == 0) {
									blower[i]->position_ = { float(X * mapsize), float(Y * mapsize) };
									blower[i]->type_ = Map[mapnumber][Y][X];
								}
							}
						}
					}
				}
			}
			player->Update(keys, preKeys);
	        //左上
	        leftTop = {int(player->position_.x / mapsize), int(player->position_.y / mapsize)};
	        //左下
	        leftBottom = {int(player->position_.x / mapsize), int((player->position_.y + player->height_ - 1) / mapsize) };
	        //右上
	        rightTop = {int((player->position_.x + player->width_ - 1)  / mapsize), int(player->position_.y / mapsize)};
	        //右下
	        rightBottom = {int((player->position_.x + player->width_ - 1) / mapsize), int((player->position_.y + player->height_ - 1) / mapsize)};
	        
	        //左
	        if (Map[mapnumber][leftTop.y][leftTop.x] >= BLOCK && Map[mapnumber][leftTop.y][leftTop.x] <= NETWORK && player->jump_ != 2) {
	        	if (player->type_ == SOYMILK && Map[mapnumber][leftTop.y][leftTop.x] == NETWORK) {
	        
	        	}
	        	else {
	        		player->position_.x = leftTop.x * mapsize + player->width_;
	        		player->velocity_.x = 0;
	        	}
	        	
	        }
	        else if (Map[mapnumber][leftTop.y][leftTop.x] >= BLOWER_LEFT && Map[mapnumber][leftTop.y][leftTop.x] <= BLOWER_RIGHT) {
	        	player->position_.x = leftTop.x * mapsize + player->width_;
	        	player->velocity_.x = 0;
	        }
	        else if (Map[mapnumber][leftBottom.y][leftBottom.x] >= BLOCK && Map[mapnumber][leftBottom.y][leftBottom.x] <= NETWORK) {
	        	if (player->type_ == SOYMILK && Map[mapnumber][leftTop.y][leftTop.x] == NETWORK) {
	        
	        	}
	        	else {
	        		player->position_.x = leftTop.x * mapsize + player->width_;
	        		player->velocity_.x = 0;
	        	}
	        }
	        else if (Map[mapnumber][leftBottom.y][leftBottom.x] >= BLOWER_LEFT && Map[mapnumber][leftBottom.y][leftBottom.x] <= BLOWER_RIGHT) {
	        	player->position_.x = leftTop.x * mapsize + player->width_;
	        	player->velocity_.x = 0;
	        }
	        //右
	        if (Map[mapnumber][rightTop.y][rightTop.x] >= BLOCK && Map[mapnumber][rightTop.y][rightTop.x] <= NETWORK) {
	        	if (player->type_ == SOYMILK && Map[mapnumber][rightTop.y][rightTop.x] == NETWORK) {
	        
	        	}
	        	else {
	        		player->position_.x = leftTop.x * mapsize;
	        		player->velocity_.x = 0;
	        	}
	        	
	        }
	        else if (Map[mapnumber][rightTop.y][rightTop.x] >= BLOWER_LEFT && Map[mapnumber][rightTop.y][rightTop.x] <= BLOWER_RIGHT) {
	        	player->position_.x = leftTop.x * mapsize;
	        	player->velocity_.x = 0;
	        }
	        else if (Map[mapnumber][rightBottom.y][rightBottom.x] >= BLOCK && Map[mapnumber][rightBottom.y][rightBottom.x] <= NETWORK) {
	        	if (player->type_ == SOYMILK && Map[mapnumber][rightTop.y][rightTop.x] == NETWORK) {
	        
	        	}
	        	else {
	        		player->position_.x = leftTop.x * mapsize;
	        		player->velocity_.x = 0;
	        	}
	        }
	        else if (Map[mapnumber][rightBottom.y][rightBottom.x] >= BLOWER_LEFT && Map[mapnumber][rightBottom.y][rightBottom.x] <= BLOWER_RIGHT) {
	        	player->position_.x = leftTop.x * mapsize;
	        	player->velocity_.x = 0;
	        }

			player->Jump();
			//左上
	        leftTop = { int(player->position_.x / mapsize), int(player->position_.y / mapsize) };
	        //左下
	        leftBottom = { int(player->position_.x / mapsize), int((player->position_.y + player->height_ - 1) / mapsize) };
	        //右上
	        rightTop = { int((player->position_.x + player->width_ - 1) / mapsize), int(player->position_.y / mapsize) };
	        //右下
	        rightBottom = { int((player->position_.x + player->width_ - 1) / mapsize), int((player->position_.y + player->height_ - 1) / mapsize) };
	        
	        //足
	        if (Map[mapnumber][leftBottom.y][leftBottom.x] >= BLOCK && Map[mapnumber][leftBottom.y][leftBottom.x] <= NETWORK) {
	        	if (player->type_ == SOYMILK && Map[mapnumber][rightBottom.y][rightBottom.x] == NETWORK) {
	        
	        	}
	        	else {
	        		player->position_.y = leftTop.y * mapsize;
	        		player->velocity_.y = 0;
	        		player->jump_ = 0;
	        	}
	        }
	        else if (Map[mapnumber][leftBottom.y][leftBottom.x] >= BLOWER_LEFT && Map[mapnumber][leftBottom.y][leftBottom.x] <= BLOWER_RIGHT) {
	        	player->position_.y = leftTop.y * mapsize;
	        	player->velocity_.y = 0;
	        	player->jump_ = 0;
	        }
	        else if (Map[mapnumber][rightBottom.y][rightBottom.x] >= BLOCK && Map[mapnumber][rightBottom.y][rightBottom.x] <= NETWORK) {
	        	if (player->type_ == SOYMILK && Map[mapnumber][rightBottom.y][rightBottom.x] == NETWORK) {
	        
	        	}
	        	else {
	        		player->position_.y = rightTop.y * mapsize;
	        		player->velocity_.y = 0;
	        		player->jump_ = 0;
	        	}
	        }
	        else if (Map[mapnumber][rightBottom.y][rightBottom.x] >= BLOWER_LEFT && Map[mapnumber][rightBottom.y][rightBottom.x] <= BLOWER_RIGHT) {
	        	player->position_.y = rightTop.y * mapsize;
	        	player->velocity_.y = 0;
	        	player->jump_ = 0;
	        }
	        //頭
	        else if (Map[mapnumber][leftTop.y][leftTop.x] >= BLOCK && Map[mapnumber][leftTop.y][leftTop.x] <= NETWORK) {
	        	if (player->type_ == SOYMILK && Map[mapnumber][leftTop.y][leftTop.x] == NETWORK) {
	        
	        	}
	        	else {
	        		player->position_.y = leftTop.y * mapsize + mapsize + 1;
	        		player->velocity_.y = 0;
	        		
	        	}
	        }
			else if (Map[mapnumber][rightTop.y][rightTop.x] >= BLOCK && Map[mapnumber][rightTop.y][rightTop.x] <= NETWORK) {
				if (player->type_ == SOYMILK && Map[mapnumber][rightTop.y][rightTop.x] == NETWORK) {

				}
				else {
					player->position_.y = rightTop.y * mapsize + mapsize + 1;
					player->velocity_.y = 0;

				}
			}
	        else if (Map[mapnumber][leftTop.y][leftTop.x] >= BLOWER_LEFT && Map[mapnumber][leftTop.y][leftTop.x] <= BLOWER_RIGHT) {
	        	player->position_.y = leftBottom.y * mapsize;
	        	player->velocity_.y = 0;
	        	
	        }
	        else if (Map[mapnumber][rightTop.y][rightTop.x] >= BLOCK && Map[mapnumber][rightTop.y][rightTop.x] <= NETWORK) {
	        	if (player->type_ == SOYMILK && Map[mapnumber][leftTop.y][leftTop.x] == NETWORK) {
	        
	        	}
	        	else {
	        		player->position_.y = leftBottom.y * mapsize;
	        		player->velocity_.y = 0;
	        	}
	        }
	        else if (Map[mapnumber][rightTop.y][rightTop.x] >= BLOWER_LEFT && Map[mapnumber][rightTop.y][rightTop.x] <= BLOWER_RIGHT) {
	        	player->position_.y = leftBottom.y * mapsize;
	        	player->velocity_.y = 0;
	        	
	        }
	        
	        if (Map[mapnumber][leftBottom.y][leftBottom.x] == NONE && Map[mapnumber][rightBottom.y][rightBottom.x] == NONE) {
	        	player->jump_ = 1;
	        }

			for (int i = 0; i < 3; i++) {
				machine[i]->Update(player->position_, player->velocity_, player->width_, player->height_, player->type_);
				machine[i]->Collision(player->position_, player->velocity_, player->width_, player->height_, player->jump_);
			}

			for (int i = 0; i < 5; i++) {
				if (moveFloor[i]->isActive == 1) {
					moveFloor[i]->Update();
					moveFloor[i]->Collision(player->position_, player->velocity_, player->width_, player->height_, player->jump_);
				}
			}

			for (int i = 0; i < 5; i++) {
				blower[i]->Update(player->position_, player->width_, player->height_, player->jump_, player->type_, mapnumber);
			}

			scroll->Update(player->position_, player->velocity_, player->width_, player->height_);
			scrollspeed = scroll->speed_.x;
			player->Screen(scrollspeed);

			////横移動
			//player.velocity.x = 0;
			//for (int Y = 0; Y < map1Y; Y++) {
			//	for (int X = 0; X < map1X; X++) {
			//		if (Map[mapnumber][Y][X] == BLOWER_UP) {
			//			/*for (int i = 0; i < 50; i++) {
			//				if (par[i].isActive == 0) {
			//					par[i].pos.x = X * kblocksize
			//				}
			//			}*/

			//			if (player.type != SOYMILK) {
			//				if (Map[mapnumber][Y][X - 1] == BLOWER_UP || Map[mapnumber][Y][X + 1] == BLOWER_UP) {
			//					if (player.position.x < X * kblocksize + kblocksize && player.position.x + player.radius * 2 > X * kblocksize) {
			//						if (player.position.y < Y * kblocksize) {
			//							player.jump == 2;
			//							if (player.type == BEANS) {
			//								player.velocity.y -= 2.0f;
			//							}
			//							else {
			//								player.velocity.y -= 1.0f;
			//							}
			//						}
			//					}
			//				}
			//				if (Map[mapnumber][Y - 1][X] == BLOWER_UP || Map[mapnumber][Y + 1][X] == BLOWER_UP) {
			//					if (player.position.y < Y * kblocksize + kblocksize && player.position.y + player.radius * 2 > Y * kblocksize) {
			//						if (player.position.x > X * kblocksize) {
			//							if (player.type == BEANS) {
			//								player.velocity.x += 4.0f;
			//							}
			//							else {
			//								player.velocity.x += 2.0f;
			//							}
			//						}
			//					}
			//				}

			//			}

			//		}
			//	}
			//}
			//if (player.Alive != 10 && overflag == 0 && clearflag == 0) {
			//	if (keys[DIK_LEFT]) {
			//		player.velocity.x -= 5.0f;
			//		direction = 1;
			//	}
			//	if (keys[DIK_RIGHT]) {
			//		player.velocity.x += 5.0f;
			//		direction = 0;
			//	}
			//	if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0 && player.jump == 0) {
			//		player.velocity.y = -20.0f;
			//		player.jump = 1;
			//	}

			//}
			//if (keys[DIK_C] != 0 && preKeys[DIK_C] == 0) {
			//	if (player.type == BEANS) {
			//		player.type = SOYMILK;
			//	}
			//	else if (player.type == SOYMILK) {
			//		player.type = TOFU;
			//	}
			//	else if (player.type == TOFU) {
			//		player.type = FREEZ;
			//	}
			//	else if (player.type == FREEZ) {
			//		player.type = BEANS;
			//	}
			//}

			////リセット
			//if (keys[DIK_R] != 0 && preKeys[DIK_R] == 0) {
			//	player.Alive = 0;
			//	player.velocity = { 0, 0 };
			//	player.type = BEANS;
			//	scrollspeed = { 0, 0 };
			//}

			//if (player.Alive == 0) {
			//	for (int Y = 0; Y < map1Y; Y++) {
			//		for (int X = 0; X < map1X; X++) {
			//			if (Map[mapnumber][Y][X] == START) {
			//				player.position.x = X * kblocksize;
			//				player.position.y = Y * kblocksize;
			//				player.Alive = 1;
			//				scrollspeed.x = 0;
			//			}
			//			if (Map[mapnumber][Y][X] == GOAL) {
			//				Goal.x = X * kblocksize;
			//				Goal.y = Y * kblocksize;
			//			}
			//			if (Map[mapnumber][Y][X] == MILKMC) {
			//				MILKM.x = X * kblocksize;
			//				MILKM.y = Y * kblocksize - kblocksize;
			//			}
			//			if (Map[mapnumber][Y][X] == TOFUMC) {
			//				TOFUM.x = X * kblocksize;
			//				TOFUM.y = Y * kblocksize - kblocksize;
			//			}
			//			if (Map[mapnumber][Y][X] == FREEZMC) {
			//				FREEZM.x = X * kblocksize;
			//				FREEZM.y = Y * kblocksize - kblocksize;
			//			}
			//			if (Map[mapnumber][Y][X] == MOVEFLOOR) {
			//				movefloor.position.x = X * kblocksize;
			//				movefloor.position.y = Y * kblocksize;
			//				movefloor.LeftReturn.x = movefloor.position.x;
			//				movefloor.LeftReturn.y = movefloor.position.y;
			//				movefloor.RightReturn.x = movefloor.LeftReturn.x + 300;
			//				movefloor.RightReturn.y = movefloor.LeftReturn.y;
			//			}
			//		}
			//	}
			//}

			//tentativeplayer.x = player.position.x + player.velocity.x;
			//tentativeplayer.y = player.position.y;

			////左上
			//leftTop.x = tentativeplayer.x / kblocksize;
			//leftTop.y = tentativeplayer.y / kblocksize;
			////左下
			//leftBottom.x = tentativeplayer.x / kblocksize;
			//leftBottom.y = ((tentativeplayer.y + kblocksize - 1) / kblocksize);
			////右上
			//rightTop.x = (tentativeplayer.x + kblocksize - 1) / kblocksize;
			//rightTop.y = tentativeplayer.y / kblocksize;
			////右下
			//rightBottom.x = (tentativeplayer.x + kblocksize - 1) / kblocksize;
			//rightBottom.y = (tentativeplayer.y + kblocksize - 1) / kblocksize;

			////左
			//if (Map[mapnumber][int(leftTop.y)][int(leftTop.x)] == NONE && Map[mapnumber][int(leftBottom.y)][int(leftBottom.x)] == NONE) {
			//	//player.position.x +=  player.velocity.x;
			//}
			//else if (Map[mapnumber][int(leftTop.y)][int(leftTop.x)] == BLOCK || Map[mapnumber][int(leftTop.y)][int(leftTop.x)] == THORN) {
			//	tentativeplayer.x = int(tentativeplayer.x / kblocksize);
			//	player.position.x = tentativeplayer.x * kblocksize + kblocksize;
			//	player.velocity.x = 0;

			//}
			//else if (Map[mapnumber][int(leftBottom.y)][int(leftBottom.x)] == BLOCK || Map[mapnumber][int(leftBottom.y)][int(leftBottom.x)] == THORN) {
			//	tentativeplayer.x = int(tentativeplayer.x / kblocksize);
			//	player.position.x = tentativeplayer.x * kblocksize + kblocksize;
			//	player.velocity.x = 0;

			//}
			//else if (Map[mapnumber][int(leftTop.y)][int(leftTop.x)] == HOT || Map[mapnumber][int(leftBottom.y)][int(leftBottom.x)] == HOT) {
			//	if (player.type == SOYMILK && pTime == 0) {
			//		pTime == 30;
			//	}
			//	tentativeplayer.x = int(tentativeplayer.x / kblocksize);
			//	player.position.x = tentativeplayer.x * kblocksize + kblocksize;
			//	player.velocity.x = 0;

			//}
			//else if (Map[mapnumber][int(leftBottom.y)][int(leftBottom.x)] == HOT) {
			//	tentativeplayer.x = int(tentativeplayer.x / kblocksize);
			//	player.position.x = tentativeplayer.x * kblocksize + kblocksize;
			//	player.velocity.x = 0;

			//}
			//else if (Map[mapnumber][int(leftTop.y)][int(leftTop.x)] == NETWORK || Map[mapnumber][int(leftBottom.y)][int(leftBottom.x)] == NETWORK) {
			//	if (player.type != SOYMILK) {
			//		tentativeplayer.x = int(tentativeplayer.x / kblocksize);
			//		player.position.x = tentativeplayer.x * kblocksize + kblocksize;
			//		player.velocity.x = 0;
			//	}


			//}
			//else if (Map[mapnumber][int(leftBottom.y)][int(leftBottom.x)] == NETWORK) {
			//	tentativeplayer.x = int(tentativeplayer.x / kblocksize);
			//	player.position.x = tentativeplayer.x * kblocksize + kblocksize;
			//	player.velocity.x = 0;

			//}
			//else if (Map[mapnumber][int(leftTop.y)][int(leftTop.x)] == BLOWER_UP || Map[mapnumber][int(leftBottom.y)][int(leftBottom.x)] == BLOWER_UP) {
			//	tentativeplayer.x = int(tentativeplayer.x / kblocksize);
			//	player.position.x = tentativeplayer.x * kblocksize + kblocksize;
			//	player.velocity.x = 0;
			//}
			////右
			//if (Map[mapnumber][int(rightTop.y)][int(rightTop.x)] == NONE && Map[mapnumber][int(rightBottom.y)][int(rightBottom.x)] == NONE) {
			//	//player.position.x += player.velocity.x;
			//}
			//else if (Map[mapnumber][int(rightTop.y)][int(rightTop.x)] == BLOCK || Map[mapnumber][int(rightTop.y)][int(rightTop.x)] == THORN) {
			//	tentativeplayer.x = int(tentativeplayer.x / kblocksize);
			//	player.position.x = tentativeplayer.x * kblocksize;
			//	player.velocity.x = 0;

			//}
			//else if (Map[mapnumber][int(rightBottom.y)][int(rightBottom.x)] == BLOCK || Map[mapnumber][int(rightBottom.y)][int(rightBottom.x)] == THORN) {
			//	tentativeplayer.x = int(tentativeplayer.x / kblocksize);
			//	player.position.x = tentativeplayer.x * kblocksize;
			//	player.velocity.x = 0;

			//}
			//else if (Map[mapnumber][int(rightTop.y)][int(rightTop.x)] == HOT || Map[mapnumber][int(rightBottom.y)][int(rightBottom.x)] == HOT) {
			//	if (player.type == SOYMILK && pTime == 0) {
			//		pTime == 30;
			//	}
			//	tentativeplayer.x = int(tentativeplayer.x / kblocksize);
			//	player.position.x = tentativeplayer.x * kblocksize;
			//	player.velocity.x = 0;

			//}
			//else if (Map[mapnumber][int(rightBottom.y)][int(rightBottom.x)] == HOT) {
			//	tentativeplayer.x = int(tentativeplayer.x / kblocksize);
			//	player.position.x = tentativeplayer.x * kblocksize;
			//	player.velocity.x = 0;

			//}
			//else if (Map[mapnumber][int(rightTop.y)][int(rightTop.x)] == NETWORK || Map[mapnumber][int(rightBottom.y)][int(rightBottom.x)] == NETWORK) {
			//	if (player.type != SOYMILK) {
			//		tentativeplayer.x = int(tentativeplayer.x / kblocksize);
			//		player.position.x = tentativeplayer.x * kblocksize;
			//		player.velocity.x = 0;
			//	}


			//}
			//else if (Map[mapnumber][int(rightBottom.y)][int(rightBottom.x)] == NETWORK) {
			//	tentativeplayer.x = int(tentativeplayer.x / kblocksize);
			//	player.position.x = tentativeplayer.x * kblocksize;
			//	player.velocity.x = 0;

			//}
			//else if (Map[mapnumber][int(leftTop.y)][int(leftTop.x)] == BLOWER_UP || Map[mapnumber][int(leftBottom.y)][int(leftBottom.x)] == BLOWER_UP) {
			//	tentativeplayer.x = int(tentativeplayer.x / kblocksize);
			//	player.position.x = tentativeplayer.x * kblocksize;
			//	player.velocity.x = 0;
			//}


			//if (player.velocity.y < 30 && player.jump != 2) {
			//	player.velocity.y += player.acceleration.y;
			//}


			//player.position.x += player.velocity.x;

			//player.position.y += int(player.velocity.y) * player.Alive;
			//tentativeplayer.x = player.position.x;
			//tentativeplayer.y = player.position.y;


			////左上
			//leftTop.x = int(tentativeplayer.x / kblocksize);
			//leftTop.y = int(tentativeplayer.y / kblocksize);
			////右上
			//rightTop.x = int((tentativeplayer.x + kblocksize - 1) / kblocksize);
			//rightTop.y = int(tentativeplayer.y / kblocksize);
			////左下
			//leftBottom.x = int(tentativeplayer.x / kblocksize);
			//leftBottom.y = int((tentativeplayer.y + kblocksize - 1) / kblocksize);
			////右下
			//rightBottom.x = int((tentativeplayer.x + kblocksize - 1) / kblocksize);
			//rightBottom.y = int((tentativeplayer.y + kblocksize - 1) / kblocksize);


			////足
			//if (player.velocity.y > 0 && Map[mapnumber][rightBottom.y][rightBottom.x] == BLOCK) {
			//	tentativeplayer.y = rightBottom.y * kblocksize;
			//	player.position.y = tentativeplayer.y - kblocksize;
			//	player.velocity.y = 0;
			//	player.jump = 0;
			//}
			//else if (player.velocity.y > 0 && Map[mapnumber][leftBottom.y][leftBottom.x] == BLOCK) {

			//	tentativeplayer.y = leftBottom.y * kblocksize;
			//	player.position.y = tentativeplayer.y - kblocksize;
			//	player.velocity.y = 0;
			//	player.jump = 0;
			//}
			//else if (player.velocity.y > 0 && Map[mapnumber][rightBottom.y][rightBottom.x] == NETWORK) {
			//	if (player.type != SOYMILK) {
			//		tentativeplayer.y = rightBottom.y * kblocksize;
			//		player.position.y = tentativeplayer.y - kblocksize;
			//		player.velocity.y = 0;
			//		player.jump = 0;
			//	}

			//}
			//else if (player.velocity.y > 0 && Map[mapnumber][leftBottom.y][leftBottom.x] == NETWORK) {
			//	if (player.type != SOYMILK) {
			//		tentativeplayer.y = leftBottom.y * kblocksize;
			//		player.position.y = tentativeplayer.y - kblocksize;
			//		player.velocity.y = 0;
			//		player.jump = 0;
			//	}

			//}
			//if (player.velocity.y > 0 && Map[mapnumber][rightBottom.y][rightBottom.x] == THORN) {
			//	if (player.type != SOYMILK && player.type != FREEZ && pTime == 0) {
			//		pTime = 30;
			//	}
			//	tentativeplayer.y = rightBottom.y * kblocksize;
			//	player.position.y = tentativeplayer.y - kblocksize;
			//	player.velocity.y = 0;
			//	player.jump = 0;
			//}
			//else if (player.velocity.y > 0 && Map[mapnumber][leftBottom.y][leftBottom.x] == THORN) {
			//	if (player.type != SOYMILK && player.type != FREEZ && pTime == 0) {
			//		pTime = 30;
			//	}
			//	tentativeplayer.y = leftBottom.y * kblocksize;
			//	player.position.y = tentativeplayer.y - kblocksize;
			//	player.velocity.y = 0;
			//	player.jump = 0;
			//}
			//if (player.velocity.y > 0 && Map[mapnumber][rightBottom.y][rightBottom.x] == HOT) {
			//	if (player.type == SOYMILK && pTime == 0) {
			//		pTime = 30;
			//	}
			//	if (player.type == FREEZ) {
			//		player.type = TOFU;
			//	}
			//	tentativeplayer.y = rightBottom.y * kblocksize;
			//	player.position.y = tentativeplayer.y - kblocksize;
			//	player.velocity.y = 0;
			//	player.jump = 0;
			//}
			//else if (player.velocity.y > 0 && Map[mapnumber][leftBottom.y][leftBottom.x] == HOT) {
			//	if (player.type == SOYMILK && pTime == 0) {
			//		pTime = 30;
			//	}
			//	if (player.type == FREEZ) {
			//		player.type = TOFU;
			//	}
			//	tentativeplayer.y = leftBottom.y * kblocksize;
			//	player.position.y = tentativeplayer.y - kblocksize;
			//	player.velocity.y = 0;
			//	player.jump = 0;
			//}
			//if (player.velocity.y > 0 && Map[mapnumber][rightBottom.y][rightBottom.x] == BLOWER_UP) {
			//	tentativeplayer.y = rightBottom.y * kblocksize;
			//	player.position.y = tentativeplayer.y - kblocksize;
			//	player.velocity.y = 0;
			//	player.jump = 0;
			//}
			//else if (player.velocity.y > 0 && Map[mapnumber][leftBottom.y][leftBottom.x] == BLOWER_UP) {
			//	tentativeplayer.y = leftBottom.y * kblocksize;
			//	player.position.y = tentativeplayer.y - kblocksize;
			//	player.velocity.y = 0;
			//	player.jump = 0;
			//}
			////頭
			//else if (Map[mapnumber][leftTop.y][leftTop.x] == BLOCK) {
			//	tentativeplayer.y = leftTop.y * kblocksize;
			//	player.position.y = tentativeplayer.y + kblocksize;
			//	player.velocity.y = 0.0f;
			//}
			//else if (Map[mapnumber][rightTop.y][rightTop.x] == BLOCK) {
			//	tentativeplayer.y = rightTop.y * kblocksize;
			//	player.position.y = tentativeplayer.y + kblocksize;
			//	player.velocity.y = 0.0f;
			//}
			//else if (Map[mapnumber][leftTop.y][leftTop.x] == BLOWER_UP) {
			//	tentativeplayer.y = leftTop.y * kblocksize;
			//	player.position.y = tentativeplayer.y + kblocksize;
			//	player.velocity.y = 0.0f;
			//}
			//else if (Map[mapnumber][rightTop.y][rightTop.x] == BLOWER_UP) {
			//	tentativeplayer.y = rightTop.y * kblocksize;
			//	player.position.y = tentativeplayer.y + kblocksize;
			//	player.velocity.y = 0.0f;
			//}
			//else if (Map[mapnumber][leftTop.y][leftTop.x] == NETWORK) {
			//	if (player.type != SOYMILK) {
			//		tentativeplayer.y = leftTop.y * kblocksize;
			//		player.position.y = tentativeplayer.y + kblocksize;
			//		player.velocity.y = 0.0f;
			//	}

			//}
			//else if (Map[mapnumber][rightTop.y][rightTop.x] == NETWORK) {
			//	if (player.type != SOYMILK) {
			//		tentativeplayer.y = rightTop.y * kblocksize;
			//		player.position.y = tentativeplayer.y + kblocksize;
			//		player.velocity.y = 0.0f;
			//	}

			//}
			//else if (Map[mapnumber][leftTop.y][leftTop.x] == HOT) {
			//	if (player.type == SOYMILK && pTime == 0) {
			//		pTime = 30;
			//	}
			//	if (player.type == FREEZ) {
			//		player.type = TOFU;
			//	}
			//	tentativeplayer.y = leftTop.y * kblocksize;
			//	player.position.y = tentativeplayer.y + kblocksize;
			//	player.velocity.y = 0.0f;

			//}
			//else if (Map[mapnumber][rightTop.y][rightTop.x] == HOT) {
			//	if (player.type == SOYMILK && pTime == 0) {
			//		pTime = 30;
			//	}
			//	if (player.type == FREEZ) {
			//		player.type = TOFU;
			//	}
			//	tentativeplayer.y = rightTop.y * kblocksize;
			//	player.position.y = tentativeplayer.y + kblocksize;
			//	player.velocity.y = 0.0f;

			//}
			////空中
			//if (Map[mapnumber][leftBottom.y][leftBottom.x] == NONE && Map[mapnumber][rightBottom.y][rightBottom.x] == NONE) {
			//	player.jump = 1;
			//}


			//if (player.jump != 0 && player.type == TOFU && player.velocity.y > 19) {
			//	cheak = 1;
			//}
			//if (cheak == 1 && player.jump == 0 && pTime == 0) {
			//	cheak = 0;
			//	pTime = 30;
			//}

			////状態変化
			//if (player.position.x <= MILKM.x + kblocksize * 2 && player.position.x + player.radius >= MILKM.x) {
			//	if (player.position.y + player.radius * 2 >= MILKM.y && player.position.y + player.radius * 2 < MILKM.y + kblocksize * 2) {
			//		player.position.y = MILKM.y - player.radius * 2;
			//		player.velocity.y = 0;
			//		player.jump = 0;

			//	}
			//	if (player.velocity.x > 0 && player.position.y <= MILKM.y + kblocksize * 2 && player.position.y >= MILKM.y && player.type == BEANS) {
			//		player.type = SOYMILK;
			//	}
			//}
			//if (player.position.x <= TOFUM.x + kblocksize * 2 && player.position.x + player.radius >= TOFUM.x) {
			//	if (player.position.y + player.radius * 2 >= TOFUM.y && player.position.y + player.radius * 2 < TOFUM.y + kblocksize * 2) {
			//		player.position.y = TOFUM.y - player.radius * 2;
			//		player.velocity.y = 0;
			//		player.jump = 0;

			//	}
			//	if (player.velocity.x > 0 && player.position.y <= TOFUM.y + kblocksize * 2 && player.position.y >= TOFUM.y && player.type == SOYMILK) {
			//		player.type = TOFU;
			//	}
			//}
			//if (player.position.x <= FREEZM.x + kblocksize * 2 && player.position.x + player.radius >= FREEZM.x) {
			//	if (player.position.y + player.radius * 2 >= FREEZM.y && player.position.y + player.radius * 2 < FREEZM.y + kblocksize * 2) {
			//		player.position.y = FREEZM.y - player.radius * 2;
			//		player.velocity.y = 0;
			//		player.jump = 0;

			//	}
			//	if (player.velocity.x > 0 && player.position.y <= FREEZM.y + kblocksize * 2 && player.position.y >= FREEZM.y && player.type == TOFU) {
			//		player.type = FREEZ;
			//	}
			//}

			////動く床
			//movefloor.position.x += movefloor.speed;
			//if (movefloor.LeftReturn.x > movefloor.position.x || movefloor.RightReturn.x < movefloor.position.x) {
			//	movefloor.speed *= -1;
			//}
			//if (player.position.x <= movefloor.position.x + kblocksize * 3 && player.position.x + player.radius * 2 >= movefloor.position.x) {
			//	if (player.position.y + player.radius * 2 >= movefloor.position.y && player.position.y + player.radius * 2 < movefloor.position.y + kblocksize) {
			//		player.position.y = movefloor.position.y - player.radius * 2;
			//		player.jump = 0;
			//		player.position.x += movefloor.speed;
			//		scrollspeed.x += movefloor.speed;
			//		player.velocity.y = 0;

			//	}
			//	if (player.position.y <= movefloor.position.y + kblocksize && player.position.y + player.radius * 2 >= movefloor.position.y + kblocksize) {
			//		player.position.y = movefloor.position.y + kblocksize;
			//		player.velocity.y = 0;
			//	}
			//}

			////ゴール
			//a = player.position.x + player.radius - Goal.x;
			//b = player.position.y + player.radius - Goal.y;
			//c = sqrt(a * a + b * b);
			//if (c <= player.radius + kblocksize && player.type == FREEZ) {
			//	player.Alive = 0;
			//	player.type = BEANS;
			//	scene = RESULT;
			//}

			////スクロール
			//if (player.position.x + player.radius > scrollstart && player.position.x + player.radius < scrollend) {
			//	if (player.position.x > scrollstart && scrollspeed.x == 0) {
			//		scrollspeed.x += player.position.x + player.radius - scrollstart;
			//	}
			//	scrollspeed.x += player.velocity.x;


			//}

			////座標変換


			//screenpos.x = player.position.x - scrollspeed.x;
			//screenpos.y = player.position.y;
			break;
		case RESULT:
			if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
				scene = TITLE;
			}
			break;
		}
		
		

		

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		switch (scene) {
		case TITLE:
			Novice::DrawSprite(0, 0, Title, 1, 1, 0.0f, 0xFFFFFFFF);
			break;
		case SELECT:
			
			Novice::DrawSprite(0, 0, Select, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawBox(frame.x, frame.y, 250, 250, 0.0f, 0xFFFF00FF, kFillModeSolid);
			Novice::DrawSprite(50, 150, Stage1, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(300, 150, Stage2, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(550, 150, Stage3, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(175, 500, Stage4, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(425, 500, Stage5, 1, 1, 0.0f, 0xFFFFFFFF);
			
			break;
		case PLAY:
			for (int Y = 0; Y < map1Y; Y++) {
				for (int X = 0; X < map1X; X++) {
					if (Map[mapnumber][Y][X] == BLOCK) {
						Novice::DrawBox(X * kblocksize - scrollspeed, Y * kblocksize, kblocksize, kblocksize, 0.0f, BLACK, kFillModeSolid);
						/*Novice::DrawQuad(X * kblocksize - scrollspeed.x, Y * kblocksize, (X * kblocksize + kblocksize) - scrollspeed.x, Y * kblocksize, X * kblocksize - scrollspeed.x, Y * kblocksize + kblocksize, (X * kblocksize + kblocksize) - scrollspeed.x, Y * kblocksize + kblocksize, (Map[Y][X] % Map1X) * kblocksize, (Map[Y][X] / Map1Y) * kblocksize, kblocksize, kblocksize, blocktexture, 0xFFFFFFFF);*/
					}
					if (Map[mapnumber][Y][X] == THORN) {//とげ
						Novice::DrawTriangle(X * kblocksize + kblocksize / 2 - scrollspeed, Y * kblocksize, X * kblocksize - scrollspeed, Y * kblocksize + kblocksize, X * kblocksize + kblocksize - scrollspeed, Y * kblocksize + kblocksize, 0x696969FF, kFillModeSolid);
					}
					if (Map[mapnumber][Y][X] == HOT) {//熱
						Novice::DrawBox(X * kblocksize - scrollspeed, Y * kblocksize, kblocksize, kblocksize, 0.0f, 0xFF4500FF, kFillModeSolid);
					}
					if (Map[mapnumber][Y][X] == BLOWER_UP) {//風(上)
						Novice::DrawBox(X * kblocksize - scrollspeed, Y * kblocksize, kblocksize, kblocksize, 0.0f, 0x66CDAAFF, kFillModeSolid);
					}
					if (Map[mapnumber][Y][X] == BLOWER_LEFT) {
						Novice::DrawBox(X* kblocksize - scrollspeed, Y* kblocksize, kblocksize, kblocksize, 0.0f, 0x66CDAAFF, kFillModeSolid);
					}
					if (Map[mapnumber][Y][X] == BLOWER_RIGHT) {
						Novice::DrawBox(X* kblocksize - scrollspeed, Y* kblocksize, kblocksize, kblocksize, 0.0f, 0x66CDAAFF, kFillModeSolid);
					}
					if (Map[mapnumber][Y][X] == NETWORK) {//網
						Novice::DrawBox(X * kblocksize - scrollspeed, Y * kblocksize, kblocksize, kblocksize, 0.0f, 0x708090FF, kFillModeSolid);
					}

					if (Map[mapnumber][Y][X] == GOAL) {//ゴール
						Novice::DrawEllipse(X * kblocksize - scrollspeed, Y * kblocksize, kblocksize, kblocksize, 0.0f, RED, kFillModeSolid);
					}
				}
			}
			if (player->Alive_ == 1) {
				player->Draw();
				///*Novice::DrawQuad(screenpos.x, screenpos.y, screenpos.x + player.radius * 2, screenpos.y, screenpos.x, screenpos.y + player.radius * 2, screenpos.x + player.radius * 2, screenpos.y + player.radius * 2, pMove * (player.radius * 2), direction * (player.radius * 2), (player.radius * 2), (player.radius * 2), playertextur, 0xFFFFFFFF);*/
				//if (player.type == BEANS) {
				//	Novice::DrawEllipse(screenpos.x + kblocksize / 2, screenpos.y + kblocksize / 2, kblocksize / 2, kblocksize / 2, 0.0f, 0x665400FF, kFillModeSolid);
				//}
				//if (player.type == SOYMILK) {
				//	Novice::DrawTriangle(screenpos.x + kblocksize / 2, screenpos.y, screenpos.x, screenpos.y + kblocksize, screenpos.x + kblocksize, screenpos.y + kblocksize, 0xFFFFFAFF, kFillModeSolid);
				//}
				//if (player.type == TOFU) {
				//	Novice::DrawBox(screenpos.x, screenpos.y, player.radius * 2, player.radius * 2, 0.0f, WHITE, kFillModeSolid);
				//}
				//if (player.type == FREEZ) {
				//	Novice::DrawBox(screenpos.x, screenpos.y, player.radius * 2, player.radius * 2, 0.0f, 0x02669CFF, kFillModeSolid);
				//}

			}
			for (int i = 0; i < 3; i++) {
				machine[i]->Draw(scrollspeed);
			}
			for (int i = 0; i < 5; i++) {
				if (moveFloor[i]->isActive == 1) {
					moveFloor[i]->Draw(scrollspeed);
				}
			}
			//Novice::DrawBox(MILKM.x - scrollspeed.x, MILKM.y, kblocksize * 2, kblocksize * 2, 0.0f, 0xFAFAD2FF, kFillModeSolid);//豆乳作る君
			//Novice::DrawBox(TOFUM.x - scrollspeed.x, TOFUM.y, kblocksize * 2, kblocksize * 2, 0.0f, 0xFFFAFAFF, kFillModeSolid);//豆腐作る君
			//Novice::DrawBox(FREEZM.x - scrollspeed.x, FREEZM.y, kblocksize * 2, kblocksize * 2, 0.0f, 0x00FFFFFF, kFillModeSolid);//凍らせる君
			//Novice::DrawBox(movefloor.position.x - scrollspeed.x, movefloor.position.y, kblocksize * 3, kblocksize, 0.0f, 0x44832FF, kFillModeSolid);//動く床
			//Novice::ScreenPrintf(0, 0, "X : %f ", scrollspeed.x);
			//Novice::ScreenPrintf(0, 20, "X : %f ", player.position.y);
			//Novice::ScreenPrintf(0, 40, "Y : %f", player.velocity.y);
			break;
		case RESULT:
			Novice::DrawSprite(0, 0, Result, 1, 1, 0.0f, 0xFFFFFFFF);
			break;
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
