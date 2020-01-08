#pragma once
#include "Application.h"
#include "UI.h"
#include "UIControl.h"
#include "ButtonControl.h"
#include "WindowControl.h"
#include "VerticalSplitterControl.h"
#include "HorizontalSplitterControl.h"

class Texture2D;
class IDraw;
class ScopeNineApp :
	public Application
{
public:

	ScopeNineApp();

	void Init();
	void Update();
	void Render();

private:

	VerticalSplitterControl* Split1;
	HorizontalSplitterControl* Split2;
	HorizontalSplitterControl* Split3;
	UI* ui;

};

