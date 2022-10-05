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

	float ellipse1X = 400;
	float ellipse1Y = 400;
	float ellipse2X = 800;
	float ellipse2Y = 400;

	typedef struct Ellipse {
		int r1 = 100;
		int r2 = 100;
		int r3 = 50;
		int r4 = 50;
	};Ellipse;
	struct Ellipse ellipse {
		100,
		100,
		50,
	    50,
	};
	
	float hitvelX = ellipse1X - ellipse2X;
	float hitvelY = ellipse1Y - ellipse2Y;
	float hitvel = sqrtf( hitvelX * hitvelX + hitvelY * hitvelY);
	float ellipsevX = 0;
	float ellipsevY = 0;
	float length=0;
	float ELLIPSEvx = ellipsevX;
	float ELLIPSEvy = ellipsevY;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		
		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		Novice::GetMousePosition;
		ellipsevX = 0;
		ellipsevY = 0;
		if (keys[DIK_D]) {
			 ellipsevX = 10;
		}
		if (keys[DIK_A]) {
			ellipsevX = -10;
		}
		if (keys[DIK_S]) {
			ellipsevY = 10;
		}
		if (keys[DIK_W]) {
			ellipsevY = -10;
		}
		if (ellipse2X >= 1230 && keys[DIK_D]) {
			ellipsevX = 0;
		}
		if (ellipse2Y >= 670 && keys[DIK_S]) {
			ellipsevX = 0;
		}
		if (ellipse2X <= 50 && keys[DIK_A]) {
			ellipsevY = 0;
		}
		if (ellipse2Y <= 50 && keys[DIK_W]) {
			ellipsevY = 0;
		}

		ELLIPSEvx = ellipsevX;
		ELLIPSEvy = ellipsevY;
		length = sqrt(ellipsevX * ellipsevX + ellipsevY * ellipsevY);
		if (length != 0.0f) {
			ELLIPSEvx = ellipsevX * ellipsevX / length;
			ELLIPSEvy = ellipsevY * ellipsevY / length;
			if (keys[DIK_A]) {
				ELLIPSEvx *= -1;
			}
			if (keys[DIK_W]) {
				ELLIPSEvy *= -1;
			}

		}
		

		ellipse2X += ELLIPSEvx;
		ellipse2Y += ELLIPSEvy;
		hitvelX = ellipse1X - ellipse2X;
		hitvelY = ellipse1Y - ellipse2Y;
		hitvel = sqrtf(hitvelX * hitvelX + hitvelY * hitvelY);

		Novice::DrawEllipse(ellipse1X, ellipse1Y, ellipse.r1, ellipse.r2, 0.0f, 0xFFFFFFFF, kFillModeSolid);
		if (hitvel > 150) {
			Novice::DrawEllipse(ellipse2X, ellipse2Y, ellipse.r3, ellipse.r4, 0.0f, RED, kFillModeSolid);
		}
		if (hitvel<=150) {
		   Novice::DrawEllipse(ellipse2X, ellipse2Y, ellipse.r3, ellipse.r4, 0.0f, 0x0000FFFF, kFillModeSolid);
	    }	
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