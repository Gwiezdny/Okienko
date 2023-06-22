#pragma once
#include <SFML/Graphics.hpp>

class BackgroundField : public::sf::Drawable {
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::RectangleShape Object;
	const int sizeX = 64;
	const int sizeY = 64;
	sf::Vector2f sizeVector{ sizeX,sizeY };
public:
	BackgroundField();
	void setTexture(sf::Texture&);
	void setPosition(int, int);
	//void setColor(sf::Color);
	int getSizeX();
};

