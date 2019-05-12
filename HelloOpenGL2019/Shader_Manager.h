#pragma once

#include "C:\source\lib\GL\glew.h"
#include "C:\source\lib\GL\freeglut.h"
#include <iostream>
namespace Core
{

	class Shader_Manager
	{
		private:

			std::string ReadShader(const char* filename);
			GLuint CreateShader(GLenum shaderType, std::string source, const char* shaderName);

		public:

			Shader_Manager(void);
			~Shader_Manager(void);
			GLuint CreateProgram(const char* VertexShaderFilename, const char* FragmentShaderFilename);

	};
}

