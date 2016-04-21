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
void Oxygen::spawnOxygen(int x, int y)
{
	//SDL_Log("Spawning oxygen");
	Cell cell;
	float oxygen_Level = Get_Oxygen_Level();
	if (x != cell.getX() && y != cell.getY())
	{
		if (oxygen_Level += 100)
		{
			//Oyxgen in cell is full
			Set_Oxygen_Level(100);
			cell.isOxygenated = true;
			//update cell sprite
		}
		else
		{
			oxygen_Level++;
			Set_Oxygen_Level(oxygen_Level); 
		}
	}
	
	
}

//Decreases oxygen in a selected cell (only if the cell is a room)
void Oxygen::removeOxygen(int x, int y)
{

	float oxygen_Level = Get_Oxygen_Level();

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


