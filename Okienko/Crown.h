#pragma once
#include "Root.h"
#include "BackgroundField.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <tuple>
#include <iostream>
#include <fstream>

class Crown
{
	Root Root;
	std::vector < std::vector < BackgroundField > > background;
	std::vector<sf::Texture> textureVector;

	void downloadTexture(std::string);
	void textureBackgroundMap();


public:
	void gameloop();
};

