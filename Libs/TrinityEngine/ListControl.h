#pragma once
#include "UIControl.h"
#include<vector>

struct ListItem {

	const char* Text;


};

class ListControl :
	public UIControl
{
public:
	
	ListControl();

	ListItem * AddItem(const char* text);

	void Render();


private:
	std::vector<ListItem*> Items;
};

