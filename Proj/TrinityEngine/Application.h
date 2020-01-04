#pragma once
#include <SDL.h>

class Application
{
public:

	bool CrWindow(const char* title, int w, int h);

	void SetGL();

	void Run();

private:

	SDL_Window* Window;
	SDL_GLContext Context;
	int WinWidth;
	int WinHeight;

};

