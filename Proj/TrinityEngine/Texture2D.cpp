#include "pch.h"
#include "Texture2D.h"
#include "stb_image.h"

Texture2D::Texture2D(const char* path,bool alpha) {

	int iw, ih, bpp;
	
	int ds = 3;

	if (alpha) {
		ds = 4;
	}
	
	Raw = stbi_load(path, &iw, &ih, &bpp, ds);

	glGenTextures(1, &ID);

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ID);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	GLenum form = GL_RGB;

	if (bpp == 4) {
		form = GL_RGBA;
	}


	glTexImage2D(GL_TEXTURE_2D, 0, bpp, iw, ih, 0, form, GL_UNSIGNED_BYTE, Raw);

	Alpha = alpha;

};

void Texture2D::Bind(int unit) {

	glActiveTexture(GL_TEXTURE0 + unit);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ID);

}

void Texture2D::Release(int unit) {

	glActiveTexture(GL_TEXTURE0 + unit);
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);


}