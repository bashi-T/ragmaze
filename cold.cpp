#include "cold.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <Novice.h>


unsigned int currentTime = time(nullptr);

void ColdSet(int x,int y,int scale) 
{
	for (int i = 0; i < 4; i++) 
	{
		srand(currentTime + i * i);
		coldX[i] = rand() % 20 - 10 + x + scale / 2;
		coldY[i] = rand() % 20 - 10 + y + scale / 2;
		
	}
	coldX[1] = coldX[0] - 5;
	coldX[3] = coldX[2] - 5;
	coldY[1] = coldY[0] - 10;
	coldY[3] = coldY[2] - 10;
}

void ColdMove(int x, int y)
{
	for (int i = 0; i < 4; i++) {
		srand(currentTime + i * i);
		coldvelX[i] = rand() % 4 - 2;
		coldvelX[1] = coldvelX[0];
		coldvelX[3] = coldvelX[2];
		coldX[i] += coldvelX[i];
	}
}

void ColdDraw() {
	for (int i = 0; i < 4; i++) {
		Novice::DrawEllipse(
		  coldX[i], coldY[i], coldRadiusX[i], coldRadiusY[i], 0.0f, coldColor[i], kFillModeSolid);
	}
}