//vertex shader
#version 450 core //lower this version if your card does not support GLSL 4.5
layout(location = 0) in vec3 in_position;
layout(location = 1) in vec4 in_color;
 
out vec4 color;
 
void main()
{
  color = in_color;
  gl_Position = vec4(in_position, 1);
}