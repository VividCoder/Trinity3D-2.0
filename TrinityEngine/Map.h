#pragma once
#include "MapTile.h"

class IDraw;

const int MAX_W = 512;
const int MAX_H = 512;

class Map
{
public:

	Map(int w,int h,int tw,int th);
	
	void SetTile(int x, int y, MapTile* tile);

	void SetDraw(int w, int h);

	void Render();


private:
	MapTile* Tiles[MAX_W][MAX_H];
	int MapW, MapH;
	int TileW, TileH;
	float CamX, CamY;
	IDraw* Draw = NULL;
};

