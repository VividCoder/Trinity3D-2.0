#pragma once
#include "UIControl.h"

class HorizontalSplitterControl : public UIControl
{
public:

	void SetLeft(UIControl* control) {

		Left = control;
		Resized();
		AddControl(control);

	};

	void SetRight(UIControl* control) {

		Right = control;
		Resized();
		AddControl(control);

	}

	void SetSplit(int split) {
		SplitPos = split;
		Resized();
	}

	void MouseDown(int b);
	void MouseUp(int b);
	void MouseMove(int x, int y, int dx, int dy);

	void Resized();

	void Render();

private:

	int SplitPos = -1;
	UIControl* Left;
	UIControl* Right;
	bool Dragging = false;
	bool OverDrag = false;
};

