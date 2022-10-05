#include <Novice.h>
#define _USE_MATH_DEFINES
#include<math.h>
const char kWindowTitle[] = "LC1A_16_�c�d�L�o�V�}�T�~_MT1";

// Windows�A�v���ł̃G���g���[�|�C���g(main�֐�)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ���C�u�����̏�����
	Novice::Initialize(kWindowTitle, 1280, 720);
	
	// �L�[���͌��ʂ��󂯎�锠
	char keys[256] = {0};
	char preKeys[256] = {0};

	float ellipse1X = 800;
	float ellipse1Y = 500;
	float ellipse2X = 300;
	float ellipse2Y = 300;

	typedef struct Ellipse {
		int r1 = 50;
		int r2 = 50;
		int r3 = 50;
		int r4 = 50;
	};Ellipse;
	struct Ellipse ellipse {
		50,
		50,
		50,
	    50,
	};
	float t = 0;
	float hitvelX = ellipse1X - ellipse2X;
	float hitvelY = ellipse1Y - ellipse2Y;
	float hitvel = sqrtf( hitvelX * hitvelX + hitvelY * hitvelY);
	float ellipsevX = 0;
	float ellipsevY = 0;
	float length=0;
	float ELLIPSEvx = ellipsevX;
	float ELLIPSEvy = ellipsevY;
	int scene = 0;
	int scenecount = 0;

	// �E�B���h�E�́~�{�^�����������܂Ń��[�v
	while (Novice::ProcessMessage() == 0) {
		// �t���[���̊J�n
		Novice::BeginFrame();
		
		// �L�[���͂��󂯎��
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		Novice::GetMousePosition;
		ellipsevX = 0;
		ellipsevY = 0;

		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
			scene = 1;
		}
		if (scene==1&&scenecount == 120) {
			scene = 2;
		}
		if (scene==1){
			t += 0.001f;
			ellipse2X = (1.0f - t) * ellipse2X + t * ellipse1X;
			ellipse2Y = (1.0f - t) * ellipse2Y + t * ellipse1Y;
			scenecount += 1;
		}
		/*
		ELLIPSEvx = ellipsevX;
		ELLIPSEvy = ellipsevY;
		length = sqrt(ellipsevX * ellipsevX + ellipsevY * ellipsevY);
		if (length != 0.0f) {
			ELLIPSEvx = ellipsevX * ellipsevX / length;
			ELLIPSEvy = ellipsevY * ellipsevY / length;
			if (keys[DIK_A]) {
				ELLIPSEvx *= -1;
			}
			if (keys[DIK_W]) {
				ELLIPSEvy *= -1;
			}

		}
		

		ellipse2X += ELLIPSEvx;
		ellipse2Y += ELLIPSEvy;*/
		hitvelX = ellipse1X - ellipse2X;
		hitvelY = ellipse1Y - ellipse2Y;
		hitvel = sqrtf(hitvelX * hitvelX + hitvelY * hitvelY);

		Novice::DrawEllipse(ellipse1X, ellipse1Y, ellipse.r1, ellipse.r2, 0.0f, RED, kFillModeSolid);
		//if (hitvel > 100) {
			Novice::DrawEllipse(ellipse2X, ellipse2Y, ellipse.r3, ellipse.r4, 0.0f, 0xFFFFFFFF, kFillModeSolid);
		//}
		//if (hitvel<=100) {
		//   Novice::DrawEllipse(ellipse2X, ellipse2Y, ellipse.r3, ellipse.r4, 0.0f, 0x0000FFFF, kFillModeSolid);
	    //}	
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