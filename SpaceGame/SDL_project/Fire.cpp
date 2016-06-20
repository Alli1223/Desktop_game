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

void Fire::spawn()
{

}

void Fire::update(Level grid, int cellX, int cellY)
{
	
	if (fireSpawnChance <= 0)
	{
		fireSpawnChance = 60;

		//if the cell is a room and contains oxygen
		if (grid.grid[cellX][cellY]->oxygenLevel > 0)
		{
			grid.grid[cellX][cellY]->isOnFire = true;
		}


	}

	else
		fireSpawnChance--;
}
