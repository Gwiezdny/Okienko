#pragma once
#include <SFML/Graphics.hpp>>
#include <iostream>

class Player : public::sf::Drawable	{
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::RectangleShape Object;
	const int sizeX = 32;
	const int sizeY = 32;
	sf::Vector2f sizeVector{ sizeX,sizeY };
	sf::Texture playerTexture;
	sf::Vector2f velocityVector;

public:
	Player();
	void setTexture(sf::Texture&);
	void setPosition(int, int);
	int getSizeX();
	void move(float, float);
	sf::Vector2f getPosition();
};

