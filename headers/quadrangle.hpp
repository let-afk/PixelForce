#ifndef PF_QUADRANGLE_H
#define PF_QUADRANGLE_H

#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "shader.h"

struct Quadrangle
{
    GLfloat vertices[32];
    // GLfloat color[3] = {0.0f, 0.0f, 0.0f};
    Shader ourShader;
    GLuint indices[6] = {0, 1, 3, 1, 2, 3};
    GLuint VBO, VAO, EBO;
    GLuint tex_id = 0;
    Quadrangle(GLfloat vertices[12]);
    Quadrangle() = default;
    ~Quadrangle();
    void SettingGL();
    void Draw();
    void SetTexture(const char *name_image);
};

#endif
// GLfloat vertices[] = {
//     0.5f, 0.5f, 0.0f,
//     0.5f, -0.5f, 0.0f,
//     -0.5f, -0.5f, 0.0f,
//     -0.5f, 0.5f, 0.0f