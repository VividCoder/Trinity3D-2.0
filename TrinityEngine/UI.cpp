#include "pch.h"
#include "UI.h"
#include "IDraw.h"
#include "Texture2D.h"
#include "UITheme.h"
#include "kFont.h"
UI::UI(int w,int h) {

	UIRoot = new UIControl();

	Drawer = new IDraw(w, h);
	CursorTex = new Texture2D("Data/UI/Neon/cursor1.png", true);
	MouseX = 10;
	MouseY = 10;
	MouseZ = 0;
	UIOver = NULL;
	UIPressed = NULL;
	UIActive = NULL;
	PressedBut = -1;
	UIFont = new kFont("Data/font/font.pf");

}

IDraw * UI::Drawer = NULL;

UITheme* UI::Theme = NULL;


void UI::SetTheme(UITheme* theme) {
	UI::Theme = theme;
}

UIControl* UI::GetRoot() {

	return UIRoot;

}

void UI::Update() {

	//return;
	UpdateControl(UIRoot);

	if (UIPressed != NULL) {

		if (B1 == 0) {

			UIPressed->MouseUp(0);
			UIPressed = NULL;

		}

	}

	if (UIOver != NULL) {

		if (UIPressed != UIOver) {

			if (!UIOver->InBounds(MouseX, MouseY))
			{
				UIOver->MouseLeave();
				UIOver = NULL;

			}
		}

	};

};

bool UI::UpdateControl(UIControl* control) {

	for (int i = 0; i < control->ControlsCount(); i++) {

		int reali = control->ControlsCount() - (i + 1);
		if (UpdateControl(control->GetControl(reali))) {
			return true;
		}

	}

	control->Update();
	if (control->InBounds(MouseX, MouseY))
	{
	  
		if (UIOver != NULL) {
			if (UIOver != control) {
				UIOver->MouseLeave();
				UIOver = control;
				UIOver->MouseEnter();

			}
		}
		else {
			control->MouseEnter();
			UIOver = control;
		}

		if (B1) {
			
			if (UIPressed == NULL) {
				UIPressed = UIOver;
				UIOver->MouseDown(0);
			}

		}
		else {
			if (UIPressed == control) {
				control->MouseUp(0);
				UIPressed = NULL;
			}
		}

		return true;

	}
	else {

		if (control == UIOver && control!=UIOver) {
			UIOver = NULL;
			control->MouseLeave();
		}
		if (UIPressed == control) {

			if (B1 == false) {
				control->MouseUp(0);
				UIPressed = NULL;
			}

		}
	}

};

void UI::DrawTexture(Texture2D* tex, int x, int y, int w, int h, float r, float g, float b, float a) {

	//printf("X:%d Y:%d W:%d H:%d \n",x,y,w,h);
	Drawer->DrawTex(x, y, w, h, tex, r, g, b, a);

};

void UI::Render() {

	Drawer->Begin();


	RenderControl(UIRoot);

	Drawer->DrawTex(MouseX, MouseY, 32, 32, CursorTex, 1, 1, 1, 1);

	Drawer->End();



};

void UI::RenderControl(UIControl * control) {

	control->Render();
	for (int i = 0; i < control->ControlsCount(); i++)
	{

		RenderControl(control->GetControl(i));

	}
}

void UI::SetMouse(int x, int y, int z) {

	UI::MouseX = x;
	UI::MouseY = y;
	UI::MouseZ = z;

}

void UI::SetMouseBut(int id, bool state) {

	if (id == 0) {
		B1 = state;
	}
	if (id == 1) {
		B2 = state;
	}
	if (id == 2) {
		B3 = state;
	}

};

int UI::MouseX = 0;
int UI::MouseY = 0;
int UI::MouseZ = 0;

bool UI::B1 = false;
bool UI::B2 = false;
bool UI::B3 = false;

kFont* UI::UIFont = NULL;

void UI::DrawText(int x, int y, const char* txt, float r, float g, float b, float a) {

	UIFont->drawText(txt, x, y, r, g, b, a);

};

int UI::TextWidth(const char* text) {

	return UIFont->getWidth(text);

}

int UI::TextHeight(const char* text) {

	return UIFont->getHeight();

};