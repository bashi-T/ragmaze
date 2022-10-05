
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
	float a = 100;
	float A = OY-100;
	float b = 1000;
	float B = OY-400;
	float ba = 0;
	float BA = 0;
	float cf = 0;
	float CF = 0;
	float c = 0;
	float C = 0;
	float d = 0;
	float D = 0;
	float e = 0;
	float E = 0;
	float f = 0;
	float F = 0;
	float g = 0;
	float G = 0;
	float T = 0;
	float t = 0;
	float U = 0;
	float u = 0;
	float lengthba = 0;
	float lengthd = 0;
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
	  500, 0, 0, 0, 0, -0.8f,200,200,
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
		if (keys[DIK_RIGHT]) {
			vector2.velocityX = 10;
		}
		if (keys[DIK_LEFT]) {
			vector2.velocityX = -10;
		}
		if (keys[DIK_DOWN]) {
			vector2.velocityY = -10;
		}
		if (keys[DIK_UP]) {
			vector2.velocityY = 10;
		}
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
		if (keys[DIK_LEFT]) {
			vector2.velocityX *= -1;
		}
		if (keys[DIK_DOWN]) {
			vector2.velocityY *= -1;
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
		}
		if (400 - (vector2.positionX-100)/3 > vector2.positionY ) {
			b = -1;
		}
		if (400 - (vector2.positionX - 100) / 3 <= vector2.positionY) {
			b = 1;
		}*/
		//vector2.velocityX += vector2.accelerationX;
		//vector2.velocityY += vector2.accelerationY;
		vector2.positionX = vector2.positionX + vector2.velocityX;
		vector2.positionY = vector2.positionY - vector2.velocityY;

	 /* if (vector2.positionY > 470) { ball.radius + 60
			vector2.positionY = 470;
			vector2.velocityY = 0;
		}*/
		if (vector2.positionX >= 1250) {
			vector2.positionX = 1250;
		}
		if (vector2.positionX <= 30) {
			vector2.positionX = 30;
		}

		c = vector2.positionX;//自機のｘ
		C = vector2.positionY;//自機のｙ
		d = vector2.positionX - a; //ベクトルdのｘ
		D = vector2.positionY - A; //ベクトルdのｙ
		ba = b - a;//900
		BA = B - A;//-300
		lengthba = sqrt(ba * ba + BA * BA); // b-aの正規化
		e = ba;//正規化したベクトルb-aのx
		E = BA;//正規化したベクトルb-aのy
		if (lengthba != 0.0f) {
			e = ba / lengthba;
			E = BA / lengthba;
		}
		T = sqrt(ba * ba + BA * BA);
		t = (d * e + D * E) / T ; // dとeの内積とb-aの長さの除算
	
		if (t < 0) {
			t = 0;
		}
		if (t >= 1) {
			t = 1;
		}
		
		f = (1 - t) * a + t * b;
		F = (1 - t) * A + t * B;

		cf = vector2.positionX - f;
		CF = vector2.positionY - F;
		U = sqrt(cf * cf + CF * CF);
		
		Novice::DrawEllipse(
		  100, OY - 100, 60, 60, 0.0f,WHITE, kFillModeWireFrame);
		Novice::DrawEllipse(1000, OY - 400, 60, 60, 0.0f, WHITE, kFillModeWireFrame);
		Novice::DrawLine(100, OY - 100, 1000, OY - 400, WHITE);
		Novice::ScreenPrintf(0, 10, "%f", U);
		Novice::ScreenPrintf(0, 30, "%f,%f", f,F);//変動しない？
		Novice::ScreenPrintf(0, 50, "%f,%f", c,C);
		Novice::ScreenPrintf(0, 70, "%f,%f,%f", ba, BA, sqrt(ba * ba + BA * BA));
		Novice::ScreenPrintf(0, 90, "%f,%f", t, d * e + D * E /sqrt(ba * ba + BA * BA));
		//tが１～０の間にならない
		Novice::ScreenPrintf(0, 110, "%f,%f", d,D);
		Novice::ScreenPrintf(0, 130, "%f,%f", e,E);
		Novice::DrawEllipse(f, F,1, 1, 0.0f,BLACK,kFillModeSolid);

		// Novice::ScreenPrintf(0, 50, "%f", vector2.accelerationY);
		//Novice::DrawLine(vector2.positionX, OY-ball.radius, vector2.positionX+vector2.veclineX, OY-ball.radius, WHITE);
		//Novice::DrawLine(800, OY-ball.radius, 800+vector2.veclinex, OY - ball.radius, WHITE);
		if (U > ball.radius + 60) {
				ball.color=WHITE;
				Novice::DrawEllipse( vector2.positionX, vector2.positionY, ball.radius, ball.radius, 0.0f, ball.color,kFillModeSolid);
		}
		if (U <= ball.radius + 60) {
			ball.color = RED;
			Novice::DrawEllipse( vector2.positionX, vector2.positionY, ball.radius, ball.radius, 0.0f, ball.color, kFillModeSolid);
			 
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