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
void Oxygen::spawnOxygen(int x, int y, int cell_X, int cell_Y, Cell cell)
{
	Grid grid;
	int oxygen_level = cell.get_Oxygen_level();
	int local_oxygen_level = Get_Oxygen_Level();
	if (x >= (cell_X - grid.getCellSize()) && x <= cell_X + grid.getCellSize())
	{
		if (y >= cell_Y - grid.getCellSize() && y <= cell_Y + grid.getCellSize())
		{
			if (cell.isRoom)
			{
				if (Get_Oxygen_Level() >= 100)
				{
					//Oyxgen in cell is full
					cell.set_Oxygen_level(100);
					cell.isOxygenated = true;
					cell.set_Oxygen_level(100);
					SDL_Log("Oxygen full");
					//update cell sprite

				}

				else
				{
					oxygen_level++;
					local_oxygen_level++;
					cell.set_Oxygen_level(local_oxygen_level);
					
					Set_Oxygen_Level(local_oxygen_level);
					cell.isOxygenated = false;
					SDL_Log("Spawning oxygen %i", cell.get_Oxygen_level());
				}
				if (cell.isOxygenated)
				{
					
				}
			}
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



