#include "stdafx.h"
#include "Oxygen.h"
#include "Cell.h"
#include "MainCharacter.h"
#include "Grid.h"

Oxygen::Oxygen()
{
}

Oxygen::~Oxygen()
{

}

// Increases oxygen in a selected cell (only if the cell is a room)
void Oxygen::addOxygen(int mouseX, int mouseY, int cellSize, Grid grid)
{
	int cellX = mouseX / cellSize;
	int cellY = mouseY / cellSize;

	int oxygenLevel = grid.grid[cellX][cellY]->getOxygenLevel();
	if (grid.grid[cellX][cellY]->isRoom && oxygenLevel < 100)
	{
		oxygenLevel = oxygenLevel + 2;
		grid.grid[cellX][cellY]->setOxygenLevel(oxygenLevel);
	}
	else if (grid.grid[cellX][cellY]->getOxygenLevel() >= 100)
	{
		grid.grid[cellX][cellY]->isOxygenated = true;
	}
}

//Decreases oxygen in a selected cell (only if the cell is a room)
void Oxygen::removeOxygen(int mouseX, int mouseY, int cellSize, Grid grid)
{
	int cellX = mouseX / cellSize;
	int cellY = mouseY / cellSize;

	int oxygenLevel = grid.grid[cellX][cellY]->getOxygenLevel();
	if (oxygenLevel <= 100)
	{
		oxygenLevel = oxygenLevel - 2;
		grid.grid[cellX][cellY]->isOxygenated = false;
		grid.grid[cellX][cellY]->setOxygenLevel(oxygenLevel);

		//spread to neighbouring cells
		update(cellSize, cellX, cellY, grid);
		if (oxygenLevel <= 0)
		{
			oxygenLevel = 0;
			grid.grid[cellX][cellY]->setOxygenLevel(oxygenLevel);
		}
		
	}
}




void Oxygen::update(int cellSize, int cellX, int cellY, Grid grid)
{
	std::vector<std::shared_ptr<Cell>> neighbourCells = getNeighbouringCells(cellX, cellY, cellSize);
	for (int i = 0; i < neighbourCells.size(); i++)
	{
		//int neighbourcell = neighbourCells[i + 1]->getOxygenLevel();
		if (neighbourCells[i]->getX() > cellX)
		{
			neighbourCells[i]->setOxygenLevel(0);
		}
		else if (neighbourCells[i]->getY() > cellY)
		{
			neighbourCells[i]->setOxygenLevel(0);
		}
	}
}

std::vector<std::shared_ptr<Cell>> Oxygen::getNeighbouringCells(int cellX, int cellY, int cellSize)
{// Creates a vector of the possible directions that the character could move in

	std::vector<std::shared_ptr<Cell>> surroundingCells;
	if (cellY - cellSize)  //up
		surroundingCells.push_back(std::make_shared<Cell>(Cell(cellX, cellY - cellSize)));
	if (cellY + cellSize) //down
		surroundingCells.push_back(std::make_shared<Cell>(Cell(cellX, cellY + cellSize)));
	if (cellX - cellSize) //right
		surroundingCells.push_back(std::make_shared<Cell>(Cell(cellX - cellSize, cellY)));
	if (cellX + cellSize) //left
		surroundingCells.push_back(std::make_shared<Cell>(Cell(cellX + cellSize, cellY)));
	return surroundingCells;
}