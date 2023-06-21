#include "Root.h"


//std::vector<std::vector<BackgroundField>>* backgroundPtr


std::tuple<std::vector<std::vector<int>>, int, int> Root::downloadTextureMap(std::string fileName) {
	std::fstream data;
	data.open(fileName, std::ios::in);
	std::vector<std::vector<int>> intTextureMap;

	if (data.good()) {
		std::string line;
		std::string tmp;
		int i{ 0 };
		int point, prePoint;

		std::getline(data, line);
		int n = std::count(line.begin(), line.end(), ',');
		while (data.good()) {

			for (int j = 0; j <= n; j++) {

				point = line.find(',');
				tmp = line.substr(0, point);
				intTextureMap[i][j] = stoi(tmp);
				prePoint = point + 1;
			}

			std::getline(data, line);
			i++;
		}
		return { intTextureMap, n, i - 1 };;
	}
	throw;
}