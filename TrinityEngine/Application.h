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

	static void SetRen(int w, int h);
	static void ResetRen();

	static int WinW;
	static int WinH;
	static int RenW;
	static int RenH;
	

	void Run();

private:
	GLFWwindow* Window;
	int WinWidth, WinHeight;
	int RenWidth, RenHeight;
};

