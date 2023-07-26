#ifndef PF_SHADER_H
#define PF_SHADER_H

#include<GL/glew.h>
#include<iostream>
#include<fstream>
#include<string>

struct Shader
{
    //Reference ID of the Shader Program
    GLuint ID;

    /**
     * @brief Construct a new Shader object
     * 
     * @param vertexFile 
     * @param fragmentFile 
     */
    Shader(const char * vertexFile, const char * fragmentFile);

    //active Shader Program
    void Active();

    //delete Shader Program
    void Delete();

    private:
    /**
     * @brief read the file's content and store it in the string
     * 
     * @param file filepath
     * @return string content of the file
     */
    std::string ReadFile(const char * file);
};

#endif