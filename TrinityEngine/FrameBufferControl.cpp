#include "pch.h"
#include "FrameBufferControl.h"
#include "IDraw.h"
#include "Application.h"
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

	Draw = new IDraw(Application::WinW, Application::WinH);

};

void FrameBufferControl::Render() {

	Buffer->bind();
	RenderBuffer();
	Buffer->unbind();


	Draw->SingleDrawTex(GetX(), GetY(), GetW(), GetH(), Buffer->GetBB(), 1, 1, 1, 1);


}