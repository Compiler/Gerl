#version 460


layout(location = 0) in vec4 o_color;

layout(location = 0) out vec4 outColor;

void main(){
    outColor = o_color;
}
