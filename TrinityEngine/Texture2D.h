#pragma once
#include <GL/glew.h>

class Texture2D
{
public:

	Texture2D(const char* path,bool alpha);
	Texture2D(unsigned char* data, int w, int h);
	void Bind(int unit);
	void Release(int unit);
	int GetWidth();

	int GetHeight();

private:

	GLuint ID;
	unsigned char* Raw;
	int Width, Height;
	bool Alpha;

};

