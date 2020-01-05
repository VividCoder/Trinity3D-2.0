#include "pch.h"
#include "FXImageDraw.h"

FXImageDraw::FXImageDraw(int w,int h) {

	load("Data/Shader/2D/drawVS1.glsl", "Data/Shader/2D/drawFS1.glsl");
	pw = w;
	ph = h;
};

void FXImageDraw::setPars() {

	glm::mat4 pMat = glm::ortho((float)0, (float)pw, (float)ph, (float)0, (float)0, (float)100);


	setInt("tR", 0);
	setMat("proj", pMat);

};