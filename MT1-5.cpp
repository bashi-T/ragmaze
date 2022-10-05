#include <Novice.h>
#define _USE_MATH_DEFINES
#include<math.h>
const char kWindowTitle[] = "LC1A_16_ツヅキバシマサミ_MT1";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	float theta = (1.0 / 16.0f) * M_PI;
	    float X1 = 300;
		float Y1 = 350;
		float X2 = 500;
		float Y2 = 350;
		float X3 = 300;
		float Y3 = 450;
		float X4 = 500;
		float Y4 = 450;
	    float x1;
	    float y1;
	    float x2;
	    float y2;
	    float x3;
	    float y3;
	    float x4;
	    float y4;
		int turn = 0;
	int whiteTextureHandle = Novice::LoadTexture("white1x1.png");
	
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		
		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		Novice::GetMousePosition;


		

		if (keys[DIK_SPACE]) {
			turn += 1;
		}
		if (turn == 1) {
			
		    x1 = X1 - 400;
			y1 = Y1 - 400;
			x2 = X2 - 400;
			y2 = Y2 - 400;
			x3 = X3 - 400;
			y3 = Y3 - 400;
			x4 = X4 - 400;
			y4 = Y4 - 400;
		
			X1 = x1 * cos(theta) - y1 * sin(theta) + 400;
			Y1 = y1 * cos(theta) + x1 * sin(theta) + 400;
			X2 = x2 * cos(theta) - y2 * sin(theta) + 400;
			Y2 = y2 * cos(theta) + x2 * sin(theta) + 400;
			X3 = x3 * cos(theta) - y3 * sin(theta) + 400;
			Y3 = y3 * cos(theta) + x3 * sin(theta) + 400;
			X4 = x4 * cos(theta) - y4 * sin(theta) + 400;
			Y4 = y4 * cos(theta) + x4 * sin(theta) + 400;
			
		}

		if (turn == 2 ) {
			turn = 0;
		}

 		 Novice::DrawQuad (X1, Y1, X2, Y2, X3, Y3, X4, Y4, 0, 0, 1, 1, whiteTextureHandle, WHITE);
		  //if ();
	
		

		
		

        //Novice::DrawBox(box1X, box1Y, 100, 100, 0.0f, WHITE, kFillModeSolid);
		
		
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