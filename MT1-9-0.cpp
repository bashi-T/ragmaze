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

	float AX = 600;
	float AY = 400;
	float BX = 0;
	float BY = 0;
	typedef struct VECTOR2 {
		float x=300;
		float y = 200;
		float x1 = 0;
		float y1 = 0;
		float x2 = 0;
		float y2 = 0;
	};VECTOR2;
	struct VECTOR2 vector = { 
		300,
	    200,
		0,
		0,
		0,
		0,
	};
	vector.x = 300;
	vector.y = 200;
	float bx = 900;
	float by = 400;
	float theta = (1.0 / 16.0f) * M_PI;
	float length = sqrt(vector.x * vector.x + vector.y * vector.y);
	float vxsize = 1;
	float vysize = 1;
	float vxsizechange = 0.1f;
	float vysizechange = 0.1f;


	// �E�B���h�E�́~�{�^�����������܂Ń��[�v
	while (Novice::ProcessMessage() == 0) {
		// �t���[���̊J�n
		Novice::BeginFrame();
		
		// �L�[���͂��󂯎��
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		Novice::GetMousePosition;
		
		vector.x = BX - 600;
		vector.y = BY - 400;

		vector.x1 = vector.x * cos(theta) - vector.y * sin(theta) + 600;
		vector.y1 = vector.y * cos(theta) + vector.x * sin(theta) + 400;
		vector.x2 = vector.x1;
		vector.y2 = vector.y1;
		length = sqrt(vector.x1 * vector.x1 + vector.y1 * vector.y1);
		if (length != 0.0f) {
			vector.x2 = vector.x1 * vector.x1 / length;
			vector.y2 = vector.y1 * vector.y1 / length;
		}
		/*
		if (vxsize == 0.5f && vxsizechange == -0.1f) {
			vxsizechange = 0.1f;
		}
		if (vysize == 0.5f && vysizechange == -0.1f) {
			vysizechange = 0.1f;
		}
		if (vxsize == 2.0f && vxsizechange == 0.1f) {
			vxsizechange = -0.1f;
		}
		if (vysize == 2.0f && vysizechange == 0.1f) {
			vysizechange = -0.1f;
		}

		vxsize += vxsizechange;
		vysize += vysizechange;
		*/
		vector.x2 *= vxsize;
		vector.y2 *= vysize;
		
		BX = AX + vector.x2;
		BY = AY + vector.y2;
        
	Novice::DrawLine(AX, AY, BX, BY, 0xFFFFFFFF);
		
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