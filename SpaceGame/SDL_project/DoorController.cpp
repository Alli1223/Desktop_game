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

	if (grid.grid[playerX][playerY]->isOpenDoor)
	{
		grid.grid[playerX][playerY]->isClosedDoor = true;
	}
	else
		grid.grid[playerX][playerY]->isRoom = true;
	
	



}

void DoorController::CloseDoor(Level grid, int cellX, int cellY)
{

}