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
int increase_oxygen_level(int level, Cell cell)
{
	return cell.set_Oxygen_level(level);
}

int get_level(Cell cell)
{
	return cell.get_Oxygen_level();
}

//Increases oxygen in a selected cell (only if the cell is a room)
int Oxygen::spawnOxygen(int x, int y, int cell_X, int cell_Y, int OxygenLevel)
{
	if (cell_X == x && cell_Y == y)
	{

		if (OxygenLevel >= 100)
		{
			//Oyxgen in cell is full
			OxygenLevel = 100;
			SDL_Log("Oxygen full");
			return OxygenLevel;
		}

		else
		{
			OxygenLevel++;
			SDL_Log("Spawning oxygen %i", OxygenLevel);
			return OxygenLevel;
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

}


