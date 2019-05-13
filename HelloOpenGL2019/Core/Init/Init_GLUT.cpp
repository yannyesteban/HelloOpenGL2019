//GlutInit.cpp
#include "Init_GLUT.h"

using namespace Core::Init;

void Init_GLUT::init(const Core::WindowInfo& windowInfo,
	const Core::ContextInfo& contextInfo,
	const Core::FramebufferInfo& framebufferInfo)
{
	//we need to create these fake arguments
	int fakeargc = 1;
	const char* fakeargv = { "Fake", NULL };
	glutInit(&fakeargc, fakeargv);

	if (contextInfo.core)
	{
		glutInitContextVersion(contextInfo.major_version,
			contextInfo.minor_version);
		glutInitContextProfile(GLUT_CORE_PROFILE);
	}
	else
	{
		//As I said in part II, version doesn't matter
		// in Compatibility mode
		glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	}

	//these functions were called in the old main.cpp
	//Now we use info from the structures
	glutInitDisplayMode(framebufferInfo.flags);
	glutInitWindowPosition(windowInfo.position_x,
		windowInfo.position_y);
	glutInitWindowSize(windowInfo.width, windowInfo.height);

	glutCreateWindow(windowInfo.name.c_str());

	std::cout << "GLUT:initialized" << std::endl;
	//these callbacks are used for rendering
	glutIdleFunc(idleCallback);
	glutCloseFunc(closeCallback);
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);

	//init GLEW, this can be called in main.cpp
	Init::Init_GLEW::Init();

	//cleanup
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,
		GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	//our method to display some info. Needs contextInfo and windowinfo
	printOpenGLInfo(windowInfo, contextInfo);

}

//starts the rendering Loop
void Init_GLUT::run()
{
	std::cout << "GLUT:\t Start Running " << std::endl;
	glutMainLoop();
}