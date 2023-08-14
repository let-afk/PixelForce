#include "../headers/shader.h"

std::string Shader::ReadFile(const char *file)
{
    std::ifstream in(file, std::ios::binary);

    if (not in.is_open())
    {
        std::cout << "File " << file << " is not found\n";
        throw(errno);
    }

    std::string contents;
    in.seekg(0, std::ios::end);
    contents.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    in.close();
    return (contents);
}

Shader::Shader(const char *vertexFile, const char *fragmentFile)
{
    // read vertexFile and fragmentFile
    std::string vertexCode = ReadFile(vertexFile);
    std::string fragmentCode = ReadFile(fragmentFile);

    // convert to C string
    const char *vertexShaderSource = vertexCode.c_str();
    const char *fragmentShaderSource = fragmentCode.c_str();

    // create vertexShader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLint success;
    GLchar info[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    // check errors
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, info);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << info << std::endl;
    }

    // create fragmentShader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    // check errors
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, info);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
                  << info << std::endl;
    }

    // create ShaderProgram and get it reference
    ID = glCreateProgram();

    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);

    // link shaders in ShaderProgram
    glLinkProgram(ID);

    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(ID, 512, NULL, info);
        std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n"
                  << info << std::endl;
    }

    // delete now useless vertex and fragment shader
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::Active()
{
    glUseProgram(ID);
}

void Shader::Delete()
{
    glDeleteProgram(ID);
}