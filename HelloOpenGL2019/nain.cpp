#include "C:\source\lib\GL\glew.h"
#include "C:\source\lib\GL\freeglut.h"
#include <iostream>
#include <stdio.h>
#include<stdlib.h>;
#include<fstream>;
#include<vector>;
#include "Shader_Loader.h";
#include "GameModels.h";
using namespace Core;
//http://s08.idav.ucdavis.edu/fatahalian-gpu-architecture.pdf
//http://in2gpu.com/2014/12/02/create-triangle-opengl-part/
Models::GameModels* gameModels;
GLuint program;
void Redisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.3, 0.3, 1.0);

	glBindVertexArray(gameModels->GetModel("triangle1"));
	glUseProgram(program);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glutSwapBuffers();
}
void closeCallback()
{

	std::cout << "GLUT:\t Finished" << std::endl;
	glutLeaveMainLoop();
}

void Init()
{

	glEnable(GL_DEPTH_TEST);

	gameModels = new Models::GameModels();
	gameModels->CreateTriangleModel("triangle1");

	//load and compile shaders
	Core::Shader_Loader shaderLoader;
	program = shaderLoader.CreateProgram("Vertex_Shader.glsl", "Fragment_Shader.glsl");
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500, 500);//optional
	glutInitWindowSize(800, 600); //optional
	glutCreateWindow("OpenGL First Window");


	

	glewInit();
	if (glewIsSupported("GL_VERSION_4_5"))
	{
		std::cout << " GLEW Version is 4.5\n ";
	}
	else
	{
		std::cout << "GLEW 4.5 not supported\n ";
	}
	//glEnable(GL_DEPTH_TEST);

	Init();

	glutDisplayFunc(Redisplay);
	glutCloseFunc(closeCallback);
	glutMainLoop();
	delete gameModels;
	glDeleteProgram(program);
	return 0;
}