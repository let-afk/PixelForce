#version 330 core

out vec4 FragColor;

//in vec3 color;
in vec3 position;

void main()
{
   //FragColor = vec4(color, 1.0f);
   FragColor = vec4(position.x + 0.1f, position.y + 0.5f, position.z + 1.0f, 1.0f);
}