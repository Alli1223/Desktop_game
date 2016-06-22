
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

// Function that spawns oxygen in the map
void Fire::spawn(Level& grid, int cellX, int cellY)
{
	
	//Fire will spawn in a room that is not the spawn room
	if (fireSpawnChance == 0 && grid.grid[cellX][cellY]->isRoom && cellX >= 5 && cellY >= 5)
	{
		// It will not spawn on doors or oxygen tanks or hull breaches
			if (grid.grid[cellX][cellY]->isOpenDoor == false && grid.grid[cellX][cellY]->isOxygenTank == false && grid.grid[cellX][cellY]->isHullBreach == false)
			{
				fireSpawnChance = 500;
				grid.grid[cellX][cellY]->isOnFire = true;
				grid.grid[cellX][cellY]->oxygenLevel = 0;
			}
	}
	else
		fireSpawnChance--;
		
}

// Function that manages the spread of oxygen in the map
void Fire::fireSpread(Level& grid, int cellX, int cellY)
{
	// If the cell is on fire, choose a random direction to spread
	if (grid.grid[cellX][cellY]->isOnFire == true)
	{
		int randomDirectionX = rand() % (-1 - 2) - 1;
		int randomDirectionY = rand() % (-1 - 2) - 1;


		// The new random cell is within the map
		if (cellX + (randomDirectionX)+1 <= grid.grid.size() && cellX + (randomDirectionX)-1 >= 0 && cellY + (randomDirectionY)+1 <= grid.grid.size() && cellY + (randomDirectionY)-1 >= 0)
		{
			// The new random cell is room and not a hull breach
			if (grid.grid[cellX + (randomDirectionX)][cellY + (randomDirectionY)]->isRoom && grid.grid[cellX + (randomDirectionX)][cellY + (randomDirectionY)]->isHullBreach == false)
			{
				// The new random cell is not an open door
				if ( grid.grid[cellX + (randomDirectionX)][cellY + (randomDirectionY)]->isOpenDoor == false)
				{
					// The cell has oxygen
					if (grid.grid[cellX + (randomDirectionX)][cellY + (randomDirectionY)]->getOxygenLevel() >= 25)
					{
						// Random fire spread rate
						int randomSpawnChance = rand() % (0 - spawnRate);
						if (randomSpawnChance == 0)
						{
							grid.grid[cellX + (randomDirectionX)][cellY + (randomDirectionY)]->isOnFire = true;
							grid.grid[cellX + (randomDirectionX)][cellY + (randomDirectionY)]->oxygenLevel = 0;
						}
					}
				}
			}
		}
	}
}


	


