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

	void makeGrid(int Window_Width, int Window_Height);


protected:

	int cellSize = 50;
	
	Cell placeCell(int xPos, int yPos);
};

