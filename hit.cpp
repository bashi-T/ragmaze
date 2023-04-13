#include "enemy.h"
#include "player.h"
#include "enemy.h"
#include "player.h"


void Player::enemyHit(int x,int y,int R,int Ex, int Ey,int ER,int Life) { 
	if (x - Ex < R + ER && x - Ex > -R - ER && y - Ey < R + ER && y - Ey > -R - ER) 
	{
		life = 0;
		Life = life;
	}
}
void Enemy::bulletHit(int x, int y, int R, int Ex, int Ey, int ER,int Life) {
	if (x - Ex < R + ER && x - Ex > -R - ER && y - Ey < R + ER && y - Ey > -R - ER) 
	{
		life--;
		Life = life;
	}
}