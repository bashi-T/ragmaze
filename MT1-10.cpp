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
	float Ox = 0;
	float Oy = 500;
	float ellipse1X = 30;
	float ellipse1Y = 60;
	float ellipse2X = 800;
	float ellipse2Y = 400;

	typedef struct Ellipse {
		int r1 = 30;
		int r2 = 30;
		int r3 = 50;
		int r4 = 50;
	};Ellipse;
	struct Ellipse ellipse {
		30,
		30,
		50,
	    50,
	};
	
	//float hitvelX = ellipse1X - ellipse2X;
	//float hitvelY = ellipse1Y - ellipse2Y;
	//float hitvel = sqrtf( hitvelX * hitvelX + hitvelY * hitvelY);
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
			ellipsevY = -10;
		}
		if (keys[DIK_W]) {
			ellipsevY = 10;
		}
		if (ellipse1X >= 1250 && keys[DIK_D]) {
			ellipsevX = 0;
		}
		if (ellipse1Y >= 690 && keys[DIK_S]) {
			ellipsevY = 0;
		}
		if (ellipse1X <= 30 && keys[DIK_A]) {
			ellipsevX = 0;
		}
		if (ellipse1Y <= 30 && keys[DIK_W]) {
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
			if (keys[DIK_S]) {
				ELLIPSEvy *= -1;
			}
		}
		

		ellipse1X =ellipse1X+Ox+ ELLIPSEvx;
		ellipse1Y =ellipse1Y+Oy- ELLIPSEvy-500;
		//hitvelX = ellipse1X - ellipse2X;
		//hitvelY = ellipse1Y - ellipse2Y;
		//hitvel = sqrtf(hitvelX * hitvelX + hitvelY * hitvelY);
		Novice::ScreenPrintf(10, 10, "%f", ellipse1X);
		Novice::ScreenPrintf(10, 30, "%f", ellipse1Y);
		Novice::DrawLine(Ox, Oy, 1280, Oy, 0xFFFFFFFF);
		Novice::DrawEllipse(ellipse1X, ellipse1Y, ellipse.r1, ellipse.r2, 0.0f, 0xFFFFFFFF, kFillModeSolid);
			
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