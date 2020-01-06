#pragma once
#include "UIControl.h"

class Texture2D;

class ButtonControl : public UIControl
{
public:
	ButtonControl();
	void Render();
	void MouseEnter();
	void MouseLeave();

private:
	bool Over, Pressed;
	Texture2D* Back;

};

