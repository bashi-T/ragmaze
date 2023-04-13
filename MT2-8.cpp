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

	Vector2 leftTop = {-80, 80};
	Vector2 rightTop = {80, 80};
	Vector2 leftbottom = {-80, -80};
	Vector2 rightbottom = {80, -80};
	Vector2 center = {0, 0};

	Matrix3x3 cameraworldMatrix;
	cameraworldMatrix.m[0][0] = 1.0f;
	cameraworldMatrix.m[1][0] = 0.0f;
	cameraworldMatrix.m[2][0] = 200.0f;
	cameraworldMatrix.m[0][1] = 0.0f;
	cameraworldMatrix.m[1][1] = 1.0f;
	cameraworldMatrix.m[2][1] = 200.0f;
	cameraworldMatrix.m[0][2] = 0.0f;
	cameraworldMatrix.m[1][2] = 0.0f;
	cameraworldMatrix.m[2][2] = 1.0f;


	cameraworldMatrix.m[2][1] += -720.0f;
	cameraworldMatrix.m[2][1] *= -1;

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

		// 平行移動
		if (keys[DIK_RIGHT] || keys[DIK_D]) {
			speed.x += 10.0f;
		}
		if (keys[DIK_LEFT] || keys[DIK_A]) {
			speed.x -= 10.0f;
		}
		if (keys[DIK_DOWN] || keys[DIK_S]) {
			speed.y += 10.0f;
		}
		if (keys[DIK_UP] || keys[DIK_W]) {
			speed.y -= 10.0f;
		}

		Matrix3x3 translateMatrix = MakeTranslateMatrix(speed);

		Vector2 translatecenter = Transform(center, translateMatrix);


		Matrix3x3 worldMatrix;
		worldMatrix.m[0][0] = 1.0f;
		worldMatrix.m[1][0] = 0.0f;
		worldMatrix.m[2][0] = translatecenter.x;
		worldMatrix.m[0][1] = 0.0f;
		worldMatrix.m[1][1] = 1.0f;
		worldMatrix.m[2][1] = translatecenter.y;
		worldMatrix.m[0][2] = 0.0f;
		worldMatrix.m[1][2] = 0.0f;
		worldMatrix.m[2][2] = 1.0f;

		// ビュー行列
		Matrix3x3 viewMatrix = Inverse3x3(cameraworldMatrix);
		// 正射影行列
		Matrix3x3 orthoMatrix = MakeOrthographicMatrix(-640, 360, 640, -360);
		// ビューポート行列
		Matrix3x3 viewportMatrix = MakeViewportMatrix(0, 0, 1280, 720);
		// すべての行列の積
		Matrix3x3 wvpVpMatrix = Multiply(worldMatrix, viewMatrix);
		wvpVpMatrix = Multiply(wvpVpMatrix, orthoMatrix);
		wvpVpMatrix = Multiply(wvpVpMatrix, viewportMatrix);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Novice::DrawLine(cameraworldMatrix.m[2][0], 0, cameraworldMatrix.m[2][0], 720, RED);
		Novice::DrawLine(0, cameraworldMatrix.m[2][1], 1280, cameraworldMatrix.m[2][1], GREEN);


		Vector2 screencenter = Transform(translatecenter, wvpVpMatrix);

		Novice::DrawQuad(
		  translatecenter.x + cameraworldMatrix.m[2][0] + leftTop.x,
		  translatecenter.y + cameraworldMatrix.m[2][1] + leftTop.y,
		  translatecenter.x + cameraworldMatrix.m[2][0] + rightTop.x,
		  translatecenter.y + cameraworldMatrix.m[2][1] + rightTop.y,
		  translatecenter.x + cameraworldMatrix.m[2][0] + leftbottom.x,
		  translatecenter.y + cameraworldMatrix.m[2][1] + leftbottom.y,
		  translatecenter.x + cameraworldMatrix.m[2][0] + rightbottom.x,
		  translatecenter.y + cameraworldMatrix.m[2][1] + rightbottom.y,
		  0, 0, 80, 80, square, 0xFFFFFFFF);
		  


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

