#include "Sample1App.h"
#include <stdio.h>
#include "Texture2D.h"
#include "IDraw.h"
#include "Utils.h"
#include "UITheme_Neon.h"

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

	win1 = new WindowControl();
	win1->Set(20, 20, 300, 400)->SetText("Win1/n");

	b1 = (ButtonControl*)new ButtonControl();
	b1->Set(20, 20, 300, 300)->SetText("Test/n");

	b2 = new ButtonControl();
	b2->Set(20, 100, 150, 40)->SetText("New/n");

	//void act_new() {

	//	exit(1);

	//};

	auto act_new = [&]() {

		b2->Set(b2->GetX()+5, b2->GetY(), b2->GetW(), b2->GetH());

	};

	b2->SetActionOne(act_new);

	ui->GetRoot()->AddControl(win1);
	//ui->GetRoot()->AddControl(b2);





};

void Sample1App::Update() {

	ui->Update();

};

void Sample1App::Render() {


	ui->Render();


	draw->Begin();
	

	//for (int i = 0; i < 500; i++) {

		//draw->DrawTex(20,20, 260, 260, tex1, 1, 1, 1, 1);
		//draw->DrawTex(80, 80, 260, 260, tex1, 1, 1, 1, 1);
	//	draw->DrawTex(120, 120, 260, 260, tex2, 1, 1, 1, 1);
		draw->DrawTex(100, 100, 260, 260, tex1, 1, 1, 1, 1);
	
	//}

	draw->End();


	//draw->SingleDrawTex(350, 80, 260, 260, tex1, 1, 1, 1, 1);



	//printf("R:%d \n", Utils::rand(50, 100));

};