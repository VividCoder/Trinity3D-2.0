#pragma once
#include "UIControl.h"
#include "kFrameBuffer.h"
class FrameBufferControl : public UIControl
{
public:

	FrameBufferControl();
	void Resized();
	void Render();
	virtual void RenderBuffer() {};

private:

	kFrameBuffer* Buffer = NULL;
	//std::function<void(int, int)> bufRen;

};

