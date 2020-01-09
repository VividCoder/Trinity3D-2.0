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

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	bool lb, rb, mb;
	lb = false;
	rb = false;
	mb = false;

	if (button == GLFW_MOUSE_BUTTON_LEFT) {

		if (action == GLFW_PRESS) {
			lb = true;
		}
		else {
			lb = false;
		}

		UI::SetMouseBut(0, lb);

	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT) {


		if (action == GLFW_PRESS) {
			lb = true;
		}
		else {
			lb = false;
		}
	
		UI::SetMouseBut(1, lb);

	}


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
	RenW = w;
	RenH = h;
	WinW = w;
	WinH = h;

	glfwSetCursorPosCallback(Window, cursor_callback);
	glfwSetInputMode(Window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

	glfwSetMouseButtonCallback(Window, mouse_button_callback);

};

 int Application::RenW = 0;
 int Application::RenH = 0;
 int Application::WinW = 0;
 int Application::WinH = 0;


 void Application::SetRen(int w, int h) {

	 RenW = w;
	 RenH = h;

 };

 void Application::ResetRen() {

	 RenW = WinW;
	 RenH = WinH;

 }

int Application::Width() {
	return WinWidth;
}

int Application::Height() {
	return WinHeight;
}


void Application::Run() {

	Init();

	glClearColor(0, 0,0, 1.0f);

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