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

void Camera::activate(const Window &window_obj)
{
    GLint view_loc = glGetUniformLocation(this->ourShader.ID, "view");
    GLint projection_loc = glGetUniformLocation(this->ourShader.ID, "projection");
    this->view = glm::lookAt(this->camera_pos, this->camera_pos + this->camera_front, this->camera_up);
    this->projection = glm::perspective(glm::radians(this->fov), static_cast<float>(window_obj.height) / window_obj.width, 0.1f, 1000.0f);
    glUniformMatrix4fv(view_loc, 1, GL_FALSE, &(this->view[0][0]));
    glUniformMatrix4fv(projection_loc, 1, GL_FALSE, &(this->projection[0][0]));
}