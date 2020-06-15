#version 460

layout(location = 0) in vec3 a_position;
layout(location = 1) in vec4 a_color;


layout(location = 0) out vec4 o_color;

void main(){
    gl_Position = vec4(a_position, 1.0);
    o_color = a_color;

}
