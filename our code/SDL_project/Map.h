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
	
	int getWidth() const { return width; }
	int getHeight() const { return height; }

	void generateMap(Grid level);

private:

	std::vector<std::vector<std::vector<std::shared_ptr<Cell>>>> roomVector;

	bool generateRoom(Grid level, int size, int entranceX, int entranceY, char direction); //Direction n = north, e = east, s = south, w = west.
	
	//For a 800px X 800px window size there are 16 cols X 16 rows
	Map* map;
	int width;
	int height;

	//determines what type of cell it is from the file.
	//int Cell_Value;

};


