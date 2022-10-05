#include <Novice.h>
#include<math.h>
const char kWindowTitle[] = "LC1A_16_�c�d�L�o�V�}�T�~_MT1";

// Windows�A�v���ł̃G���g���[�|�C���g(main�֐�)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ���C�u�����̏�����
	Novice::Initialize(kWindowTitle, 1280, 720);
	
	// �L�[���͌��ʂ��󂯎�锠
	char keys[256] = {0};
	char preKeys[256] = {0};
	int ellipseX=60;
	int ellipseY=60;
	int Xvel;
	int Yvel;
	float A;
	float B;
	float DIST;
	
	// �E�B���h�E�́~�{�^�����������܂Ń��[�v
	while (Novice::ProcessMessage() == 0) {
		// �t���[���̊J�n
		Novice::BeginFrame();

		// �L�[���͂��󂯎��
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		Novice::GetMousePosition;
		Xvel = 0;
		Yvel = 0;

        if (keys[DIK_D]) {
			Xvel = 10;
		}
		if (keys[DIK_A]) {
			Xvel = -10;
		}
		if (keys[DIK_S]) {
			Yvel = 10;
		}
		if (keys[DIK_W]) {
			Yvel = -10;
		}
		if (keys[DIK_D] && keys[DIK_SPACE]) {
			Xvel = 5;
		}
		if (keys[DIK_A] && keys[DIK_SPACE]) {
			Xvel = -5;
		}
		if (keys[DIK_S] && keys[DIK_SPACE]) {
			Yvel = 5;
		}
		if (keys[DIK_W] && keys[DIK_SPACE]) {
			Yvel = -5;
		}
		
		if (ellipseX <= 50 && keys[DIK_A]) {
			Xvel = 0;
		}
		if (ellipseX >= 1230&&keys[DIK_D]) {
			Xvel = 0;
		}
		if (ellipseY <= 50&&keys [DIK_W]) {
			Yvel = 0;
		}
		if (ellipseY >= 670 && keys[DIK_S]) {
			Yvel = 0;
		}

		ellipseX += Xvel;
		ellipseY += Yvel;
		A = ellipseX - 400;
		B = ellipseY - 400;
		DIST = sqrtf(A * A + B * B);
		if (DIST <= 50) {
			Novice::DrawEllipse(380, 410, 150, 150, 0.0f, RED, kFillModeSolid);
		}
        Novice::DrawEllipse(ellipseX, ellipseY, 50, 50, 0.0f, RED, kFillModeSolid);
	    Novice::DrawEllipse(400, 400, 100, 100, 0.0f, 0xFFFFFFFF, kFillModeSolid);
		if (DIST<=150) {
			Novice::DrawEllipse(ellipseX, ellipseY, 50, 50, 0.0f, BLUE, kFillModeSolid);
		}
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