#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../headers/camera.hpp"
#include "../headers/window.hpp"

void Camera::move(GLfloat speed)
{
    if (Window::keys[GLFW_KEY_W])
        this->camera_pos += speed * this->camera_front;
    if (Window::keys[GLFW_KEY_S])
        this->camera_pos -= speed * this->camera_front;
    if (Window::keys[GLFW_KEY_A])
        this->camera_pos -= glm::normalize(glm::cross(this->camera_front, this->camera_up)) * speed;
    if (Window::keys[GLFW_KEY_D])
        this->camera_pos += glm::normalize(glm::cross(this->camera_front, this->camera_up)) * speed;
}

Camera::Camera(glm::vec3 camera_pos, glm::vec3 camera_front, glm::vec3 camera_up, std::string shader_path)
{
    this->camera_pos = camera_pos;
    this->camera_front = camera_front;
    this->camera_up = camera_up;
    this->shader_path = shader_path;
    this->ourShader = Shader(("shaders/" + this->shader_path + ".vert").c_str(), ("shaders/" + this->shader_path + ".frag").c_str());
}

void Camera::activate(float width, float height)
{
    GLint view_loc = glGetUniformLocation(this->ourShader.ID, "view");
    GLint projection_loc = glGetUniformLocation(this->ourShader.ID, "projection");
    this->view = glm::lookAt(this->camera_pos, this->camera_pos + this->camera_front, this->camera_up);
    this->projection = glm::perspective(glm::radians(this->fov), height / width, 0.1f, 100.0f);
    glUniformMatrix4fv(view_loc, 1, GL_FALSE, &(this->view[0][0]));
    glUniformMatrix4fv(projection_loc, 1, GL_FALSE, &(this->projection[0][0]));
}

void Camera::camera_rotate(GLfloat x_offset, GLfloat y_offset)
{
    this->yaw += x_offset * this->mouse_sensitivity;
    this->pitch += y_offset * this->mouse_sensitivity;
    if (this->pitch > 89.0f)
        this->pitch = 89.0f;
    if (this->pitch < -89.0f)
        this->pitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(this->pitch)) * cos(glm::radians(this->yaw));
    front.y = sin(glm::radians(this->pitch));
    front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
    this->camera_front = glm::normalize(front);
    glm::vec3 right;
    right = glm::normalize(glm::cross(this->camera_front, glm::vec3(0.0f, 1.0f, 0.0f)));
    this->camera_up = glm::normalize(glm::cross(right, this->camera_front));
}