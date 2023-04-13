#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include<assert.h>
#include<vector.h>

const char kWindowTitle[] = "LC1A_16_ツヅキバシマサミ_AL1-2";
	


    // Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 480, 960);

	Vector2 speed = {0.0f, 0.0f};
	int square = Novice::LoadTexture("white1x1.png");

	typedef struct Ball1 {
		Vector2 position;
		Vector2 vel;
		Vector2 acc;
		float mass;
		float R;
		unsigned int color;
	};
	
	struct Ball1 ball1 {
		{160, 960}, {0, 0}, {0, 0}, 1, 10, 0xffffffff
	};

	typedef struct Ball2 {
		Vector2 position;
		Vector2 vel;
		Vector2 acc;
		float mass;
		float R;
		unsigned int color;
	};
	struct Ball2 ball2 {
		{320, 960}, {0, 0}, {0, 0}, 1, 10, 0xffffffff

	};

	
	float k = 0.6f;
	Vector2 G = {0,1};
	int fall = 0;

	ball1.position.y += -960.0f;
	ball1.position.y *= -1;
	ball2.position.y += -960.0f;
	ball2.position.y *= -1;


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


		Matrix3x3 orthoMatrix = MakeOrthographicMatrix(-240.0f, 480.0f, 240.0f, -480.0f);

		Matrix3x3 viewportMatrix = MakeViewportMatrix(0, 0, 480.0f, 960.0f);


		if (keys[DIK_SPACE] && fall != 1) {
			fall = 1;
		}

		if (fall == 1) {
			Vector2 airResistance = {k * -ball1.vel.x, k * -ball1.vel.y};
			Vector2 airResistanceAcc = {airResistance.x / ball1.mass, airResistance.y / ball1.mass}; 
			ball1.acc.x = G.x + airResistanceAcc.x;
			ball1.acc.y = G.y + airResistanceAcc.y;
			ball1.vel.x += (ball1.acc.x / 60.0f);
			ball1.vel.y += (ball1.acc.y / 60.0f);
			ball1.position.x += (ball1.vel.x / 60.0f);
			ball1.position.y += (ball1.vel.y / 60.0f);
			ball2.acc.x = G.x;
			ball2.acc.y = G.y;

			ball1.vel.x += ball1.acc.x;
			ball1.vel.y += ball1.acc.y;
			ball1.position.x += ball1.vel.x;
			ball1.position.y += ball1.vel.y;

			ball2.vel.x += ball2.acc.x;
			ball2.vel.y += ball2.acc.y;
			ball2.position.x += ball2.vel.x;
			ball2.position.y += ball2.vel.y;
		}



		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Novice::DrawEllipse(
		  ball1.position.x, ball1.position.y, ball1.R, ball1.R, 0.0f, ball1.color, kFillModeSolid);
		Novice::DrawEllipse(
		  ball2.position.x, ball2.position.y, ball2.R, ball2.R, 0.0f, ball2.color, kFillModeSolid);

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

