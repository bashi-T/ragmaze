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

	float AX = 600;
	float AY = 400;
	float BX = 0;
	float BY = 0;
	typedef struct VECTOR2 {
		float x=300;
		float y = 200;
		float x1 = 0;
		float y1 = 0;
		float x2 = 0;
		float y2 = 0;
	};VECTOR2;
	struct VECTOR2 vector = { 
		300,
	    200,
		0,
		0,
		0,
		0,
	};
	vector.x = 300;
	vector.y = 200;
	vector.x1 = 300;
	vector.y1 = 200;

	float bx = 900;
	float by = 400;
	float theta = (1.0 / 16.0f) * M_PI;
	float length = sqrt(vector.x * vector.x + vector.y * vector.y);
	float vxsize = 1;
	float vysize = 1;
	int vsizechange = 50;
	int vsizecount = 0;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		
		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		Novice::GetMousePosition;
		
		vxsize = vector.x / 100;
		vysize = vector.y / 100;
		if (vsizechange >= 110) {
			vsizecount = 1;
		}
		if (vsizechange <= 1) {
			vsizecount = 0;
		}

		if (vsizechange >= 0&&vsizecount==0) {
		    vector.x1 = vector.x1 + vxsize;
			vector.y1 = vector.y1 + vysize;
			vsizechange += 1;
		}
		
		if (vsizechange <= 151&&vsizecount==1) {
			vector.x1 = vector.x1 - vxsize;
			vector.y1 = vector.y1 - vysize;
			vsizechange += -1;
		}

		vector.x2 = vector.x1 * cos(theta) - vector.y1 * sin(theta); 
		vector.y2 = vector.y1 * cos(theta) + vector.x1 * sin(theta); 
		theta += 0.01f;
		
		BX = AX + vector.x2;
		BY = AY + vector.y2;
        
	 Novice::DrawLine(AX, AY, BX, BY, 0xFFFFFFFF);
		Novice::ScreenPrintf(10, 10, "%d", vsizecount);
		Novice::ScreenPrintf(10, 20, "%d", vsizechange);

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