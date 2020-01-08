#pragma once
#include "UIControl.h"
#include "kFrameBuffer.h"

class IDraw;

class FrameBufferControl : public UIControl
{
public:

	FrameBufferControl();
	void Resized();
	void Render();
	virtual void RenderBuffer() {};

private:

	IDraw* Draw;
	kFrameBuffer* Buffer = NULL;
	//std::function<void(int, int)> bufRen;

};

