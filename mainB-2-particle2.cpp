#include <Novice.h>
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

const char kWindowTitle[] = "LC1B_21_ツヅキバシマサミ_AL2";



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	int blend = 0;
	int sepalatex1 = 0;
	int sepalatey1 = 0;
	int sepalatex2 = 0;
	int sepalatey2 = 0;
	int sepalate = 0;
	typedef struct Jiki {
		int jikiX = 0;
		int jikiY = 0;
		int jikivelx = 0;
		int jikively = 0;
	} Jiki;
	struct Jiki jiki = {
	  500,
	  200,
	  0,
	  0,
	};

	const int emitter = 200;
	int vector = 360;
	int jiki1X[emitter] = {0};
	int jiki1Y[emitter] = {0};
	float speed[emitter] = {0};
	float jikivec[emitter] = {0};
	float jikivelx[emitter] = {0};
	float jikively[emitter] = {0};
	int startcount[emitter] = {0};
	int count[emitter] = {0};
	int max = 0;
	int particle = Novice::LoadTexture("./sprite/particle.png");
	float theta[emitter] = {0};

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
		unsigned int currentTime = time(nullptr);

		jiki.jikivelx = 0;
		jiki.jikively = 0;

		if (keys[DIK_D]) {
			jiki.jikivelx += 5;
		}

		if (keys[DIK_A]) {
			jiki.jikivelx -= 5;
		}
		if (keys[DIK_W]) {
			jiki.jikively += 5;
		}

		if (keys[DIK_S]) {
			jiki.jikively -= 5;
		}

		if (keys[DIK_0]) {
			blend = 0;
		}
		if (keys[DIK_1]) {
			blend = 1;
		}
		if (keys[DIK_2]) {
			blend = 2;
		}
		if (keys[DIK_3]) {
			blend = 3;
		}
		if (keys[DIK_4]) {
			blend = 4;
		}

		jiki.jikiX += jiki.jikivelx;
		jiki.jikiY -= jiki.jikively;

		if (max == 0) {
			for (int i = 0; i < emitter; i++) {
				startcount[i] = 0;
			}
		}
		max += 1;
		if (max > emitter) {
			max = emitter;
		}

		for (int i = 0; i < max; i++) {

			if (startcount[i] == 0) {
				jiki1X[i] = jiki.jikiX;
				jiki1Y[i] = jiki.jikiY;
				startcount[i] = 1;
			}

			if (startcount[i] == 1) {
				srand(currentTime + i * i);

				jikivec[i] = rand() % vector;
				theta[i] = (jikivec[i] / (vector / 2)) * M_PI;
				speed[i] = 10;
				jikivelx[i] = speed[i] * cosf(theta[i]);
				jikively[i] = speed[i] * sinf(theta[i]);

				startcount[i] = 2;
			}

			if (startcount[i] == 2) {
				jiki1X[i] += jikivelx[i];
				jiki1Y[i] += jikively[i];
				count[i] += 1;
				if (count[i] > 60) {
					count[i] = 0;
					startcount[i] = 0;
				}
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		Novice::DrawBox(0,0,1280,720,0.0f,0x000000FF,kFillModeSolid);
		if (blend==0) {
			Novice::SetBlendMode(BlendMode::kBlendModeNone);
		}
		if (blend == 1) {
			Novice::SetBlendMode(BlendMode::kBlendModeNormal);
		}
		if (blend == 2) {
			Novice::SetBlendMode(BlendMode::kBlendModeAdd);
		}
		if (blend == 3) {
			Novice::SetBlendMode(BlendMode::kBlendModeSubtract);
		}
		if (blend == 4) {
			Novice::SetBlendMode(BlendMode::kBlendModeNormal);
		}


		for (int i = 0; i < max; i++) {
			if (startcount[i] == 2) {
				Novice::DrawSprite(jiki1X[i], jiki1Y[i], particle, 1, 1, 0.0f, 0xFFFFFF77);
			}
		}

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
