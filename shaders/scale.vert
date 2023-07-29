#version 330 core
layout (location = 0) in vec3 aPos;
//layout (location = 1) in vec3 aColor;

//out vec3 color
out vec3 position;

uniform float scale;

void main()
{
   gl_Position = vec4(aPos.x * (scale - 1.1), aPos.y * 0.7, aPos.z, 1 + scale);
   //color = aColor;
   position = aPos;
}