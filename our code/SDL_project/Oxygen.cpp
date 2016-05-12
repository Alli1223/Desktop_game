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
}

//Decreases oxygen in a selected cell (only if the cell is a room)
void Oxygen::removeOxygen(int mouseX, int mouseY, int cellSize, Grid grid)
{

	int cellX = mouseX / cellSize;
	int cellY = mouseY / cellSize;

	int oxygenLevel = grid.grid[cellX][cellY]->getOxygenLevel();
	if (grid.grid[cellX][cellY]->isRoom && oxygenLevel == 100)
	{
		oxygenLevel = oxygenLevel - 2;
		grid.grid[cellX][cellY]->setOxygenLevel(oxygenLevel);

	}

}

std::vector<std::shared_ptr<Cell>> Oxygen::getNeighbouringCells(int cellSize)
{// Creates a vector of the possible directions that the character could move in
	std::vector<std::shared_ptr<Cell>> surroundingCells;
	if (cellX - cellSize)  //up
		surroundingCells.push_back(std::make_shared<Cell>(Cell(cellX, cellY - cellSize)));
	if (cellY + cellSize < 800) //down
		surroundingCells.push_back(std::make_shared<Cell>(Cell(cellX, cellY + cellSize)));
	if (cellX - cellSize > 0)
		surroundingCells.push_back(std::make_shared<Cell>(Cell(cellX - cellSize, cellY)));
	if (cellY + cellSize < 800)
		surroundingCells.push_back(std::make_shared<Cell>(Cell(cellX + cellSize, cellY)));
	return surroundingCells;
}


void Oxygen::update(int cellSize)
{
	std::vector<std::shared_ptr<Cell>> neighbourCells = getNeighbouringCells(cellSize);
	for (int i = 0; i > neighbourCells.size(); i++)
	{
		if (neighbourCells[i]->getOxygenLevel() > neighbourCells[i + 1]->getOxygenLevel())
		{
			neighbourCells[i + 1]->setOxygenLevel(neighbourCells[i + 1]->getOxygenLevel() + 100);
		}
	}

}