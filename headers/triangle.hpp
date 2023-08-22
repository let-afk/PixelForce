#include <iostream>
#include <string>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "shader.h"

#ifndef PF_TRIANGLE_H
#define PF_TRIANGLE_H

struct Triangle
{
    GLfloat vertices[15];
    GLuint tex_id = 0;
    Shader ourShader;
    std::string shader_path;
    GLuint VBO, VAO;
    Triangle(GLfloat vertices[15], std::string shader_path = "shaders/texture");
    Triangle() = default;
    ~Triangle();
    void SettingGL();
    void Draw();
    void SetTexture(const char *name_image);
};

#endif

// GLfloat vertices[] = {
//     -0.5f, -0.5f, 0.0f,
//      0.5f, -0.5f, 0.0f,
//      0.0f,  0.5f, 0.0f
// };