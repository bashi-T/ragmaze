#pragma once
#include <onigorosi.h>

typedef struct Shutter {
	int X;
	int Y;
	int count;
	int slide;
}Shutter;
struct Shutter shutter {
	400, 500, 0, 0,
};

typedef struct MoveFloor {
	int X;
	int Y;
	int count;
	int slide;
	int velX;
} MoveFloor;
struct MoveFloor movefloor {
	500, 500 - mapsize*2, 0, 0, 0,
};

typedef struct Bottun {
	int X;
	int Y;
	int count;
	
} Bottun;
struct Bottun bottun {
	600, 500, 0,
};
