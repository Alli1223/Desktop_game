#pragma once
#include "grid.h"
class Map
{
public:
	Map();
	~Map();

	void LoadMap(std::string filename, Grid room);

	void generateMap(Grid room);
};


