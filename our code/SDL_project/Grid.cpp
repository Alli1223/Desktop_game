#include "stdafx.h"
#include "Grid.h"



void Grid::makeGrid(int Window_Width, int Window_Height)
{
	int XAxis_Max = Window_Width / cellSize;
	int YAxis_Max = Window_Height / cellSize;

	for (int x = 0; x < XAxis_Max; x++)
	{
		std::vector<std::shared_ptr<Cell>> column;
		grid.push_back(column);
		for (int y = 0; y < YAxis_Max; y++)
		{
			std::shared_ptr<Cell> cell;
			grid[x].push_back(cell);
		}
	}
}

Grid::Grid()
{
}


Grid::~Grid()
{
}
