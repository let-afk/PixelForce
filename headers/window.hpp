#ifndef PF_WINDOW_H
#define PF_WINDOW_H

#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

struct Window
{
    GLFWwindow *window;
    int width, height;

    Window(int width = 1920, int height = 1080);
    ~Window();
    void Clear(GLclampf red = 0.5f, GLclampf green = 0.5f, GLclampf blue = 0.5f);
};

void close_window_esc(GLFWwindow *window, int key, int scancode, int action, int mode);

#endif