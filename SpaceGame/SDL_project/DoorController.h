#pragma once
#include "Level.h"
#include "Character.h"
class DoorController
{
public:
	DoorController();
	~DoorController();

	void DoorController::OpenDoor(Level& grid, int cellX, int cellY, Character& character);
	void DoorController::CloseDoor(Level grid, int cellX, int cellY);
};

