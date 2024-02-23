#include <iostream>

#include "../headers/stb_image.h"

#include "../headers/triangle.hpp"
#include "../headers/shader.h"

void Triangle::SettingGL()
{
    this->ourShader = Shader(("shaders/" + this->shader_path + ".vert").c_str(), ("shaders/" + this->shader_path + ".frag").c_str());
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    this->vao_obj.Bind();
    this->vbo_obj = VBO(this->vertices, sizeof(this->vertices));
    // GL_STATIC_DRAW: the data will either never change, or it will change very rarely;
    // GL_DYNAMIC_DRAW: the data will change quite often;
    // GL_STREAM_DRAW: the data will change with each rendering.
    this->vao_obj.LinkAttrib(this->vbo_obj, 0, 3, GL_FLOAT, 5 * sizeof(GLfloat), (GLvoid *)0);
    // TexCoord attribute
    this->vao_obj.LinkAttrib(this->vbo_obj, 1, 2, GL_FLOAT, 5 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
    this->vao_obj.Unbind();
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
    this->vao_obj.Delete();
    this->vbo_obj.Delete();
    this->ourShader.Delete();
}

void Triangle::Draw()
{
    if (this->tex_id != 0)
        glBindTexture(GL_TEXTURE_2D, this->tex_id);
    this->ourShader.Active();
    this->vao_obj.Bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
    this->vao_obj.Unbind();
}

void Triangle::SetTexture(std::string name_image)
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
    unsigned char *image = stbi_load(("images/" + name_image).c_str(), &width, &height, 0, STBI_rgb);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(image);
    glBindTexture(GL_TEXTURE_2D, 0);
}