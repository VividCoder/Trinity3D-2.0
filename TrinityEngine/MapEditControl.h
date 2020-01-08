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

private:

	Map* CurMap;
	IDraw* Draw;

};

