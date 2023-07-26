#ifndef PF_EBO_H
#define PF_EBO_H

#include<GL/glew.h>

struct EBO
{
    GLuint ID;

    /**
    * @brief Construct a new Element Buffer Object
    * 
    * @param indices pointer to an array of indexes
    * @param size size of array in bytes
    */
    EBO(GLuint * indices, GLsizeiptr size);

    //Bind the EBO
    void Bind();

    //Unbind the EBO
    void Unbind();

    //Delete the EBO
    void Delete();
};

#endif