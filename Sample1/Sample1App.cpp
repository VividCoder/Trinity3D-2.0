#include "Sample1App.h"
#include <stdio.h>
#include "Texture2D.h"
#include "IDraw.h"
#include "Utils.h"
#include "UITheme_Neon.h"
#include "ImageControl.h"
#include "VerticalSplitterControl.h"
#include "HorizontalSplitterControl.h"
Sample1App::Sample1App() {


};



void Sample1App::Init() {


	UITheme_Neon* theme = new UITheme_Neon();
	
	UI::SetTheme(theme);

	tex1 = new Texture2D("Data/Test/logo1.png", true);
	tex2 = new Texture2D("Data/TEst/button1.png", true);
	draw = new IDraw(Width(),Height());
	Utils::randSeedTicks();
	ui = new UI(Width(),Height());

	

	ImageControl* bg = new ImageControl("Data/UI/Bg/bg1.png", true);

	HorizontalSplitterControl* s1 = new HorizontalSplitterControl();
	VerticalSplitterControl* s2 = new VerticalSplitterControl();

	s1->Set(0, 0, 800, 600);

	win1 = new WindowControl();
	win1->Set(20, 20, 300, 400)->SetText("Win1/n");

	b1 = (ButtonControl*)new ButtonControl();
	b1->Set(20, 20, 120, 25)->SetText("Test/n");

	b2 = new ButtonControl();
	b2->Set(20, 100, 150, 40)->SetText("New/n");

	// Neon filter.

	//void act_new() {

	//	exit(1);

	//};

	auto act_new = [&]() {

		b2->Set(b2->GetX()+5, b2->GetY(), b2->GetW(), b2->GetH());

	};

	b2->SetActionOne(act_new);

	win1->AddBodyControl(b1);

	bg->AddControl(win1);

	bg->SetSize(800, 600);

	ui->GetRoot()->AddControl(s1);
	s1->SetLeft(s2);
	s2->SetTop(win1);
	
	s1->SetRight(b2);
	//ui->GetRoot()->AddControl(b2);





};

void Sample1App::Update() {

	ui->Update();

};

void Sample1App::Render() {


	ui->Render();





	//draw->SingleDrawTex(350, 80, 260, 260, tex1, 1, 1, 1, 1);



	//printf("R:%d \n", Utils::rand(50, 100));

};