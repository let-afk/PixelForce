#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "shader.h"

#ifndef PF_QUADRANGLE_H
#define PF_QUADRANGLE_H

struct Quadrangle
{
    GLfloat vertices[20];
    Shader ourShader;
    GLuint indices[6] = {0, 1, 3, 1, 2, 3};
    GLuint VBO, VAO, EBO;
    std::string shader_path;
    GLuint tex_id = 0;
    Quadrangle(GLfloat vertices[20], std::string shader_path = "texture");
    Quadrangle() = default;
    ~Quadrangle();
    void SettingGL();
    void Draw();
    void SetTexture(std::string name_image);
};

#endif
// GLfloat vertices[] = {
//     0.5f, 0.5f, 0.0f,
//     0.5f, -0.5f, 0.0f,
//     -0.5f, -0.5f, 0.0f,
//     -0.5f, 0.5f, 0.0f