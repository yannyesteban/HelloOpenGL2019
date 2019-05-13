//Init_GLUT.h
#pragma once
#include "ContextInfo.h"
#include "FrameBufferInfo.h"
#include "WindowInfo.h"
#include <iostream>
#include "Init_GLEW.h"
#include "IListener.h"
namespace Core {
	namespace Init {//two namespaces

		class Init_GLUT {

		public:             //use the structures from Part II
			static void init(const Core::WindowInfo& window,
				const Core::ContextInfo& context,
				const Core::FramebufferInfo& framebufferInfo);

		public:
			
			static Core::IListener* listener;
			
			static void run();//called from outside
			static void close();

			void enterFullscreen();
			void exitFullscreen();

			//used to print info about GL
			static void printOpenGLInfo(const Core::WindowInfo& windowInfo,
				const Core::ContextInfo& context);
			static void setListener(Core::IListener*& iListener);
		private:
			
			static Core::WindowInfo windowInformation;

			static void idleCallback(void);
			static void displayCallback(void);
			static void reshapeCallback(int width, int height);
			static void closeCallback();

			
		};
	}
}