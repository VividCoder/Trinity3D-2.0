#include "pch.h"
#include "Application.h"

Application::Application() {

	Window = NULL;

};

void Application::CrWindow(int w, int h, const char* title) {

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	Window = glfwCreateWindow(w, h, title, NULL, NULL);

	glfwMakeContextCurrent(Window);

	glViewport(0, 0, w, h);
	glDisable(GL_BLEND);
	glDisable(GL_SCISSOR_TEST);

	glewInit();

	WinWidth = w;
	WinHeight = h;



};

int Application::Width() {
	return WinWidth;
}

int Application::Height() {
	return WinHeight;
}


void Application::Run() {

	Init();

	glClearColor(0, 1, 1, 1.0f);

	while (true) {

		Update();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Render();



		glfwSwapBuffers(Window);
		glfwPollEvents();
	}

}