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
void Oxygen::spawnOxygen(int mouseX, int mouseY, int cellSize, Grid grid)
{
	int cellX = mouseX / cellSize;
	int cellY = mouseY / cellSize;

	int oxygenLevel = grid.grid[cellX][cellY]->getOxygenLevel();
	if (oxygenLevel < 100)
	{
		oxygenLevel = oxygenLevel + 2;
		grid.grid[cellX][cellY]->setOxygenLevel(oxygenLevel);
	}	
}



	//int local_oxygen_level = Get_Oxygen_Level();

	/*
	if (grid.grid[cellX][cellY]->isRoom)
	{
		if (oxygenLevel >= 100)
		{
			//Oyxgen in cell is full
			grid.grid[cellX][cellY]->setOxygenLevel(100);
	
			SDL_Log("Oxygen full");
			//update cell sprite
		}

		else
		{
			oxygenLevel++;
			grid.grid[cellX][cellY]->setOxygenLevel(oxygenLevel);

			//grid.grid[cellX][cellY]->isOxygenated = false;
			SDL_Log("Spawning oxygen %i", grid.grid[cellX][cellY]->getOxygenLevel());
		}
		if (grid.grid[cellX][cellY]->isOxygenated)
		{

		}
	}
}


//Decreases oxygen in a selected cell (only if the cell is a room)
void Oxygen::removeOxygen(int x, int y)
{

	int oxygen_Level = Get_Oxygen_Level();

	if (oxygen_Level <= 0)
	{
		//Oyxgen in cell is empty
		oxygen_Level = 0;

		//update cell sprite

	}
	else
	{
		oxygen_Level--;
	}

}*/



