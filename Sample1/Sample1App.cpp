#include "Sample1App.h"
#include <stdio.h>
#include "Texture2D.h"
#include "IDraw.h"


Sample1App::Sample1App() {


};

void Sample1App::Init() {

	tex1 = new Texture2D("Data/Test/logo1.png", true);
	draw = new IDraw();

};

void Sample1App::Update() {



};

void Sample1App::Render() {

	draw->Begin();
	
	draw->DrawTex(20, 20, 300, 300, tex1, 1, 1, 1, 1);

	draw->End();

};