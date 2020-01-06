#pragma once
#include "UIControl.h"
//#include "IDraw.h"
class IDraw;
class Texture2D;
class UITheme;
class kFont;

class UI
{
public:

	UI(int w, int h);
	UIControl* GetRoot();
	void Update();
	void Render();
	void RenderControl(UIControl* control);
	bool UpdateControl(UIControl* control);

	static void DrawTexture(Texture2D* tex, int x, int y, int w, int h, float r, float g, float b, float a);
	static IDraw* Drawer;
	static UITheme* Theme;
	static void SetTheme(UITheme* theme);
	static void SetMouse(int mx, int my, int mz);
	static void SetMouseBut(int id, bool state);

	static kFont* UIFont;

	static void DrawText(int x, int y, const char* text, float r, float g, float b, float a);
	static int TextWidth(const char* text);
	static int TextHeight(const char* text);

private:

	
	UIControl* UIRoot;
	Texture2D* CursorTex;
	static int MouseX, MouseY, MouseZ;
	static bool B1, B2, B3;
	UIControl* UIOver;
	UIControl* UIActive;
	UIControl* UIPressed;
	int PressedBut;


};

