#pragma once
int coldX[4] = {0};
int coldY[4] = {0};
int coldvelX[4] = {0};
int coldvelY[4] = {0};
int coldCount[4] = {0};
int coldFlag[4] = {0};
int coldRadiusX[4] = {10,10,10,10};
int coldRadiusY[4] = {3,3,3,3};
int coldColor[4] = {0xcaf4ff5f, 0xcaf4ff5f, 0xcaf4ff5f, 0xcaf4ff5f};

void ColdSet(int x, int y,int scale);
void ColdMove(int x, int y);
void ColdDraw();
