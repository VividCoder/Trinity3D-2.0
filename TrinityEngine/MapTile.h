#pragma once
#include "Texture2D.h"

class MapTile
{
public:

	MapTile(Texture2D* img);
	MapTile(const char* path);
	MapTile(MapTile* tile);
	Texture2D* GetImage();

private:

	Texture2D* Image;
	bool CastShadows = false;
	bool RecvShadows = true;
	bool Collider = false;

};

