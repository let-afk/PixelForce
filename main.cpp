#include <iostream>
#include <math.h>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "headers/window.hpp"
#include "headers/triangle.hpp"
#include "headers/quadrangle.hpp"
#include "headers/cube.hpp"
#include "headers/camera.hpp"

int main()
{
    // necessarily in this order
    Window window_object = Window();
    Camera cam_obj = Camera();
    window_object.camera_obj = &cam_obj;
    window_object.set_callback();

    float vertices_cube[] = {
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

        -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f};

    glm::vec3 cubePositions[] = {
        glm::vec3(1.0f, 0.0f, 0.0f),
        glm::vec3(2.0f, 0.0f, 0.0f),
        glm::vec3(3.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(1.0f, 1.0f, 0.0f),
        glm::vec3(2.0f, 1.0f, 0.0f),
        glm::vec3(3.0f, 1.0f, 0.0f),
        glm::vec3(0.0f, 2.0f, 0.0f),
        glm::vec3(1.0f, 2.0f, 0.0f),
        glm::vec3(2.0f, 2.0f, 0.0f),
        glm::vec3(3.0f, 2.0f, 0.0f),
        glm::vec3(0.0f, 3.0f, 0.0f),
        glm::vec3(1.0f, 3.0f, 0.0f),
        glm::vec3(2.0f, 3.0f, 0.0f),
        glm::vec3(3.0f, 3.0f, 0.0f)};

    Cube cube = Cube(vertices_cube);
    Cube cube1 = Cube(vertices_cube);
    cube.SetTexture("wood.jpg");
    cube1.SetTexture("stone.jpg");
    while (!glfwWindowShouldClose(window_object.window))
    {
        // check events and call callback functions
        glfwPollEvents();
        cam_obj.move();
        // code
        window_object.Clear();
        cam_obj.activate(window_object.width, window_object.height);
        cube.Draw();
        cube1.Draw(glm::vec3(5.0f, 0.0f, 0.0f));
        for (const auto &pos : cubePositions)
        {
            cube.Add(pos);
            cube1.Add(-pos);
        }
        glfwSwapBuffers(window_object.window);
    }
    glfwTerminate();
    return 0;
}
