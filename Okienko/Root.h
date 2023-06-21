#pragma once
#include "BackgroundField.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>

class Root
{
	
public:
	//static const int sizeX{ 16 };
	//static const int sizeY{ 16 };

	//int GetSizeX() { return sizeX; }
	//int GetSizeY() { return sizeY; }

	std::tuple<std::vector<std::vector<int>>, int, int> downloadTextureMap(std::string fileName);

};

