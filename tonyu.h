#pragma once

unsigned int currentTime;
typedef struct Jiki {
	int X;
	int Y;
	int velX;
	int velY;
	int jumpheight;
	int jumpcount;
	int radiusX;
	int radiusY;
} Jiki;
struct Jiki jiki {
	200, 500, 10, 0, 15, 0, 32, 8,
};

const int max = 10;
const int splashmax = 16;

typedef struct Tonyu {
	//int X[max];
	//int Y[max];
	//int radiusX[max];
	//int radiusY[max];
	//int jumpcount[max];
	int splashX[splashmax];
	int splashY[splashmax];
	int splashRX[splashmax];
	int splashRY[splashmax];
	int splashVX[splashmax];
	int splashVY[splashmax];
	int splashcount[splashmax];
};
struct Tonyu tonyu {
	/*{0}, {0}, {0}, {0}, {0},*/ {0}, {0}, {0}, {0}, {0}, {0}, {0},
	
};

int ground = 0;
int groundcount = 0;
int yobi1 = 0;
int yobi2 = 0;
