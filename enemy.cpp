#include"Novice.h"
#include"enemy.h"
#include"player.h"
#include<stdio.h>


void Enemy::SetEnemy(int x, int y, int velx, int vely, int R, int Life) {
	X = x;
	Y = y;
	speedX = velx;
	speedY = vely;
	radius = R;
	life = Life;
};

void Enemy::Move(int x, int y, int velx, int vely, int radius, int plrX) {
	Y += speedY;

	if (Y < radius || Y > screenedgeY - radius)
	{
		speedY *= -1;
		if (Y < radius) 
		{
			Y = radius;

			if (plrX > X) 
			{
				X += velx;
			}
			if (plrX < X) 
			{
				X -= velx;
			}
		}
		if (Y > screenedgeY - radius) 
		{
			Y = screenedgeY - radius;

			if (plrX > X) 
			{
				X += velx;
			}
			if (plrX < X) 
			{
				X -= velx;
			}
		}
	}
	x = X;
	y = Y;
	vely = speedY;
};

void Enemy::Reset(int x, int y, int velx, int vely, int R, int Life){
	X = 500;
	Y = 300;
	speedX = 20;
	speedY = 15;
	radius = 20;
	life = 50;

	x = X;
	y = Y;
	velx = speedX;
	vely = speedY;
	R = radius;
	Life = life;
};


void Enemy::Draw(int x, int y, int radius ) {
	if (life >0) {
		Novice::DrawEllipse(x, y, radius, radius, 0.0f, 0xFF0000FF, kFillModeSolid);
	}
};