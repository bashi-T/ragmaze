#include <Novice.h>
#define _USE_MATH_DEFINES
#include<math.h>
const char kWindowTitle[] = "LC1A_16_ツヅキバシマサミ_MT1";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	float theta = (1.0/2.0f)*M_PI;
	float box1X=60;
	float box1Y=60;
	float box2X = box1X;
	float box2Y = box1Y;
	float box3X = box2X;
	float box3Y = box2Y;
	float box4X = box3X;
	float box4Y = box3Y;
	float box5X = box4X;
	float box5Y = box4Y;
	float box6X = box5X;
	float box6Y = box5Y;
	float box7X = box6X;
	float box7Y = box6Y;
	float box8X = box7X;
	float box8Y = box7Y;
	float box9X = box8X;
	float box9Y = box8Y;
	float box10X = box9X;
	float box10Y = box9Y;
	float box11X = box10X;
	float box11Y = box10Y;
	float box12X = box11X;
	float box12Y = box11Y;
	float box13X = box12X;
	float box13Y = box12Y;
	float box14X = box13X;
	float box14Y = box13Y;
	float box15X = box14X;
	float box15Y = box14Y;
	float box16X = box15X;
	float box16Y = box15Y;
	float box17X = box16X;
	float box17Y = box16Y;
	float box18X = box17X;
	float box18Y = box17Y;
	float box19X = box18X;
	float box19Y = box18Y;
	float box20X = box19X;
	float box20Y = box19Y;
	float box21X = box20X;
	float box21Y = box20Y;
	float box22X = box21X;
	float box22Y = box21Y;
	float box23X = box22X;
	float box23Y = box22Y;
	float box24X = box23X;
	float box24Y = box23Y;
	float box25X = box24X;
	float box25Y = box24Y;
	float box26X = box25X;
	float box26Y = box25Y;
	float box27X = box26X;
	float box27Y = box26Y;
	float box28X = box27X;
	float box28Y = box27Y;
	float box29X = box28X;
	float box29Y = box28Y;
	float box30X = box29X;
	float box30Y = box29Y;
	float box31X = box30X;
	float box31Y = box30Y;
	float box32X = box31X;
	float box32Y = box31Y;
	float box33X = box32X;
	float box33Y = box32Y;
	float box34X = box33X;
	float box34Y = box33Y;
	float box35X = box34X;
	float box35Y = box34Y;

	float Xvec;
	float Yvec;
	float speed=0;

	
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		speed = 0;
		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		Novice::GetMousePosition;
		
      if (keys[DIK_D]) {
			theta=(0.0f)*M_PI;
		    speed = 25.0f;
		}
		if (keys[DIK_A]) {
			theta=M_PI;
			speed = 25.0f;
		}
		if (keys[DIK_S]) {
			theta=(3.0/2.0f)*M_PI;
			speed = 25.0f;
		}
		if (keys[DIK_W]) {
			theta=(1.0/2.0f)*M_PI;
			speed = 25.0f;
		}


		if (keys[DIK_D] && keys[DIK_W]) {
			theta = (1.0 / 4.0f) * M_PI;
		}
		if (keys[DIK_A] && keys[DIK_W]) {
			theta = (3.0 / 4.0f) * M_PI;
		}
		if (keys[DIK_A] && keys[DIK_S]) {
			theta = (5.0 / 4.0f) * M_PI;
		}
		if (keys[DIK_D] && keys[DIK_S]) {
			theta = (7.0 / 4.0f) * M_PI;
		}


		if (box1X >= 1230 && keys[DIK_D]) {
			speed = 0;
		}
		if (box1Y >= 670 && keys[DIK_S]) {
			speed = 0;
		}
		if (box1X <= 0 && keys[DIK_A]) {
			speed = 0;
		}
		if (box1Y <= 0 && keys[DIK_W]) {
			speed = 0;
		}

		box35X = box34X;
		box35Y = box34Y;
		box34X = box33X;
		box34Y = box33Y;
		box33X = box32X;
		box33Y = box32Y;
		box32X = box31X;
		box32Y = box31Y;
		box31X = box30X;
		box31Y = box30Y;
		box30X = box29X;
		box30Y = box29Y;
		box29X = box28X;
		box29Y = box28Y;
		box28X = box27X;
		box28Y = box27Y;
		box27X = box26X;
		box27Y = box26Y;
		box26X = box25X;
		box26Y = box25Y;
		box25X = box24X;
		box25Y = box24Y;
		box24X = box23X;
		box24Y = box23Y;
		box23X = box22X;
		box23Y = box22Y;
		box22X = box21X;
		box22Y = box21Y;
		box21X = box20X;
		box21Y = box20Y;
		box20X = box19X;
		box20Y = box19Y;
		box19X = box18X;
		box19Y = box18Y;
		box18X = box17X;
		box18Y = box17Y;
		box17X = box16X;
		box17Y = box16Y;
		box16X = box15X;
		box16Y = box15Y;
		box15X = box14X;
		box15Y = box14Y;
		box14X = box13X;
		box14Y = box13Y;
		box13X = box12X;
		box13Y = box12Y;
		box12X = box11X;
		box12Y = box11Y;
		box11X = box10X;
		box11Y = box10Y;
		box10X = box9X;
		box10Y = box9Y;
		box9X = box8X;
		box9Y = box8Y;
		box8X = box7X;
		box8Y = box7Y;
		box7X = box6X;
		box7Y = box6Y;
		box6X = box5X;
		box6Y = box5Y;
		box5X = box4X;
		box5Y = box4Y;
		box4X = box3X;
		box4Y = box3Y;
		box3X = box2X;
		box3Y = box2Y;
		box2X = box1X;
		box2Y = box1Y;
		Xvec = cosf(theta);
		Yvec = sinf(theta);
		box1X += Xvec*speed;
		box1Y -= Yvec*speed;

        Novice::DrawBox(box1X, box1Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box2X, box2Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box3X, box3Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box4X, box4Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box5X, box5Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box6X, box6Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box7X, box7Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box8X, box8Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box9X, box9Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box10X, box10Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box11X, box11Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box12X, box12Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box13X, box13Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box14X, box14Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box15X, box15Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box16X, box16Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box17X, box17Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box18X, box18Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box19X, box19Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box20X, box20Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box21X, box21Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box22X, box22Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box23X, box23Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box24X, box24Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box25X, box25Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box26X, box26Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box27X, box27Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box28X, box28Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box29X, box29Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box30X, box30Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box31X, box31Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box32X, box32Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box33X, box33Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box34X, box34Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(box35X, box35Y, 50, 50, 0.0f, WHITE, kFillModeSolid);
		
	     
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