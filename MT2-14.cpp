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
	Novice::Initialize(kWindowTitle, 1280, 720);

	Vector2 speed = {0.0f, 0.0f};
	int square = Novice::LoadTexture("white1x1.png");

	typedef struct Box {
		Vector2 pos;
		Vector2 vel;
		Vector2 acc;
		Vector2 size;
		float mass;
		unsigned int color;
	};

	struct Box box {
		{50.0f, 50.0f},
		{0.0f, 0.0f},
		{0.0f, 0.0f},
		{100, 100},
		10.0f,
		0xffffffff,
	};

	box.pos.y += -520.0f;
	box.pos.y *= -1;

	float miu = 0.4f;                //摩擦係数
	const Vector2 kG = {0.0f, -9.8f};//重力加速度 
	float Length=-box.mass * kG.y;  // 垂直抗力
	float magnitude = miu * Length;  //動摩擦力の大きさ 

	int move = 0;

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


		if (keys[DIK_SPACE] && move != 1) {
			move = 1;
			box.vel.x = 70.0f;
		}

		if (move == 1) {
			if (fabs(box.vel.x) != 0.0f) {
				
				Vector2 direction = {-box.vel.x /box.vel.x, 0}; 
				Vector2 frictionalForce = {
				  magnitude * direction.x, magnitude * direction.y}; 

				box.acc.x = frictionalForce.x / box.mass; 
				box.acc.y = frictionalForce.y / box.mass; 

				box.vel.x += box.acc.x;
				box.vel.y += box.acc.y;

				if (box.vel.x < 0 && box.acc.x < 0) {
					box.vel.x = 0.0f;
					box.acc.x = 0.0f;
				}

				box.pos.x += box.vel.x;
				box.pos.y += box.vel.y;
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Novice::DrawBox(
		  box.pos.x, box.pos.y, box.size.x, box.size.y, 0.0f, box.color, kFillModeSolid);
		Novice::ScreenPrintf(10, 15, "%f,%f,%f,%f", box.pos.x, box.pos.y, box.vel.x,box.acc.x);

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

