#//Init_GLEW.h
#pragma once
#include <iostream>
#include "C:\source\lib\GL\glew.h"
#include "C:\source\lib\GL\freeglut.h"
namespace Core {
	//notice that I added another namespace here(optional)
	namespace Init {

		class Init_GLEW
		{
		public:
			static void Init();
		};
	}
}