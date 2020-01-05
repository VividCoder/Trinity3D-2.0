#include "pch.h"
#include "Application.h"
#include "UI.h"

Application::Application() {

	Window = NULL;

};

static void cursor_callback(GLFWwindow* win, double xpos, double ypos)
{

	UI::SetMouse((int)xpos, (int)ypos, 0);

}

void Application::CrWindow(int w, int h, const char* title) {

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_DOUBLEBUFFER, GL_FALSE);
	Window = glfwCreateWindow(w, h, title, NULL, NULL);

	glfwMakeContextCurrent(Window);

	glViewport(0, 0, w, h);
	glDisable(GL_BLEND);
	glDisable(GL_SCISSOR_TEST);

	glewInit();

	WinWidth = w;
	WinHeight = h;

	glfwSetCursorPosCallback(Window, cursor_callback);
	glfwSetInputMode(Window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
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

	double prev_time = glfwGetTime();
	int framec = 0;
	int fps=0;
	//glfwSwapInterval(0);

	while (true) {

		double cur_time = glfwGetTime();
		framec++;
		if ((cur_time - prev_time) >= 1.0)
		{
			fps = framec;
			framec = 0;
			prev_time = cur_time;
			printf("FPS:%d \n", fps);
		}

		Update();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Render();


		glFlush();
		//glfwSwapBuffers(Window);
		glfwPollEvents();

	}

}