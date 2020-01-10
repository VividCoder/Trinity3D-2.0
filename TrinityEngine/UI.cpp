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
	MouseX = 1;
	MouseY = 1;
	MouseZ = 0;
	UIOver = NULL;
	for (int i = 0; i < 16; i++) {
		UIPressed[i] = NULL;
	}
	UIActive = NULL;
	PressedBut = -1;
	LastX = 0;
	LastY = 0;
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

	for (int i = 0; i < 16; i++) {
		if (UIPressed[i] != NULL) {

			if (But[i] == false) {

				UIPressed[i]->MouseUp(i);
				UIPressed[i] = NULL;

			}

		}
	}

	if (UIOver != NULL) {

		bool keep = false;

		for (int cx = 0; cx < 16; cx++) {

			if (UIPressed[cx] == UIOver) {

				keep = true;

			}

		}

		if (!keep) {

			if (!UIOver->InBounds(MouseX-UIOver->GetX(), MouseY-UIOver->GetY()))
			{
				UIOver->MouseLeave();
				UIOver = NULL;

			}

		}

		

	};

	for (int i = 0; i < 16; i++) {
		if (UIPressed[i] != NULL) {

			int xd = UI::MouseX - UI::LastX;
			int yd = UI::MouseY - UI::LastY;
			UIPressed[i]->Dragged(xd, yd);

		}


		if (UIPressed[i] != NULL) {
			int mx = UI::MouseX - UIOver->GetX();
			int my = UI::MouseY - UIOver->GetY();
			UIPressed[i]->MouseMove(mx, my, UI::MouseX - UI::LastX, UI::MouseY - UI::LastY);

		}
	}
	
	if (UIOver != NULL) {

		bool dol = false;
		for (int i = 0; i < 16; i++){
			if (UIPressed[i] == UIOver) {
				dol = true;
			}
		}

		if (dol == false) {
			int mx = UI::MouseX - UIOver->GetX();
			int my = UI::MouseY - UIOver->GetY();

			UIOver->MouseMove(mx, my, UI::MouseX - UI::LastX, UI::MouseY - UI::LastY);
		}

	}

	UI::LastX = UI::MouseX;
	UI::LastY = UI::MouseY;
};

bool UI::UpdateControl(UIControl* control) {

	for (int i = 0; i < control->ControlsCount(); i++) {

		int reali = control->ControlsCount() - (i + 1);
		if (UpdateControl(control->GetControl(reali))) {
			return true;
		}

	}

	control->Update();
	if (control->InBounds(MouseX-control->GetX(), MouseY-control->GetY()))
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


		for (int i = 0; i < 16; i++) {
			if (But[i]) {

				if (UIPressed[i] == NULL) {
				
					UIPressed[i] = UIOver;
					UIOver->MouseDown(i);
				}

			}
			else {
				if (UIPressed[i] == control) {
					control->MouseUp(i);
					UIPressed[i] = NULL;
				}
			}
		}
		return true;
	}
	
	else {

		if (control == UIOver && control!=UIOver) {
			UIOver = NULL;
			control->MouseLeave();
		}

		for (int i = 0; i < 16; i++) {
			if (UIPressed[i] == control) {

				if (But[i] == false) {
					control->MouseUp(i);
					UIPressed[i]= NULL;
				}

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

	UI::LastX = UI::MouseX;
	UI::LastY = UI::MouseY;
	UI::MouseX = x;
	UI::MouseY = y;
	UI::MouseZ = z;

}

void UI::SetMouseBut(int id, bool state) {

	But[id] = state;


};

bool UI::But[];

int UI::MouseX = 0;
int UI::MouseY = 0;
int UI::MouseZ = 0;
int UI::LastX = 0;
int UI::LastY = 0;




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