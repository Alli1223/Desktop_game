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
	int oxygen_Level = cell.get_Oxygen_level();
	if (x >= cell.getX() - grid.getCellSize() && x <= cell.getX() + grid.getCellSize())
	{
		if (y >= cell.getY() - grid.getCellSize() && y <= cell.getY() + grid.getCellSize())
		{
			if (cell.isRoom)
			{
				if (cell.get_Oxygen_level() >= 100)
				{
					//Oyxgen in cell is full
					Set_Oxygen_Level(100);
					cell.isOxygenated = true;
					cell.set_Oxygen_level(100);
					SDL_Log("Oxygen full");
					//update cell sprite

				}

				else
				{
					cell.isOxygenated = false;
					oxygen_Level++;
					Set_Oxygen_Level(oxygen_Level);
					cell.set_Oxygen_level(oxygen_Level);
					SDL_Log("Spawning oxygen %i", cell.get_Oxygen_level());

				}
			}
		}
	}
}

//Decreases oxygen in a selected cell (only if the cell is a room)
void Oxygen::removeOxygen(int x, int y)
{

	int oxygen_Level = Get_Oxygen_Level();

	if (oxygen_Level -= 0)
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



