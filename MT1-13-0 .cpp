
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
  const char kWindowTitle[] = "LC1A_16_ツヅキバシマサミ_MT1";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	int OY = 500;
	float a = 0;
	float b = 1;
	typedef struct Vector2 {
		float positionX = 0;
		float positionY = 0;
		float velocityX = 0;
		float velocityY = 0;
		float accelerationX = 0;
		float accelerationY = 0;
		float veclineX;
		float veclinex;

	};
	Vector2;

	struct Vector2 vector2 = {
	  500.0, 300.0, 0, 0, 0, -0.8f,200,200,
	};
	typedef struct Ball {
		Vector2 positionX;
		Vector2 velocityX;
		Vector2 positionY;
		Vector2 velocityY;
		Vector2 accelerationX;
		Vector2 accelerationY;
		unsigned int color = 0xFFFFFFFF;
		float radius = 30;
	};
	Ball;
	struct Ball ball = {
	  600, 50, 0, 0, 0, -0.8,
	};
	float length = 0;
	int scene = 0;
	float velx = 0;
	float vely = 0;
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		Novice::GetMousePosition;
		vector2.velocityX = 0;
		vector2.velocityY = 0;
		vector2.accelerationY = 0;
		//if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		//	vector2.velocityY = 20;
		//}
		if (keys[DIK_D]) {
			vector2.velocityX = 10;
		}
		if (keys[DIK_A]) {
			vector2.velocityX = -10;
		}
		if (keys[DIK_S]) {
			vector2.velocityY = -10;
		}
		if (keys[DIK_W]) {
			vector2.velocityY = 10;
		}

		//  ball.color -= 0x00001100;

		 length =sqrt(vector2.velocityX * vector2.velocityX + vector2.velocityY *vector2.velocityY);
		
		if (length != 0.0f) {
		    vector2.velocityX = vector2.velocityX * vector2.velocityX / length;
		    vector2.velocityY = vector2.velocityY * vector2.velocityY / length;
		}
		if (keys[DIK_A]) {
			vector2.velocityX *= -1;
		}
		if (keys[DIK_S]) {
			vector2.velocityY *= -1;
		}
		/* if (vector2.velocityX > 0) {
			vector2.veclineX = 200;
		}
		if (vector2.velocityX < 0) {
			vector2.veclineX = -200;
		}
		if (vector2.positionX > 800) {
			vector2.veclinex = 200;
		}
		if (vector2.positionX < 800) {
			vector2.veclinex = -200;
		}*/
		//vector2.velocityX += vector2.accelerationX;
		//vector2.velocityY += vector2.accelerationY;
		vector2.positionX = vector2.positionX + vector2.velocityX;
		vector2.positionY = vector2.positionY - vector2.velocityY;

		if (400 - (vector2.positionX-100)/3 > vector2.positionY ) {
			b = -1;
		}
		if (400 - (vector2.positionX - 100) / 3 <= vector2.positionY) {
			b = 1;
		}
		a =vector2.positionY * b -  vector2.positionX * 0;
		
	 /* if (vector2.positionY > 470) {
			vector2.positionY = 470;
			vector2.velocityY = 0;
		}*/
		if (vector2.positionX >= 1250) {
			vector2.positionX = 1250;
		}
		if (vector2.positionX <= 30) {
			vector2.positionX = 30;
		}

		Novice::DrawLine(100, OY-100, 1000, OY-400, WHITE);
		Novice::ScreenPrintf(0, 10, "%f",b);
		Novice::ScreenPrintf(0, 30, "%f", vector2.positionY);
		Novice::ScreenPrintf(0, 50, "%f", vector2.positionX);
		// Novice::ScreenPrintf(0, 50, "%f", vector2.accelerationY);
		//Novice::DrawLine(vector2.positionX, OY-ball.radius, vector2.positionX+vector2.veclineX, OY-ball.radius, WHITE);
		//Novice::DrawLine(800, OY-ball.radius, 800+vector2.veclinex, OY - ball.radius, WHITE);
		if (a>=0) {
			ball.color = WHITE;
			Novice::DrawEllipse(
			  vector2.positionX, vector2.positionY, ball.radius, ball.radius, 0.0f, ball.color,
			  kFillModeSolid);
		}
		if (a<0) {
			ball.color = BLUE;
			Novice::DrawEllipse(
			  vector2.positionX, vector2.positionY, ball.radius, ball.radius, 0.0f, ball.color,
			  kFillModeSolid);
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