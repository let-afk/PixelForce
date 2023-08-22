#include <iostream>
#include <math.h>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "headers/window.hpp"
#include "headers/triangle.hpp"
#include "headers/quadrangle.hpp"

int main()
{
    Window window_object = Window();

    GLfloat vertices_quad[] = {
        // Positions  // Texture Coords
        0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.0f, 0.0f, 1.0f};
    Quadrangle quad = Quadrangle(vertices_quad);
    quad.SetTexture("images/tree.jpg");

    GLfloat vertices_tri[] = {
        -1.0f, -0.5f, 0.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        -1.0f, 0.5f, 0.0f, 0.0f, 1.0f};
    Triangle tri = Triangle(vertices_tri);
    tri.SetTexture("images/tree.jpg");

    while (!glfwWindowShouldClose(window_object.window))
    {
        // check events and call callback functions
        glfwPollEvents();

        // code
        window_object.Clear();
        quad.Draw();
        tri.Draw();

        glfwSwapBuffers(window_object.window);
    }

    glfwTerminate();
    return 0;
}