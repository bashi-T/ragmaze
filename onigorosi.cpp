#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <onigorosi.h>

const char kWindowTitle[] = "�G�t�F�N�g�E�F�|��";

// Windows�A�v���ł̃G���g���[�|�C���g(main�֐�)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ���C�u�����̏�����
	Novice::Initialize(kWindowTitle, 1280, 720);

	// �L�[���͌��ʂ��󂯎�锠
	char keys[256] = {0};
	char preKeys[256] = {0};

	// �E�B���h�E�́~�{�^�����������܂Ń��[�v
	while (Novice::ProcessMessage() == 0) {
		// �t���[���̊J�n
		Novice::BeginFrame();

		// �L�[���͂��󂯎��
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		unsigned int currentTime = time(nullptr);

		///
		/// ���X�V������������
		///

		if (hitTime == 0) {
			if (keys[DIK_D]) {
				jikiX += jikivelX;
			}
			if (keys[DIK_A]) {
				jikiX -= jikivelX;
			}
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && jumpcount == 0) {
				jikivelY += jumpheight;
				jumpcount = 1;
			}
			jikivelY -= 1;
			jikiY -= jikivelY;
			if (jikiY > 500) {
				jikiY = 500;
				jikivelY = 0;
				jumpcount = 0;
			}
		}
		if (
		  (jikiY + mapsize / 2) - (oniY + mapsize / 2) < mapsize &&
		  (jikiY + mapsize / 2) - (oniY + mapsize / 2) > -mapsize &&
		  (jikiX + mapsize / 2) - (oniX + mapsize / 2) < mapsize &&
		  (jikiX + mapsize / 2) - (oniX + mapsize / 2) > -mapsize&&
			bustercount==0) {
			bustercount = 1;
		}
		if (bustercount > 0) {
			hitTime += 1;
		}
		if (bustercount == 0) {
			hitTime = 0;
		}
		if (bustercount == 1) {
			for (int i = 0; i < effect; i++) {
				srand(currentTime+i*i);

				randamX[i] = rand();
				randamY[i] = rand();

				bloodX[i] = oniX + mapsize / 2;
				//-2;
				bloodY[i] = oniY + mapsize / 2;
				//-2;

				bloodvelX[i] = randamX[i] % splashX - splashX/2;
				bloodvelY[i] = randamY[i] % splashY;
			}
			if (hitTime < 60 && hitTime % 4 == 3) {
				sepalateX = 5;
			}else if (hitTime < 60 && hitTime % 4 == 1) {
				sepalateX = -5;
			} else {
				sepalateX = 0;
			}
			
		}
		if (hitTime > 60) {
			bustercount = 2;
			sepalateX = 0;
		}
		if (bustercount == 2) {
			for (int i = 0; i < effect; i++) {
				bloodvelY[i] -= 2;
				bloodX[i] += bloodvelX[i];
				bloodY[i] -= bloodvelY[i];
			}
		}

		///
		/// ���X�V���������܂�
		///

		///
		/// ���`�揈����������
		///
		///
		Novice::DrawBox(jikiX, jikiY, mapsize, mapsize, 0.0f, BLUE, kFillModeSolid);

		if (bustercount != 2) {
			Novice::DrawBox(
			  oniX + sepalateX, oniY + sepalateY, mapsize, mapsize, 0.0f, RED, kFillModeSolid);
		}
		if (bustercount == 2) {
			for (int i = 0; i < effect; i++) {
				//Novice::DrawQuad(
				//  bloodX[i], bloodY[i], bloodX[i], bloodY[i] + 8, bloodX[i] + 8, bloodY[i],
				//  bloodX[i] + 8, bloodY[i] + 8, 0, 0, 8, 8, floor, 0xFFFFFFFF);
				Novice::DrawEllipse(
				  bloodX[i], bloodY[i], radius, radius, 0.0f, RED,kFillModeSolid);
				  

			}
				 
		}

		///
		/// ���`�揈�������܂�
		///

		// �t���[���̏I��
		Novice::EndFrame();

		// ESC�L�[�������ꂽ�烋�[�v�𔲂���
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ���C�u�����̏I��
	Novice::Finalize();
	return 0;
}