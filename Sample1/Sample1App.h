#pragma once
#include "Application.h"

class Texture2D;

class Sample1App :
	public Application
{
public:

	Sample1App();

	void Init();
	void Update();
	void Render();

private:

	Texture2D* tex1;

};
