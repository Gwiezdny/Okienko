#pragma once
#include "BackgroundField.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include <iostream>

class Root
{
	
public:
	
	std::tuple<std::vector<std::vector<int>>, int, int> downloadTextureMap(std::string fileName);
	void downloadTexture(std::string, std::vector<sf::Texture>&);

};

