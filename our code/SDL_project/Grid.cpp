#include "stdafx.h"
#include "Grid.h"

Cell Grid::placeCell(int xPos, int yPos)
{
	Cell newCell;
	newCell.setX(xPos);
	newCell.setY(yPos);

	return newCell;
}

void Grid::makeGrid(int Window_Width, int Window_Height)
{
	int XAxis_Max = Window_Width / cellSize;
	int YAxis_Max = Window_Height / cellSize;

	for (int x = 0; x < XAxis_Max; x++)
	{
		for (int y = 0; y < YAxis_Max; y++)
		{
			grid.push_back(placeCell(x, y));
		}
	}
}

Grid::Grid()
{
}


Grid::~Grid()
{
}
