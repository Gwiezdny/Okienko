#include "Crown.h"

Crown::Crown() {
	View.setSize(sf::Vector2f(400.f, 300.f));
}

template<typename Type>
void Crown::textureMap(std::vector < std::vector < Type > >& Map, std::string fileName) {
	const auto [intTextureMap, sizeX, sizeY] = Root.downloadTextureMap(fileName);

	for (int y = 0; y <= sizeY; y++) {
		std::vector<Type> rowVector;
		for (int x = 0; x <= sizeX; x++) {
			Type patternBackground;
			patternBackground.setTexture(backgroundTextureVector[intTextureMap[y][x]]);
			rowVector.push_back(patternBackground);
		}
		Map.push_back(rowVector);

	//for (int y = 0; y <= mapSizeY; y++) {
	//	for (int x = 0; x <= mapSizeX; x++) {
	//		std::cout << intTextureMap[y][x] << " ";
	//	}
	//	std::cout << std::endl;
	//}
	}
}

template<typename Type>
void Crown::assignMapTexturesPosition(std::vector < std::vector < Type > >& Map) {
	int size = Map[0][0].getSizeX();
	for (int y = 0; y < Map.size(); y++) {
		for (int x = 0; x < Map[0].size(); x++) {
			Map[y][x].setPosition(x * size, y * size);
		}
	}
}

template<typename Type>
void Crown::drawMap(std::vector < std::vector < Type > >& Map) {
	for (int y = 0; y < Map.size(); y++) {
		for (int x = 0; x < Map[0].size(); x++) {
			Window.draw(Map[y][x]);
		}
	}
}

void Crown::gameloop() {
	Window.setFramerateLimit(60);
	sf::Event Event;

	Root.downloadTexture("assets/texturesPaths.txt", backgroundTextureVector);
	textureMap(backgroundMap, "assets/BackgroundTextureMap.txt");
	assignMapTexturesPosition(backgroundMap);

	while (true) {
		Window.clear(sf::Color::Black);
		Window.pollEvent(Event);

		if (Event.type == sf::Event::Closed) {
			Window.close();
			break;
		}

		Root.checkPlayerMove(Player);
		View.setCenter(Player.getPosition());
		Window.setView(View);
		drawMap(backgroundMap);
		Window.draw(Player);


		Window.display();
	}
}
