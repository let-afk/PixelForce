#ifndef PF_VBO_H
#define PF_VBO_H

#include<GL/glew.h>

struct VBO
{
    GLuint ID;

    /**
    * @brief Construct a new Vertex Buffer Object
    * 
    * @param vertices pointer to an array of vertex
    * @param size size of array in bytes
    */
    VBO(GLfloat * vertices, GLsizeiptr size);

    //Bind the VBO
    void Bind();

    //Unbind the VBO
    void Unbind();

    //Delete the VBO
    void Delete();
};

#endif