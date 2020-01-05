#include "pch.h"
#include "UI.h"
#include "IDraw.h"
#include "Texture2D.h"
UI::UI(int w,int h) {

	UIRoot = new UIControl();

	Drawer = new IDraw(w, h);
	CursorTex = new Texture2D("Data/UI/Neon/cursor1.png", true);
	MouseX = 10;
	MouseY = 10;
	MouseZ = 0;
}

IDraw * UI::Drawer = NULL;


UIControl* UI::GetRoot() {

	return UIRoot;

}

void UI::Update() {

};

void UI::DrawTexture(Texture2D* tex, int x, int y, int w, int h, float r, float g, float b, float a) {

	printf("X:%d Y:%d W:%d H:%d \n",x,y,w,h);
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

int UI::MouseX = 0;
int UI::MouseY = 0;
int UI::MouseZ = 0;