#version 330 core

out vec4 FragColor;

in vec3 position;

uniform float time;

void main()
{
    //FragColor = vec4(position, 1.0f);
    //FragColor = vec4(position.x + ourColor.x, position.y + ourColor.x, position.z + ourColor.x, 1.0f);
    //FragColor = vec4(position.x + ourColor.x + 0.1f, position.y + ourColor.y + 0.5f, position.z + ourColor.z  + 1.0f, 1.0f);
    float x= position.x - 0.05, y= position.y + 1.1;
    x+=sin(fract(y*1.5+time*0.55)*6.28)*0.05;
    y+=cos(fract(x*0.9+time*0.55)*6.28)*0.075;
    bool w = true;
    if(x>.2&&x<.7&&y<.8&&y>.2) w =! w;
    if(x>.24&&x<.66&&y<.8&&y>.2) w =! w;
    if(x>.4&&x<.6&&y<.8&&y>.2) w =! w;
    if(x>.45&&x<.55&&y<.7&&y>.3) w =! w;
    if(x>.24&&x<.85&&y<.3&&y>.2) w =! w;
    if(x>.35&&x<.7&&y<.3&&y>.2) w =! w;
    FragColor=vec4(w);
}