#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "shader.h"

#ifndef PF_CUBE_H
#define PF_CUBE_H

struct Cube
{
    GLfloat vertices[180];
    glm::mat4 MVP;
    Shader ourShader;
    GLuint VBO, VAO;
    std::string shader_path;
    GLuint tex_id = 0;
    Cube(GLfloat vertices[180], std::string shader_path = "texture");
    Cube() = default;
    ~Cube();
    void SettingGL();
    void Draw(glm::vec3 pos = glm::vec3(0, 0, -10), float angle = 90.0f, glm::vec3 axis_rot = glm::vec3(1, 0, 0));
    void Add(glm::vec3 pos, float angle = 0.0f, glm::vec3 axis_rot = glm::vec3(1.0f, 0.0f, 0.0f));
    void SetTexture(std::string name_image);
};

#endif
