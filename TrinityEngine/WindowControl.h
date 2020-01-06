#pragma once
#include "UIControl.h"

class ButtonControl;

class WindowControl : public UIControl
{
public:

	WindowControl();

	void Render();

	void Resized();

private:
	ButtonControl* Title;

};

