#include <Novice.h>
#include <player.h>
#include <player.cpp>

void Player::Move(char* keys); {
	if (keys[DIK_D]) {
		posx = 10;
	}
}

//instance
///Player* player=new Player;


int main() {
	SpeedX = 0;
	if (keys[DIK_D]) {
		SpeedX += 10;
	}
	if (keys[DIK_A]) {
		SpeedX -= 10;
	}
	SpeedY = 0;
	if (keys[DIK_W]) {
		SpeedY += 10;
	}
	if (keys[DIK_S]) {
		SpeedY -= 10;
	}

	
	
	
	
	
	return 0;

}