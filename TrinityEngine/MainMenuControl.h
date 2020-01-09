#pragma once
#include "UIControl.h"
#include <vector>

struct MenuItem {

	const char* Text;
	std::vector<MenuItem*> Items;
	MenuItem * AddItem(const char* text) {

		MenuItem* item = new MenuItem;

		item->Text = text;
		item->Items.resize(0);

		Items.push_back(item);

		return item;

	};
	bool Open = false;

};

class MainMenuControl :
	public UIControl
{
public:

	MainMenuControl();

	MenuItem * AddItem(const char* text);

	void MouseMove(int x, int y, int mx, int my);

	void DrawMenu(MenuItem* item, int dx, int dy);
	bool CheckMenuBounds(MenuItem* item, int dx, int dy,int mx,int my);
	void MM_Menu(MenuItem* item, int x, int y, int dx, int dy);
	bool InBounds(int mx, int my);

	void Update();
	void Render();


private:
	std::vector<MenuItem*> Items;
	MenuItem* OverItem = NULL;
	MenuItem* ActiveItem = NULL;
};



