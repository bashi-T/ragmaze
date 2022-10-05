#include <Novice.h>
#include<math.h>

const char kWindowTitle[] = "LC1A_16_ツヅキバシマサミ_AL1-2";



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	int playerX = 450;
	int playerY = 450;
	int bulletx=playerX;
	int bullety=playerY;
	int bulspd;
	int plrXspd;
	int plrYspd;
	int enemyX=30;
	int enemyY=30;
	int enespd = 10;
	int bulletshot=0;
    int respown=120;
	int graphHandle;
	float A;
	float B;
	float DIST;
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
		graphHandle = Novice::LoadTexture("./REsources/explode.png");
		///
		/// ↓更新処理ここから
		///
		 plrXspd = 0;
	     plrYspd = 0;
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
			bulletshot = 1;
		}
	
	if ( bullety<=-25) {
		bulletshot =0;

	}
		 
	

		if (keys[DIK_A]){
			plrXspd = -10;
		}
		if (keys[DIK_D]){
			plrXspd = 10;
		}
		if (keys[DIK_W]){
			plrYspd = -10;
		}
		if (keys[DIK_S]){
			plrYspd = 10;
		}
		if (plrXspd ==10 && plrYspd==10) {
			plrXspd =7;
			plrYspd =7;
		}
		if (plrXspd == 10 && plrYspd == -10) {
			plrXspd =7;
			plrYspd =-7;
		}
		if (plrXspd == -10 && plrYspd == 10) {
			plrXspd =-7;
			plrYspd =7;
		}
		if (plrXspd == -10 && plrYspd == -10) {
			plrXspd =-7;
			plrYspd =-7;
		}
		if (playerX >= 1260 && keys[DIK_D]) {
			plrXspd = 0;
		}
		if (playerY >= 680 && keys[DIK_S]) {
			plrYspd = 0;
		}
		if (playerX <= 20 && keys[DIK_A]) {
			plrXspd = 0;
		}
		if (playerY <= 0 && keys[DIK_W]) {
			plrYspd = 0;
		}

		if (playerX >= 1260){
			playerX = 1260;
		}
		if (playerX <= 20){
			playerX = 20;
		}
		if (playerY >= 680){
			playerY = 680;
		}
		if (playerY <= 0){
			playerY = 0;
		}
		A = bulletx - enemyX;
		B = bullety - enemyY;
		
		enemyX += enespd;
		DIST=B*B+A*A;
		if (DIST<= 900&&DIST>=-900) {
		bulletshot = 2;
	    } 
		if (bulletshot == 2) {
			respown += -1;
		}
		if (respown == 0 && enemyX <= playerX) {
			enespd = -10;
		}
		if (respown == 0 && enemyX > playerX) {
			enespd = 10;
		}
		if (respown == 0) {
			bulletshot = 0;
		    respown = 120;
		}	

		if (bulletshot == 0) {
			bulspd = 0;
			bullety = playerY+10;
			bulletx = playerX;
		}
		if (bulletshot == 1) {
			bulspd = -10;
			bullety += bulspd;
			bulletx += 0;
		}	
	    if (enemyX == 1260) {
			enespd = -10;
		}
		if (enemyX == 20) {
			enespd = 10;
		}
		if (bulletshot == 2) {
			enespd = 0;
		}
		playerX += plrXspd;
		playerY += plrYspd;
			/// ↑更新処理ここまで
			///

			///
			/// ↓描画処理ここから
			///
		
		Novice::ScreenPrintf(10, 10, "bulletshot=%d", bulletshot);
		Novice::ScreenPrintf(10, 25, "bulletx=%d", bulletx);
		Novice::ScreenPrintf(10, 40, "bullety=%d", bullety);
		Novice::ScreenPrintf(10, 55, "respown=%d", respown);
		Novice::ScreenPrintf(10, 70, "enemyX=%d", enemyX);
		Novice::ScreenPrintf(10, 85, "playerX=%d", playerX);
		if (bulletshot == 1) {
			Novice::DrawEllipse(bulletx, bullety, 10, 10, 0.0f, 0xFFFFFFFF, kFillModeSolid);
			
		} 
		Novice::DrawTriangle(playerX, playerY, playerX+20, playerY+40, playerX-20, playerY+40, 0xFF0000FF, kFillModeSolid);
		if (bulletshot<2) {
			Novice::DrawEllipse(enemyX, enemyY, 20, 20, 0.0f, 0x0000FF, kFillModeSolid);
		}
		if (bulletshot==2&&respown>=90) {
			Novice::DrawSprite(enemyX-30, enemyY-30, graphHandle, 3, 3, 0.0f, 0xFFFFFFFF);
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
