#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

const char kWindowTitle[] = "LC1A_16_ツヅキバシマサミ_AL1-2";



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1200, 720);

	float x = 450;
	float y = 450;
	int xspd;
	int yspd;
	int graphHandle1 = Novice::LoadTexture("./Resources/scroll1.png");
	int graphHandle2 = Novice::LoadTexture("./Resources/scroll2.png");
	int graphHandle3 = Novice::LoadTexture("./Resources/scroll3.png");
	int graphHandle4 = Novice::LoadTexture("./Resources/scroll4.png");
	float X=0;
	float Y=0;
	float DIST=0;
	int enemyhit = 0;
	float length=0;
	int worldx = 0;
	int worldy = 0;
	int scrollx = 0;
	int scrolly = 0;
	int screenx = 0;
	int screeny = 0;
	int scrollber = 600;

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
		xspd = 0;
		yspd = 0;
		

		if (keys[DIK_A]) {
			worldx += -10;
		}
		if (keys[DIK_D]) {
			worldx += 10;
		}
		if (keys[DIK_W]) {
			yspd = 10;
		}
		if (keys[DIK_S]) {
			yspd = -10;
		}
		if (keys[DIK_C]) {
			scrollber += 10;
			if (x == scrollber) {
				x += 10;
			}
		}
		if (keys[DIK_Z]) {
			scrollber += -10;
			if (x == scrollber) {
				x -= 10;
			}
		}
		
		/* if (x >= 1180 && keys[DIK_D]) {
			worldx = 0;
		}
		if (y >= 700 && keys[DIK_S]) {
			yspd = 0;
		}
		if (x <= 20 && keys[DIK_A]) {
			worldx = 0;
		}
		if (y <= 20 && keys[DIK_W]) {
			yspd = 0;
		}*/

		if (worldx >= scrollber && worldx <= 4800 - scrollber) {
			if (keys[DIK_D]) {
				scrollx += 10;
			}
			if (keys[DIK_A]) {
				scrollx -= 10;
			}
		}
		if (worldx <= scrollber) {
			scrollx = 0;
		}
		if (worldx >=4800-scrollber) {
			scrollx = 3600;
		}
		
		/* X = xspd;
		Y = yspd;
		length = sqrt(X * X + Y * Y);
		if (length != 0.0f) {
			xspd = X * X / length;
			yspd = Y * Y / length;
			if (keys[DIK_A]) {
				xspd *= -1;
			}
			if (keys[DIK_S]) {
				yspd *= -1;
			}
		}*/

		x = worldx-scrollx;
		y -= yspd;

		if (worldx > 4780) {
			worldx = 4780;
		}
		if (worldx < 20) {
			worldx = 20;
		}


		if (x >= 1180) {
			x = 1180;
		}
		if (x <= 20) {
			x = 20;
		}
		if (y >= 700) {
			y = 700;
		}
		if (y <= 20) {
			y = 20;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Novice::ScreenPrintf(10, 10, "x=%f", x);
		Novice::ScreenPrintf(10, 30, "worldx=%d", worldx);
		Novice::ScreenPrintf(10, 50, "scrollx=%d", scrollx);

		Novice::DrawSprite(0 - scrollx, 0, graphHandle1, 1, 1, 0.0f, 0xFFFFFFFF);
		Novice::DrawSprite(1200 - scrollx, 0, graphHandle2, 1, 1, 0.0f, 0xFFFFFFFF);
		Novice::DrawSprite(2400 - scrollx, 0, graphHandle3, 1, 1, 0.0f, 0xFFFFFFFF);
		Novice::DrawSprite(3600 - scrollx, 0, graphHandle4, 1, 1, 0.0f, 0xFFFFFFFF);
		Novice::DrawSprite(4800 - scrollx, 0, graphHandle4, 1, 1, 0.0f, 0xFFFFFFFF);
		Novice::DrawLine(scrollber, 0, scrollber, 1200, WHITE);
		Novice::DrawEllipse(x, y, 20, 20, 0.0f, 0xFFFFFFFF, kFillModeSolid);
		//Novice::DrawLine();
	
		//	Novice::DrawSprite(0, 0, graphHandle1, 3, 3, 0.0f, 0xFFFFFFFF);
		
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
