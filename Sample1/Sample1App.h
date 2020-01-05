#pragma once
#include "Application.h"
#include "UI.h"
#include "UIControl.h"
#include "ButtonControl.h"

class Texture2D;
class IDraw;

class Sample1App :
	public Application
{
public:

	Sample1App();

	void Init();
	void Update();
	void Render();

private:

	Texture2D* tex1;
	Texture2D* tex2;
	IDraw* draw;
	UI* ui;
	ButtonControl* b1;
	ButtonControl* b2;
};

