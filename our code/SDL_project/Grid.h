#pragma once
#include "Cell.h"
#include<vector>

class Grid
{
public:
	Grid();
	~Grid();

	int getCellSize() { return cellSize; }

	std::vector<Cell> grid;


protected:

	int cellSize = 50;
	
	Cell placeCell(int xPos, int yPos);
};

