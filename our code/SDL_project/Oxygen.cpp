#include "stdafx.h"
#include "Oxygen.h"
#include "Cell.h"
#include "MainCharacter.h"

Oxygen::Oxygen()
{
	int x, y;
	SDL_PumpEvents();
	if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)) 
	{
		SDL_Log("Mouse Button 1 (left) is pressed.");

		spawnOxygen(x, y);
	}	
}


Oxygen::~Oxygen()
{

}

//Increases oxygen in a selected cell (only if the cell is a room)
void Oxygen::spawnOxygen(int x, int y)
{
	Character character;
	float oxygen_Level = Get_Oxygen_Level();
	if (character.getX() == x || character.getY() == y)
	{
		if (oxygen_Level += 100)
		{
			//Oyxgen in cell is full
			
			Set_Oxygen_Level(100);
			//update cell sprite
		}
		else
		{
			oxygen_Level++;
		}
	}
	
}

//Decreases oxygen in a selected cell (only if the cell is a room)
void Oxygen::removeOxygen()
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


