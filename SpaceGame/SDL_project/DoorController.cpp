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
	

	int pX = character.getX();
	int pY = character.getY();
	int playerX = pX / grid.getCellSize();
	int playerY = pY / grid.getCellSize();

	if (grid.grid[playerX][playerY]->isOpenDoor == true)
	{
		grid.grid[playerX][playerY]->isOpenDoor = false;
		grid.grid[playerX][playerY]->isClosedDoor = true;
	}

	if (grid.grid[playerX][playerY]->isOxygenTank == true)
	{
		int currentOxygen = oxygen.getOxygenReserves();
		oxygen.setOxygenReserves(currentOxygen + 1000);
		grid.grid[playerX][playerY]->isOxygenTank = false;
	}
	else
		grid.grid[playerX][playerY]->isOxygenTank = false;

	
	



}
