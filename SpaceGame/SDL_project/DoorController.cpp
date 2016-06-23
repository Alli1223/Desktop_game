#include "stdafx.h"
#include "DoorController.h"
#include "Character.h"
#include "level.h"
#include "Oxygen.h"



DoorController::DoorController()
{
}


DoorController::~DoorController()
{
}

void DoorController::OpenDoor(Level& grid, int cellX, int cellY, Character& character, Oxygen& oxygen)
{
	
	//Gets the player X and Y values
	int pX = character.getX();
	int pY = character.getY();
	int playerX = pX / grid.getCellSize();
	int playerY = pY / grid.getCellSize();

	// If the player walks on to the door, open it
	if (grid.grid[playerX][playerY]->isOpenDoor == true)
	{
		grid.grid[playerX][playerY]->isOpenDoor = false;
		grid.grid[playerX][playerY]->isClosedDoor = true;
	}

	// If the player walks over an oxygen tank, remove it
	if (grid.grid[playerX][playerY]->isOxygenTank == true)
	{
		int currentOxygen = oxygen.getOxygenReserves();
		oxygen.setOxygenReserves(currentOxygen + 1000);
		grid.grid[playerX][playerY]->isOxygenTank = false;
	}
	
	if (grid.grid[playerX][playerY]->isHealthPack == true)
	{
		grid.grid[playerX][playerY]->isHealthPack = false;	

		character.health = 100;

	}

	
	



}
