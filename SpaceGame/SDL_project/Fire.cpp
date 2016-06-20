#include "stdafx.h"
#include "Fire.h"
#include "Cell.h"
#include "Level.h"


Fire::Fire()
{
}


Fire::~Fire()
{
}

void Fire::spawn(Level grid, int cellX, int cellY)
{
	if (fireSpawnChance <= 0)
	{
		fireSpawnChance = 20;
		grid.grid[cellX][cellY]->isOnFire = true;
		grid.grid[cellX][cellY]->oxygenLevel = 0;
	}
	else
		fireSpawnChance--;

}

void Fire::fireSpread(Level grid, int cellX, int cellY)
{

	if (grid.grid[cellX][cellY]->isOnFire == true)
	{

		int randomDirectionX = rand() % (0 - 2) - 1;
		int randomDirectionY = rand() % (0 - 2) - 1;
		if (grid.grid[cellX + (randomDirectionX)][cellY + (randomDirectionY)]->isRoom && grid.grid[cellX + (randomDirectionX)][cellY + (randomDirectionY)]->isDoor == false)
		{
			if (cellX + (randomDirectionX) +1 <= grid.grid.size() && cellX + (randomDirectionX) -1 >= 0 && cellY + (randomDirectionY)+1 <= grid.grid.size() && cellY + (randomDirectionY)-1 >= 0)
			{
				grid.grid[cellX + (randomDirectionX)][cellY + (randomDirectionY)]->isOnFire = true;
				grid.grid[cellX + (randomDirectionX)][cellY + (randomDirectionY)]->oxygenLevel = 0;
			}
		}
	}
}


	


