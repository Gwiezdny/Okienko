#pragma once
#include "Root.h"
#include "BackgroundField.h"
#include "UpperField.h"
#include "Player.h"
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
	std::vector < std::vector < BackgroundField > > backgroundMap;
	std::vector < std::vector < UpperField > > upperMap;
	std::vector<sf::Texture> backgroundTextureVector;
	Player Player;
	sf::View View;

	//int backgroundMapSizeX, backgroundMapSizeY, upperMapSizeX, upperMapSizeY;
	
	template<typename Type>
	void textureMap(std::vector < std::vector < Type > >&, std::string);
	template<typename Type>
	void assignMapTexturesPosition(std::vector < std::vector < Type > >&);
	template<typename Type>
	void drawMap(std::vector < std::vector < Type > >&);

public:
	Crown();
	void gameloop();
};