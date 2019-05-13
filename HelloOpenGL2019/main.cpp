#pragma once
#include "Core\Init\Init_GLUT.h"
#include "Scene_Manager.h"
//http://realtech-vr.com/admin/glview
using namespace Core;
using namespace Init;
int main(int argc, char** argv)
{
	WindowInfo window(std::string("in2gpu OpenGL Beginner Tutorial "),
		400, 200,//position
		800, 600, //size
		true);//reshape

	ContextInfo context(4, 5, true);
	FramebufferInfo frameBufferInfo(true, true, true, true);
	Init_GLUT::init(window, context, frameBufferInfo);

	IListener* scene = new Managers::Scene_Manager();
	Init::Init_GLUT::setListener(scene);

	Init_GLUT::run();

	return 0;
}