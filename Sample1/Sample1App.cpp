#include "Sample1App.h"
#include <stdio.h>
#include "Texture2D.h"
#include "IDraw.h"


Sample1App::Sample1App() {


};

void Sample1App::Init() {

	tex1 = new Texture2D("Data/Test/logo1.png", true);
	draw = new IDraw(Width(),Height());

};

void Sample1App::Update() {



};

void Sample1App::Render() {

	draw->Begin();
	
	draw->DrawTex(50, 50, 260,260, tex1, 1, 1, 1, 1);
	draw->DrawTex(100, 100, 260, 260, tex1, 1, 1, 1, 1);

	draw->End();

};