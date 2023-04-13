#pragma once

const int fullbullet = 20;

class Player {
  public:
	void SetPlayer(int x, int y, int velx, int vely, int radius,int life);
	void Move(int x, int y, int velx, int vely, int radius);
	void Shoot(int X1, int Y1, int X2);
	void BulletMove();
	void Draw(int x, int y, int radius);
	void bulletDraw();
	void enemyHit(int x, int y, int R, int Ex, int Ey, int ER,int Life);
	void Reset(int x, int y, int velx, int vely, int R, int Life);
	int GetX() { return X; };
	int GetY() { return Y; };
	int GetSpeedX() { return speedX; };
	int GetSpeedY() { return speedY; };
	int GetRadius() { return radius; };
	int GetLife() { return life; };


	int bulletX[fullbullet] = {0};
	int bulletY[fullbullet] = {0};
	int bulletSpeed[fullbullet] = {0};
	int bulletRadius = 5;
	int bulletCount = 0;
	int bulletFlag[fullbullet] = {0};
	int bulletroute[fullbullet] = {0};
	int bulletshot[fullbullet] = {0};
	int shotcount = 0;
	int bulletCountMax = 20;


  private:
	int X = 100;
	int Y = 300;
	int speedX = 5;
	int speedY = 5;
	int radius = 10;
	int life = 1;
};
int screenedgeX = 0;
int screenedgeY = 0;

char keys[256] = {0};
char preKeys[256] = {0};
