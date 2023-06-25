#pragma once
#include <SFML/Graphics.hpp>
#include "BackgroundField.h"

class UpperField : public::BackgroundField {

	//void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::RectangleShape Object;
	const int sizeX = 32;
	const int sizeY = 32;
	sf::Vector2f sizeVector{ sizeX,sizeY };

public:
	UpperField();
	//void setTexture(sf::Texture&);
	//void setPosition(int, int);
	//int getSizeX();
};

