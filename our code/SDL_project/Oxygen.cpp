#include "stdafx.h"
#include "Oxygen.h"
#include "Cell.h"

Oxygen::Oxygen()
{

	SDL_PumpEvents();

	int x, y;
	if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
		SDL_Log("Mouse Button 1 (left) is pressed.");

		Cell cell;
		cell.getX();
		cell.getY();
	}


	
}


Oxygen::~Oxygen()
{
}

//Increases oxygen in a selected cell
void Oxygen::spawnOxygen()
{
	
	float oxygen_Level = Get_Oxygen_Level();

	if (oxygen_Level += 100)
	{
		//Oyxgen in cell is full
		oxygen_Level = 100;

		//update cell sprite
	}
	else
	{
		oxygen_Level++;
	}
}

void Oxygen::removeOxygen()
{

}


