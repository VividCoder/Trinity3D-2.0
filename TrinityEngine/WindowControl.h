#pragma once
#include "UIControl.h"

class ButtonControl;

class WindowControl : public UIControl
{
public:

	WindowControl();

	void Render();

	void Resized();

	void AddBodyControl(UIControl* control) {
		Body->AddControl(control);
	}

private:
	ButtonControl* Title;
	ButtonControl* Resize;
	UIControl* Body;
};

