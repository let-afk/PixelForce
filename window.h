#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<iostream>

#define WINDOW_DEFAULT_WIDTH 1024
#define WINDOW_DEFAULT_HEIGHT 768
#define WINDOW_DEFAULT_NAME "PixelForce"

class Window
{
private:
    GLFWwindow * window;

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

