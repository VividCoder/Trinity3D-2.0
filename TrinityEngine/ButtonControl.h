#pragma once
#include "UIControl.h"

class Texture2D;

class ButtonControl : public UIControl
{
public:
	ButtonControl();
	void Render();

private:

	Texture2D* Back;

};

