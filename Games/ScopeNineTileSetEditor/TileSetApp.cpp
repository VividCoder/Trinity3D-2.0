#include "TileSetApp.h"
#include "UITheme.h"
#include "UITheme_Neon.h"
#include "MainMenuControl.h";
#include "FileRequestorControl.h"
#include "UI.h"
#include "Utils.h"


TileSetApp::TileSetApp() {


}

void TileSetApp::Init() {
	UITheme_Neon* theme = new UITheme_Neon();

	UI::SetTheme(theme);

	ui = new UI(Width(), Height());

	HorizontalSplitterControl * Split = new HorizontalSplitterControl;
	
	
	Split->Set(0, 0, Width(), Height());
	

	MainMenuControl* Menu = new MainMenuControl;

	auto m_file = Menu->AddItem("Files/n");

	auto f_addimg = m_file->AddItem("Add Image/n");
	auto f_addfolder = m_file->AddItem("Add Folder/n");

	auto a_addimg = [&] {

		FileRequestorControl* filer = new FileRequestorControl;

		filer->SetText("FILER/n");

		filer->Set(50, 50, 350, 500);

		ui->SetTop(filer);

	};

	f_addimg->SetAction(a_addimg);


	auto map = new MapEditControl(64, 64, 64, 64);

	//return;
	Split->SetSplit(Width()-300);


	Split->SetLeft(map);

	

	map->AddControl(Menu);

	//return;

	
	//eturn;

	Menu->Set(0, 0, Width(), 25);
	
	//return;

	ui->GetRoot()->AddControl(Split);
//	while (true) {};
	return;
};

void TileSetApp::Update() {

	ui->Update();

};

void TileSetApp::Render() {

	ui->Render();

};