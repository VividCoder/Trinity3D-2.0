#include "pch.h"
#include "Application.h"

typedef int32_t i32;
typedef uint32_t u32;
typedef int32_t b32;

bool Application::CrWindow(const char* title, int w, int h) {

    u32 WindowFlags = SDL_WINDOW_OPENGL;
     Window = SDL_CreateWindow(title, 0, 0,w, h, WindowFlags);
    assert(Window);
    Context = SDL_GL_CreateContext(Window);

    WinWidth = w;
    WinHeight = h;


	return true;
};

void Application::Run() {


    glViewport(0, 0, WinWidth, WinHeight);
    glClearColor(1.f, 0.f, 1.f, 0.f);
    
    SDL_Event Event;

    while (true) {



        glClear(GL_COLOR_BUFFER_BIT);
  
        SDL_GL_SwapWindow(Window);
    
    }
    
//    glClear(GL_COLOR_BUFFER_BIT);


};

void Application::SetGL() {

    glViewport(0, 0, WinWidth, WinHeight);
    glDisable(GL_BLEND);
    glDisable(GL_SCISSOR_TEST);
   


};