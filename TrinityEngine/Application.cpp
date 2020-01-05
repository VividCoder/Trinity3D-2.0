#include "pch.h"
#include "Application.h"

Application::Application() {

	Window = NULL;

};

void Application::CrWindow(int w, int h, const char* title) {

	glfwInit();
	Window = glfwCreateWindow(w, h, title, NULL, NULL);

	glfwMakeContextCurrent(Window);



};

void Application::Run() {

	Init();

	glClearColor(0, 1, 1, 1.0f);

	while (true) {

		Update();

		glClear(GL_COLOR_BUFFER_BIT);

		Render();



		glfwSwapBuffers(Window);
		glfwPollEvents();
	}

}