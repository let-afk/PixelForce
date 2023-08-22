#include <iostream>

#include "../headers/stb_image.h"

#include "../headers/triangle.hpp"
#include "../headers/shader.h"

void Triangle::SettingGL()
{
    this->ourShader = Shader((this->shader_path + ".vert").c_str(), (this->shader_path + ".frag").c_str());
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray(this->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices), this->vertices, GL_STATIC_DRAW);
    // GL_STATIC_DRAW: the data will either never change, or it will change very rarely;
    // GL_DYNAMIC_DRAW: the data will change quite often;
    // GL_STREAM_DRAW: the data will change with each rendering.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid *)0);
    glEnableVertexAttribArray(0);
    // TexCoord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

    glBindVertexArray(0);
}

Triangle::Triangle(GLfloat vertices[15], std::string shader_path)
{
    this->shader_path = shader_path;
    for (int i = 0; i < 15; i++)
        this->vertices[i] = vertices[i];
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
    if (this->tex_id != 0)
        glBindTexture(GL_TEXTURE_2D, this->tex_id);
    this->ourShader.Active();
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}

void Triangle::SetTexture(const char *name_image)
{
    GLuint texture;
    glGenTextures(1, &texture);
    this->tex_id = texture;
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height;
    unsigned char *image = stbi_load(name_image, &width, &height, 0, STBI_rgb);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(image);
    glBindTexture(GL_TEXTURE_2D, 0);
}