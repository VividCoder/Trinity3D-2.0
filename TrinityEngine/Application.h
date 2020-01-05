#pragma once
//#include "pch.h"
class GLFWwindow;


class Application
{
public:

	Application();

	void CrWindow(int w, int h, const char* title);

	virtual void Init() {};
	virtual void Update() {};
	virtual void Render() {};

	int Width();
	int Height();

	void Run();

private:
	GLFWwindow* Window;
	int WinWidth, WinHeight;
};

