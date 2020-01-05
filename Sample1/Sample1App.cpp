#include "Sample1App.h"
#include <stdio.h>
#include "Texture2D.h"
#include "IDraw.h"
#include "Utils.h"


Sample1App::Sample1App() {


};

void Sample1App::Init() {

	tex1 = new Texture2D("Data/Test/logo1.png", true);
	draw = new IDraw(Width(),Height());
	Utils::randSeedTicks();

};

void Sample1App::Update() {



};

void Sample1App::Render() {

	draw->Begin();
	

	for (int i = 0; i < 5; i++) {

		draw->DrawTex(Utils::rand(20, 500), Utils::rand(20, 500) , 260, 260, tex1, 1, 1, 1, 1);
		//draw->DrawTex(100, 100, 260, 260, tex1, 1, 1, 1, 1);
	
	}

	draw->End();

	//printf("R:%d \n", Utils::rand(50, 100));

};