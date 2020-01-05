#include "Sample1App.h"
#include <stdio.h>
#include "Texture2D.h"
#include "IDraw.h"
#include "Utils.h"


Sample1App::Sample1App() {


};

void Sample1App::Init() {

	tex1 = new Texture2D("Data/Test/logo1.png", true);
	tex2 = new Texture2D("Data/TEst/button1.png", true);
	draw = new IDraw(Width(),Height());
	Utils::randSeedTicks();

};

void Sample1App::Update() {



};

void Sample1App::Render() {

	draw->Begin();
	

	//for (int i = 0; i < 500; i++) {

		draw->DrawTex(20,20, 260, 260, tex1, 1, 1, 1, 1);
		draw->DrawTex(80, 80, 260, 260, tex1, 1, 1, 1, 1);
		draw->DrawTex(120, 120, 260, 260, tex2, 1, 1, 1, 1);
		//draw->DrawTex(100, 100, 260, 260, tex1, 1, 1, 1, 1);
	
	//}

	draw->End();

	draw->SingleDrawTex(350, 80, 260, 260, tex1, 1, 1, 1, 1);

	//printf("R:%d \n", Utils::rand(50, 100));

};