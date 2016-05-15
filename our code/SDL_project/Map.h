#pragma once
#include "grid.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>

class Map
{
public:
	Map();
	~Map();

	int random(int smallestValue, int largestValue);

	void LoadMap(std::string filename, Grid room);

	void generateMap(Grid level);

private:

	std::vector<std::vector<std::vector<std::shared_ptr<Cell>>>> roomVector;

	bool generateRoom(Grid level, int size, int entranceX, int entranceY, char direction); //Direction n = north, e = east, s = south, w = west.
};


