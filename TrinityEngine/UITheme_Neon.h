#pragma once
#include "UITheme.h"

class Texture2D;

class UITheme_Neon : public UITheme
{
public:

	UITheme_Neon();

	void DrawButton(int x, int y, int w, int h, const char* text,bool over,bool pressed);

private:

	

};


