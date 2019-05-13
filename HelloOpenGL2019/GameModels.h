#pragma once
#ifndef _GAME_MODELS_H_
#define _GAME_MODELS_H_

#include "C:\source\lib\GL\glew.h"
#include "C:\source\lib\GL\freeglut.h"
#include "VertexFormat.h" //added 3/21/2015
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
namespace Models
{
	//I explain this structure in Part III
	struct Model
	{
		unsigned int vao;
		std::vector<unsigned int> vbos;

		Model() {}
	};

	class GameModels
	{
	public:
		GameModels();
		~GameModels();
		void CreateTriangleModel(const std::string& gameModelName);
		void DeleteModel(const std::string& gameModelName);
		unsigned int GetModel(const std::string& gameModelName);
	private:
		std::map<std::string, Model> GameModelList;//keep our models
	};
}
#endif