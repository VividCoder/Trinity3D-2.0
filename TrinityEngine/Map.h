#pragma once
#include "MapTile.h"

class IDraw;

const int MAX_W = 512;
const int MAX_H = 512;
const int MAX_D = 8;

class Map
{
public:

	Map(int w,int h,int tw,int th);
	
	void SetTile(int x, int y,int z, MapTile* tile);

	void SetDraw(int w, int h);

	void SetHighlight(int x, int y, bool high);

	void Move(float x, float y) {

		CamX += x;
		CamY += y;

	}

	void Render();


private:
	MapTile* Tiles[MAX_W][MAX_H][MAX_D];
	bool Highlight[MAX_W][MAX_H];
	int MapW, MapH;
	int TileW, TileH;
	float CamX, CamY;
	IDraw* Draw = NULL;
	Texture2D* HighLight;
};

