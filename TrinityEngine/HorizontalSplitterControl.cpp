#include "pch.h"
#include "HorizontalSplitterControl.h"
#include "UI.h"
#include "UITheme.h"
void HorizontalSplitterControl::Resized() {


	if (Left != NULL) {
		Left->Set(0, 0, SplitPos - 4, GetH());
	}
	if (Right != NULL) {
		Right->Set(SplitPos + 4, 0, GetW() - (SplitPos + 4), GetH());
	}
	if (SplitPos < 0) {
		SplitPos = GetW() / 2;
	}

};

void HorizontalSplitterControl::Render() {

	//UI::Theme->DrawFrame(GetX(), GetY(), SplitPos - 4, GetH(),0.8f,0.8f,0.8f,1);
	UI::Theme->DrawFrame(GetX() + SplitPos - 4, GetY(), 8, GetH(),2,2,2,1);
	//UI::Theme->DrawFrame(SplitPos + 4, GetY(), GetW() - (SplitPos + 4), GetH(),0.8f,0.8f,0.8f,1);


};

void HorizontalSplitterControl::MouseDown(int b) {

	if (OverDrag) {

		Dragging = true;

	}

}

void HorizontalSplitterControl::MouseUp(int b) {

	Dragging = false;


};

void HorizontalSplitterControl::MouseMove(int x, int y, int mx, int my) {

	//printf("XM:%d YM:%d\n", mx, my);

	if (!Dragging) {

		if (x >= (SplitPos - 4) && x <= (SplitPos + 4)) {
			if (y >= (GetY()) && y <= (GetY() + GetH()))
			{
				OverDrag = true;
			}
			else {
				OverDrag = false;
			}

		}
		else {
			OverDrag = false;
		}

	}
	else {

		SplitPos += mx;
		if (SplitPos < 10)
		{
			SplitPos = 10;
		}
		if (SplitPos > (GetW() - 10)) {
			SplitPos = GetW() - 10;
		}

		Resized();


	}

	//SplitPos += mx;

}

