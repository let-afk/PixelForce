#ifndef PF_WINDOW_H
#define PF_WINDOW_H

#include<GLFW/glfw3.h>
#include<iostream>

#define WINDOW_DEFAULT_WIDTH 1024
#define WINDOW_DEFAULT_HEIGHT 768
#define WINDOW_DEFAULT_NAME "PixelForce"

struct Window
{

    GLFWwindow * window;
private:
    //инициализация всяких штук из GLFW
    void _Init();
public:
    //создаёт окно по заданным параметрам
    Window(int width, int height, const char *title, GLFWmonitor *monitor, GLFWwindow *share);
    //удаляет окно
    ~Window();

    //void display()
    
    //если окно открыто вернёт true
    bool IsOpened();
    GLFWwindow * GetGLFWwindow() {return window;}
};
#endif