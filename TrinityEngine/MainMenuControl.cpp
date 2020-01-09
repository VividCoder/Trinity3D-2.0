#include "pch.h"
#include "MainMenuControl.h"
#include "UI.h"
#include "UITheme.h"

MainMenuControl::MainMenuControl() {

	Items.resize(0);

};

MenuItem* MainMenuControl::AddItem(const char* text) {

	MenuItem* item = new MenuItem;

	item->Text = text;
	item->Items.resize(0);

	Items.push_back(item);

	return item;

}

void MainMenuControl::MM_Menu(MenuItem* item, int x, int y, int dx, int dy) {


	dy = dy + 4;

	for (int i = 0; i < item->Items.size(); i++) {

		auto it = item->Items[i];
		//UI::DrawText(dx, dy, it->Text, 1, 1, 1, 1);
		if (x >= dx && x <= (dx + UI::TextWidth(it->Text)))
		{
			if (y >= dy && y <= (dy + UI::TextHeight(it->Text)+4)) {
			//	exit(1);
				OverItem = it;
				return;
			}
		}

		dy = dy + UI::TextHeight(it->Text) + 8;

	}




}

void MainMenuControl::MouseMove(int x, int y, int mx, int my) {
	int rx = 3;
	OverItem = NULL;
	ActiveItem = NULL;
	for (int i = 0; i < Items.size(); i++) {

		auto mi = Items[i];

		if (x > rx && x <= (rx + UI::TextWidth(mi->Text)))
		{
			if (y >= 0 && y <= (25)) {
				ActiveItem = mi;
			}
		}

		if (mi->Items.size() > 0) {

			MM_Menu(mi, GetX()+x,GetY()+ y, GetX() + mx, GetY() + 25);

		}
		rx = rx + UI::TextWidth(mi->Text) + 10;
	}

};

void MainMenuControl::DrawMenu(MenuItem* item, int dx, int dy) {

	int mh = 0;
	int mw = 0;

	for (int i = 0; i < item->Items.size(); i++) {

		auto it = item->Items[i];
		mh = mh + UI::TextHeight(it->Text) + 8;
		if (UI::TextWidth(it->Text) > mw)
		{
			mw = UI::TextWidth(it->Text);
		}
	}

	UI::Theme->DrawFrame(dx, dy, mw+8, mh+5, 0.5f, 0.5f, 0.5f, 0.7f);

	dy = dy + 4;

	for (int i = 0; i < item->Items.size(); i++) {

		auto it = item->Items[i];
		if (OverItem == it) {

			UI::Theme->DrawFrame(dx, dy-3, mw+4, 23, 0.7f, 1, 1, 0.8f);

		};
		UI::DrawText(dx, dy, it->Text, 1, 1, 1, 1);

		dy = dy + UI::TextHeight(it->Text) + 8;

	}


}; 

bool MainMenuControl::CheckMenuBounds(MenuItem * item,int dx, int dy,int mx,int my) {


	int mh = 0;
	int mw = 0;

	for (int i = 0; i < item->Items.size(); i++) {

		auto it = item->Items[i];
		mh = mh + UI::TextHeight(it->Text) + 8;
		if (UI::TextWidth(it->Text) > mw)
		{
			mw = UI::TextWidth(it->Text);
		}
	}

	if (mx >= (dx) && mx <= (dx + mw + 8))
	{
		if (my >= (dy) && my <= (dy + mh + 5))
		{
			return true;
		}
	}
	return false;
	//UI::Theme->DrawFrame(dx, dy, mw + 8, mh + 5, 0.5f, 0.5f, 0.5f, 0.7f);

}

bool MainMenuControl::InBounds(int x, int y) {

	int mx = 3;

	for (int i = 0; i < Items.size(); i++) {

		auto mi = Items[i];

		if (x >= GetX() + mx && y <= (GetX() + mx + UI::TextWidth(mi->Text)))
		{
			if (y >= GetY() && y <= GetH()) {
				return true;
			}

		}



	//	UI::DrawText(GetX() + mx, GetY() + 3, mi->Text, 1, 1, 1, 1);

	//	UI::Theme->DrawFrame(GetX() + mx + UI::TextWidth(mi->Text) + 5, GetY(), 2, GetH(), 1, 1, 1, 1);

		mx = mx + UI::TextWidth(mi->Text) + 10;

		if (mi->Items.size() > 0) {

			if (CheckMenuBounds(mi, GetX(), GetY() + 25, x, y)) {
				return true;
			}


		}


	}

	return false;

};

void MainMenuControl::Render() {

	UI::Theme->DrawFrame(GetX(), GetY(), GetW(), GetH(), 0.4f, 0.4f, 0.4f, 0.7f);

	int mx = 3;

	for (int i = 0; i < Items.size(); i++) {

		auto mi = Items[i];

		if (ActiveItem == mi) {

			UI::Theme->DrawFrame(GetX() + mx, GetY() + 3, UI::TextWidth(mi->Text) + 3, 23, 0.9f, 0.9f, 0.9f, 0.7f);

		}

		UI::DrawText(GetX()+mx, GetY() + 3, mi->Text, 1, 1, 1, 1);

		UI::Theme->DrawFrame(GetX()+mx + UI::TextWidth(mi->Text) + 5, GetY(), 2, GetH(), 1, 1, 1, 1);


		if (mi->Items.size() > 0) {

			if (mi->Open) {

				DrawMenu(mi, GetX() + mx, GetY() + 25);
			}
		}


		mx = mx + UI::TextWidth(mi->Text) + 10;
	}

}

void MainMenuControl::Update() {


};