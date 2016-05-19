#include "stdafx.h"
#include "Oxygen.h"
#include "Cell.h"
#include "MainCharacter.h"
#include "Level.h"
#include "Map.h"


Oxygen::Oxygen()
{
}

Oxygen::~Oxygen()
{

}

//Increases oxygen in a selected cell (only if the cell is a room)
void Oxygen::addOxygen(int mouseX, int mouseY, int cellSize, Level grid)
{
	int cellX = mouseX / cellSize;
	int cellY = mouseY / cellSize;
	int oxygenLevel = grid.grid[cellX][cellY]->getOxygenLevel();
	if (cellY -1 >= 0)
	{
		if (grid.grid[cellX][cellY]->isRoom && oxygenLevel < 100)
		{
			oxygenLevel++;
			grid.grid[cellX][cellY]->setOxygenLevel(oxygenLevel);
		}
		else if (oxygenLevel >= 100)
		{
			oxygenLevel = 100;
		}
	}
}

//Decreases oxygen in a selected cell
void Oxygen::removeOxygen(int mouseX, int mouseY, int cellSize, Level grid)
{
	int cellX = mouseX / cellSize;

	int cellY = mouseY / cellSize;


	int oxygenLevel = grid.grid[cellX][cellY]->getOxygenLevel();

	if (oxygenLevel <= 100)
	{
		oxygenLevel--;

		grid.grid[cellX][cellY]->setOxygenLevel(oxygenLevel);

		// make sure the oxygen cant go below zero
		if (oxygenLevel <= 0)
		{
			grid.grid[cellX][cellY]->setOxygenLevel(0);
		}
		else if (oxygenLevel >= 100)
		{
			oxygenLevel = 100;
		}
	}

}

void Oxygen::update(int cellSize, Level grid)
{
	for (int x = 0; x < grid.grid.size() - 1; x++)
	{
		cellX = grid.grid[x][x]->getX();
		for (int y = 0; y < grid.grid.size() - 1; y++)
		{
			cellY = grid.grid[y][y]->getY();
			int oxygenLevel = grid.grid[cellX][cellY]->getOxygenLevel();
			int oxygenReserve = getOxygenReserves();

			//Loops through the rooms
			if (grid.grid[cellX][cellY]->isRoom && !grid.grid[cellX][cellY]->isDoor)
			{
				if (oxygenLevel <= 0)
					oxygenLevel = 0;
				else if (oxygenLevel >= 100)
					oxygenLevel = 100;

				else if (oxygenLevel >= 0 && oxygenLevel <= 100 && oxygenReserve >= 0)
				{
					
					//if oxygen level is less than the cell to the right
					if (cellX + 1 <= grid.grid.size() && grid.grid[cellX][cellY]->getOxygenLevel() < grid.grid[cellX + 1][cellY]->getOxygenLevel() && oxygenLevel >= 100 && oxygenLevel <= 0)
					{
						//increase the oxygen level
						grid.grid[cellX][cellY]->setOxygenLevel(oxygenLevel + 1);
						
						//decrease the lefts cell oxygen level
						grid.grid[cellX + 1][cellY]->setOxygenLevel(oxygenLevel - 1);
					}


					//if oxygen level is greater than the cell to the right
					else if (cellX + 1 <= grid.grid.size() && grid.grid[cellX][cellY]->getOxygenLevel() > grid.grid[cellX + 1][cellY]->getOxygenLevel())
					{
						//decrease the oxygen level
						grid.grid[cellX][cellY]->setOxygenLevel(oxygenLevel - 1);
						setOxygenReserves(oxygenReserve - 1);
						//icrease the rights cell oxygen level
						grid.grid[cellX + 1][cellY]->setOxygenLevel(oxygenLevel + 1);
					}



					//if oxygen level is less than the cell to the left
					if (cellX - 1 >= 0 && grid.grid[cellX + 1][cellY]->getOxygenLevel() < grid.grid[cellX - 1][cellY]->getOxygenLevel() && oxygenLevel >= 100 && oxygenLevel <= 0)
					{
						//increase the oxygen level
						grid.grid[cellX][cellY]->setOxygenLevel(oxygenLevel + 1);
						
						//decrease the lefts cell oxygen level
						grid.grid[cellX - 1][cellY]->setOxygenLevel(oxygenLevel - 1);

					}

					//if oxygen level is greater than the cell to the left
					else if (cellX - 1 >= 0 && grid.grid[cellX][cellY]->getOxygenLevel() > grid.grid[cellX - 1][cellY]->getOxygenLevel())
					{
						//decrease the oxygen level
						grid.grid[cellX][cellY]->setOxygenLevel(oxygenLevel - 1);
						setOxygenReserves(oxygenReserve - 1);
						//icrease the rights cell oxygen level
						grid.grid[cellX - 1][cellY]->setOxygenLevel(oxygenLevel + 1);
					}



					//if oxygen level is less than the cell below
					if (cellY + 1 <= grid.grid.size() && grid.grid[cellX][cellY]->getOxygenLevel() <= grid.grid[cellX][cellY + 1]->getOxygenLevel() && oxygenLevel >= 100 && oxygenLevel <= 0)
					{
						//increase the oxygen level
						grid.grid[cellX][cellY]->setOxygenLevel(oxygenLevel + 1);
						
						//decrease the cell belows oxygen level
						grid.grid[cellX][cellY + 1]->setOxygenLevel(oxygenLevel - 1);
					}

					//if oxygen level is greater than the cell below
					else if (cellY + 1 <= grid.grid.size() && grid.grid[cellX][cellY]->getOxygenLevel() > grid.grid[cellX][cellY + 1]->getOxygenLevel())
					{
						//decrease the oxygen level
						grid.grid[cellX][cellY]->setOxygenLevel(oxygenLevel - 1);
						setOxygenReserves(oxygenReserve - 1);
						//increase the ceell below oxygen level
						grid.grid[cellX][cellY + 1]->setOxygenLevel(oxygenLevel + 1);
					}


					//if oxygen level is less than the cell above
					if (cellY - 1 >= 0 && grid.grid[cellX][cellY]->getOxygenLevel() < grid.grid[cellX][cellY - 1]->getOxygenLevel() && oxygenLevel >= 100 && oxygenLevel <= 0)
					{
						//increase the oxygen level
						grid.grid[cellX][cellY]->setOxygenLevel(oxygenLevel + 1);
						
						//decrease the cell belows oxygen level
						grid.grid[cellX][cellY - 1]->setOxygenLevel(oxygenLevel - 1);
					}

					//if oxygen level is greater than the cell above
					else if (cellY - 1 >= 0 && grid.grid[cellX][cellY]->getOxygenLevel() > grid.grid[cellX][cellY - 1]->getOxygenLevel())
					{
						//decrease the oxygen level
						grid.grid[cellX][cellY]->setOxygenLevel(oxygenLevel - 1);
						setOxygenReserves(oxygenReserve - 1);
						//increase the ceel aboves oxygen level
						grid.grid[cellX][cellY - 1]->setOxygenLevel(oxygenLevel + 1);
					}
				}
			}
		}
	}
}
