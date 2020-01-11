#pragma once
#include "FrameBufferControl.h"
#include "UIControl.h"
#include "Map.h"

class IDraw;

class MapEditControl :
	public FrameBufferControl
{
public:

	MapEditControl(int mw, int mh, int tw, int th);

	void Resized();

	void RenderBuffer();

	void MouseDown(int b);

	void MouseUp(int b);

	void MouseMove(int x, int y, int dx, int dy);

private:

	Map* CurMap;
	IDraw* Draw;
	bool Dragging = false;
};

