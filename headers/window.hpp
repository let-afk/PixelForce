#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../headers/camera.hpp"

#ifndef PF_WINDOW_H
#define PF_WINDOW_H

struct Window
{
    static inline bool keys[1024], first_mouse = true;
    static inline double last_x = 0, last_y = 0;
    GLFWwindow *window;
    static inline Camera *camera_obj;
    int width, height;
    Window(Camera *camera_obj = nullptr, int width = 1920, int height = 1080);
    ~Window();
    void Clear(GLclampf red = 0.5f, GLclampf green = 0.5f, GLclampf blue = 0.5f);
    void set_callback();
};

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow *window, double xpos, double ypos);

#endif