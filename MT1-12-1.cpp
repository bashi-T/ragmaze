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

	int OY = 500;
	typedef struct Vector2 {
		float positionX=0;
		float positionY=0;
		float velocityX = 0;
		float velocityY = 0;
		float accelerationX=0;
		float accelerationY=0;
		float e;
	};
	Vector2;

	struct Vector2 vector2 = {
	  100.0,
	  50.0,
	  0,
	  0,
	  0,
	  -0.8f,
	  0.8f,
	};
	typedef struct Ball {
		Vector2 positionX;
		Vector2 velocityX;
		Vector2 positionY;
		Vector2 velocityY;
		Vector2 accelerationX;
		Vector2 accelerationY;
		unsigned int color = 0xFFFFFFFF ;
		float radius = 50;
		
	};Ball;
	struct Ball ball = {
	  600,
	  50,
	  0,
	  0,
	  0,
	  -0.8,
	};
	float length=0;
	int scene = 0;
	float velx = 0;
	float vely = 0;
	// �E�B���h�E�́~�{�^�����������܂Ń��[�v
	while (Novice::ProcessMessage() == 0) {
		// �t���[���̊J�n
		Novice::BeginFrame();
		
		// �L�[���͂��󂯎��
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		Novice::GetMousePosition;
		//vector2.velocityX = 0;
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && vector2.velocityX >= 0) {
			vector2.velocityX = 30;
		}
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && vector2.velocityX < 0) {
			vector2.velocityX = -30;
		}

		/* if (keys[DIK_D]) {
			vector2.velocityX = 10;
		}
		if (keys[DIK_A]) {
			vector2.velocityX = -10;
		}*/
			
			
		  //  ball.color -= 0x00001100;
		
		/* length =sqrt(vector2.velocityX * vector2.velocityX + vector2.velocityY * vector2.velocityY);
		if (length != 0.0f&&vector2.velocityY<0) {
			vector2.velocityX = vector2.velocityX * vector2.velocityX / length;
			vector2.velocityY = -vector2.velocityY * vector2.velocityY / length;
		}
		if (length != 0.0f) {
			vector2.velocityX = vector2.velocityX * vector2.velocityX / length;
			vector2.velocityY = vector2.velocityY * vector2.velocityY / length;
		}
		if (keys[DIK_A]) {
			vector2.velocityX *= -1;
		}*/
		if (vector2.positionX >= 1230) {
			vector2.positionX = 1230;
			vector2.velocityX = -vector2.velocityX*vector2.e;
		}
		if (vector2.positionX <= 50) {
			vector2.positionX=50;
			vector2.velocityX = -vector2.velocityX * vector2.e;
		}
		vector2.velocityX += vector2.accelerationX;
		//vector2.velocityY += vector2.accelerationY;
		vector2.positionX = vector2.positionX+vector2.velocityX;
		vector2.positionY = vector2.positionY - vector2.velocityY;
		/* if (vector2.positionY > 550) {
			vector2.positionY = 550;
			vector2.velocityY = 0;
		}*/
		

		Novice::DrawLine(0, OY, 1280, OY, WHITE);
		Novice::ScreenPrintf(0, 10, "%f", vector2.velocityY);
		Novice::ScreenPrintf(0, 30, "%f", vector2.positionY);
		Novice::ScreenPrintf(0, 50, "%f", vector2.accelerationY);

		Novice::DrawEllipse( vector2.positionX, OY-vector2.positionY, ball.radius, ball.radius, 0.0f, ball.color,kFillModeSolid);
			
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