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

//Increases oxygen in a selected cell (only if the cell is a room)
void Oxygen::addOxygen(int mouseX, int mouseY, int cellSize, Grid grid)
{
	int cellX = mouseX / cellSize;
	int cellY = mouseY / cellSize;

	int oxygenLevel = grid.grid[cellX][cellY]->getOxygenLevel();
	if (grid.grid[cellX][cellY]->isRoom && oxygenLevel < 100)
	{
		oxygenLevel = oxygenLevel + 4;
		grid.grid[cellX][cellY]->setOxygenLevel(oxygenLevel);
	}
	else if (grid.grid[cellX][cellY]->getOxygenLevel() >= 100)
	{
		grid.grid[cellX][cellY]->isOxygenated = true;
	}
}

//Decreases oxygen in a selected cell
void Oxygen::removeOxygen(int mouseX, int mouseY, int cellSize, Grid grid)
{
	int cellX = mouseX / cellSize;
	int cellY = mouseY / cellSize;

	int oxygenLevel = grid.grid[cellX][cellY]->getOxygenLevel();
	if (oxygenLevel <= 100)
	{
		oxygenLevel = oxygenLevel - 4;
		grid.grid[cellX][cellY]->isOxygenated = false;
		grid.grid[cellX][cellY]->setOxygenLevel(oxygenLevel);

		//spread to neighbouring cells
		//disperseOxygen(cellSize, oxygenLevel);
		//update(cellSize, grid);

		//make sure the oxygen cant go below zero
		if (oxygenLevel <= 0)
		{
			grid.grid[cellX][cellY]->setOxygenLevel(0);
		}
	}
}

void Oxygen::update(int cellSize, Grid grid)
{

	for (int i = 0; i < 16; i++)
	{
		cellX = grid.grid[i][i]->getX();
		for (int i = 0; i < 16; i++)
		{
			cellY = grid.grid[i][i]->getY();
			int oxygenLevel = grid.grid[cellX][cellY]->getOxygenLevel();


			//Loops through the rooms
			if (grid.grid[cellX][cellY]->isRoom)
			{
				//right
				if (oxygenLevel <= grid.grid[cellX + 1][cellY]->getOxygenLevel() && oxygenLevel >= 0 && oxygenLevel <= 100)
				{
					grid.grid[cellX + 1][cellY]->setOxygenLevel(grid.grid[cellX + 1][cellY]->getOxygenLevel() - 1);
				}
				//down
				else if (oxygenLevel >= grid.grid[cellX][cellY + 1]->getOxygenLevel() && oxygenLevel >= 0 && oxygenLevel <= 100)
				{
					grid.grid[cellX][cellY + 1]->setOxygenLevel(grid.grid[cellX][cellY + 1]->getOxygenLevel() - 1);
				}
				//center
				else if (grid.grid[cellX][cellY]->getOxygenLevel() >= oxygenLevel && oxygenLevel <= 100 && oxygenLevel <= 100)
				{
					grid.grid[cellX][cellY]->setOxygenLevel(oxygenLevel + 1);
				}
				//left
				else if (grid.grid[cellX - 1][cellY]->getOxygenLevel() <= oxygenLevel && oxygenLevel <= 100 && oxygenLevel <= 100)
				{
					grid.grid[cellX - 1][cellY]->setOxygenLevel(oxygenLevel + 1);
				}
				
			}
		}
	}
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

void Oxygen::disperseOxygen(int cellSize, int oxygenLevel)
{
	std::vector<std::shared_ptr<Cell>> neighbourCells = getNeighbouringCells(cellSize);
	for (int i = 0; i < neighbourCells.size(); i++)
	{
		if (neighbourCells[i]->getOxygenLevel() >= neighbourCells[i + 1]->getOxygenLevel())
		{
			neighbourCells[i]->setOxygenLevel(oxygenLevel - 1);
		}
		else if (neighbourCells[i]->getOxygenLevel() < oxygenLevel)
		{
			neighbourCells[i]->setOxygenLevel(oxygenLevel + 1);
		}
	}
}