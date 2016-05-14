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
		update(cellSize, oxygenLevel, grid);
		if (oxygenLevel <= 0)
		{
			oxygenLevel = 0;
			grid.grid[cellX][cellY]->setOxygenLevel(oxygenLevel);
		}
	}
}


//void 

void Oxygen::update(int cellSize, int oxygenLevel, Grid grid)
{
	disperseOxygen(cellSize);
	grid.grid[cellX][cellY]->getOxygenLevel();
}

std::vector<std::shared_ptr<Cell>> Oxygen::getNeighbouringCells(int cellSize)
{// Creates a vector of the possible directions that the character could move in

	std::vector<std::shared_ptr<Cell>> surroundingCells;
	if (cellY - cellSize < 0)  //up
		surroundingCells.push_back(std::make_shared<Cell>(Cell(cellX, cellY - cellSize)));
	if (cellY + cellSize < 800) //down
		surroundingCells.push_back(std::make_shared<Cell>(Cell(cellX, cellY + cellSize)));
	if (cellX - cellSize < 0) //left
		surroundingCells.push_back(std::make_shared<Cell>(Cell(cellX - cellSize, cellY)));
	if (cellX + cellSize < 800) //left
		surroundingCells.push_back(std::make_shared<Cell>(Cell(cellX + cellSize, cellY)));
	return surroundingCells;
}

void Oxygen::disperseOxygen(int cellSize)
{
	std::vector<std::shared_ptr<Cell>> neighbourCells = getNeighbouringCells(cellSize);
	for (int i = 0; i < neighbourCells.size(); i++)
	{
		//int neighbourcell = neighbourCells[i + 1]->getOxygenLevel();
		if (neighbourCells[i]->getOxygenLevel() <= 0)
		{
			neighbourCells[i + 1]->setOxygenLevel(0); //neighbourCells[i + 1]->getOxygenLevel() - 10
		}
		else if (neighbourCells[i]->getOxygenLevel() >= 1)
		{
			neighbourCells[i]->setOxygenLevel(0);
		}
	}
}