//fragment shader
#version 450 core
 
layout(location = 0) out vec4 out_color;
 
in vec4 color;
 
void main()
{
  out_color = color;
  //color = vec4(0.456, 0.23, 0.02, 1.0);
}