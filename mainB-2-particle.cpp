#include <Novice.h>
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include<mainB2prt.h>

const char kWindowTitle[] = "LC1B_21_ツヅキバシマサミ";



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

    int jikipic[4] = {
	  Novice::LoadTexture("./sprite/tornado4.png"),
	  Novice::LoadTexture("./sprite/tornado3.png"),
	  Novice::LoadTexture("./sprite/tornado2.png"),
	  Novice::LoadTexture("./sprite/tornado1.png"),
	};
	int shockpic = Novice::LoadTexture("./sprite/maptile4.png");
	int prtpic = Novice::LoadTexture("./sprite/maptile2.png");
	unsigned int currentTime = time(nullptr);
	breaker.shockX = jiki.jikiX + mapsize / 2;


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
	
		animation++;
		jiki.jikivelx = 0;
		jiki.jikively -= 1;

		if (animation >= 20) {
			animation = 0;
		}
		if (animation >= 0 && animation <= 4) {
			jiki.pic = jikipic[0];
		}
		if (animation >= 5 && animation <= 9) {
			jiki.pic = jikipic[1];
		}
		if (animation >= 10 && animation <= 14) {
			jiki.pic = jikipic[2];
		}
		if (animation >= 15 && animation <= 19) {
			jiki.pic = jikipic[3];
		}

		if (breaker.fall == 0) {
			if (keys[DIK_D] || keys[DIK_RIGHT]) {
				jiki.jikivelx += 5;
				breaker.shockX = jiki.jikiX + mapsize / 2;

				if (mapsizex < 0) {
					mapsizex *= -1;
					jiki.jikiX -= mapsize;
					breaker.shockX = jiki.jikiX + mapsize / 2;
				}
			}

			if (keys[DIK_A] || keys[DIK_LEFT]) {
				jiki.jikivelx -= 5;
				breaker.shockX = jiki.jikiX - mapsize / 2;

				if (mapsizex > 0) {
					mapsizex *= -1;
					jiki.jikiX += mapsize;
					breaker.shockX = jiki.jikiX - mapsize / 2;
				}
			}

			if (keys[DIK_SPACE] && jumpcount==0) {
				jiki.jikively += 20;
				jumpcount = 1;
				dustFlag = 1;
			}
		}

		if (keys[DIK_X]) {
			expansion += 0.1f;
			for (int i = 0; i < max * expansion; i++) {
				currentTime = time(nullptr);
				srand(currentTime + i * i);
				if (dirtcount[i]==0) {
					dirtX[i] = jiki.jikiX + rand() % prtRange * expansion - prtRange * expansion / 2;
					dirtcount[i] = 1;
				}
				if (dirtX[i] < jiki.jikiX) {
					dirtvelX[i]++;
				}
				if (dirtX[i] > jiki.jikiX) {
					dirtvelX[i]--;
				}
				dirtX[i] += dirtvelX[i];
			}
		}

		if (keys[DIK_X] == 0) {
			for (int i = 0; i < max * expansion; i++) {
				dirtcount[i] = 0;
			}
		}

		if (keys[DIK_R]) {
		  jiki.jikiX = 200;
		  jiki.jikiY = 600;
		  expansion = 1;
		  breaker.shockX = jiki.jikiX + mapsize / 2;

		}
		if (expansion > 20) {
		  expansion = 20;
		}

		if (jumpcount == 1 && keys[DIK_Z] && preKeys[DIK_Z]==0) {
		  breaker.fall = 1;
		}
		if (breaker.fall == 1) {
			breaker.fallcount++;
		}
		if (breaker.fall == 1 && breaker.fallcount < 30) {
			jiki.jikively = 0;
		}
		if (breaker.fall == 1 && breaker.fallcount >= 30) {
			jiki.jikively = -20;
		}


		jiki.jikiX += jiki.jikivelx;
		jiki.jikiY -= jiki.jikively;
		
		if (jiki.jikiY > 600) {
			jiki.jikiY = 600;
			jiki.jikively = 0;
		}

		if (jiki.jikiY < 600) {
			prtFlag = 1;
			dustFlag = 0;
			for (int i = 0; i < 20; i++) {
				currentTime = time(nullptr);
				srand(currentTime + i * i);
				prtX[i] = (jiki.jikiX - expansion * prtRange / 2) + (i * prtRange / 20 * expansion);
				prtY[i] = 600;
			}
		}

		if (jiki.jikiY == 600) {
			jumpcount = 0;
			if (prtFlag == 1) {
				for (int i = 0; i < 20; i++) {
					srand(currentTime + i * i);

					prtvelY[i] = rand() % 5 + 2;
					
				}
				dustFlag = 1;
				prtFlag = 0;
			}
		}
		if (dustFlag == 1) {
			dustcount++;
		}

		if (dustcount < 30 && jiki.jikiY == 600) {
			for (int i = 0; i < 20; i++) {
				prtY[i] -= prtvelY[i];
				prtvelY[i] -= 1;
				if (prtvelY[i] < 0) {
					prtvelY[i] = 0;
				}
				if (prtY[i] > 600) {
					prtY[i] = 600;
				}
			}
		}

		if (dustcount >= 30) {
			dustcount = 0;
			dustFlag = 0;
		}



		if (breaker.fall == 1 && jiki.jikiY == 600) {
			breaker.shock = 1;
		}

		if (breaker.shock == 1) {
			breaker.shockcount++;
			breaker.shockRX += 2;
			breaker.shockRY++;
			breaker.shockY = jiki.jikiY;
			
			if (expansion >= 5) {
				shakecount++;
				if (shakecount % 10 <= 4) {
					sepalatey1 = expansion;
				}
				if (shakecount % 10 >= 5) {
					sepalatey1 = -expansion;
				}
			}
		}

		if (breaker.shockcount > 20&&breaker.shock==1) {
			breaker.fall = 0;
			breaker.shock = 0;
			breaker.shockcount = 0;
			breaker.shockRX = 0;
			breaker.shockRY = 0;
			breaker.shockY = 0;
			sepalatey1 = 0;
			breaker.fallcount = 0;
		}



		









		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///


		Novice::DrawBox(0, -50 + sepalatey1, 1280, 720, 0.0f, 0x006fffFF, kFillModeSolid);
		Novice::DrawBox(0, 600 + sepalatey1, 1280, 200, 0.0f, 0x8b4513FF, kFillModeSolid);

		if (breaker.shock == 1) {
			Novice::DrawEllipse(
			  breaker.shockX + mapsizex, breaker.shockY + sepalatey1, breaker.shockRX * expansion,
			  breaker.shockRY / 2, 0.0f, 0xFFFFFFFF, kFillModeWireFrame);
			Novice::DrawEllipse(
			  breaker.shockX + mapsizex, breaker.shockY + sepalatey1,
			  breaker.shockRX * expansion + 1, breaker.shockRY / 2 + 1, 0.0f, 0xFFFFFFFF,
			  kFillModeWireFrame);
			Novice::DrawEllipse(
			  breaker.shockX + mapsizex, breaker.shockY + sepalatey1,
			  breaker.shockRX * expansion + 2, breaker.shockRY / 2 + 1, 0.0f, 0xFFFFFFFF,
			  kFillModeWireFrame);
			Novice::DrawEllipse(
			  breaker.shockX + mapsizex, breaker.shockY + sepalatey1,
			  breaker.shockRX * expansion + 3, breaker.shockRY / 2 + 2, 0.0f, 0xFFFFFFFF,
			  kFillModeWireFrame);
			Novice::DrawEllipse(
			  breaker.shockX + mapsizex, breaker.shockY + sepalatey1,
			  breaker.shockRX * expansion + 4, breaker.shockRY / 2 + 2, 0.0f, 0xFFFFFFFF,
			  kFillModeWireFrame);
		}

		Novice::DrawQuad(
		  jiki.jikiX - mapsize / 2 * expansion + mapsizex, jiki.jikiY - mapsize * expansion + sepalatey1,
		  jiki.jikiX + mapsize / 2 * expansion + mapsizex, jiki.jikiY - mapsize * expansion + sepalatey1,
		  jiki.jikiX - mapsize / 2 * expansion + mapsizex, jiki.jikiY + sepalatey1,
		  jiki.jikiX + mapsize / 2 * expansion + mapsizex, jiki.jikiY + sepalatey1,
			0, 0, mapsize, mapsize, jiki.pic, 0xFFFFFFFF);


		for (int i = 0; i < 20; i++) {
			if (dustFlag == 1) {
				Novice::DrawSprite(
				  prtX[i]  + mapsizex, prtY[i], prtpic, 0.1, 0.1, 0.5f,
				  0xFFFFFFFF);
			}
		}

		Novice::SetBlendMode(BlendMode::kBlendModeNormal);

		if (keys[DIK_X]) {
			for (int i = 0; i < 20; i++) {
				Novice::DrawEllipse(
				  dirtX[i] + mapsizex, 595, 4, 4, 0.0f, 0xFFFFFF66, kFillModeSolid);
			}
		}

		Novice::ScreenPrintf(10,10,"MOVE:A D/<- ->　JUMP:SPACE　DIVE:Z in the air　giantism:X　RESET:R");
		
		 

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
