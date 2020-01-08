#include "pch.h"
#include "MapTile.h"
#include "Texture2D.h"

MapTile::MapTile(Texture2D* img) {

	Image = img;

};

MapTile::MapTile(const char* path) {

	Image = new Texture2D(path, true);

};

MapTile::MapTile(MapTile* tile) {

	Image = tile->GetImage();

};

Texture2D* MapTile::GetImage() {

	return Image;

};