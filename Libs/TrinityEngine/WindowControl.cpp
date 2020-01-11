#include "pch.h"
#include "WindowControl.h"
#include "UI.h"
#include "UITheme.h"
#include "ButtonControl.h"

WindowControl::WindowControl() {

	Title = new ButtonControl();
	Resize = new ButtonControl();

	auto act_drag = [&](int x,int y) {

		SetX(GetX() + x);
		SetY(GetY() + y);
	
//		b2->Set(b2->GetX() + 5, b2->GetY(), b2->GetW(), b2->GetH());

	};

	auto act_size = [&](int x, int y) {

		SetSize(GetW() + x, GetH() + y);

	};

	Title->SetDrag(act_drag);

	Resize->SetDrag(act_size);

	Body = new UIControl();

	Resize->SetText("/n");

	Title->SetText("Window\n");

	AddControl(Title);
	//AddControl(Body);
	AddControl(Resize);

};

void WindowControl::Resized() {

	Title->Set(0, 0, GetW(), 20);
	Body->Set(0, 20, GetW(), GetH() - 20);
	Resize->Set(GetW()-8,GetH()-8, 8, 8);

};

void WindowControl::Render() {

	UI::Theme->DrawFrame(GetX(), GetY(), GetW(), GetH(), 1,1,1,1);

}
