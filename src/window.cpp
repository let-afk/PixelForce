#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../headers/window.hpp"
#include "../headers/camera.hpp"

Window::Window(Camera *camera_obj, int width, int height)
{
    this->width = width;
    this->height = height;
    this->camera_obj = camera_obj;
    // GLFW base settings
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    this->window = glfwCreateWindow(width, height, "PixelForce", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GlFW window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);
    // GLEW base settings
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        this->~Window();
    }

    glfwGetFramebufferSize(window, &this->height, &this->width);
    glViewport(0, 0, width, height);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

Window::~Window()
{
    glfwDestroyWindow(this->window);
}

void Window::Clear(GLclampf red, GLclampf green, GLclampf blue)
{
    // fills the window with one color
    glClearColor(red, green, blue, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
            Window::keys[key] = true;
        else if (action == GLFW_RELEASE)
            Window::keys[key] = false;
    }
}

void mouse_callback(GLFWwindow *window, double xpos, double ypos)
{
    GLfloat x_offset = xpos - Window::last_x;
    GLfloat y_offset = Window::last_y - ypos;
    Window::last_x = xpos;
    Window::last_y = ypos;
    Window::camera_obj->camera_rotate(x_offset, y_offset);
}

void Window::set_callback()
{
    if (this->camera_obj != nullptr)
    {
        glfwSetKeyCallback(this->window, key_callback);
        glfwSetCursorPosCallback(this->window, mouse_callback);
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        glfwSetCursorPos(window, 0, 0);
    }
}