﻿#include <Novice.h>

const char kWindowTitle[] = "LC1A_16_ツヅキバシマサミ_AL1-2";



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	int a = 450;
	int b = 450;
	int bulletx[6] = {a,a,a,a,a,a};
	int bullety[6] = {b, b, b, b, b, b};
	int aspd;
	int bspd;
	int yspd1;
	int yspd2;
	int yspd3;
	int yspd4;
	int yspd5;
	int yspd6;
	int bulletshot = 0;
	int enemyX = 30;
	int enemyY = 30;
	int enespd = 10;
	int respown = 120;
	int graphHandle = Novice::LoadTexture("./Resources/explode.png");
	float A=0;
	float B=0;
	float DIST;
	int enemyhit = 0;

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
		aspd = 0;
		bspd = 0;
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
			bulletshot = 1;
		}
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE]) {
			bulletshot += 1;
		}
		if (bullety[5] <= -25) {
			bulletshot = 0;
		}

		if (bulletshot == 0) {
			yspd1 = 0;
			bullety[0] = b - 5;
			bulletx[0] = a;
		}
		if (bulletshot >= 1) {
			yspd1 = -10;
			bullety[0] += yspd1;
			bulletx[0] += 0;
		}

		if (bulletshot >= 0 && bulletshot <= 5) {
			yspd2 = 0;
			bullety[1] = b - 5;
			bulletx[1] = a;
		}
		if (bulletshot >= 6) {
			yspd2 = -10;
			bullety[1] += yspd2;
			bulletx[1] += 0;
		}
		if (bulletshot >= 0 && bulletshot <= 10) {
			yspd3 = 0;
			bullety[2] = b - 5;
			bulletx[2] = a;
		}
		if (bulletshot >= 11) {
			yspd3 = -10;
			bullety[2] += yspd3;
			bulletx[2] += 0;
		}
		if (bulletshot >= 0 && bulletshot <= 15) {
			yspd4 = 0;
			bullety[3] = b - 5;
			bulletx[3] = a;
		}
		if (bulletshot >= 16) {
			yspd4 = -10;
			bullety[3] += yspd4;
			bulletx[3] += 0;
		}
		if (bulletshot >= 0 && bulletshot <= 20) {
			yspd5 = 0;
			bullety[4] = b - 5;
			bulletx[4] = a;
		}
		if (bulletshot >= 21) {
			yspd5 = -10;
			bullety[4] += yspd5;
			bulletx[4] += 0;
		}
		if (bulletshot >= 0 && bulletshot <= 25) {
			yspd6 = 0;
			bullety[5] = b - 5;
			bulletx[5] = a;
		}
		if (bulletshot >= 26) {
			yspd6 = -10;
			bullety[5] += yspd6;
			bulletx[5] += 0;
		}

		if (keys[DIK_A]) {
			aspd = -10;
		}
		if (keys[DIK_D]) {
			aspd = 10;
		}
		if (keys[DIK_W]) {
			bspd = -10;
		}
		if (keys[DIK_S]) {
			bspd = 10;
		}
		if (aspd == 10 && bspd == 10) {
			aspd = 7;
			bspd = 7;
		}
		if (aspd == 10 && bspd == -10) {
			aspd = 7;
			bspd = -7;
		}
		if (aspd == -10 && bspd == 10) {
			aspd = -7;
			bspd = 7;
		}
		if (aspd == -10 && bspd == -10) {
			aspd = -7;
			bspd = -7;
		}
		if (a >= 1260 && keys[DIK_D]) {
			aspd = 0;
		}
		if (b >= 700 && keys[DIK_S]) {
			bspd = 0;
		}
		if (a <= 20 && keys[DIK_A]) {
			aspd = 0;
		}
		if (b <= 20 && keys[DIK_W]) {
			bspd = 0;
		}

		if (a >= 1260) {
			a = 1260;
		}
		if (a <= 20) {
			a = 20;
		}
		if (b >= 700) {
			b = 700;
		}
		if (b <= 20) {
			b = 20;
		}
		a += aspd;
		b += bspd;

		enemyX += enespd;
		for (int i = 0; i < 6; i++) {

			A = bulletx[i] - enemyX;
			B = bullety[i] - enemyY;
			DIST = B * B + A * A;
			if (DIST <= 900 && DIST >= -900) {
				enemyhit = 2;
			}
		}
		if (enemyhit == 2) {
			respown += -1;
		}
		if (respown == 0 && enemyX <= a) {
			enespd = -10;
		}
		if (respown == 0 && enemyX > a) {
			enespd = 10;
		}
		if (respown == 0) {
			enemyhit = 0;
			respown = 120;
		}

		if (enemyX == 1260) {
			enespd = -10;
		}
		if (enemyX == 20) {
			enespd = 10;
		}
		if (enemyhit == 2) {
			enespd = 0;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Novice::ScreenPrintf(10, 10, "bulletshot=%d", bulletshot);
		Novice::ScreenPrintf(10, 25, "bulletx=%d", bulletx[0]);
		Novice::ScreenPrintf(10, 40, "bullety=%d", bullety[0]);
		if (bulletshot >= 1) {
			Novice::DrawTriangle(
			  bulletx[0], bullety[0], bulletx[0] - 5, bullety[0] + 25, bulletx[0] + 5, bullety[0] + 25,
			  0xFFFFFFFF, kFillModeSolid);
		}
		if (bulletshot >= 6) {
			Novice::DrawTriangle(
			  bulletx[1], bullety[1], bulletx[1] - 5, bullety[1] + 25, bulletx[1] + 5, bullety[1] + 25,
			  0xFFFFFFFF, kFillModeSolid);
		}
		if (bulletshot >= 11) {
			Novice::DrawTriangle(
			  bulletx[2], bullety[2], bulletx[2] - 5, bullety[2] + 25, bulletx[2] + 5, bullety[2] + 25,
			  0xFFFFFFFF, kFillModeSolid);
		}
		if (bulletshot >= 16) {
			Novice::DrawTriangle(
			  bulletx[3], bullety[3], bulletx[3] - 5, bullety[3] + 25, bulletx[3] + 5, bullety[3] + 25,
			  0xFFFFFFFF, kFillModeSolid);
		}
		if (bulletshot >= 21) {
			Novice::DrawTriangle(
			  bulletx[4], bullety[4], bulletx[4] - 5, bullety[4] + 25, bulletx[4] + 5,bullety[4] + 25,
			  0xFFFFFFFF, kFillModeSolid);
		}
		if (bulletshot >= 26) {
			Novice::DrawTriangle(
			  bulletx[5], bullety[5], bulletx[5] - 5, bullety[5] + 25, bulletx[5] + 5, bullety[5] + 25,
			  0xFFFFFFFF, kFillModeSolid);
		}
		Novice::DrawEllipse(a, b, 20, 20, 0.0f, 0xFF0000FF, kFillModeSolid);
		if (enemyhit < 2) {
			Novice::DrawEllipse(enemyX, enemyY, 20, 20, 0.0f, 0x0000FF, kFillModeSolid);
		}
		if (enemyhit == 2 && respown >= 90) {
			Novice::DrawSprite(enemyX - 30, enemyY - 30, graphHandle, 3, 3, 0.0f, 0xFFFFFFFF);
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
