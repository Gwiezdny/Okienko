#include "Crown.h"

void Crown::textureBackgroundMap() {
	const auto [intTextureMap, sizeX, sizeY] = Root.downloadTextureMap("assets/backgroundTextureMap.txt");
	mapSizeX = sizeX;
	mapSizeY = sizeY;

	for (int y = 0; y <= mapSizeY; y++) {
		std::vector<BackgroundField> rowVector;
		for (int x = 0; x <= mapSizeX; x++) {
			BackgroundField patternBackground;
			patternBackground.setTexture(backgroundTextureVector[intTextureMap[y][x]]);
			rowVector.push_back(patternBackground);

		}
		background.push_back(rowVector);
	}

	//for (int y = 0; y <= mapSizeY; y++) {
	//	for (int x = 0; x <= mapSizeX; x++) {
	//		std::cout << intTextureMap[y][x] << " ";
	//	}
	//	std::cout << std::endl;
	//}

}

void Crown::assignBackgroundTexturePosition() {
	int size = background[0][0].getSizeX();
	for (int y = 0; y <= mapSizeY; y++) {
		for (int x = 0; x <= mapSizeX; x++) {
			background[y][x].setPosition(x * size, y * size);
		}
	}
}

void Crown::drawBackground() {
	for (int y = 0; y <= mapSizeY; y++) {
		for (int x = 0; x <= mapSizeX; x++) {
			Window.draw(background[y][x]);
		}
	}
}

void Crown::gameloop() {
	Window.setFramerateLimit(60);

	Root.downloadTexture("assets/texturesPaths.txt", backgroundTextureVector);
	textureBackgroundMap();
	assignBackgroundTexturePosition();

	while (true) {
		Window.clear(sf::Color::White);

		drawBackground();

		Window.display();
	}
}
