#pragma once
#include "UIControl.h"

class VerticalSplitterControl : public UIControl
{
public:
	
	void SetTop(UIControl* top) {

		Top = top;
		Resized();
		AddControl(top);

	};

	void SetBottom(UIControl* bottom) {

		Bottom = bottom;
		Resized();
		AddControl(bottom);

	};

	void MouseDown(int b);
	void MouseUp(int b);
	void MouseMove(int x, int y, int dx, int dy);

	void Resized();

	void Render();

private:
	int SplitPos = -1;
	UIControl* Top;
	UIControl* Bottom;
	bool Dragging = false;
	bool OverDrag = false;

};

