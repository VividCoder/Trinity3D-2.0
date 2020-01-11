#pragma once
#include "Application.h"
#include "UI.h"
#include "UIControl.h"
#include "ButtonControl.h"
#include "WindowControl.h"
#include "VerticalSplitterControl.h"
#include "HorizontalSplitterControl.h"
#include "MapEditControl.h"
class TileSetApp : public Application
{

public:

	TileSetApp();

	void Init();
	void Update();
	void Render();

private:

	UI* ui;

};


