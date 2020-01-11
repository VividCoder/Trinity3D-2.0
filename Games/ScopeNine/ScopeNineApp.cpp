#include "ScopeNineApp.h"
#include "UITheme.h"
#include "UITheme_Neon.h"
#include "MainMenuControl.h";
#include "UI.h"
#include "Utils.h"
ScopeNineApp::ScopeNineApp() {


};


void ScopeNineApp::Init()
{


	UITheme_Neon* theme = new UITheme_Neon();

	UI::SetTheme(theme);

	Utils::randSeedTicks();
	ui = new UI(Width(), Height());

	Split1 = new  VerticalSplitterControl();

	Split1->Set(0, 0, Width(), Height());

	Split2 = new HorizontalSplitterControl();

	Split3 = new HorizontalSplitterControl();

	auto b = new ButtonControl();


	Split1->SetTop(Split2);

	Split2->SetRight(Split3);

	Split1->SetSplit(Height() - 150);

	Split2->SetSplit(200);
	Split3->SetSplit(850);

	Edit1 = new MapEditControl(4,4,64,64);

	MainMenuControl* MapMenu = new MainMenuControl();

	auto mm = MapMenu->AddItem("Map/n");

	auto new_map = mm->AddItem("New Mapo/n");
	auto load_map = mm->AddItem("Load Map/n");
	auto save_map = mm->AddItem("Save Map/n");

	auto me = MapMenu->AddItem("Edit/n");

	auto cut = me->AddItem("Cut/n");
	auto copy = me->AddItem("Copy/n");
	auto paste = me->AddItem("Paste/n");
	auto smart = paste->AddItem("Auto1/n");
	auto norm = paste->AddItem("Norm/n");

	

	//norm->SetAction(test);

	auto morem = MapMenu->AddItem("More/n");


	Edit1->AddControl(MapMenu);

	Split3->SetLeft(Edit1);

	MapMenu->Set(0, 0, Edit1->GetW(), 25);

	ui->GetRoot()->AddControl(Split1);

}

void ScopeNineApp::Update() {

	ui->Update();

};

void ScopeNineApp::Render() {

	ui->Render();

}