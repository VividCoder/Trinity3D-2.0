#pragma once
#include "UIControl.h"
//#include "IDraw.h"
class IDraw;
class Texture2D;

class UI
{
public:

	UI(int w, int h);
	UIControl* GetRoot();
	void Update();
	void Render();
	void RenderControl(UIControl* control);
	static void DrawTexture(Texture2D* tex, int x, int y, int w, int h, float r, float g, float b, float a);
	static IDraw* Drawer;
	static void SetMouse(int mx, int my, int mz);

private:

	UIControl* UIRoot;
	Texture2D* CursorTex;
	static int MouseX, MouseY, MouseZ;


};

