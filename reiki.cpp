#include<cold.cpp>



char keys[256] = {0};
char preKeys[256] = {0};

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {


	// ���C�u�����̏�����

	int RE1 = Novice::LoadTexture("tohu/resource/reitouko1.png");
	int RE2 = Novice::LoadTexture("tohu/resource/reitouko2.png");

	// �L�[���͌��ʂ��󂯎�锠

	// �E�B���h�E�́~�{�^�����������܂Ń��[�v
	while (Novice::ProcessMessage() == 0) {
		// �t���[���̊J�n
		Novice::BeginFrame();

		// �L�[���͂��󂯎��
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
