#pragma once
#include <GL/glew.h>

class Texture2D
{
public:

	Texture2D(const char* path,bool alpha);
	Texture2D(unsigned char* data, int w, int h);
	Texture2D(int w, int h);
	~Texture2D();
	void Bind(int unit);
	void Release(int unit);
	int GetWidth();
	int GetID() {

		return (int)ID;

	};
	int GetHeight();

private:

	GLuint ID;
	unsigned char* Raw;
	int Width, Height;
	bool Alpha;

};

