#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include <iostream>

class Root
{
	sf::Keyboard key;
public:
	
	std::tuple<std::vector<std::vector<int>>, int, int> downloadTextureMap(std::string fileName);
	void downloadTexture(std::string, std::vector<sf::Texture>&);
	void checkPlayerMove(Player&);

};

