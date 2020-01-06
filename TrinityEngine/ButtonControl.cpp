#include "pch.h"
#include "ButtonControl.h"
#include "UI.h"
#include "Texture2D.h"
#include "UITheme.h"

ButtonControl::ButtonControl() {

	Back = new Texture2D("Data/UI/Neon/button1.png", true);
	Over = false;
	Pressed = false;
};

void ButtonControl::Render() {

	UI::Theme->DrawButton(GetX(), GetY(), GetW(), GetH(), GetText(),Over,Pressed);

	//UI::DrawTexture(Back, GetX(), GetY(), GetW(),GetH(), 1, 1, 1, 1);
	
};

void ButtonControl::MouseEnter() {
	Over = true;
};

void ButtonControl::MouseLeave() {

	Over = false;

};

void ButtonControl::MouseDown(int b) {
	//exit(1);
	Pressed = true;
	Action();
};

void ButtonControl::MouseUp(int b) {
	//exit(1);
	Pressed = false;
}
