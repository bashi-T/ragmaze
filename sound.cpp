
#include <Novice.h>
#include<math.h>

const char kWindowTitle[] = "LC1A_16_ツヅキバシマサミ_AL1-2";



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	int scene = -1;
	enum Soundscene {fanfare, mokugyo, start}; 
	int Sound1=Novice::LoadAudio("./Sounds/fanfare.wav");
	int Sound2 = Novice::LoadAudio("./Sounds/mokugyo.wav");
	int Sound3 = Novice::LoadAudio("./Sounds/start.wav");
	int playSound1=-1;
	int playSound2=-1;
	int playSound3=-1;

	Soundscene soundscene = fanfare;


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
	
			
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE]==0) {
			scene += 1;
			
		}
        	
		if (scene == 3) {
			scene = 0;
		}


		
			/// ↑更新処理ここまで
			///

			///
			/// ↓描画処理ここから
			///
		switch (scene) {
		case fanfare:
			Novice::StopAudio(playSound3);

	        if (Novice::IsPlayingAudio(playSound1)==0&&playSound1==-1) {
			    playSound1=Novice::PlayAudio(Sound1, true, 0.5f);
				playSound3 = -1;
		    }
		    break;
		case mokugyo:
			Novice::StopAudio(playSound1);
			if (Novice::IsPlayingAudio(playSound2) == 0 && playSound2 == -1) {
				playSound2 = Novice::PlayAudio(Sound2, true, 0.5f);
				playSound1 = -1;
			}
			break;
		case start:
			Novice::StopAudio(playSound2);
			if (Novice::IsPlayingAudio(playSound3) == 0 && playSound3 == -1) {
				playSound3 = Novice::PlayAudio(Sound3, true, 0.5f);
				playSound2 = -1;
			}
			break;
		}
		Novice::ScreenPrintf(10, 10, "scene==%d", scene);
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
