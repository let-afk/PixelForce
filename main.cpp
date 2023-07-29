#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<iostream>

#include"window.h"
#include"shader.h"
#include"EBO.h"
#include"VBO.h"
#include"VAO.h"

//vertex coordinate with colors
GLfloat verticesWithColors [] = {//color:
    -1.0f, -1.0f, 0.0f,  0.98f, 0.36f, 0.06f,// lower left corner
	 1.0f, -1.0f, 0.0f,  0.98f, 0.36f, 0.96f,// lower right corner
	 0.0f,  1.0f, 0.0f,  0.98f, 0.36f, 0.06f,// upper corner
    -0.5f,  0.0f, 0.0f,  0.98f, 0.36f, 0.06f,// inner left
     0.0f, -1.0f, 0.0f,  0.98f, 0.96f, 0.96f,// inner down
     0.5f,  0.0f, 0.0f,  0.98f, 0.96f, 0.96f // inner right 
};

//vertex coordinate
GLfloat vertices [] = {
    -1.0f, -1.0f, 0.0f,// lower left corner
	 1.0f, -1.0f, 0.0f,// lower right corner
	 0.0f,  1.0f, 0.0f,// upper corner
    -0.5f,  0.0f, 0.0f,// inner left
     0.0f, -1.0f, 0.0f,// inner down
     0.5f,  0.0f, 0.0f // inner right 
};

//indexes for vertex order
GLuint indices[] = {
    0, 3, 4, //lower left triangle
    3, 2, 5, //upper triangle
    4, 5, 1  //lower right triangle
};

int main() {
    if (not glfwInit()) {
        std::cout << "Failed to initialize GLFW\n";
        return -1;
    }

    Window window(1024, 768, WINDOW_DEFAULT_NAME, NULL, NULL);

    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW\n";
        glfwTerminate();
        return -1;
    }

    //Shader shaderProgram("shaders/default.vert","shaders/default.frag");
    //Shader shaderProgram("shaders/default.vert","shaders/test.frag");
    //Shader shaderProgram("shaders/scale.vert","shaders/lol.frag");
    Shader shaderProgram("shaders/scale.vert","shaders/test.frag");

    //glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    VAO VAO1;
	VAO1.Bind();
    
    VBO VBO1(vertices, sizeof(vertices));

    EBO EBO1(indices, sizeof(indices));
    
    //Link VBO to VAO
    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 0, (void*)0); //for vertices
    //VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);                     //for vertices
    //VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));   //with color

    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    do {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //active shader
        shaderProgram.Active();
        
        //update uniform color (in test.frag)
        float timeValue = glfwGetTime();
        float colorValue = glm::cos(timeValue) / 2.0f + 0.1f;
        float redValue = glm::sin(timeValue) + 0.1f;
        int vertexColorLocation = glGetUniformLocation(shaderProgram.ID, "ourColor");
        glUniform4f(vertexColorLocation, redValue, colorValue, 0.0f, 1.0f);

        //upadate uniform "time" (in lol.frag)
        //int timeUniformLocation = glGetUniformLocation(shaderProgram.ID, "time");
        //glUniform1f(timeUniformLocation, timeValue);

        //update uniform "scale" (in default.vert)
        float scale = glm::sin(timeValue) / 2.0f + 1.0f;
        int scaleUniformLocation = glGetUniformLocation(shaderProgram.ID, "scale");
        glUniform1f(scaleUniformLocation, scale);

        //std::cout << scale << std::endl;

        VAO1.Bind();

        //glDrawArrays(GL_TRIANGLES, 0, 3);

        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

        //swap buffers and poll IO events
        glfwSwapBuffers(window.GetGLFWwindow());
        glfwPollEvents();
    } while (window.IsOpened());
    
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();

    glfwTerminate();
    
    return 0;
}