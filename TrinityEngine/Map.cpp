#include "pch.h"
#include "Map.h"
#include "IDraw.h"
#include "Application.h"

Map::Map(int w, int h,int tw,int th) {

	MapW = w;
	MapH = h;
	for (int y = 0; y < MapH; y++) {

		for (int x = 0; x < MapW; x++) {

			Tiles[x][y] = NULL;

		}
	}

	TileW = tw;
	TileH = th;

	CamX = 0;
	CamY = 0;


};

void Map::SetDraw(int w, int h) {

	Draw = new IDraw(Application::RenW,Application::RenH);
	printf("DX:%d DY:%d\n", w, h);

}

void Map::SetTile(int x, int y, MapTile* tile) {

	Tiles[x][y] = tile;

};

void Map::Render() {


	Draw->Begin();

	for (int y = 0; y < MapH; y++) {

		for (int x = 0; x < MapW; x++) {

			int ren_x = (x * TileW) - CamX;
			int ren_y = (y * TileH) - CamY;

		

			MapTile* tile = Tiles[x][y];

			if (tile != NULL) {

				Texture2D* img = tile->GetImage();

				Draw->DrawTex(ren_x, ren_y, TileW, TileH, img, 1, 1, 1, 1);
				//printf("MapX:%d MapY:%d\n", ren_x, ren_y);
				//
			};

		}

	}

	Draw->End();

};