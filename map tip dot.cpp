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
	int jikiY = 200;
	int jikivelx = 0;
	int jikively = 0;
	int robotX = 0;
	int robotY = 200;
	int robotvelX = 0;
	int robotvelY = 0;
	int robotvelxA = 0;
	int robotvelyA = 0;
	int robotvelxB = 0;
	int robotvelyB = 0;
	int robotvelxC = 0;
	int robotvelyC = 0;

	const int mapX1 = 20;
	const int mapY1 = 20;
	const int mapX2 = 20;
	const int mapY2 = 20;
	int mapsize = 40;
	int movecount = 0;
	int movetimeA = 0;
	int movetimeB = 0;
	int movetimeC = 0;
	int staytime = 0;
	

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
		
		int map1[map1Y][map1X]{
			2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
		    2,0,2,0,0,0,0,0,0,0,0,0,0,2,0,2,0,0,0,2,
		    2,0,2,2,2,2,2,2,0,2,2,0,0,2,0,0,0,2,0,2,
		    2,0,0,0,0,0,0,0,0,2,2,0,2,2,0,2,0,0,0,2,
		    2,0,2,0,2,2,0,2,0,2,0,0,0,0,0,2,0,2,2,2,
		    2,0,2,0,2,2,0,2,0,0,0,0,2,2,0,2,0,2,2,2,
		    2,0,2,0,0,0,0,2,0,2,2,0,0,2,0,2,0,2,2,2,
		    2,0,2,2,2,2,0,0,0,2,2,2,0,2,0,2,0,0,0,2,
		    2,0,0,0,0,2,0,2,2,2,2,0,0,2,0,2,2,2,0,1,
		    2,2,2,2,2,2,0,2,2,2,2,0,2,2,0,2,2,2,2,2,
		    0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,2,0,0,2,2,
		    2,2,2,2,2,2,0,2,2,2,2,2,2,0,0,0,0,0,0,2,
		    2,0,2,2,0,2,0,2,0,0,0,0,2,0,0,0,2,2,0,2,
		    2,0,0,0,0,2,0,2,0,0,0,0,2,2,2,0,2,2,0,2,
		    2,0,2,2,2,2,0,2,2,2,2,2,2,2,2,0,2,2,0,2,
		    2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
			2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
		};
		int map2[map2Y][map2X]{
			2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
		    2,0,2,0,0,0,0,0,0,0,0,0,0,2,0,2,0,0,0,2,
		    2,0,2,2,2,2,2,2,0,2,2,0,0,2,0,0,0,2,0,2,
		    2,0,0,0,0,0,0,0,0,2,2,0,2,2,0,2,0,0,0,2,
		    2,0,0,0,0,2,0,2,2,2,2,0,0,2,0,2,2,2,0,1,
		    2,2,2,0,2,2,0,2,2,2,2,0,2,2,0,2,2,2,2,2,		    
		    2,0,2,0,2,2,0,2,0,0,0,0,2,2,0,0,0,2,2,2,
		    2,0,0,0,0,0,0,2,0,2,2,0,0,2,0,2,0,2,2,2,
		    2,0,2,2,2,2,0,0,0,2,2,2,0,2,2,2,0,0,0,2,
			2,0,2,0,2,2,0,2,0,2,0,0,0,0,0,2,0,2,2,2,
		    0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,2,0,0,2,2,
		    2,2,2,2,2,2,0,2,2,2,2,2,2,0,0,0,0,0,0,2,
		    2,0,2,2,0,2,0,2,0,0,0,0,2,0,0,0,2,2,0,2,
		    2,0,0,0,0,2,0,2,0,0,0,0,2,2,2,0,2,2,0,2,
		    2,0,2,2,2,2,0,2,2,2,2,2,2,2,2,0,2,2,0,2,
		    2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
			2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
		};

		jikivelx = 0;
		jikively = 0;		
		
		if (keys[DIK_D] ) {
			 jikivelx = 5;
			
		}
		if (keys[DIK_A]) {
			jikivelx = -5;
			movetime += 1;

		}
		if (keys[DIK_S] ) {
			jikively = 5;
			movetime += 1;

		}
		if (keys[DIK_W] ) {
			jikively = -5;
			movetime += 1;

		}

		if (keys[DIK_RIGHT]) {
			jikivelx = 5;
			movetime += 1;

		}
		if (keys[DIK_LEFT] ) {
			jikivelx = -5;
			movetime += 1;

		}
		if (keys[DIK_DOWN] ) {
			jikively = 5;
			movetime += 1;

		}
		if (keys[DIK_UP]) {
			jikively = -5;
			movetime += 1;

		}
		
		//当たり判定
		//if (map[(jikiY+jikively) / mapsize][(jikiX+jikivelx) / mapsize] == 2) {
		//	jikivelx = 0;
		//	jikively = 0;
		//}

		for (int x = 0; x < mapX; x++) {
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
		}
		
		
		if (pushcount == 0 && movetime == 1) {
			robotvelx1 = jikivelx;
			robotvely1 = jikively;
		}
		if (pushcount == 1 && movetime == 1) {
			robotvelx2 = jikivelx;
			robotvely2 = jikively;
		}
		if (pushcount == 2 && movetime == 1) {
			robotvelx3 = jikivelx;
			robotvely3 = jikively;
		}

		if (pushcount == 0 && movetime == 1) {
			robotvelX = robotvelx2;
			robotvelY = robotvely2;
		}
		if (pushcount == 1 && movetime == 1) {
			robotvelX = robotvelx3;
			robotvelY = robotvely3;
		}
		if (pushcount == 2 && movetime == 1) {
			robotvelX = robotvelx1;
			robotvelY = robotvely1;
		}
		
		
		
		
		
		

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

		       

		jikiX += jikivelx;
		jikiY += jikively;
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		
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
		

		
		Novice::DrawBox(jikiX, jikiY + 100, mapsize, mapsize, 0.0f, RED, kFillModeSolid);
		Novice::DrawBox(robotX + 500, robotY + 100, mapsize, mapsize, 0.0f, GREEN, kFillModeSolid);
		

		 
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
