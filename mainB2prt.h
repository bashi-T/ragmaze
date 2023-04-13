#pragma once
#include <Novice.h>

int blend = 0;
int sepalatex1 = 0;
int sepalatey1 = 0;
int shakecount = 0;
int sepalatey2 = 0;
int sepalate = 0;
int mapsize = 32;
int mapsizex = 32;
int loadspritex = 0;
int loadspritey = 0;
float expansion = 1;
int expscount = 0;
int jumpcount = 0;
int animation = 0;

typedef struct Jiki {
	int jikiX = 0;
	int jikiY = 0;
	int jikivelx = 0;
	int jikively = 0;
	int pic;
} Jiki;
struct Jiki jiki = {
  200, 500, 0, 0, 0,
};


const int emitter = 300;
int vector = 360;
int prtX[emitter] = {0};
int prtY[emitter] = {0};
int prtvelY[emitter] = {0};
float speed[emitter] = {0};
float jikivec[emitter] = {0};
float jikivelx[emitter] = {0};
float jikively[emitter] = {0};
int startcount[emitter] = {0};
int count[emitter] = {0};
int max = 10;
int dirtX[emitter] = {0};
int dirtvelX[emitter] = {0};
int dirtcount[emitter] = {0};

int prtRange = 64;
int prtFlag = 0;
int dustFlag = 0;
int dustcount = 0;

typedef struct Breaker {
	int fall;
    int fallcount;
	int shock;
	int shockX;
	int shockY;
	int shockRX;
	int shockRY;
	int shockcount;
} Breaker;
struct Breaker breaker = {
  0, 0, 0, 0, 0, 0, 0, 0, 
};

typedef struct Moving {
	int speed;
	int jump;
	int velY;
} Moving;
struct Moving moving {
	(5, 0, 0), (0, 10, 0), (0, 0, 0),
};
