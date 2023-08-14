#ifndef PF_TRIANGLE_H
#define PF_TRIANGLE_H

#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "shader.h"

struct Triangle
{

    GLfloat vertices[9];
    GLfloat color[3] = {0.0f, 0.0f, 0.0f};
    Shader ourShader;
    GLuint VBO, VAO;
    Triangle(GLfloat *vertices, int dim = 3);
    Triangle() = default;
    ~Triangle();
    void SettingGL();
    void Draw();
};

#endif

// GLfloat vertices[] = {
//     -0.5f, -0.5f, 0.0f,
//      0.5f, -0.5f, 0.0f,
//      0.0f,  0.5f, 0.0f
// };