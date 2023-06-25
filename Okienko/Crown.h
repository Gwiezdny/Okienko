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
	sf::RenderWindow Window{ sf::VideoMode(800,600), "Okienko <3" };
	std::vector < std::vector < BackgroundField > > background;
	std::vector<sf::Texture> backgroundTextureVector;

	int mapSizeX, mapSizeY;

	void textureBackgroundMap();
	void assignBackgroundTexturePosition();
	void drawBackground();

public:
	void gameloop();
};

