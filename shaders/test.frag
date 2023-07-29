#version 330 core

out vec4 FragColor;

in vec3 position;

uniform vec4 ourColor;

void main()
{
   //FragColor = vec4(position, 1.0f);
   //FragColor = vec4(position.x + ourColor.x, position.y + ourColor.x, position.z + ourColor.x, 1.0f);
   FragColor = vec4(position.x + ourColor.x + 0.1f, position.y + ourColor.y + 0.5f, position.z + ourColor.z  + 1.0f, 1.0f);
}