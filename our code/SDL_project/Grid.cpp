#include "stdafx.h"
#include "Grid.h"

Cell Grid::placeCell(int xPos, int yPos)
{
	Cell newCell;
	newCell.setX(xPos);
	newCell.setY(yPos);

	return newCell;
}



Grid::Grid()
{
}


Grid::~Grid()
{
}
