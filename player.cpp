#include<stdio.h>
#include"Novice.h"
#include"player.h"


void Player::SetPlayer(int x, int y, int velx, int vely, int R,int life) {
	X = x;
	Y = y;
	speedX = velx;
	speedY = vely;
	radius = R;
};

void Player::Move(int x, int y, int velx, int vely, int radius) 
{
	if (keys[DIK_D]) 
	{
		X += velx;
	}
	if (keys[DIK_A]) 
	{
		X -= velx;
	}
	if (keys[DIK_W]) 
	{
		Y -= vely;
	}
	if (keys[DIK_S]) 
	{
		Y += vely;
	}

	if (X < radius || X > screenedgeX - radius) 
	{
		if (X < radius) 
		{
			X = radius;
		}
		if (X > screenedgeX - radius) 
		{
		    X = screenedgeX - radius;
		}
	}
	if (Y < radius || Y > screenedgeY - radius) 
	{
		if (Y < radius) 
		{
			Y = radius;
		}
		if (Y > screenedgeX - radius)
		{
			Y = screenedgeX - radius;
		}
	}
	x = X;
	y = Y;
};
void Player::Reset(int x, int y, int velx, int vely, int R, int Life) {
	X = 100;
	Y = 300;
	speedX = 5;
	speedY = 5;
	radius = 10;
	life = 1;

	x = X;
	y = Y;
	velx = speedX;
	vely = speedY;
	R=radius;
	Life=life;
}

void Player::Draw(int x, int y, int radius) 
{
	if (life != 0) {
		Novice::DrawEllipse(x, y, radius, radius, 0.0f, 0xFFFFFFFF, kFillModeSolid);
	}
};