#include "pch.h"
#include "Texture2D.h"
#include <stdio.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <GL/glew.h>

Texture2D::Texture2D(const char* path,bool alpha) {

	int iw, ih, bpp;
	
	ID = 0;

	int ds = 3;

	if (alpha) {
		ds = 4;
	}
	
	//iw = 0;
	//ih = 0;
//	bpp = 0;
	Raw = stbi_load(path, &iw, &ih, &bpp, ds);

	glGenTextures(1,&ID);

	printf("TEX - W:%d H:%d BPP:%d\n", iw, ih, bpp);
	


	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ID);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	GLenum form = GL_RGB;

	if (bpp == 4) {
		form = GL_RGBA;
	}


	glTexImage2D(GL_TEXTURE_2D, 0, bpp, iw, ih, 0, form, GL_UNSIGNED_BYTE, Raw);

	glBindTexture(GL_TEXTURE_2D, 0);

	Width = iw;
	Height = ih;

	Alpha = alpha;

};

void Texture2D::Bind(int unit) {

	glActiveTexture(GL_TEXTURE0 + unit);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ID);

};

void Texture2D::Release(int unit) {

	glActiveTexture(GL_TEXTURE0 + unit);
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);


};

int Texture2D::GetWidth() {

	return Width;

}

int Texture2D::GetHeight() {

	return Height;

}