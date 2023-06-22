#include "BackgroundField.h"

BackgroundField::BackgroundField() {
	Object.setSize(sizeVector);
}

void BackgroundField::draw(sf::RenderTarget& target, sf::RenderStates state) const {
	target.draw(this->Object, state);
}

void BackgroundField::setTexture(sf::Texture& tmp) {
	Object.setTexture(&tmp);
}

void BackgroundField::setPosition(int x, int y) {
	Object.setPosition(x, y);
}

int BackgroundField::getSizeX() {
	return sizeX;
}

//void BackgroundField::setColor(sf::Color tmp) {
//	Object.setFillColor(tmp);
//}

