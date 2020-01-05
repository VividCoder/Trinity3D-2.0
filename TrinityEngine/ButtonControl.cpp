#include "pch.h"
#include "ButtonControl.h"
#include "UI.h"
#include "Texture2D.h"

ButtonControl::ButtonControl() {

	Back = new Texture2D("Data/UI/Neon/button1.png", true);

};

void ButtonControl::Render() {

	
	UI::DrawTexture(Back, GetX(), GetY(), GetW(),GetH(), 1, 1, 1, 1);
	
};