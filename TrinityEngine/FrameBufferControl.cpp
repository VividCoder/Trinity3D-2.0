#include "pch.h"
#include "FrameBufferControl.h"

FrameBufferControl::FrameBufferControl() {

	Buffer = NULL;

};

void FrameBufferControl::Resized() {

	if (Buffer == NULL) {

		Buffer = new kFrameBuffer(GetW(), GetH());

	}
	else
	{
		delete Buffer;
		Buffer = new kFrameBuffer(GetW(), GetH());
	}

};

void FrameBufferControl::Render() {

	Buffer->bind();
	RenderBuffer();
	Buffer->unbind();

}