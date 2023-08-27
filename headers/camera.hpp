#include <iostream>
#include <math.h>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"

#ifndef PF_CAMERA_H
#define PF_CAMERA_H

struct Camera
{
    glm::vec3 camera_pos, camera_front, camera_up;
    glm::mat4 view, projection;
    GLfloat fov = 45.0f, mouse_sensitivity = 0.25f, yaw = -90.0f, pitch = 0.0f;
    Shader ourShader;
    std::string shader_path;
    Camera(glm::vec3 camera_pos = glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3 camera_front = glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3 camera_up = glm::vec3(0.0f, 1.0f, 0.0f), std::string shader_path = "trans_tex");
    ~Camera() = default;
    void move(GLfloat speed = 0.05f);
    void activate(float width, float height);
    void camera_rotate(GLfloat x_offset, GLfloat y_offset);
};

#endif
