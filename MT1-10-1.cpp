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

	int OY = 400;
	typedef struct Vector2 {
		float positionX=300;
		float positionY=600;
		float velocityX = 0;
		float velocityY = 0;
		float acceleration;
	};Vector2;

	struct Vector2 vector2 = {
	  300,
	  600,
	  0,
	  0,
	};
	typedef struct Ball {
		Vector2 positionX;
		Vector2 velocityX;
		Vector2 positionY;
		Vector2 velocityY;
		float radius = 100;
		unsigned int color;
	};Ball;
	struct Ball ball = {
	  300,
	  600,
	  0,
	  0,
	};
	float length=0;
	int scene = 0;
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		
		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		Novice::GetMousePosition;
		if (keys[DIK_SPACE]) {
			scene = 1;
		}
		if (scene == 1) {
			vector2.velocityX = 10;
			scene = 2;
		}
		
		//length =sqrt(vector2.velocityX * vector2.velocityX + vector2.velocityY * vector2.velocityY);
		//if (length != 0.0f) {
		//	vector2.velocityX = vector2.velocityX * vector2.velocityX / length;
		//	vector2.velocityY = vector2.velocityY * vector2.velocityY / length;
		//}

		if (vector2.positionX >= 1180) {
			vector2.positionX = 1180;
			vector2.velocityX = -10;
		}
		if (vector2.positionX <= 100) {
			vector2.positionX = 100;
			vector2.velocityX = 10;
		}
		vector2.positionX = vector2.positionX+vector2.velocityX;

		Novice::DrawLine(0, 0, 1280, 0, 0xFFFFFFFF);
		if (scene >= 1) {
		 Novice::DrawEllipse(vector2.positionX, vector2.positionY, ball.radius, ball.radius, 0.0f, 0xFFFFFFFF, kFillModeSolid);
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