#include "BackgroundField.h"

void BackgroundField::draw(sf::RenderTarget& target, sf::RenderStates state) const {
	target.draw(this->Object, state);
}

void BackgroundField::setTexture(sf::Texture& tmp) {
	Object.setTexture(&tmp);
}
