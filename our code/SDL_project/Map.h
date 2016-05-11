#pragma once
#include "grid.h"

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
};


