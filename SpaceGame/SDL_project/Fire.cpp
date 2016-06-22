
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

void Fire::spawn(Level& grid, int cellX, int cellY)
{
	
	if (fireSpawnChance <= 0 && grid.grid[cellX][cellY]->isRoom && grid.grid[cellX][cellY]->isOpenDoor == false && cellX >= 5 && cellY >= 5)
	{
		
		fireSpawnChance = 500;
		grid.grid[cellX][cellY]->isOnFire = true;
		grid.grid[cellX][cellY]->oxygenLevel = 0;
	}
	else
		fireSpawnChance--;
		
}

void Fire::fireSpread(Level& grid, int cellX, int cellY)
{

	if (grid.grid[cellX][cellY]->isOnFire == true)
	{

		int randomDirectionX = rand() % (-1 - 2) - 1;
		int randomDirectionY = rand() % (-1 - 2) - 1;


		//is within the map
		if (cellX + (randomDirectionX)+1 <= grid.grid.size() && cellX + (randomDirectionX)-1 >= 0 && cellY + (randomDirectionY)+1 <= grid.grid.size() && cellY + (randomDirectionY)-1 >= 0)
		{
			//Is room and not a door
			if (grid.grid[cellX + (randomDirectionX)][cellY + (randomDirectionY)]->isRoom && grid.grid[cellX + (randomDirectionX)][cellY + (randomDirectionY)]->isHullBreach == false)
			{
				if ( grid.grid[cellX + (randomDirectionX)][cellY + (randomDirectionY)]->isOpenDoor == false)
				{


					//The cell has oxygen
					if (grid.grid[cellX + (randomDirectionX)][cellY + (randomDirectionY)]->getOxygenLevel() >= 25)
					{
						//random fire spread rate
						int randomSpawnChance = rand() % (0 - 50);
						if (randomSpawnChance <= 1)
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


	


