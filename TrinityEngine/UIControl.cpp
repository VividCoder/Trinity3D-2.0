#include "pch.h"
#include "UIControl.h"

UIControl::UIControl() {

	Controls.resize(0);
	actionPtr = NULL;
	X = 0;
	Y = 0;
	W = 0;
	H = 0;
	Text = "\n";
	Root = NULL;
};

UIControl* UIControl::Set(int x, int y, int w, int h) {

	X = x;
	Y = y;
	W = w;
	H = h;
	return this;
}

UIControl* UIControl::SetText(const char* text) {

	Text = text;

	return this;

}

void UIControl::AddControl(UIControl* control) {

	Controls.push_back(control);
	control->SetRoot(this);

}

int UIControl::ControlsCount() {

	return Controls.size();

};

UIControl* UIControl::GetControl(int index) {

	return Controls[index];


}

void UIControl::SetRoot(UIControl* root) {

	Root = root;

}

int UIControl::GetX() {

	int rx = 0;

	if (Root != NULL) {

		rx = Root->GetX();

	}

	return (rx + X);

};

int UIControl::GetY() {

	int ry = 0;

	if (Root != NULL) {

		ry = Root->GetY();

	}

	return (ry + Y);

};

int UIControl::GetW() {

	return W;

};

int UIControl::GetH() {

	return H;

};

void UIControl::Action() {

	if (actionPtr != NULL) {
		actionPtr();
	}

};
