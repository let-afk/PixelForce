#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<iostream>

#include"window.h"
#include"shader.h"


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

    Shader shaderProgram("shaders/default.vert","shaders/default.frag");

    //glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    GLfloat vertices [] = {
        -1.0f, -1.0f, 0.0f,// lower left corner
		 1.0f, -1.0f, 0.0f,// lower right corner
		 0.0f,  1.0f, 0.0f,// upper corner
         -0.5f, 0.0f, 0.0f,// inner left
         0.0f, -1.0f, 0.0f,// inner down
         0.5f, 0.0f, 0.0f  // inner right 
    };

    GLuint indices[] = {
        0, 3, 4, //lower left triangle
        3, 2, 5, //upper triangle
        4, 5, 1  //lower right triangle
    };

    // Create reference containers for the Vartex Array Object, the Vertex Buffer Object and the Element Buffer Object
    GLuint VAO, VBO, EBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    do {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.Active();
        glBindVertexArray(VAO);
        //glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window.GetGLFWwindow());
        glfwPollEvents();
    } while (window.IsOpened());
    
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    shaderProgram.Delete();

    glfwTerminate();
    
    return 0;
}