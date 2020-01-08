#pragma once
#include "UIControl.h"

class Texture2D;

class ImageControl : public UIControl
{
public:

	ImageControl(Texture2D* img);
	ImageControl(const char* path,bool alpha);

	void Render();

private:

	Texture2D* Image;

};

