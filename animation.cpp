#include <Novice.h>
#include<math.h>

const char kWindowTitle[] = "LC1A_16_ツヅキバシマサミ_AL1-2";



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	int playerX = 450;
	int playerY = 450;
	int plrXspd;
	int plrYspd;
	int walkcount=5;
	int walkframe=0;
	int framecount=0;
	int graphHandle1;
	int graphHandle2;
	int graphHandle3;
	int graphHandle4;
	int graphHandle5;
	int graphHandle6;
	int graphHandle7;
	int graphHandle8;
	int graphHandle9;
	int graphHandle10;
	int graphHandle11;
	int graphHandle12;
	int graphHandle13;
	int graphHandle14;
	int graphHandle15;
	int graphHandle16;	
	
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
		graphHandle1 = Novice::LoadTexture("./REsources/right0.png");
		graphHandle2 = Novice::LoadTexture("./REsources/right1.png");
		graphHandle3 = Novice::LoadTexture("./REsources/right2.png");
		graphHandle4 = Novice::LoadTexture("./REsources/right3.png");
		graphHandle5 = Novice::LoadTexture("./REsources/left0.png");
		graphHandle6 = Novice::LoadTexture("./REsources/left1.png");
		graphHandle7 = Novice::LoadTexture("./REsources/left2.png");
		graphHandle8 = Novice::LoadTexture("./REsources/left3.png");
		graphHandle9 = Novice::LoadTexture("./REsources/back0.png");
		graphHandle10 = Novice::LoadTexture("./REsources/back1.png");
		graphHandle11 = Novice::LoadTexture("./REsources/back2.png");
		graphHandle12 = Novice::LoadTexture("./REsources/back3.png");
		graphHandle13 = Novice::LoadTexture("./REsources/front0.png");
		graphHandle14 = Novice::LoadTexture("./REsources/front1.png");
		graphHandle15 = Novice::LoadTexture("./REsources/front2.png");
		graphHandle16 = Novice::LoadTexture("./REsources/front3.png");

		///
		/// ↓更新処理ここから
		///
		 plrXspd = 0;
	     plrYspd = 0;
		 framecount = 0;
		 
	

		if (keys[DIK_A]){
			plrXspd = -5;
			framecount = 1;
		}
		if (keys[DIK_D]){
			plrXspd = 5;
			framecount = 1;
		}
		if (keys[DIK_W]){
			plrYspd = -5;
			framecount = 1;
		}
		if (keys[DIK_S]){
			plrYspd = 5;
			framecount = 1;
		}
		
		if (playerX >= 1230 && keys[DIK_D]) {
			plrXspd = 0;
		}
		if (playerY >= 630 && keys[DIK_S]) {
			plrYspd = 0;
		}
		if (playerX <= 0 && keys[DIK_A]) {
			plrXspd = 0;
		}
		if (playerY <= 0 && keys[DIK_W]) {
			plrYspd = 0;
		}

		if (playerX >= 1150){
			playerX = 1150;
		}
		if (playerX <= 0){
			playerX = 0;
		}
		if (playerY >= 550){
			playerY = 550;
		}
		if (playerY <= 0){
			playerY = 0;
		}
        if (preKeys[DIK_D] && keys[DIK_D] == 0) {
			walkcount = 5;
			walkframe = 0;
		}
		if (preKeys[DIK_A] && keys[DIK_A] == 0) {
			walkcount = 5;
			walkframe = 0;

		}
		if (preKeys[DIK_S] && keys[DIK_S] == 0) {
			walkcount = 5;
			walkframe = 0;
		}
		if (preKeys[DIK_W] && keys[DIK_W] == 0) {
			walkcount = 5;
			walkframe = 0;
		}
		
		
		


		walkframe += framecount;
		playerX += plrXspd;
		playerY += plrYspd;
		if (walkframe == 1) {
			walkcount += 1;
		}
		if (walkframe == 15) {
			walkframe = 0;
		}
        if (walkcount == 4) {
			walkcount = 0;
		}
		if (walkcount == 6) {
			walkcount = 1;
		}
		
			/// ↑更新処理ここまで
			///

			///
			/// ↓描画処理ここから
			///
		Novice::ScreenPrintf(0, 0, "walkcount=%d", walkcount);
		Novice::ScreenPrintf(0, 15, "walkframe=%d", walkframe);

		if (walkcount==5) {
			Novice::DrawSprite(playerX, playerY, graphHandle13, 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (keys[DIK_D] && walkcount == 0 && keys[DIK_S] == 0 && keys[DIK_W]==0) {
			Novice::DrawSprite(playerX, playerY, graphHandle1, 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (keys[DIK_D] && walkcount == 1 && keys[DIK_S] == 0 && keys[DIK_W] == 0) {
			Novice::DrawSprite(playerX, playerY, graphHandle2, 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (keys[DIK_D] && walkcount == 2 && keys[DIK_S] == 0 && keys[DIK_W] == 0) {
			Novice::DrawSprite(playerX, playerY, graphHandle3, 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (keys[DIK_D] && walkcount == 3 && keys[DIK_S] == 0 && keys[DIK_W]==0) {
			Novice::DrawSprite(playerX, playerY, graphHandle4, 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (keys[DIK_A] && walkcount == 0 && keys[DIK_S] == 0 && keys[DIK_W]==0 ){
			Novice::DrawSprite(playerX, playerY, graphHandle5, 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (keys[DIK_A] && walkcount == 1 && keys[DIK_S] == 0 && keys[DIK_W]==0 ){
			Novice::DrawSprite(playerX, playerY, graphHandle6, 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (keys[DIK_A] && walkcount == 2 && keys[DIK_S] == 0 && keys[DIK_W]==0) {
			Novice::DrawSprite(playerX, playerY, graphHandle7, 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (keys[DIK_A] && walkcount == 3 && keys[DIK_S] == 0 && keys[DIK_W]==0) {
			Novice::DrawSprite(playerX, playerY, graphHandle8, 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (keys[DIK_W] && walkcount == 0) {
			Novice::DrawSprite(playerX, playerY, graphHandle9, 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (keys[DIK_W] && walkcount == 1) {
			Novice::DrawSprite(playerX, playerY, graphHandle10, 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (keys[DIK_W] && walkcount == 2) {
			Novice::DrawSprite(playerX, playerY, graphHandle11, 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (keys[DIK_W] && walkcount == 3) {
			Novice::DrawSprite(playerX, playerY, graphHandle12, 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (keys[DIK_S] && walkcount == 0) {
			Novice::DrawSprite(playerX, playerY, graphHandle13, 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (keys[DIK_S] && walkcount == 1) {
			Novice::DrawSprite(playerX, playerY, graphHandle14, 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (keys[DIK_S] && walkcount == 2) {
			Novice::DrawSprite(playerX, playerY, graphHandle15, 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (keys[DIK_S] && walkcount == 3) {
			Novice::DrawSprite(playerX, playerY, graphHandle16, 1, 1, 0.0f, 0xFFFFFFFF);
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
