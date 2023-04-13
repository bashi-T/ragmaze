#include <Novice.h>
#define _USE_MATH_DEFINES
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<light-map.h>
#include<math.h>


const char kWindowTitle[] = "team number.1222";



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	
	const int count = 20;
	int start1 = 0;
	int scalex = 400;
	int scaley = 528;
	int Sscalex = 300;
	int Sscaley = 300;
	int slashsprite[11] = {
	  Novice::LoadTexture("./bossresource/slash1.png"),
	  Novice::LoadTexture("./bossresource/slash2.png"),
	  Novice::LoadTexture("./bossresource/slash3.png"),
	  Novice::LoadTexture("./bossresource/slash4.png"),
	  Novice::LoadTexture("./bossresource/slash5.png"),
	  Novice::LoadTexture("./bossresource/slash6.png"),
	  Novice::LoadTexture("./bossresource/slash7.png"),
	  Novice::LoadTexture("./bossresource/slash8.png"),
	  Novice::LoadTexture("./bossresource/slash9.png"),
	  Novice::LoadTexture("./bossresource/slash10.png"),
	  Novice::LoadTexture("./bossresource/slash11.png"),
	};
	int bigslash[7]{
	  Novice::LoadTexture("./bossresource/bigslash1.png"),
	  Novice::LoadTexture("./bossresource/bigslash2.png"),
	  Novice::LoadTexture("./bossresource/bigslash3.png"),
	  Novice::LoadTexture("./bossresource/bigslash4.png"),
	  Novice::LoadTexture("./bossresource/bigslash5.png"),
	  Novice::LoadTexture("./bossresource/bigslash6.png"),
	  Novice::LoadTexture("./bossresource/slash11.png"),
	};
	int SSnumber=0;
	int slashtime = 0;
	int excount = 0;
	int maxcount = 2;
	int highlight=0;
	int slash=0;
	int slashcount=0;
	
	
	


	float LTX=340;
	float LTY=-36;
	float LBX=340;
	float LBY=564;
	float RTX=940;
	float RTY=-36;
	float RBX=940;
	float RBY=564;

	int BSX = 376;
	int BSY = 0;
	int BScount = 0;
	int BSsprite = 0;
	int BSnumber = 0;
	int shockRx = 0;
	int shockRy = 0;


	int sepalatex2 = 0;
	int sepalatey2 = 0;

	int burnX = 640;
	int burnY = -150;
	int burnR = 170;
	int burncount = 0;

	float randam1X[20] = {0};
	float randam1Y[20] = {0};
	float randam2X[20] = {0};
	float randam2Y[20] = {0};
	float randamV[20] = {0};
	float theta[20] = {0};



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
		unsigned int currentTime = time(nullptr);
		srand(currentTime);

		if (keys[DIK_1] && preKeys[DIK_1] == 0) {
			start1 = 1;
		}
		if (start1 == 0) {
			slashtime = 0;
		}

		if (start1 == 1) {
			excount++;
			if (excount == maxcount) {
				slashtime++;
				excount = 0;
			}
		}
		slash = slashsprite[slashtime];

		if (slashtime == 10 && excount == maxcount-1) { // scene1-end
			excount = 0;
			maxcount = 2;
			start1 = 0;
		}

		//------------------------------------------------------------------------------------------------------

		if (keys[DIK_2] && preKeys[DIK_2] == 0) {
			start1 = 2;
		}
		if (start1 == 2) {
			BScount++;
			if (BScount == 1) {
				BSsprite = bigslash[BSnumber];
				BSnumber++;
			}
			if (BScount == 5) {
				BScount = 0;
			}
			if (BSnumber > 2) {
				if (BScount / 2 == 0) {
					sepalatey1 = 5;
				}
				if (BScount / 2 == 1) {
					sepalatey1 = -5;
				}
				shockRx += 150;
				shockRy += 5;
			}
		}
		if (BSnumber == 6&&BScount==4) {
			start1 = 0;
			BScount = 0;
			BSnumber = 0;
			shockRx = 0;
			shockRy = 0;
		}

		//----------------------------------------------------------------------------

		if (keys[DIK_3] && preKeys[DIK_3] == 0) {
			start1 = 3;
		}

		if (start1 == 3) {
			burncount++;

			if (burncount < 180) {
				burnY += 1;
			}

			if (burncount >= 180) {
				burnR += 200;
			}
			if (burncount > 240) {
			    burnX = 640;
			    burnY = -200;
			    burnR = 170;
			    burncount = 0;
				start1 = 0;
			}
		}




		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		if (start1 != 0) {
			Novice::DrawBox(0, 0, 1280, 528, 0.0f, 0x000000ea, kFillModeSolid);
		}

		 if (start1 == 1) {

			for (int i = 0; i < slashtime; i++) {

				Novice::DrawQuad(
				  LTX + sepalatex1, LTY + sepalatey1, RTX + sepalatex1,
				  RTY+ sepalatey1, LBX + sepalatex1, LBY + sepalatey1,
				  RBX + sepalatex1, RBY + sepalatey1, 0, 0, 600, 600, slash,
				  0xFFFFFFFF);
			}
		}
			  
		if (start1 == 2) {
			if (BSnumber > 2) {
				Novice::DrawEllipse(
				  640 + sepalatex1, 500 + sepalatey1, shockRx, shockRy, 0.0f, 0xFFFFFFFF,
				  kFillModeWireFrame);
				Novice::DrawEllipse(
				  640 + sepalatex1, 500 + sepalatey1, shockRx - 1, shockRy - 1, 0.0f, 0xFFFFFFFF,
				  kFillModeWireFrame);
				Novice::DrawEllipse(
				  640 + sepalatex1, 500 + sepalatey1, shockRx - 2, shockRy - 2, 0.0f, 0xFFFFFFFF,
				  kFillModeWireFrame);
				Novice::DrawEllipse(
				  640 + sepalatex1, 500 + sepalatey1, shockRx - 3, shockRy - 3, 0.0f, 0xFFFFFFFF,
				  kFillModeWireFrame);
				Novice::DrawEllipse(
				  640 + sepalatex1, 500 + sepalatey1, shockRx - 4, shockRy - 4, 0.0f, 0xFFFFFFFF,
				  kFillModeWireFrame);
				Novice::DrawEllipse(
				  640 + sepalatex1, 500 + sepalatey1, shockRx - 5, shockRy - 5, 0.0f, 0xFFFFFFFF,
				  kFillModeWireFrame);
				Novice::DrawEllipse(
				  640 + sepalatex1, 500 + sepalatey1, shockRx - 6, shockRy - 6, 0.0f, 0xFFFFFFFF,
				  kFillModeWireFrame);
				Novice::DrawEllipse(
				  640 + sepalatex1, 500 + sepalatey1, shockRx - 7, shockRy - 7, 0.0f, 0xFFFFFFFF,
				  kFillModeWireFrame);
				Novice::DrawEllipse(
				  640 + sepalatex1, 500 + sepalatey1, shockRx - 8, shockRy - 8, 0.0f, 0xFFFFFFFF,
				  kFillModeWireFrame);
				Novice::DrawEllipse(
				  640 + sepalatex1, 500 + sepalatey1, shockRx - 9, shockRy - 9, 0.0f, 0xFFFFFFFF,
				  kFillModeWireFrame);
			}
			Novice::DrawQuad(
			  BSX + sepalatex2, BSY + sepalatey2, BSX + scalex + sepalatex2, BSY + sepalatey2,
			  BSX + sepalatex2, BSY + scaley + sepalatey2, BSX + scalex + sepalatex2,BSY + scaley + sepalatey2,
			   0, 0, scalex, scaley, bigslash[BSnumber], 0xFFFFFFFF);
		
		
		
		}
		if (start1 == 3&&burncount<185) {
			Novice::DrawEllipse(
			  burnX + sepalatex1, burnY + sepalatey1, burnR + 150, burnR + 150, 0.0f, 0xff0000FF,
			  kFillModeSolid);
			for (int i = 0; i < 100; i++) {
				Novice::DrawEllipse(
				  burnX + sepalatex1, burnY + sepalatey1, burnR +100- i, burnR +100- i, 0.0f,
				  0xff0000FF + i * 0x00020200, kFillModeSolid);
			}

			Novice::DrawEllipse(
			  burnX + sepalatex1, burnY + sepalatey1, burnR, burnR, 0.0f, 0xFFFFFFFF,
			  kFillModeSolid);
		}

		/* if (start1 == 4) {
			for (int i = 0; i < count; i++) {
				Novice::DrawLine(randam1X[i], randam1Y[i], randam2X[i], randam2Y[i], WHITE);
				Novice::DrawLine(
				  randam1X[i] + 1, randam1Y[i] + 1, randam2X[i] + 1, randam2Y[i] + 1, WHITE);
				Novice::DrawLine(
				  randam1X[i] + 2, randam1Y[i] + 2, randam2X[i] + 2, randam2Y[i] + 2, WHITE);
				Novice::DrawLine(
				  randam1X[i] - 1, randam1Y[i] - 1, randam2X[i] - 1, randam2Y[i] - 1, WHITE);
				Novice::DrawLine(
				  randam1X[i] - 2, randam1Y[i] - 2, randam2X[i] - 2, randam2Y[i] - 2, WHITE);
			}
		}*/



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
