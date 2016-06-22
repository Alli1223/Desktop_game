#include "stdafx.h"
#include "DoorController.h"
#include "Character.h"
#include "level.h"



DoorController::DoorController()
{
}


DoorController::~DoorController()
{
}

void DoorController::OpenDoor(Level& grid, int cellX, int cellY, Character& character)
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

	
	



}
