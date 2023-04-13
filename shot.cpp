#include "Novice.h"
#include "enemy.h"
#include "player.h"
#include <stdio.h>

void Player::Shoot(int X1,int Y1,int X2) {
	for (int i = 0; i < bulletCountMax; i++) {
		if (bulletFlag[i] == 0) {
			bulletY[i] = Y1;
			bulletX[i] = X1;
		}
		if (bulletFlag[i] == 1 && bulletroute[i] == 0) {
			if (X1 <= X2) {
				bulletSpeed[i] = 10;
				bulletroute[i] = 1;
			}
			if (X1 > X2) {
				bulletSpeed[i] = -10;
				bulletroute[i] = 2;
			}
		}
		if (bulletFlag[i] != 0) {
			bulletshot[i]++;
		}

		if (bulletshot[i]>60) {
			bulletFlag[i] = 0;
			bulletroute[i] = 0;
			bulletSpeed[i] = 0;
			bulletshot[i] = 0;
		}
	}
}
void Player::BulletMove() {
	for (int i = 0; i < bulletCount; i++) 
	
	{
		bulletX[i] += bulletSpeed[i];
	}
}

void Player::bulletDraw() {
	for (int i = 0; i < fullbullet; i++) {
		Novice::DrawEllipse(
		  bulletX[i], bulletY[i], bulletRadius, bulletRadius, 0.0f, 0x0000FFF, kFillModeSolid);
	}
}