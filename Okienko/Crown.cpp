#include "Crown.h"

void Crown::downloadTexture(std::string fileName) {
	std::fstream data;
	data.open(fileName, std::ios::in);

	if (data.good()) {
		std::string line;
		while (data.good())
		{
			sf::Texture tmpTexture;
			std::getline(data, line);
			if (!tmpTexture.loadFromFile(line)) { std::cout << "Texture loading failed...\n"; }
			textureVector.push_back(tmpTexture);
		}
	}
}

void Crown::textureBackgroundMap() {
	const auto [intTextureMap, sizeX, sizeY] = Root.downloadTextureMap("assets/backgroundTextureMap.txt");
	
	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
			background[y][x].setTexture(textureVector[intTextureMap[y][x]]);
		}
	}

}

void Crown::gameloop() {
	sf::RenderWindow Window{ sf::VideoMode(800,600), "Okienko <3" };
	Window.setFramerateLimit(60);


	downloadTexture("assets/texturesPaths");
	textureBackgroundMap();
	while (true) {
		Window.clear(sf::Color::Black);
		Window.draw(background[1][1]);

		Window.display();
	}
}
