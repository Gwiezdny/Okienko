#include "Player.h"

Player::Player() {
	Object.setSize(sizeVector);
	if (!playerTexture.loadFromFile("assets/textures/player.png")) { std::cout << "Texture loading failed...\n"; }
	Object.setTexture(&playerTexture);
}

void Player::move(float x, float y) {
	//velocityVector = { x, y };
	Object.move(y, x);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates state) const {
	target.draw(this->Object, state);
}

void Player::setTexture(sf::Texture& tmp) {
	Object.setTexture(&tmp);
}

void Player::setPosition(int x, int y) {
	Object.setPosition(x, y);
}

int Player::getSizeX() {
	return sizeX;
}

sf::Vector2f Player::getPosition() {
	return Object.getPosition();
}