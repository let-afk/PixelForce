#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<iostream>
#include"window.h"

/**
 * @brief 
 * compile with command: g++ main.cpp window.cpp -lglew32 -lglu32 -lopengl32 -lglfw3
 * 
 * @warning  возможны баги
 */

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

    //glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    do {
        glClear(GL_COLOR_BUFFER_BIT);



        glfwSwapBuffers(window.GetGLFWwindow());
        glfwPollEvents();
    } while (window.IsOpened());
    
    glfwTerminate();
    
    return 0;
}