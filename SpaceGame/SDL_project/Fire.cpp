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
	{
		
		if (grid.grid[cellX][cellY]->isOnFire == true)
		{
			for (int i = 3; i >= 0; i--)
			{
				int randomDirection = rand() % (0 - 2) - 1;
				if (grid.grid[cellX + (randomDirection)][cellY + (randomDirection)]->isRoom && grid.grid[cellX + (randomDirection)][cellY + (randomDirection)]->isDoor == false)
				{
					grid.grid[cellX + (randomDirection)][cellY + (randomDirection)]->isOnFire = true;
				}

			}
		}
	}
}
	


