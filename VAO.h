#ifndef PF_VAO_H
#define PF_VAO_H

#include<GL/glew.h>
#include"VBO.h"

struct VAO
{
    GLuint ID;

   //Construct a new Vertex Array Object
    VAO();

    //Bind the VAO
    void Bind();

    //Unbind the VAO
    void Unbind();

    //void LinkVBO(VBO & VBO, GLuint layout);
    void LinkAttrib(VBO & VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
    
    //Delete the VAO
    void Delete();
};


#endif