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

				point = line.find(',', point + j);
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