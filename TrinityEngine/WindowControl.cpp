#include "pch.h"
#include "WindowControl.h"
#include "UI.h"
#include "UITheme.h"
#include "ButtonControl.h"

WindowControl::WindowControl() {

	Title = new ButtonControl();

	AddControl(Title);

};

void WindowControl::Resized() {

	Title->Set(0, 0, GetW(), 20);

};

void WindowControl::Render() {

	UI::Theme->DrawFrame(GetX(), GetY(), GetW(), GetH(), 1,1,1,1);

}
