#include "pch.h"
#include "MapEditControl.h"
#include "IDraw.h"

MapEditControl::MapEditControl(int mw, int mh, int tw, int th) {

	SetText("MapEdit:/n");
	CurMap = new Map(mw, mh, tw, th);
	MapTile* noTile = new MapTile("Edit/notile.png");

	CurMap->SetTile(1, 0,0, noTile);

	for (int y = 0; y < mh; y++) {

		for (int x = 0; x < mw; x++) {

			//CurMap->SetTile(x, y,0, noTile);

		}
	}

	CurMap->SetHighlight(0, 0, true);


}

void MapEditControl::MouseDown(int b) {
	
	if (b == 1) {
		Dragging = true;
	//	exit(1);
	}
};

void MapEditControl::MouseUp(int b) {

	if (b == 1) {
		Dragging = false;
	//	exit(1);
	}

};

void MapEditControl::MouseMove(int x, int y, int dx, int dy)
{
	//exit(1);
	if (Dragging) {
		CurMap->Move(-dx, -dy);
	}

	CurMap->ClearHighlight();

	TileInfo* info = CurMap->TileAt(x, y);

	if (info->TileX != -1) {

		CurMap->SetHighlight(info->TileX, info->TileY, true);
		//printf("HX:%d HY:%d\n MX:%d\n", info->TileX, info->TileY, x);
	}

	delete info;
}



void MapEditControl::Resized() {

	FrameBufferControl::Resized();

	CurMap->SetDraw(GetW(), GetH());

	Draw = new IDraw(GetW(), GetH());

}

void MapEditControl::RenderBuffer() {

	CurMap->Render();

};