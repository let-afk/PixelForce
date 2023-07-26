#include"window.h"

void Window::_Init() 
{
    glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy;
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

Window::Window(int width, int height, const char *title, GLFWmonitor *monitor, GLFWwindow *share) 
{
    _Init();
    window = glfwCreateWindow( width, height, title, monitor, share);

    if (window == NULL) {
        std::cout << "Failed to create window\n";
        glfwTerminate();
        throw(errno);
    }

    glfwMakeContextCurrent(window);
}

Window::~Window()
{
    glfwDestroyWindow(window);
}

bool Window::IsOpened()
{
    return glfwWindowShouldClose(window) == 0;
}