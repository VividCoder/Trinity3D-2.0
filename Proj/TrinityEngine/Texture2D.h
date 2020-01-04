#pragma once
#include <SDL.h>

class Texture2D
{
public:

	Texture2D(const char* path,bool alpha);
	void Bind(int unit);
	void Release(int unit);


private:

	GLuint ID;
	unsigned char* Raw;
	int Width, Height;
	bool Alpha;

};

