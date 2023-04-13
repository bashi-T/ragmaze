#pragma once
class Enemy {
public:
	void SetEnemy(int x, int y, int velx, int vely, int R,int Life);
  void Move(int x, int y, int velx, int vely, int radius, int plrX);
	void Draw(int x,int y,int radius); 
	void bulletHit(int x, int y, int R, int Ex, int Ey, int ER,int Life);
	void Reset(int x, int y, int velx, int vely, int R, int Life);

	int GetX() { return X; };
	int GetY() { return Y; };
	int GetSpeedX() { return speedX; };
	int GetSpeedY() { return speedY; };
	int GetRadius() { return radius; };
	int GetLife() { return life; };

  private:
	int X = 500;
	int Y = 300;
	int speedX = 20;
	int speedY = 15;
	int radius = 20;
	int life = 50;
};

