#include "Root.h"


//std::vector<std::vector<BackgroundField>>* backgroundPtr


std::tuple<std::vector<std::vector<int>>, int, int> Root::downloadTextureMap(std::string fileName) {
	std::fstream data;
	data.open(fileName, std::ios::in);
	std::vector<std::vector<int>> intTextureMap;

	if (data.good()) {
		std::string line;
		std::string tmp;
		int n, i{ 0 };
		while (data.good()) {
			std::vector<int> rowVector;
			int point{ 0 }, prePoint{ 0 };

			std::getline(data, line);
			n = std::count(line.begin(), line.end(), ',');

			for (int j = 0; j <= n; j++) {

				point = line.find(',', point + 1);
				tmp = line.substr(prePoint, point - prePoint);
				rowVector.push_back(stoi(tmp));
				prePoint = point + 1;
			}
			intTextureMap.push_back(rowVector);
			i++;
		}
		return { intTextureMap, n, i - 1 };;
	}
	throw;
}

void Root::downloadTexture(std::string fileName, std::vector<sf::Texture>& textureVector) {
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
	else {
		std::cout << "Texture link file opening failed...\n";
	}
}