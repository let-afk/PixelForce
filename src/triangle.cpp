#include <iostream>

#include "../headers/triangle.hpp"
#include "../headers/shader.h"

void Triangle::SettingGL()
{
    this->ourShader = Shader("shaders/triangle.vert", "shaders/triangle.frag");
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray(this->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices), this->vertices, GL_STATIC_DRAW);
    // GL_STATIC_DRAW: the data will either never change, or it will change very rarely;
    // GL_DYNAMIC_DRAW: the data will change quite often;
    // GL_STREAM_DRAW: the data will change with each rendering.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

    glBindVertexArray(0);
}

Triangle::Triangle(GLfloat *vertices, int dim)
{
    switch (dim)
    {
    case 2:
    {
        int ind_v = 0;
        for (int i = 0; i < 9; i++)
        {
            if ((i + 1) % 3 == 0)
                this->vertices[i] = 0.0f;
            else
                this->vertices[i] = vertices[ind_v++];
        }
        break;
    }
    case 3:
        for (int i = 0; i < 9; i++)
            this->vertices[i] = vertices[i];
        break;

    default:
        std::cout << "the dimension can only be 2 or 3" << std::endl;
        break;
    }
    this->SettingGL();
}

Triangle::~Triangle()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    this->ourShader.Delete();
}

void Triangle::Draw()
{
    GLint vertexColorLocation = glGetUniformLocation(this->ourShader.ID, "ourColor");

    this->ourShader.Active();
    if (vertexColorLocation != -1)
        glUniform4f(vertexColorLocation, this->color[0], this->color[1], this->color[2], 1.0f);
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}