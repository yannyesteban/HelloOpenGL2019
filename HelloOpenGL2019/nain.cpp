#include "C:\source\lib\GL\glew.h"
#include "C:\source\lib\GL\freeglut.h"
#include <iostream>
#include <stdio.h>

#include "Shader_Loader.h";
using namespace Core;

GLuint program;
void Redisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 0.0, 0.0, 0.200);//clear red
	//use the created program
	glUseProgram(program);

	//draw 3 vertices as triangles
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glutSwapBuffers();
}
void Init()
{

	glEnable(GL_DEPTH_TEST);

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

	glutMainLoop();
	glDeleteProgram(program);
	return 0;
}