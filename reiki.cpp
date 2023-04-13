#include<cold.cpp>



char keys[256] = {0};
char preKeys[256] = {0};

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {


	// ライブラリの初期化

	int RE1 = Novice::LoadTexture("tohu/resource/reitouko1.png");
	int RE2 = Novice::LoadTexture("tohu/resource/reitouko2.png");

	// キー入力結果を受け取る箱

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		for (int i = 0; i < 4; i++) {
			if (coldCount[i] == 0) {
				coldColor[i] = 0xcaf4ff5f;
				ColdSet(100, 100, 48);

			}
				if (coldCount[i] > 0) {
				coldColor[i] -= 0x00000003;
			}
			coldCount[i]++;
			if (coldCount[i] > 31) {
				coldCount[i] = 0;
				coldColor[i] = 0;
			}
		}

		ColdMove(100,100);

		Novice::DrawQuad(100, 100, 100, 148, 148, 100, 148, 148, 0, 0, 48, 48, RE1, 0xffffffff);

		ColdDraw();











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
