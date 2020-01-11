#include "pch.h"
#include "ListControl.h"
#include "UI.h"
#include "UITheme.h"
#include "UITheme_Neon.h"

ListControl::ListControl() {

	Items.resize(0);

}

ListItem * ListControl::AddItem(const char* text) {


	ListItem* item = new ListItem;
	item->Text = text;
	Items.push_back(item);
	return item;

};

void ListControl::Render() {

	UI::Theme->DrawFrame(GetX(), GetY(), GetW(), GetH(), 3, 3, 3, 1);

	int dy = 5;

	for (int i = 0; i < Items.size(); i++) {

		auto it = Items[i];

		UI::DrawText(GetX() + 6, GetY() + dy, it->Text, 0.3f, 0.3f, 0.3f, 1.0f);
		//exit(1);
		dy = dy + UI::TextHeight(it->Text) + 4;
	}

}