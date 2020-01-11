#include "pch.h"
#include "Map.h"
#include "IDraw.h"
#include "Application.h"

Map::Map(int w, int h, int tw, int th) {

	MapW = w;
	MapH = h;
	for (int z = 0; z < 8; z++) {
		for (int y = 0; y < MapH; y++) {

			for (int x = 0; x < MapW; x++) {

				Tiles[x][y][z] = NULL;
				Highlight[x][y] = false;
			}
		}
	}

	TileW = tw;
	TileH = th;

	CamX = 0;
	CamY = 0;

	HighLight = new Texture2D("Data/Edit/highlight1.png", true);


};

void Map::SetDraw(int w, int h) {

	Draw = new IDraw(Application::RenW, Application::RenH);
	printf("DX:%d DY:%d\n", w, h);

}

void Map::SetTile(int x, int y, int z, MapTile* tile) {

	Tiles[x][y][z] = tile;

};

TileInfo* Map::TileAt(int mx, int my) {

	TileInfo* info = new TileInfo;


		for (int y = 0; y < MapH; y++) {

			for (int x = 0; x < MapW; x++) {

				int ren_x = (x * TileW) - CamX;
				int ren_y = (y * TileH) - CamY;

				if (mx >= ren_x && mx <= (ren_x + TileW)) {
					if (my >= ren_y && my <= (ren_y + TileH)) {

						info->TileX = x;
						info->TileY = y;
						for (int i = 0; i < 8; i++) {
							info->Tile[i] = Tiles[x][y][i];
						}
						//printf("TXX:%d TYY:%d W:%d H:%d\n", x, y, TileW, TileH);
						//printf("RX:%d RY:%d\n", ren_x, ren_y);
						return info;

					}
				}


			}

		}


	info->TileX = -1;
	return info;

};

void Map::Render() {


	Draw->Begin();

	for (int y = 0; y < MapH; y++) {
		for (int x = 0; x < MapW; x++) {

			bool hasTile = false;
			for (int z = 0; z < 8; z++) {
				if (Tiles[x][y][z] != NULL) {
					hasTile = true;
					break;
				}
			}

			if (!hasTile) {

				int ren_x = (x * TileW) - CamX;
				int ren_y = (y * TileH) - CamY;
				Draw->DrawTex(ren_x, ren_y, TileW, TileH, HighLight, 0.2f, 0.2f, 0.2f, 1);

			}

		}
	}

	for (int z = 0; z < 8; z++) {
		for (int y = 0; y < MapH; y++) {

			for (int x = 0; x < MapW; x++) {

				int ren_x = (x * TileW) - CamX;
				int ren_y = (y * TileH) - CamY;



				MapTile* tile = Tiles[x][y][z];

				if (tile != NULL) {

					Texture2D* img = tile->GetImage();

					Draw->DrawTex(ren_x, ren_y, TileW, TileH, img, 1, 1, 1, 1);
					//printf("MapX:%d MapY:%d\n", ren_x, ren_y);
					//
				};
				if (z == 7) {

					if (Highlight[x][y])
					{
						Draw->DrawTex(ren_x, ren_y, TileW, TileH, HighLight, 1, 1, 1, 1);
					}

				}

			}

		}

	}

	
	Draw->End();

};

void Map::ClearHighlight() {

	for (int y = 0; y < MapH; y++) {
		for (int x = 0; x < MapW; x++) {
			Highlight[x][y] = false;
		}
	}

}

void Map::SetHighlight(int x, int y, bool high) {

	Highlight[x][y] = high;

}