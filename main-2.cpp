#include <Novice.h>
#define _USE_MATH_DEFINES
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>

const char kWindowTitle[] = "エフェクトウェポン";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	int MouseX = 0;
	int MouseY = 0;
	int a = 0;
	int x = 640;
	int y = 300;
	int A = 801;
	int AA = 400;
	int frame = 1;
	float bossx = 0;
	float bossy = 0;
	float bossspdx = 0.7;
	float bossspdy = 1;
	int sword1 = Novice::LoadTexture("./resource/sword2.png");
	int sword1mouse = 1;
	int spear = Novice::LoadTexture("./resource/spear0.png");
	int spearmouse = 0;
	int sword = Novice::LoadTexture("./resource/sword.png");
	int swordmouse = 0;
	int beamsord = Novice::LoadTexture("./resource/sword1.png");
	int beamsordmouse = 0;
	int boss = Novice::LoadTexture("./resource/boss.png");
	int buki1 = Novice::LoadTexture("./resource/wepon2.png");
	int buki1mouse = 0;
	int BossX = 590;
	int BossY = 600;
	int spd = 1;
	int spd2 = 0;
	int trigger = 0;
	float MP = 100;
	float mpspd = 0.05;
	float mpspear = 0.12;
	int color = WHITE;
	int colortime = 0;
	struct Vector2
	{
		float x;
		float y;
	};

	struct Effect
	{
		Vector2 position;
	};

	Effect effect
	{
		{500,0}
	};

	int timer = 15;
	int start = 0;

	int graphhandle = Novice::LoadTexture("./resource/effect10.png");
	int graphhandle1 = Novice::LoadTexture("./resource/effect11.png");
	int graphhandle2 = Novice::LoadTexture("./resource/effect12.png");
	int graphhandle3 = Novice::LoadTexture("./resource/effect13.png");
	int graphhandle4 = Novice::LoadTexture("./resource/effect14.png");

	int graphhandle5 = Novice::LoadTexture("./resource/effect1.png");
	int graphhandle6 = Novice::LoadTexture("./resource/effect2.png");
	int graphhandle7 = Novice::LoadTexture("./resource/effect3.png");
	int graphhandle8 = Novice::LoadTexture("./resource/effect4.png");
	int graphhandle9 = Novice::LoadTexture("./resource/effect5.png");
	int graphhandle10 = Novice::LoadTexture("./resource/effect6.png");
	int graphhandle11 = Novice::LoadTexture("./resource/effect7.png");
	int graphhandle12 = Novice::LoadTexture("./resource/effect8.png");

	const int count = 20;
	int start1 = 0;
	int scalex = 400;
	int scaley = 528;

	int bigslash[7]{
	  Novice::LoadTexture("./resource/bigslash1.png"),
	  Novice::LoadTexture("./resource/bigslash2.png"),
	  Novice::LoadTexture("./resource/bigslash3.png"),
	  Novice::LoadTexture("./resource/bigslash4.png"),
	  Novice::LoadTexture("./resource/bigslash5.png"),
	  Novice::LoadTexture("./resource/bigslash6.png"),
	  Novice::LoadTexture("./resource/slash11.png"),
	};

	int BSX = 376;
	int BSY = 0;
	int BScount = 0;
	int BSsprite = 0;
	int BSnumber = 0;
	int shockRx = 0;
	int shockRy = 0;

	int sepalatex1 = 0;
	int sepalatey1 = 0;
	int sepalatex2 = 0;
	int sepalatey2 = 0;

	int burnX = 640;
	int burnY = -150;
	int burnR = 170;
	int burncount = 0;

	int scene = 0;
	int bosshp = 1000;

	int title = Novice::LoadTexture("./resource/TITLE.png");
	int explanation = Novice::LoadTexture("./resource/explanation.png");
	int clear = Novice::LoadTexture("./resource/clear.png");

	    int SEcount[6] = {-1, -1, -1, -1, -1, -1};
	int SE1 = Novice::LoadAudio("./resource/SEbomb.wav");
	int SE2 = Novice::LoadAudio("./resource/SEfire.wav");
	int SE3 = Novice::LoadAudio("./resource/SEhislash.wav");
	int SE4 = Novice::LoadAudio("./resource/SEslash1.wav");
	int SE5 = Novice::LoadAudio("./resource/SEslash2.wav");
	int SE6 = Novice::LoadAudio("./resource/SEwind.wav");

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		Novice::GetMousePosition(&MouseX, &MouseY);
		Novice::SetMouseCursorVisibility(0);

		unsigned int currentTime = time(nullptr);
		srand(currentTime);

		///
		/// ↓更新処理ここから
		///

		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && scene < 2)
		{
			scene += 1;
		}
		switch (scene)
		{
		case 1:
			break;
		case 2:
			MP += mpspd;
			if (MP >= 100) {
				MP = 100;
			}
			if (MP <= 0) {
				MP = 0;
			}

			if (preKeys[DIK_1] == 0 && keys[DIK_1] != 0) {
				sword1mouse = 1;
				swordmouse = 0;
				spearmouse = 0;
				beamsordmouse = 0;
				buki1mouse = 0;
			}
			if (preKeys[DIK_2] == 0 && keys[DIK_2] != 0) {
				sword1mouse = 0;
				swordmouse = 1;
				spearmouse = 0;
				beamsordmouse = 0;
				buki1mouse = 0;
			}
			if (preKeys[DIK_3] == 0 && keys[DIK_3] != 0) {
				sword1mouse = 0;
				swordmouse = 0;
				spearmouse = 1;
				beamsordmouse = 0;
				buki1mouse = 0;
			}
			if (preKeys[DIK_4] == 0 && keys[DIK_4] != 0) {
				sword1mouse = 0;
				swordmouse = 0;
				spearmouse = 0;
				beamsordmouse = 1;
				buki1mouse = 0;
			}
			if (preKeys[DIK_5] == 0 && keys[DIK_5] != 0) {
				sword1mouse = 0;
				swordmouse = 0;
				spearmouse = 0;
				beamsordmouse = 0;
				buki1mouse = 1;
			}
			if (bosshp <= 0) {
				bosshp = 0;
				scene = 3;
			}
			break;
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		/// 
		Novice::DrawSprite(0, 0, title, 1, 1, 0, WHITE);//タイトル画面

		switch (scene)
		{
		case 1:
			Novice::DrawSprite(0, 0, explanation, 1, 1, 0, WHITE);//説明画面
			break;
		case 2:

			Novice::DrawBox(0, 0, 2000, 2000, 0.0f, BLACK, kFillModeSolid);
			Novice::DrawSprite(bossx, bossy, boss, 1, 1, 0.0f, color);
			Novice::DrawBox(140, 10, bosshp, 20, 0.0f, RED, kFillModeSolid);
			bossx += bossspdx;
			bossy += bossspdy;
			if (bossx >= 50 || bossx <= -50) {
				bossspdx *= -1;
			}
			if (bossy >= 25 || bossy <= -25) {
				bossspdy *= -1;
			}
			if (Novice::IsPressMouse(0) && sword1mouse == 1) {
				start = 2;
				effect.position.y = rand() % 200;
				bosshp -= 0.5;
			}
			if (Novice::IsPressMouse(0) && swordmouse == 1) {
				start = 1;
				effect.position.y = rand() % 278;
				bosshp -= 0.5;
			}
			if (Novice::IsPressMouse(0) && beamsordmouse == 1) {
				start1 = 2;
				bosshp -= 0.5;
			}
			if (Novice::IsPressMouse(0) && buki1mouse == 1 && MP >= 25 && start1 != 3) {
				start1 = 3;
				MP -= 25;
				bosshp -= 50;
			}

			if (Novice::IsPressMouse(0) && MP >= 1 && spearmouse == 1) {
				bosshp -= 0.3;
				MP -= mpspear;
				frame++;
				colortime++;

				if (frame == 2) {
					SEcount[5] = -1;
					if (Novice::IsPlayingAudio(SEcount[5]) == 0 && SEcount[5] == -1) {
						SEcount[5] = Novice::PlayAudio(SE6, true, 0.5f);
					}
				}

				if (frame >= 500) {
					Novice::DrawEllipse(x, y + 200, -300 + frame, -300 + frame / 1.5, 0.0f, 0x732ae8FF, kFillModeWireFrame);
					Novice::DrawEllipse(x + 1, y + 200, -300 + frame, -300 + frame / 1.5, 0.0f, 0x860018FF, kFillModeWireFrame);
					Novice::DrawEllipse(x - 1, y + 200, -300 + frame, -300 + frame / 1.5, 0.0f, 0x9e001cFF, kFillModeWireFrame);
				}
				if (frame >= 800) {
					Novice::DrawEllipse(x, y + 200, -600 + frame, -450 + frame / 1.5, 0.0f, 0x732ae8FF, kFillModeWireFrame);
					Novice::DrawEllipse(x + 1, y + 200, -600 + frame, -450 + frame / 1.5, 0.0f, 0x860018FF, kFillModeWireFrame);
					Novice::DrawEllipse(x - 1, y + 200, -600 + frame, -450 + frame / 1.5, 0.0f, 0x9e001cFF, kFillModeWireFrame);
				}
				if (frame >= 1100) {
					Novice::DrawEllipse(x, y + 200, -900 + frame, -600 + frame / 1.5, 0.0f, 0x732ae8FF, kFillModeWireFrame);
					Novice::DrawEllipse(x + 1, y + 200, -900 + frame, -600 + frame / 1.5, 0.0f, 0x860018FF, kFillModeWireFrame);
					Novice::DrawEllipse(x - 1, y + 200, -900 + frame, -600 + frame / 1.5, 0.0f, 0x9e001cFF, kFillModeWireFrame);
				}
				for (int i = 0; i < 36; i++) {
					x += 14;
					y += 20;
					A -= 20;
					AA -= -4;
					if (frame >= 125) {
						Novice::DrawBox(940 + rand() % 601 - 600, 500 + rand() % 13 - 6, 9, 9, rand() % 3 - 1, 0x860018FF, kFillModeSolid);
						Novice::DrawBox(940 + rand() % 601 - 600, 500 + rand() % 13 - 6, 6, 6, rand() % 3 - 1, 0x860018FF, kFillModeSolid);
					}
					if (frame >= 312) {
						Novice::DrawBox(780 + rand() % 701 - 500, 400 + rand() % 13 - 6, 11, 11, rand() % 3 - 1, 0x9e001cFF, kFillModeSolid);
						Novice::DrawBox(780 + rand() % 701 - 500, 400 + rand() % 13 - 6, 6, 6, rand() % 3 - 1, 0x9e001cFF, kFillModeSolid);
					}
					if (frame >= 500) {
						Novice::DrawBox(640 + rand() % 801 - 400, 300 + rand() % 13 - 6, 11, 11, rand() % 3 - 1, 0xce0025FF, kFillModeSolid);
						Novice::DrawBox(640 + rand() % 801 - 400, 300 + rand() % 13 - 6, 8, 8, rand() % 3 - 1, 0xce0025FF, kFillModeSolid);

					}
					if (frame >= 2) {
						for (int j = 0; j < 5; j++) {
							//Novice::DrawEllipse(x + rand() % A - AA, y - 250 + rand() % 13 - 6, 1.5, 1.5, 0.0f, BLUE, kFillModeSolid);
							Novice::DrawBox(x + rand() % A - AA, y - 250 + rand() % 13 - 6, 6, 6, rand() % 3 - 1, BLUE, kFillModeSolid);
						}
					}
					if (frame >= 250) {
						for (int j = 0; j < 5; j++) {
							Novice::DrawBox(x + rand() % A - AA, y - 250 + rand() % 13 - 6, 9, 9, rand() % 3 - 1, 0x5290FFFF, kFillModeSolid);
						}
					}
					if (frame >= 375) {
						for (int j = 0; j < 5; j++) {
							Novice::DrawBox(x + rand() % A - AA, y - 250 + rand() % 13 - 6, 10, 10, rand() % 3 - 1, 0x4ed7ffFF, kFillModeSolid);
						}
					}
					if (frame >= 500) {
						for (int j = 0; j < 5; j++) {
							//Novice::DrawEllipse(x + rand() % A - AA, y - 250 + rand() % 13 - 6, 6, 6,0.0f, 0x732ae8FF, kFillModeSolid);
							Novice::DrawBox(x + rand() % A - AA, y - 250 + rand() % 13 - 6, 15, 15, rand() % 3 - 1, 0x732ae8FF, kFillModeSolid);
						}
					}
				}

				x = 640;
				y = 300;
				A = 801;
				AA = 400;
				if (frame >= 1500) {
					frame = 1500;
				}
			}
			else
			{
				frame -= 2;
				if (frame >= 500) {
					Novice::DrawEllipse(x, y + 200, -300 + frame, -300 + frame / 1.5, 0.0f, 0x732ae8FF, kFillModeWireFrame);
					Novice::DrawEllipse(x + 1, y + 200, -300 + frame, -300 + frame / 1.5, 0.0f, 0x860018FF, kFillModeWireFrame);
					Novice::DrawEllipse(x - 1, y + 200, -300 + frame, -300 + frame / 1.5, 0.0f, 0x9e001cFF, kFillModeWireFrame);
				}
				if (frame >= 800) {
					Novice::DrawEllipse(x, y + 200, -600 + frame, -450 + frame / 1.5, 0.0f, 0x732ae8FF, kFillModeWireFrame);
					Novice::DrawEllipse(x + 1, y + 200, -600 + frame, -450 + frame / 1.5, 0.0f, 0x860018FF, kFillModeWireFrame);
					Novice::DrawEllipse(x - 1, y + 200, -600 + frame, -450 + frame / 1.5, 0.0f, 0x9e001cFF, kFillModeWireFrame);
				}
				if (frame >= 1100) {
					Novice::DrawEllipse(x, y + 200, -900 + frame, -600 + frame / 1.5, 0.0f, 0x732ae8FF, kFillModeWireFrame);
					Novice::DrawEllipse(x + 1, y + 200, -900 + frame, -600 + frame / 1.5, 0.0f, 0x860018FF, kFillModeWireFrame);
					Novice::DrawEllipse(x - 1, y + 200, -900 + frame, -600 + frame / 1.5, 0.0f, 0x9e001cFF, kFillModeWireFrame);
				}
				for (int i = 0; i < 36; i++) {
					x += 14;
					y += 20;
					A -= 20;
					AA -= -4;
					if (frame >= 125) {
						Novice::DrawBox(940 + rand() % 601 - 600, 500 + rand() % 13 - 6, 9, 9, rand() % 3 - 1, 0x860018FF, kFillModeSolid);
						Novice::DrawBox(940 + rand() % 601 - 600, 500 + rand() % 13 - 6, 6, 6, rand() % 3 - 1, 0x860018FF, kFillModeSolid);
					}
					if (frame >= 312) {
						Novice::DrawBox(780 + rand() % 701 - 500, 400 + rand() % 13 - 6, 11, 11, rand() % 3 - 1, 0x9e001cFF, kFillModeSolid);
						Novice::DrawBox(780 + rand() % 701 - 500, 400 + rand() % 13 - 6, 6, 6, rand() % 3 - 1, 0x9e001cFF, kFillModeSolid);
					}
					if (frame >= 500) {
						Novice::DrawBox(640 + rand() % 801 - 400, 300 + rand() % 13 - 6, 11, 11, rand() % 3 - 1, 0xce0025FF, kFillModeSolid);
						Novice::DrawBox(640 + rand() % 801 - 400, 300 + rand() % 13 - 6, 8, 8, rand() % 3 - 1, 0xce0025FF, kFillModeSolid);

					}
					if (frame >= 2) {
						for (int j = 0; j < 5; j++) {
							//Novice::DrawEllipse(x + rand() % A - AA, y - 250 + rand() % 13 - 6, 1.5, 1.5, 0.0f, BLUE, kFillModeSolid);
							Novice::DrawBox(x + rand() % A - AA, y - 250 + rand() % 13 - 6, 6, 6, rand() % 3 - 1, BLUE, kFillModeSolid);
						}
					}
					if (frame >= 250) {
						for (int j = 0; j < 5; j++) {
							Novice::DrawBox(x + rand() % A - AA, y - 250 + rand() % 13 - 6, 9, 9, rand() % 3 - 1, 0x5290FFFF, kFillModeSolid);
						}
					}
					if (frame >= 375) {
						for (int j = 0; j < 5; j++) {
							Novice::DrawBox(x + rand() % A - AA, y - 250 + rand() % 13 - 6, 10, 10, rand() % 3 - 1, 0x4ed7ffFF, kFillModeSolid);
						}
					}
					if (frame >= 500) {
						for (int j = 0; j < 5; j++) {
							//Novice::DrawEllipse(x + rand() % A - AA, y - 250 + rand() % 13 - 6, 6, 6,0.0f, 0x732ae8FF, kFillModeSolid);
							Novice::DrawBox(x + rand() % A - AA, y - 250 + rand() % 13 - 6, 15, 15, rand() % 3 - 1, 0x732ae8FF, kFillModeSolid);
						}
					}
				}
				x = 640;
				y = 300;
				A = 801;
				AA = 400;
				if (frame <= 0) {
					frame = 1;
				}
				if (frame == 1) {
					Novice::StopAudio(SEcount[5]);
				}

				colortime = 0;
				color = WHITE;
			}
			if (start == 1 || start == 2)
			{
				timer -= 1;
			}

			if (timer == -15)
			{
				start = 0;
				timer = 15;
			}
			if (start == 1) {
				SEcount[3] = -1;

				if (timer == 14) {
					if (Novice::IsPlayingAudio(SEcount[3]) == 0 && SEcount[3] == -1) {
						SEcount[3] = Novice::PlayAudio(SE4, false, 0.5f);
					}
				}

				if (timer <= 14 && timer >= 10)
				{
					Novice::DrawSprite(effect.position.x, effect.position.y, graphhandle, 1, 1, 0, WHITE);
				}
				if (timer <= 10 && timer > 5)
				{
					Novice::DrawSprite(effect.position.x, effect.position.y, graphhandle1, 1, 1, 0, WHITE);
				}
				if (timer <= 5 && timer >= 0)
				{
					Novice::DrawSprite(effect.position.x, effect.position.y, graphhandle2, 1, 1, 0, WHITE);
				}
				if (timer <= 0 && timer >= -5)
				{
					Novice::DrawSprite(effect.position.x, effect.position.y, graphhandle3, 1, 1, 0, WHITE);
				}
				if (timer <= -5 && timer >= -10)
				{
					Novice::DrawSprite(effect.position.x, effect.position.y, graphhandle4, 1, 1, 0, WHITE);
				}
			}

			if (start == 2) {
				SEcount[4] = -1;
				if (timer == 14) {
					if (Novice::IsPlayingAudio(SEcount[4]) == 0 && SEcount[4] == -1) {
						SEcount[4] = Novice::PlayAudio(SE5, false, 0.5f);
					}
				}

				if (timer <= 14 && timer >= 11)
				{
					Novice::DrawSprite(effect.position.x, effect.position.y, graphhandle5, 1, 1, 0, WHITE);
				}
				if (timer <= 11 && timer > 8)
				{
					Novice::DrawSprite(effect.position.x, effect.position.y, graphhandle6, 1, 1, 0, WHITE);
				}
				if (timer <= 8 && timer >= 5)
				{
					Novice::DrawSprite(effect.position.x, effect.position.y, graphhandle7, 1, 1, 0, WHITE);
				}
				if (timer <= 5 && timer >= 2)
				{
					Novice::DrawSprite(effect.position.x, effect.position.y, graphhandle8, 1, 1, 0, WHITE);
				}
				if (timer <= -1 && timer >= -4)
				{
					Novice::DrawSprite(effect.position.x, effect.position.y, graphhandle9, 1, 1, 0, WHITE);
				}
				if (timer <= -4 && timer >= -7)
				{
					Novice::DrawSprite(effect.position.x, effect.position.y, graphhandle10, 1, 1, 0, WHITE);
				}
				if (timer <= -7 && timer >= -10)
				{
					Novice::DrawSprite(effect.position.x, effect.position.y, graphhandle11, 1, 1, 0, WHITE);
				}
			}
	
			Novice::DrawBox(0, 600, MP * 3, 655, 0.0f, BLUE, kFillModeSolid);//MPゲージ
			Novice::DrawBox(0, 656, 1280, 64, 0.0f, WHITE, kFillModeSolid);//下の白い枠

			if (sword1mouse == 1) {
				Novice::DrawSprite(MouseX - 56, MouseY - 7, sword1, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(64, 656, sword, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(128, 656, spear, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(192, 656, beamsord, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(256, 656, buki1, 1, 1, 0.0f, WHITE);
			}
			if (spearmouse == 1) {
				Novice::DrawSprite(MouseX - 56, MouseY - 7, spear, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(0, 656, sword1, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(64, 656, sword, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(192, 656, beamsord, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(256, 656, buki1, 1, 1, 0.0f, WHITE);
			}
			if (swordmouse == 1) {
				Novice::DrawSprite(MouseX - 56, MouseY - 7, sword, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(0, 656, sword1, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(128, 656, spear, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(192, 656, beamsord, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(256, 656, buki1, 1, 1, 0.0f, WHITE);
			}
			if (beamsordmouse == 1) {
				Novice::DrawSprite(MouseX - 56, MouseY - 7, beamsord, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(0, 656, sword1, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(64, 656, sword, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(128, 656, spear, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(256, 656, buki1, 1, 1, 0.0f, WHITE);
			}
			if (buki1mouse == 1) {
				Novice::DrawSprite(MouseX - 56, MouseY - 7, buki1, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(0, 656, sword1, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(64, 656, sword, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(128, 656, spear, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(192, 656, beamsord, 1, 1, 0.0f, WHITE);
			}
			if (start1 == 2) {
				BScount++;
				if (BSnumber == 1 && BScount == 1) {
					SEcount[2] = -1;
				}

				if (BScount == 1) {
					BSsprite = bigslash[BSnumber];
					BSnumber++;
				}
				if (BScount == 5) {
					BScount = 0;
				}
				if (BSnumber > 2) {
					if (BScount / 2 == 0) {
						sepalatey1 = 5;
					}
					if (BScount / 2 == 1) {
						sepalatey1 = -5;
					}
					shockRx += 150;
					shockRy += 5;
				}
			}
			if (BSnumber == 6 && BScount == 4) {
				start1 = 0;
				BScount = 0;
				BSnumber = 0;
				shockRx = 0;
				shockRy = 0;
				sepalatey1 = 0;
				Novice::StopAudio(SEcount[2]);
			}

			if (start1 == 3) {
				burncount++;
				if (burncount == 1) {
					SEcount[1] = -1;
				}

				if (burncount < 180) {
					burnY += 1;
				}

				if (burncount >= 180) {
					Novice::StopAudio(SEcount[1]);
					burnR += 200;

					if (burncount == 181) {
						SEcount[0] = -1;
					}
				}

				if (burncount > 240) {
					burnX = 640;
					burnY = -150;
					burnR = 170;
					burncount = 0;
					start1 = 0;
					Novice::StopAudio(SEcount[0]);
				}
			}
			if (start1 != 0) {
				Novice::DrawBox(0, 0, 1280, 528, 0.0f, 0x000000ea, kFillModeSolid);
			}

			if (start1 == 2) {
				if (Novice::IsPlayingAudio(SEcount[2]) == 0 && SEcount[2] == -1) {
					SEcount[2] = Novice::PlayAudio(SE3, false, 0.5f);
				}

				if (BSnumber > 2) {
					Novice::DrawEllipse(
						640 + sepalatex1, 500 + sepalatey1, shockRx, shockRy, 0.0f, 0xFFFFFFFF,
						kFillModeWireFrame);
					Novice::DrawEllipse(
						640 + sepalatex1, 500 + sepalatey1, shockRx - 1, shockRy - 1, 0.0f, 0xFFFFFFFF,
						kFillModeWireFrame);
					Novice::DrawEllipse(
						640 + sepalatex1, 500 + sepalatey1, shockRx - 2, shockRy - 2, 0.0f, 0xFFFFFFFF,
						kFillModeWireFrame);
					Novice::DrawEllipse(
						640 + sepalatex1, 500 + sepalatey1, shockRx - 3, shockRy - 3, 0.0f, 0xFFFFFFFF,
						kFillModeWireFrame);
					Novice::DrawEllipse(
						640 + sepalatex1, 500 + sepalatey1, shockRx - 4, shockRy - 4, 0.0f, 0xFFFFFFFF,
						kFillModeWireFrame);
					Novice::DrawEllipse(
						640 + sepalatex1, 500 + sepalatey1, shockRx - 5, shockRy - 5, 0.0f, 0xFFFFFFFF,
						kFillModeWireFrame);
					Novice::DrawEllipse(
						640 + sepalatex1, 500 + sepalatey1, shockRx - 6, shockRy - 6, 0.0f, 0xFFFFFFFF,
						kFillModeWireFrame);
					Novice::DrawEllipse(
						640 + sepalatex1, 500 + sepalatey1, shockRx - 7, shockRy - 7, 0.0f, 0xFFFFFFFF,
						kFillModeWireFrame);
					Novice::DrawEllipse(
						640 + sepalatex1, 500 + sepalatey1, shockRx - 8, shockRy - 8, 0.0f, 0xFFFFFFFF,
						kFillModeWireFrame);
					Novice::DrawEllipse(
						640 + sepalatex1, 500 + sepalatey1, shockRx - 9, shockRy - 9, 0.0f, 0xFFFFFFFF,
						kFillModeWireFrame);
				}
				Novice::DrawQuad(
					BSX + sepalatex2, BSY + sepalatey2, BSX + scalex + sepalatex2, BSY + sepalatey2,
					BSX + sepalatex2, BSY + scaley + sepalatey2, BSX + scalex + sepalatex2, BSY + scaley + sepalatey2,
					0, 0, scalex, scaley, bigslash[BSnumber], 0xFFFFFFFF);



			}
			if (start1 == 3 && burncount < 185) {
				Novice::DrawEllipse(
				  burnX + sepalatex1, burnY + sepalatey1, burnR + 150, burnR + 150, 0.0f,
				  0xff0000FF, kFillModeSolid);
				for (int i = 0; i < 100; i++) {
					Novice::DrawEllipse(
					  burnX + sepalatex1, burnY + sepalatey1, burnR + 100 - i, burnR + 100 - i,
					  0.0f, 0xff0000FF + i * 0x00020200, kFillModeSolid);
				}

				Novice::DrawEllipse(
				  burnX + sepalatex1, burnY + sepalatey1, burnR, burnR, 0.0f, 0xFFFFFFFF,
				  kFillModeSolid);

				if (Novice::IsPlayingAudio(SEcount[1]) == 0 && SEcount[1] == -1) {
					SEcount[1] = Novice::PlayAudio(SE2, false, 0.25f);
				}

				if (Novice::IsPlayingAudio(SEcount[0]) == 0 && SEcount[0] == -1) {
					SEcount[0] = Novice::PlayAudio(SE1, false, 0.5f);
				}
			}
			if (colortime >= 15 && colortime <= 30) {
				color = RED;
			}
			if (colortime >= 31) {
				colortime = 0;
				color = WHITE;
			}
			break;
				case 3:
					Novice::DrawSprite(0, 0, clear, 1, 1, 0, WHITE);//クリア画面
					if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
					{
						scene = 0;
						bosshp = 1000;
					}
					break;
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